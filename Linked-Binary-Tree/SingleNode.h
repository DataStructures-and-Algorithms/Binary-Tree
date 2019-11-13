//
// Created by Hayden Huynh on 10/28/19.
//

#ifndef LINKED_LIST_SINGLENODE_H
#define LINKED_LIST_SINGLENODE_H

#include <iostream>

template <class T>
class SingleNode {

    template <class U> friend class SingleLinkedList;

private:

    T val;

    SingleNode<T>* pNext;

public:

    SingleNode(T val);

};

template <class T>
SingleNode<T>::SingleNode(T val) {
    this->val = val;
    pNext = NULL;
}

#endif //LINKED_LIST_SINGLENODE_H
