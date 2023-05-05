#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertionHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertionTail(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void insertionMid(Node* &head, Node* &tail, int position, int data) {
    if (position == 1) {
        insertionHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        return;
    }

    if (temp == tail) {
        insertionTail(head, tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node* head) {
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->data << " ";
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertionTail(head, tail, 10);
    print(head);

    insertionTail(head, tail, 20);
    print(head);

    insertionTail(head, tail, 30);
    print(head);

    insertionMid(head, tail, 1, 15);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}