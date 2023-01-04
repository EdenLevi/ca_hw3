//
// Created by edenl on 28/12/2022.
//

#include "tree.h"

bool treeInsert(tree *head, tree *newElement) {
    if(!head || !newElement) return false;
    while(1) { // replace with condition for going left
        if(!head->left) {
            head->left = newElement;
            break;
        }
        head = head->left;
    }
    while(1) { // replace with condition for going right
        if(!head->right) {
            head->right = newElement;
            break;
        }
        head = head->right;
    }
    return true;
}

tree *isInTree(tree *head, int id) {
    if(!head || id < 0) return nullptr;
    while(head) {
        if(head->id == id) return head;
        else if(head->left) { // add condition for going left or right based on id
            head = head->left;
        }
        else if(head->right) { // add condition for going left or right based on id
            head = head->right;
        }
        else break;
    }
    return nullptr;
}
