//
// Created by Hayden Huynh on 10/28/19.
//

#ifndef LINKED_LIST_SINGLELINKEDLIST_H
#define LINKED_LIST_SINGLELINKEDLIST_H

#include "SingleNode.h"

template <class U>
class SingleLinkedList {

private:
    SingleNode<U>* pHead;

    SingleNode<U>* pTail;

    int size;

    bool rangeCheck(int i);

public:

    SingleLinkedList();

    void insert(U val, int index);

    void traverse();

    void search(U val);

    U getHeadValue();

    U getTailValue();

    void deleteNode(int index);

    void deleteList();
};

template <class U>
SingleLinkedList<U>::SingleLinkedList() {
    pHead = NULL;
    pTail = NULL;
    size = 0;
}

template <class U>
bool SingleLinkedList<U>::rangeCheck(int i) {
    return 0 <= i && i < size;
}

template <class U>
void SingleLinkedList<U>::insert(U val, int index) {
    SingleNode<U>* node = new SingleNode<U>(val);
    if (size == 0) {
        //std::cout << "\nLinked List is empty. Inserting the first node.\n";
        pHead = node;
        pTail = node;
    }
    else {
        if (index == 0) {
            node->pNext = pHead;
            pHead = node;
        }
        else if (index == size) {
            pTail->pNext = node;
            pTail = node;
        }
        else {
            if (rangeCheck(index)) {
                SingleNode<U>* temp = pHead;
                for (int i = 0; i < index-1; i++) {
                    temp = temp->pNext;
                }
                node->pNext = temp->pNext;
                temp->pNext = node;
            }
            else {
                std::cout << "\nIndex out of range.\n";
            }
        }
    }
    size++;
}

template <class U>
void SingleLinkedList<U>::traverse() {
    SingleNode<U>* temp = pHead;
    int count = 1;
    while (temp != NULL) {
        std::cout << "Node " << count << ": " << temp->val << " -> ";
        temp = temp->pNext;
        count++;
    }
    std::cout << "NULL\n";
}

template <class U>
void SingleLinkedList<U>::search(U val) {
    SingleNode<U>* temp = pHead;
    int count = 0;
    while (temp != NULL) {
        if (temp->val == val) {
            std::cout << "\nFound value: " << temp->val << " at index " << count << ".\n";
            return;
        }
        temp = temp->pNext;
        count++;
    }
    std::cout << "\nGiven value not found.\n";
}

template <class U>
U SingleLinkedList<U>::getHeadValue() {
    return pHead->val;
}

template <class U>
U SingleLinkedList<U>::getTailValue() {
    return pTail->val;
}

template <class U>
void SingleLinkedList<U>::deleteNode(int index) {
    if (size == 0) {
        std::cout << "\nLinked List is already empty.\n";
    }
    else if (size == 1) {
        //std::cout << "\nDeleting the only node in the List.\n";
        delete pHead;
        pHead = NULL;
        pTail = NULL;
        size--;
    }
    else {
        SingleNode<U>* deleteNode;
        if (index == 0) {
            deleteNode = pHead;
            pHead = pHead->pNext;
            delete deleteNode;
        }
        else if (index == size-1) {
            deleteNode = pTail;
            SingleNode<U>* temp = pHead;
            for (int i = 0; i < index-1; i++) {
                temp = temp->pNext;
            }
            temp->pNext = NULL;
            pTail = temp;
            delete deleteNode;
        }
        else {
            if (rangeCheck(index)) {
                SingleNode<U> *temp = pHead;
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->pNext;
                }
                deleteNode = temp->pNext;
                temp->pNext = deleteNode->pNext;
                delete deleteNode;
            }
            else {
                std::cout << "\nIndex out of range.\n";
            }
        }
        size--;
    }
}

template <class U>
void SingleLinkedList<U>::deleteList() {
    SingleNode<U>* temp = pHead;
    while(pHead != NULL) {
        temp = temp->pNext;
        delete pHead;
        pHead = temp;
    }
    pTail = NULL;
    size = 0;
}

#endif //LINKED_LIST_SINGLELINKEDLIST_H
