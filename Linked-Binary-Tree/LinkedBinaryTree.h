//
// Created by Hayden Huynh on 11/13/19.
//

#ifndef BINARYTREE_LINKEDBINARYTREE_H
#define BINARYTREE_LINKEDBINARYTREE_H

#include "BinaryTreeNode.h"
#include "LinkedListQueue.h"

template <class U>
class LinkedBinaryTree {
    
private:
    BinaryTreeNode<U>* root;
    
public:
    LinkedBinaryTree();
    
    BinaryTreeNode<U>*& getRoot();
    
    void preOrder(BinaryTreeNode<U>* root);
    
    void inOrder(BinaryTreeNode<U>* root);
    
    void postOrder(BinaryTreeNode<U>* root);
    
    void levelOrder();

    void search(U val);

    void insert(U val);

    void deleteNode(U val);

    void deleteTree();
};

template <class U>
LinkedBinaryTree<U>::LinkedBinaryTree() {
    root = NULL;
}

template <class U>
BinaryTreeNode<U>*& LinkedBinaryTree<U>::getRoot() {
    return root;
}

template <class U>
void LinkedBinaryTree<U>::preOrder(BinaryTreeNode<U>* root) {
    if (root == NULL) {
        return;
    }
    else {
        std::cout << root->data << " ";
        preOrder(root->pLeft);
        preOrder(root->pRight);
    }
}

template <class U>
void LinkedBinaryTree<U>::inOrder(BinaryTreeNode<U>* root) {
    if (root == NULL) {
        return;
    }
    else {
        inOrder(root->pLeft);
        std::cout << root->data << " ";
        inOrder(root->pRight);
    }
}

template <class U>
void LinkedBinaryTree<U>::postOrder(BinaryTreeNode<U>* root) {
    if (root == NULL) {
        return;
    }
    else {
        postOrder(root->pLeft);
        postOrder(root->pRight);
        std::cout << root->data << " ";
    }
}

template <class U>
void LinkedBinaryTree<U>::levelOrder() {
    if (root == NULL) {
        std::cout << "\n\nThe Binary Tree is empty.\n\n";
    }
    else {
        LinkedListQueue<BinaryTreeNode<U>*> queue;
        queue.enqueue(root);
        BinaryTreeNode<U>* temp = NULL;
        while (!queue.isEmpty()) {
            temp = queue.dequeue();

            std::cout << temp->data << " ";

            if (temp->pLeft != NULL) {
                queue.enqueue(temp->pLeft);
            }
            if (temp->pRight != NULL) {
                queue.enqueue(temp->pRight);
            }
        }
    }
}

template <class U>
void LinkedBinaryTree<U>::search(U val) {
    if (root == NULL) {
        std::cout << "\n\nThe Binary Tree is empty.\n\n";
    }
    else {
        LinkedListQueue<BinaryTreeNode<U>*> queue;
        queue.enqueue(root);
        int index = 0;
        BinaryTreeNode<U>* temp = NULL;

        while (!queue.isEmpty()) {
            temp = queue.dequeue();

            if (temp->data == val) {
                std::cout << "\n\nFound value: " << val << " at index " << index << " in Level Order Traversal.\n\n";
                return;
            }

            if (temp->pLeft != NULL) {
                queue.enqueue(temp->pLeft);
            }
            if (temp->pRight != NULL) {
                queue.enqueue(temp->pRight);
            }
            index++;
        }

        std::cout << "\n\nGiven value not found.\n\n";
    }
}

template <class U>
void LinkedBinaryTree<U>::insert(U val) {
    if (root == NULL) {
        root = new BinaryTreeNode<U>(val);
    }
    else {
        LinkedListQueue<BinaryTreeNode<U>*> queue;
        queue.enqueue(root);
        BinaryTreeNode<U>* temp = NULL;

        while (!queue.isEmpty()) {
            temp = queue.dequeue();

            if (temp->pRight == NULL) {
                if (temp->pLeft == NULL) {
                    temp->pLeft = new BinaryTreeNode<U>(val);
                }
                else {
                    temp->pRight = new BinaryTreeNode<U>(val);
                }
                break;
            }

            queue.enqueue(temp->pLeft);
            queue.enqueue(temp->pRight);
        }
    }
}

template <class U>
void LinkedBinaryTree<U>::deleteNode(U val) {
    if (root == NULL) {
        std::cout << "\n\nThe Binary Tree is empty.\n\n";
    }
    else {
        //Finding the node to be deleted
        LinkedListQueue<BinaryTreeNode<U>*> queue;
        queue.enqueue(root);

        BinaryTreeNode<U>* temp = NULL;
        BinaryTreeNode<U>* deleteNode = NULL;
        BinaryTreeNode<U>* lastNode = NULL;
        BinaryTreeNode<U>* parentOfLast = NULL;

        while (!queue.isEmpty()) {
            temp = queue.dequeue();

            if (temp->data == val) {
                deleteNode = temp;
            }
            if (queue.getCurrSize() == 1) {
                if (queue.getFirst()->pLeft == NULL && queue.getFirst()->pRight == NULL) {
                    lastNode = queue.dequeue();
                    break;
                }
            }

            if (temp->pLeft != NULL) {
                queue.enqueue(temp->pLeft);
                parentOfLast = temp;
            }
            if (temp->pRight != NULL) {
                queue.enqueue(temp->pRight);
            }
        }

        if (deleteNode == NULL) {
            std::cout << "\n\nGiven value not found.\n\n";
            return;
        }

        //Copy the data of the deepest node to the node to be deleted
        if (parentOfLast->pLeft == lastNode) {
            parentOfLast->pLeft = NULL;
        }
        else {
            parentOfLast->pRight = NULL;
        }

        if (deleteNode == lastNode) {
            delete lastNode;
            lastNode = NULL;
            deleteNode = NULL;
            return;
        }
        deleteNode->data = lastNode->data;

        //Delete the deepest node
        delete lastNode;
        lastNode = NULL;
    }
}

template <class U>
void LinkedBinaryTree<U>::deleteTree() {
    LinkedListQueue<BinaryTreeNode<U>*> queue;
    queue.enqueue(root);
    BinaryTreeNode<U>* temp = NULL;
    while (!queue.isEmpty()) {
        temp = queue.dequeue();

        if (temp->pLeft != NULL) {
            queue.enqueue(temp->pLeft);
        }
        if (temp->pRight != NULL) {
            queue.enqueue(temp->pRight);
        }

        delete temp;
        temp =  NULL;
    }
    root = NULL;
}

#endif //BINARYTREE_LINKEDBINARYTREE_H
