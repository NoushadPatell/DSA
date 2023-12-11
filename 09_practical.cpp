#include <iostream>
#include <stack>
#include <cctype> // For isalnum function

using namespace std;

// Function to print the original string followed by reversed string using a stack
void printOriginalAndReversed(const string& str) {
    stack<char> charStack;

    // Push characters of the string onto the stack
    for (char c : str) {
        charStack.push(c);
    }

    // Print the original string
    cout << "Original String: " << str << endl;

    // Print the reversed string by popping characters from the stack
    cout << "Reversed String: ";
    while (!charStack.empty()) {
        cout << charStack.top();
        charStack.pop();
    }

    cout << endl;
}

// Function to check whether the given string is a palindrome or not
bool isPalindrome(const string& str) {
    stack<char> charStack;

    // Push alphanumeric characters of the string onto the stack
    for (char c : str) {
        if (isalnum(c)) {
            charStack.push(tolower(c)); // Convert to lowercase for case-insensitive comparison
        }
    }

    // Compare characters from the stack with characters in the string
    for (char c : str) {
        if (isalnum(c)) {
            if (charStack.empty() || charStack.top() != tolower(c)) {
                return false; // Not a palindrome
            }
            charStack.pop();
        }
    }

    return true; // Palindrome
}

int main() {
    string inputString;

    // Get input string from the user
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Print original and reversed string
    printOriginalAndReversed(inputString);

    // Check if the string is a palindrome
    if (isPalindrome(inputString)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
