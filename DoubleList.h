//
// Created by Арсений Копаев on 15.10.2023.
//

#ifndef DOUBLELIST_DOUBLELIST_H
#define DOUBLELIST_DOUBLELIST_H

class DoubleList {
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int elem) {
            next = nullptr;
            prev = nullptr;
            data = elem;
        }
        Node() {
            Node(0);
        }
    };


    Node* head;
    Node* tail;
    void clear();
public:
    DoubleList();
    ~DoubleList();
    bool isEmpty();
    void addAfterNode(Node* pNode, int elem);
    void deleteAfterNode(Node* pNode);
    void addBeforeNode(Node* pNode, int elem);
    void deleteBeforeNode(DoubleList::Node* pNode);

    void addAfterHead(int elem);
    void addBeforeHead(int elem);
    void addAfterTail(int elem);
    void addBeforeTail(int elem);

    void deleteBeforeTail();
    void deleteAfterHead();
};


#endif //DOUBLELIST_DOUBLELIST_H
