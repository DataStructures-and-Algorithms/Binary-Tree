//
// Created by Hayden Huynh on 11/12/19.
//

#ifndef QUEUE_LINKEDLISTQUEUE_H
#define QUEUE_LINKEDLISTQUEUE_H

#include "SingleLinkedList.h"

template <class V>
class LinkedListQueue {

private:
    int currSize;
    SingleLinkedList<V> list;

public:
    LinkedListQueue();

    void enqueue(V val);

    V dequeue();

    V getFirst();

    V getLast();

    bool isEmpty();

    int getCurrSize();

    void deleteQueue();

};

template <class V>
LinkedListQueue<V>::LinkedListQueue() {
    currSize = 0;
}

template <class V>
void LinkedListQueue<V>::enqueue(V val) {
    list.insert(val, currSize);
    currSize++;
}

template <class V>
V LinkedListQueue<V>::dequeue() {
    if (currSize == 0) {
        std::cout << "\n\nQueue is empty.\n\n";
    }
    else {
        V returnVal = list.getHeadValue();
        list.deleteNode(0);
        currSize--;
        return returnVal;
    }
}

template <class V>
V LinkedListQueue<V>::getFirst() {
    if (currSize == 0) {
        std::cout << "\n\nQueue is empty.\n\n";
    }
    else {
        return list.getHeadValue();
    }
}

template <class V>
V LinkedListQueue<V>::getLast() {
    if (currSize == 0) {
        std::cout << "\n\nQueue is empty.\n\n";
    }
    else {
        return list.getTailValue();
    }
}

template <class V>
bool LinkedListQueue<V>::isEmpty() {
    return currSize == 0;
}

template <class V>
int LinkedListQueue<V>::getCurrSize() {
    return currSize;
}

template <class V>
void LinkedListQueue<V>::deleteQueue() {
    currSize = 0;
    list.deleteList();
}

#endif //QUEUE_LINKEDLISTQUEUE_H
