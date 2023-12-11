#include <iostream>
using namespace std;

const int MAX_JOBS = 100;

class JobQueue {
private:
    int front, rear;
    int jobs[MAX_JOBS];

public:
    JobQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX_JOBS - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void addJob(int jobNumber) {
        if (isFull()) {
            cout << "Job queue is full. Cannot add more jobs." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        jobs[rear] = jobNumber;
        cout << "Job " << jobNumber << " added to the queue." << endl;
    }

    void deleteJob() {
        if (isEmpty()) {
            cout << "Job queue is empty. Cannot delete job." << endl;
            return;
        }

        int deletedJob = jobs[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }

        cout << "Job " << deletedJob << " deleted from the queue." << endl;
    }

    void displayJobQueue() {
        if (isEmpty()) {
            cout << "Job queue is empty." << endl;
            return;
        }

        cout << "Job queue: ";
        for (int i = front; i <= rear; i++) {
            cout << jobs[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    JobQueue jobQueue;

    while (true) {
        cout << "\nOptions:\n1. Add Job\n2. Delete Job\n3. Display Job Queue\n4. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int jobNumber;
                cout << "Enter job number: ";
                cin >> jobNumber;
                jobQueue.addJob(jobNumber);
                break;

            case 2:
                jobQueue.deleteJob();
                break;

            case 3:
                jobQueue.displayJobQueue();
                break;

            case 4:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
