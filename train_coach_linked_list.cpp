#include <iostream>
using namespace std;

struct Node {
    int coach;
    Node* next;
};

void addBeginning(Node*& head, int coach) {
    Node* newNode = new Node();
    newNode->coach = coach;
    newNode->next = head;
    head = newNode;
}

void addEnd(Node*& head, int coach) {
    Node* newNode = new Node();
    newNode->coach = coach;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void removeCoach(Node*& head, int coach) {
    if (head == NULL)
        return;

    if (head->coach == coach) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->coach != coach)
        temp = temp->next;

    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->coach << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

  
    addEnd(head, 1);
    addEnd(head, 2);
    addEnd(head, 3);
    addEnd(head, 4);

    
    addBeginning(head, 0);

    addEnd(head, 5);

  
    removeCoach(head, 3);

    
    display(head);

    return 0;
}
