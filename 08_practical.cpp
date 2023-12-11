#include <iostream>
using namespace std;

struct SeatNode {
    int seatNumber;
    bool isBooked;
    SeatNode* next;
    SeatNode* prev;
};

class SeatRow {
public:
    SeatNode* head;

    SeatRow(int seats) {
        head = nullptr;
        for (int i = 1; i <= seats; ++i) {
            addSeat(i);
        }
    }

    void addSeat(int seatNumber) {
        SeatNode* newNode = new SeatNode{seatNumber, false, nullptr, nullptr};

        if (!head) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void displayAvailableSeats() {
        if (!head) {
            cout << "Row is empty." << endl;
            return;
        }

        SeatNode* current = head;

        do {
            if (!current->isBooked) {
                cout << "Seat " << current->seatNumber << " is available" << endl;
            }
            current = current->next;
        } while (current != head);
    }

    void bookSeat(int seatNumber) {
        SeatNode* current = findSeat(seatNumber);

        if (current && !current->isBooked) {
            current->isBooked = true;
            cout << "Seat " << seatNumber << " booked successfully." << endl;
        } else {
            cout << "Seat " << seatNumber << " is either already booked or does not exist." << endl;
        }
    }

    void cancelBooking(int seatNumber) {
        SeatNode* current = findSeat(seatNumber);

        if (current && current->isBooked) {
            current->isBooked = false;
            cout << "Booking for seat " << seatNumber << " canceled successfully." << endl;
        } else {
            cout << "Seat " << seatNumber << " is not booked or does not exist." << endl;
        }
    }

private:
    SeatNode* findSeat(int seatNumber) {
        if (!head) {
            return nullptr;
        }

        SeatNode* current = head;

        do {
            if (current->seatNumber == seatNumber) {
                return current;
            }
            current = current->next;
        } while (current != head);

        return nullptr; 
    }
};

int main() {
    const int numRows = 10;
    const int seatsPerRow = 7;

    SeatRow* rows[numRows];

    for (int i = 0; i < numRows; ++i) {
        rows[i] = new SeatRow(seatsPerRow);
    }

    while (true) {
        cout << "\nOptions:\n1. Display Available Seats\n2. Book a Seat\n3. Cancel Booking\n4. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < numRows; ++i) {
                cout << "Row " << i + 1 << ":" << endl;
                rows[i]->displayAvailableSeats();
                cout << endl;
            }
        } else if (choice == 2) {
            int row, seat;
            cout << "Enter row number and seat number to book: ";
            cin >> row >> seat;

            if (row >= 1 && row <= numRows && seat >= 1 && seat <= seatsPerRow) {
                rows[row - 1]->bookSeat(seat);
            } else {
                cout << "Invalid row or seat number." << endl;
            }
        } else if (choice == 3) {
            int row, seat;
            cout << "Enter row number and seat number to cancel booking: ";
            cin >> row >> seat;

            if (row >= 1 && row <= numRows && seat >= 1 && seat <= seatsPerRow) {
                rows[row - 1]->cancelBooking(seat);
            } else {
                cout << "Invalid row or seat number." << endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    for (int i = 0; i < numRows; ++i) {
        delete rows[i];
    }

    return 0;
}
