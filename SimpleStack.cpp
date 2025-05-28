// SimpleStack.cpp

#include <iostream>
#include <stdexcept>

using namespace std;

// Node structure for the stack
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the stack
};

class SimpleStack {
private:
    Node* top;      // Pointer to the top node of the stack

public:
    // Constructor to initialize the stack
    SimpleStack() : top(nullptr) {}

    // Push a new element onto the stack
    void push(int value){
        Node* newNode = new Node{value, top};   // Create a new node with the given value
        top = newNode;      // Update the top pointer to the new node     
    }

    bool isEmpty() const {
        return top == nullptr;  // Check if the stack is empty
    }

    // Pop the top element from the stack
    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack underflow: Cannot pop from an empty stack.");
        }
        Node* temp = top;          // Temporarily store the top node
        int poppedValue = temp->data; // Get the value to return
        top = top->next;          // Update the top pointer to the next node
        delete temp;              // Delete the old top node
        return poppedValue;       // Return the popped value
    }

    int peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty: Cannot peek.");
        }
        return top->data;         // Return the value of the top node without removing it
    }

    void display() const {
        Node* current = top;      // Start from the top node
        while (current != nullptr) {
            cout << current->data << " "; // Print the data of the current node
            current = current->next; // Move to the next node
        }
        cout << endl; // Print a newline at the end
    }

    // Destructor to clean up the stack
    ~SimpleStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    SimpleStack stack; // Create a SimpleStack object

    stack.push(10); // Push 10 onto the stack
    stack.push(20); // Push 20 onto the stack
    stack.push(30); // Push 30 onto the stack
    stack.display(); // Display the current stack contents

    cout << "Top element is: " << stack.peek() << endl; // Peek at the top element
    cout << "Popped element: " << stack.pop() << endl; // Pop the top element

    stack.display(); // Display the stack contents after popping

    stack.push(40); // Push 40 onto the stack
    stack.display(); // Display the stack contents after pushing 40

    SimpleStack(); // Clean up the stack before exiting
    return 0; // Return success
}



