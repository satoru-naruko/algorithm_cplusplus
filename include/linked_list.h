#pragma once

using namespace std;

template<class T>
class LinkedList {
private:
	template<class T>
	class LinkedListNode {
	public:
		T key{};
		LinkedListNode* prev = nullptr;
		LinkedListNode* next = nullptr;
	};
	LinkedListNode<T> front;
	int insertImpl(T& insertkey) {
		auto newNode = new LinkedListNode<T>();
		if (newNode) {
			newNode->key = insertkey;
			newNode->next = front.next;
			front.next->prev = newNode;
			front.next = newNode;
			newNode->prev = &front;
		}
		else {
			return -1;
		}

		return 0;
	}

	LinkedListNode<T>* search(T searchKey) {
		auto pCurrent = front.next;
		while (pCurrent != &front && pCurrent->key != searchKey)
		{
			pCurrent = pCurrent->next;
		}

		return pCurrent;
	}
public:
	LinkedList() {
		front.next = &front;
		front.prev = &front;
	}

	int insert(T& insertkey) {
		return insertImpl(insertkey);
	}

	int insert(T insertkey) {
		return insertImpl(insertkey);
	}

	void deleteNode(T &deleteKey) {
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

