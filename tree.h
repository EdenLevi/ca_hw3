//
// Created by edenl on 28/12/2022.
//

#ifndef CA_HW3_TREE_H
#define CA_HW3_TREE_H


class tree {
public:
    tree* left;
    tree* right;
    int id;

    tree() : left(nullptr), right(nullptr) {}
};

bool treeInsert(tree* head, tree* newElement);
bool treeRemove(tree* head, int id);
tree* isInTree(tree* head, int id);

#endif //CA_HW3_TREE_H
