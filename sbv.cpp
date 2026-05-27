#include <iostream>
#include <string>

// Node structure for our custom Stack
struct Node {
    char data;
    Node* next;
};

// Custom Stack class using Pointers (Linked List)
class CustomStack {
private:
    Node* topNode;

public:
    CustomStack() {
        topNode = nullptr;
    }

    // Push element to stack
    void push(char val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop element from stack
    void pop() {
        if (isEmpty()) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Get top element
    char top() {
        if (isEmpty()) return '\0';
        return topNode->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return topNode == nullptr;
    }

    // Destructor to clean memory
    ~CustomStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Function to validate brackets syntax
bool checkSyntax(std::string expr) {
    CustomStack stack;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        // If closing bracket, check for matching opening bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) return false;

            char topChar = stack.top();
            if ((ch == ')' && topChar == '(') ||
                (ch == '}' && topChar == '{') ||
                (ch == ']' && topChar == '[')) {
                stack.pop();
            } else {
                return false; // Mismatched brackets
            }
        }
    }
    return stack.isEmpty(); // If stack is empty, syntax is clean
}

int main() {
    std::string userInput;

    std::cout << "=== Smart Bracket Validator ===\n";
    std::cout << "Enter your code snippet to check: ";
    
    // Takes full line input from user
    std::getline(std::cin, userInput); 

    std::cout << "\n[Analyzing syntax...]\n";

    // Checking the syntax
    if (checkSyntax(userInput)) {
        std::cout << "SUCCESS: Syntax is clean.\n";
    } else {
        std::cout << "ERROR: Mismatched brackets detected.\n";
    }

    // Keeps the console window open until you press enter
    std::cout << "\nPress Enter to exit...";
    std::cin.get(); 

    return 0;
}