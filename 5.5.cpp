#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void deleteNode(Node* node) {
    if (node == nullptr || node->next == nullptr) return;

    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    Node* toDelete = head->next->next;
    toDelete->next = new Node(2);
    toDelete->next->next = new Node(7);

    cout << "До удаления: ";
    printList(head);

    deleteNode(toDelete);

    cout << "После удаления: ";
    printList(head);

    return 0;
}
