//
// Created by Hayden Huynh on 11/13/19.
//

#ifndef BINARYTREE_BINARYTREENODE_H
#define BINARYTREE_BINARYTREENODE_H

#include <iostream>

template <class T>
class BinaryTreeNode {
    template <class U> friend class LinkedBinaryTree;

public:
    T data;
    BinaryTreeNode<T>* pLeft;
    BinaryTreeNode<T>* pRight;

public:
    BinaryTreeNode(T data);

};

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T data) {
    this->data = data;
    pLeft = NULL;
    pRight = NULL;
}

#endif //BINARYTREE_BINARYTREENODE_H
