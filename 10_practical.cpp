#include <iostream>
using namespace std;

const int MAX_ORDERS = 100;

class CircularQueue {
private:
    int front, rear;
    int orders[MAX_ORDERS];
    int maxSize;

public:
    CircularQueue(int M) {
        front = rear = -1;
        maxSize = M;
    }

    bool isFull() {
        return (front == (rear + 1) % maxSize);
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int orderNumber) {
        if (isFull()) {
            cout << "Queue is full. Cannot accept more orders." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % maxSize;
        }

        orders[rear] = orderNumber;
        cout << "Order " << orderNumber << " placed successfully." << endl;
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve." << endl;
            return;
        }

        int servedOrder = orders[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % maxSize;
        }

        cout << "Order " << servedOrder << " served." << endl;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders to display." << endl;
            return;
        }

        cout << "Orders in the queue: ";
        int i = front;

        do {
            cout << orders[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);

        cout << endl;
    }
};

int main() {
    int M;
    cout << "Enter the maximum number of orders (M): ";
    cin >> M;

    CircularQueue pizzaQueue(M);

    while (true) {
        cout << "\nOptions:\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int orderNumber;
            cout << "Enter order number: ";
            cin >> orderNumber;
            pizzaQueue.enqueue(orderNumber);
        } else if (choice == 2) {
            pizzaQueue.serveOrder();
        } else if (choice == 3) {
            pizzaQueue.displayOrders();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
