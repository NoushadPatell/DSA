#include <iostream>
#include <string>

using namespace std;

// Node structure for the linked list
struct Node {
    int prn;
    string name;
    Node* next;
};

// Class to represent the Pinnacle Club
class PinnacleClub {
private:
    Node* president;
    Node* secretary;

public:
    PinnacleClub() {
        president = nullptr;
        secretary = nullptr;
    }

    void addMember(int prn, const string& name) {
        Node* newNode = new Node{prn, name, nullptr};

        if (!president) {
            president = newNode;
            secretary = newNode;
        } else {
            secretary->next = newNode;
            secretary = newNode;
        }

        cout << "Member added: " << name << endl;
    }

    void deleteMember(int prn) {
        Node* current = president;
        Node* prev = nullptr;

        while (current && current->prn != prn) {
            prev = current;
            current = current->next;
        }

        if (current) {
            if (current == president) {
                president = current->next;
            }

            if (current == secretary) {
                secretary = prev;
            }

            if (prev) {
                prev->next = current->next;
            }

            delete current;
            cout << "Member with PRN " << prn << " deleted." << endl;
        } else {
            cout << "Member with PRN " << prn << " not found." << endl;
        }
    }

    int totalMembers() {
        int count = 0;
        Node* current = president;

        while (current) {
            count++;
            current = current->next;
        }

        return count;
    }

    void displayMembers() {
        Node* current = president;

        cout << "Club Members:" << endl;
        while (current) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    void concatenateLists(PinnacleClub& otherClub) {
        if (!otherClub.president) {
            cout << "The other club is empty." << endl;
            return;
        }

        if (!president) {
            president = otherClub.president;
            secretary = otherClub.secretary;
        } else {
            secretary->next = otherClub.president;
            secretary = otherClub.secretary;
        }

        cout << "Lists concatenated." << endl;
    }

    ~PinnacleClub() {
        Node* current = president;
        Node* nextNode;

        while (current) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    PinnacleClub division1Club;
    PinnacleClub division2Club;

    division1Club.addMember(111, "John");
    division1Club.addMember(112, "Alice");
    division1Club.addMember(113, "Bob");

    division2Club.addMember(211, "Charlie");
    division2Club.addMember(212, "David");
    division2Club.addMember(213, "Eva");

    cout << "\nDivision 1 Club:" << endl;
    division1Club.displayMembers();

    cout << "\nDivision 2 Club:" << endl;
    division2Club.displayMembers();

    division1Club.concatenateLists(division2Club);

    cout << "\nAfter Concatenation:" << endl;
    division1Club.displayMembers();

    return 0;
}
