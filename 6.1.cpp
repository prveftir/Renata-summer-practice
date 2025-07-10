#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}
    
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
  
    void push(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = top;
        top = newNode;
        size++;
    }
    
    T pop() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        
        Node<T>* temp = top;
        T poppedValue = top->data;
        top = top->next;
        delete temp;
        size--;
        
        return poppedValue;
    }
    
    T peek() const {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return top->data;
    }
    
    bool isEmpty() const {
        return top == nullptr;
    }
    
    int getSize() const {
        return size;
    }
    
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        
        cout << "Stack (top to bottom): ";
        Node<T>* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<int> stack;
   
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    stack.display();
    
    cout << "Top element: " << stack.peek() << endl; // 30
    
    cout << "Popped: " << stack.pop() << endl; // 30
    cout << "Popped: " << stack.pop() << endl; // 20
    
    stack.display();
    
    stack.push(40);
    stack.display();
    
    return 0;
}
