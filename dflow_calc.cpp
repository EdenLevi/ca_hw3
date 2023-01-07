/* 046267 Computer Architecture - Winter 20/21 - HW #3               */
/* Implementation (skeleton)  for the dataflow statistics calculator */

#include "dflow_calc.h"
#include "vector"

using namespace std;

class Node {
public:
    InstInfo data;
    Node *dLeft; // first dependency
    Node *dRight; // second dependency
    unsigned int cyclesIncludingCommand;
    unsigned int myCycles;
    int id;

    Node(InstInfo dataIn, int id) : dLeft(nullptr), dRight(nullptr), cyclesIncludingCommand(0), myCycles(0), id(id) {
        this->data.dstIdx = dataIn.dstIdx;
        this->data.opcode = dataIn.opcode;
        this->data.src1Idx = dataIn.src1Idx;
        this->data.src2Idx = dataIn.src2Idx;
    }
};

class ProgramContext {
public:
    std::vector<Node *> nodes;
    Node *lastNodeWroteToRegister[MAX_OPS];

    ProgramContext() {
        for (int i = 0; i < MAX_OPS; i++) {
            lastNodeWroteToRegister[i] = nullptr;
        }
    }

    ~ProgramContext() {
        for (int i = 0; i < MAX_OPS; i++) {
            if(lastNodeWroteToRegister[i]) {
                delete(lastNodeWroteToRegister[i]);
            }
        }
    }
};

ProgCtx analyzeProg(const unsigned int opsLatency[], const InstInfo progTrace[], unsigned int numOfInsts) {

    ProgramContext *prog = new ProgramContext();

    for (int i = 0; i < numOfInsts; i++) {
        /// read a command from input and check its dependencies
        Node *node = new Node(progTrace[i], i);
        prog->nodes.push_back(node);

        /// updating node's dependencies
        node->dLeft = prog->lastNodeWroteToRegister[node->data.src1Idx];
        node->dRight = prog->lastNodeWroteToRegister[node->data.src2Idx];

        /// updating register destination to last used (current node)
        prog->lastNodeWroteToRegister[node->data.dstIdx] = node;

        /// updating cycles time
        if(node->dLeft && node->dRight) {
            node->cyclesIncludingCommand = max(node->dLeft->cyclesIncludingCommand, node->dRight->cyclesIncludingCommand) + opsLatency[node->data.opcode];
        }
        else if(node->dLeft) {
            node->cyclesIncludingCommand = node->dLeft->cyclesIncludingCommand + opsLatency[node->data.opcode];
        }
        else if(node->dRight) {
            node->cyclesIncludingCommand = node->dRight->cyclesIncludingCommand + opsLatency[node->data.opcode];
        }
        else {
            node->cyclesIncludingCommand = opsLatency[node->data.opcode];
        }

        /// updating myCycles
        node->myCycles = opsLatency[node->data.opcode];
    }

    return (ProgCtx) prog;
}

void freeProgCtx(ProgCtx ctx) {
    ProgramContext* prog = ((ProgramContext*)ctx);
    delete prog;
}

int getInstDepth(ProgCtx ctx, unsigned int theInst) {
    ProgramContext* prog = ((ProgramContext*)ctx);
    if(prog->nodes.size() >= theInst) {
        return (int)(prog->nodes[theInst]->cyclesIncludingCommand - prog->nodes[theInst]->myCycles);
    }
    return -1;
}

int getInstDeps(ProgCtx ctx, unsigned int theInst, int *src1DepInst, int *src2DepInst) {
    ProgramContext* prog = ((ProgramContext*)ctx);
    if(theInst >= prog->nodes.size()) return -1; // check if there is command number <theInst>
    *src1DepInst = (prog->nodes[theInst]->dLeft ? prog->nodes[theInst]->dLeft->id : -1);
    *src2DepInst = (prog->nodes[theInst]->dRight ? prog->nodes[theInst]->dRight->id : -1);

    return 0;
}

int getProgDepth(ProgCtx ctx) {

    ProgramContext* prog = ((ProgramContext*)ctx);
    int progMaxDepth = 0;
    for(Node* n : prog->nodes) {
        progMaxDepth = max(progMaxDepth, (int)(n->cyclesIncludingCommand));
    }

    return progMaxDepth;
}


