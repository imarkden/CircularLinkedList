#include "Soldiers.hpp"

Soldiers::Soldiers() : head(nullptr), size(0) {}

void Soldiers::AddSoldier(const string& name) {
    Node* newNode = new Node{name, nullptr};
    if (!head) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    size++;
}

void Soldiers::PrintSoldiers() const {
    if (!head) {
        cout << "No soldiers in the list." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void Soldiers::RemoveSoldier(int count) {
    if (!head || size == 0) {
        return;
    }
    Node* prev = head;
    for (int i = 0; i < count - 1; i++) {
        prev = prev->next;
    }
    Node* eliminate = prev->next;
    prev->next = eliminate->next;
    if (eliminate == head) {
        head = eliminate->next;
    }
    cout << eliminate->name << " was eliminated." << endl;
    delete eliminate;
    size--;
    if (size == 0) {
        head = nullptr;
    }
}

void Soldiers::EliminateSoldier(int round) {
    while (GetSize() > 1) {
        RemoveSoldier(round);
    }
}

int Soldiers::GetSize() const {
    return size;
}

string Soldiers::GetHeadName() const {
    return head ? head->name : "";
}
