#include <iostream>

struct Node {
    int key;
    Node *next;

    Node(int key) {this->key = key; this->next = nullptr;}
};

struct OneLinkedList {
    Node *head, *tail;

    OneLinkedList() {
        this->head = this->tail = nullptr;
    }

    ~OneLinkedList() {
        while (head != nullptr) {
            pop_front();
        }
    }

    void pop_front() {
        if (head == nullptr) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }

        Node *node = head;
        head = node->next;
        delete node;
    }

    void push_back(int key) {
        Node *node = new Node(key);
        if (head == nullptr) {
            head = node;
        }
        if (tail != nullptr) {
            tail->next = node;
        }
        tail = node;
    }

    void push_front(int key) {
        Node* node = new Node(key);
        node->next = head;
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
    }

    void pop_back() {
        if (tail == nullptr) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }

        Node *node = head;
        for (;node->next != tail; node = node->next);
        node->next = nullptr;
        delete tail;
        tail = node;
    }

    Node *getAt(int k) {
        if (k < 0) return nullptr;
        Node *node = head;
        int n = 0;
        while (node && (n != k) && (node->next)) {
            node = node->next;
            n++;
        }

        return (n == k) ? node : nullptr;
    }

    void insert(int k, int key) {
        Node *left = getAt(k);
        if (left == nullptr) return;
        Node *right = left->next;
        Node *node = new Node(key);
        left->next = node;
        node->next = right;
        if (right == nullptr) {
            tail = node;
        }
    }

    void erase(int k) {
        if (k < 0) return;
        if (k == 0) {
            pop_front();
            return;
        }
        Node *left = getAt(k - 1);
        Node *node = left->next;
        if (node == nullptr) return;
        Node *right = node->next;

        left->next = right;
        if (node == tail) {
            tail = left;
        }
        delete node;
    }
};

int main() {
    OneLinkedList lst;
    lst.push_front(1);
    lst.push_back(2);

    Node *n = lst.getAt(0);
    int d = (n != nullptr) ? n->key : 0;
    std::cout<<d<<std::endl;

    lst.erase(1);
    lst.insert(0, 5);
    lst.insert(0, 2);
    for (Node *node = lst.head; node != nullptr; node = node->next) {
        std::cout<<node->key<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
