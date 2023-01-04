/* 046267 Computer Architecture - Winter 20/21 - HW #3               */
/* Implementation (skeleton)  for the dataflow statistics calculator */

#include "dflow_calc.h"
#include "vector"

class Node {
public:
    InstInfo data;
    std::vector<Node *> childrenNodes; // nodes that depend on this node
    Node *dLeft; // first dependency
    Node *dRight; // second dependency

    Node(InstInfo dataIn) : dLeft(nullptr), dRight(nullptr) {
        this->data.dstIdx = dataIn.dstIdx;
        this->data.opcode = dataIn.opcode;
        this->data.src1Idx = dataIn.src1Idx;
        this->data.src2Idx = dataIn.src2Idx;
    }
};

class ProgramContext {
public:
    unsigned int numOfInsts;
    std::vector<Node *> nodes;
    Node *lastNodeWroteToRegister[MAX_OPS];


    ProgramContext(unsigned int numOfInsts) : numOfInsts(numOfInsts) {
        for(int i = 0; i < MAX_OPS; i++) {
            lastNodeWroteToRegister[i] = nullptr;
        }
    }
};

ProgCtx analyzeProg(const unsigned int opsLatency[], const InstInfo progTrace[], unsigned int numOfInsts) {

    ProgramContext *prog = new ProgramContext(numOfInsts);

    for (int i = 0; i < numOfInsts; i++) {
        /// read a command from input and
        Node *node = new Node(progTrace[i]);
        prog->nodes.push_back(node);

        node->dLeft = prog->lastNodeWroteToRegister[node->data.src1Idx];
        node->dRight = prog->lastNodeWroteToRegister[node->data.src2Idx];
        if(node->dLeft == node->dRight) node->dRight = nullptr;
    }

    return PROG_CTX_NULL;
}

void freeProgCtx(ProgCtx ctx) {
}

int getInstDepth(ProgCtx ctx, unsigned int theInst) {
    return -1;
}

int getInstDeps(ProgCtx ctx, unsigned int theInst, int *src1DepInst, int *src2DepInst) {
    return -1;
}

int getProgDepth(ProgCtx ctx) {
    return 0;
}


