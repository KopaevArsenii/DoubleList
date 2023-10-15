//
// Created by Арсений Копаев on 15.10.2023.
//

#include "DoubleList.h"

void DoubleList::clear() {
    while (!isEmpty()) {
        deleteAfterNode(head);
    }
}
DoubleList::DoubleList(): head(nullptr), tail(nullptr) {}

DoubleList::~DoubleList() {
    clear();
}

bool DoubleList::isEmpty() {
    return head == nullptr;
}

void DoubleList::addAfterNode(DoubleList::Node *pNode, int elem) {
    Node* p = new Node(elem);
    p->next = pNode->next;
    if (pNode != tail) {
        pNode->next->prev = p;
    } else {
        tail = p;
    }
    pNode->next = p;
    p->prev = pNode;
}

void DoubleList::deleteAfterNode(Node* pNode) {
    if (pNode == tail) return;
    Node* p = pNode->next;
    pNode->next = p->next;
    if (p != tail) {
        p->next->prev = pNode;
    } else {
        tail = pNode;
    }
    p->next = nullptr;
    p->prev = nullptr;
    delete p;
    p = nullptr;
}

void DoubleList::addBeforeNode(DoubleList::Node* pNode, int elem) {
    if (pNode == nullptr) {
        // You can't add before a nullptr node.
        return;
    }
    Node* p = new Node(elem);
    p->prev = pNode->prev;
    if (pNode != head) {
        pNode->prev->next = p;
    } else {
        head = p;
    }
    pNode->prev = p;
    p->next = pNode;
}

void DoubleList::deleteBeforeNode(DoubleList::Node* pNode) {
    if (pNode == nullptr || pNode == head) {
        // You can't delete before a nullptr node or before the head.
        return;
    }
    Node* p = pNode->prev;
    pNode->prev = p->prev;
    if (p != head) {
        p->prev->next = pNode;
    } else {
        head = pNode;
    }
    p->next = nullptr;
    p->prev = nullptr;
    delete p;
    p = nullptr;
}

void DoubleList::addAfterHead(int elem) {
    addAfterNode(head, elem);
}

void DoubleList::addBeforeHead(int elem) {
    addBeforeNode(head, elem);
}

void DoubleList::addAfterTail(int elem) {
    addAfterNode(tail, elem);
}

void DoubleList::addBeforeTail(int elem) {
    addBeforeNode(tail, elem);
}

void DoubleList::deleteBeforeTail() {
    deleteBeforeNode(tail);
}

void DoubleList::deleteAfterHead() {
    deleteAfterNode(head);
}

