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
};

class ProgramContext {
public:
    std::vector<Node*> nodes;
    std::vector<Node*> exitNodes; // nodes no one depend on
};

ProgCtx analyzeProg(const unsigned int opsLatency[], const InstInfo progTrace[], unsigned int numOfInsts) {



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


