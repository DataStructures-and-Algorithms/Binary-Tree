//
// Created by Hayden Huynh on 11/13/19.
//

#ifndef BINARYTREE_ARRAYBINARYTREE_H
#define BINARYTREE_ARRAYBINARYTREE_H

#include <iostream>

template <class T>
class ArrayBinaryTree {

private:
    T* arr;
    int size;
    int lastUsedIndex;

public:
    ArrayBinaryTree(int size);

    void insert(T val);

    void search(T val);

    void inOrder(int i);

    void preOrder(int i);

    void postOrder(int i);

    void levelOrder();

    void deleteNode(T val);

    void deleteTree();
};

template <class T>
ArrayBinaryTree<T>::ArrayBinaryTree(int size) {
    this->size = size;
    lastUsedIndex = 0;
    arr = new T[size];
}

template <class T>
void ArrayBinaryTree<T>::insert(T val) {
    if (lastUsedIndex == size-1) {
        std::cout << "\n\nBinary Tree is full.\n\n";
    }
    else {
        lastUsedIndex++;
        arr[lastUsedIndex] = val;
    }
}

template <class T>
void ArrayBinaryTree<T>::search(T val) {
    if (size == 0) {
        std::cout << "\n\nBinary Tree is empty.\n\n";
    }
    else {
        for (int i = 1; i <= lastUsedIndex; i++) {
            if (arr[i] == val) {
                std::cout << "\n\nFound value: " << val << " at index " << i-1 << " in Level Order Traversal.\n\n";
                return;
            }
        }
        std::cout << "\n\nGiven value not found.\n\n";
    }
}

template <class T>
void ArrayBinaryTree<T>::inOrder(int i) {
    if (i > lastUsedIndex) {
        return;
    }
    else {
        inOrder(i*2);
        std::cout << arr[i] << " ";
        inOrder(i*2+1);
    }
}

template <class T>
void ArrayBinaryTree<T>::preOrder(int i) {
    if (i > lastUsedIndex) {
        return;
    }
    else {
        std::cout << arr[i] << " ";
        preOrder(i*2);
        preOrder(i*2+1);
    }
}

template <class T>
void ArrayBinaryTree<T>::postOrder(int i) {
    if (i > lastUsedIndex) {
        return;
    }
    else {
        postOrder(i*2);
        postOrder(i*2+1);
        std::cout << arr[i] << " ";
    }
}

template <class T>
void ArrayBinaryTree<T>::levelOrder() {
    for (int i = 1; i <= lastUsedIndex; i++) {
        std::cout << arr[i] << " ";
    }
}

template <class T>
void ArrayBinaryTree<T>::deleteNode(T val) {
    for (int i = 1; i <= lastUsedIndex; i++) {
        if (arr[i] == val) {
            arr[i] = arr[lastUsedIndex];
            lastUsedIndex--;
            return;
        }
    }
    std::cout << "\n\nGiven value not found.\n\n";
}

template<class T>
void ArrayBinaryTree<T>::deleteTree() {
    size = 0;
    lastUsedIndex = 0;
    delete[] arr;
}

#endif //BINARYTREE_ARRAYBINARYTREE_H
