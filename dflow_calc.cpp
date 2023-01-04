/* 046267 Computer Architecture - Winter 20/21 - HW #3               */
/* Implementation (skeleton)  for the dataflow statistics calculator */

#include "dflow_calc.h"
#include "vector"

class Node {
public:
    InstInfo data;
    std::vector<Node*> childrenNodes; // nodes that depend on this node
    Node* dLeft;
    Node* dRight;

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
    std::vector<Node*> nodes;
    std::vector<Node*> exitNodes; // nodes no one depend on
    Node *LastNodeWroteToRegister[MAX_OPS];


    ProgramContext(unsigned int numOfInsts) : numOfInsts(numOfInsts) {}
};

ProgCtx analyzeProg(const unsigned int opsLatency[], const InstInfo progTrace[], unsigned int numOfInsts) {

    ProgramContext* prog = new ProgramContext(numOfInsts);

    for(int i = 0; i < numOfInsts; i++) {
       /// read a command from input and
        prog->nodes.push_back()  progTrace[i];
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


