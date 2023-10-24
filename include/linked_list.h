#pragma once // include guard

using namespace std;
template<class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node() : prev(nullptr), next(nullptr) {}
        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };
    Node front;
    int size;

    Node* search(T& searchKey) {
        Node* p = front.next;
        while (p != &front) {
            if (p->data == searchKey) {
                return p;
            }
            p = p->next;
        }
        return &front;
    }

    int insertImpl(T& insertKey) {
        Node* p = search(insertKey);
        if (p != &front) {
            return 0;
        }
        Node* newNode = new Node(insertKey);
        newNode->next = &front;
        newNode->prev = front.prev;
        front.prev->next = newNode;
        front.prev = newNode;
        size++;
        return 1;
    }

public:
    LinkedList() : size(0) {
        front.next = &front;
        front.prev = &front;
    }

    int insert(T& insertKey) {
        return insertImpl(insertKey);
    }

    int insert(T insertKey) {
        return insertImpl(insertKey);
    }

    void deleteNode(T& deleteKey) {
        auto p = search(deleteKey);
        if (p == &front) {
            return;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p; p = nullptr;
    }

    void deleteNode(T deleteKey) {
        auto p = search(deleteKey);
        if (p == &front) {
            return;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p; p = nullptr;
    }
};