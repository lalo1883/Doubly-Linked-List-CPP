#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int val) {
        this->value = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void getHead() {
        if (head)
            cout << "Head: " << head->value << endl;
        else
            cout << "List is empty." << endl;
    }

    void getTail() {
        if (tail)
            cout << "Tail: " << tail->value << endl;
        else
            cout << "List is empty." << endl;
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (length == 0)
            return;

        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0)
            return;

        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index >= length)
            return nullptr;

        Node* temp;
        if (index < length / 2) {
            temp = head;
            for (int i = 0; i < index; ++i)
                temp = temp->next;
        } else {
            temp = tail;
            for (int i = length - 1; i > index; --i)
                temp = temp->prev;
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    void deleteNode(int index) {
        Node* temp = get(index);
        if (!temp)
            return;

        if (index == 0)
            deleteFirst();
        else if (index == length - 1)
            deleteLast();
        else {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            delete temp;
            length--;
        }
    }
};
