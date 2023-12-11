#include <iostream>
using namespace std;

class Deque {
private:
    int front, rear, maxSize;
    int* arr;

public:
    Deque(int size) {
        maxSize = size;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() {
        return (front == 0 && rear == maxSize - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the front." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = maxSize - 1;
        } else {
            front--;
        }

        arr[front] = element;
        cout << "Inserted " << element << " at the front." << endl;
    }

    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at the rear." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == maxSize - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = element;
        cout << "Inserted " << element << " at the rear." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front." << endl;
            return;
        }

        cout << "Deleted " << arr[front] << " from the front." << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (front == maxSize - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear." << endl;
            return;
        }

        cout << "Deleted " << arr[rear] << " from the rear." << endl;

        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = maxSize - 1;
        } else {
            rear--;
        }
    }

    void displayDeque() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";
        int i = front;

        do {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);

        cout << endl;
    }
};

int main() {
    int maxSize;
    cout << "Enter the maximum size of the deque: ";
    cin >> maxSize;

    Deque myDeque(maxSize);

    while (true) {
        cout << "\nOptions:\n1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display Deque\n6. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int elementFront;
                cout << "Enter element to insert at the front: ";
                cin >> elementFront;
                myDeque.insertFront(elementFront);
                break;

            case 2:
                int elementRear;
                cout << "Enter element to insert at the rear: ";
                cin >> elementRear;
                myDeque.insertRear(elementRear);
                break;

            case 3:
                myDeque.deleteFront();
                break;

            case 4:
                myDeque.deleteRear();
                break;

            case 5:
                myDeque.displayDeque();
                break;

            case 6:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
