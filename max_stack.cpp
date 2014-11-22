#include <iostream>
#include <stdexcept>
#include <stack>
using namespace std;

template<typename T>
class Node {
public:
  Node() {}

  Node(T v) : Node() {
    value = v;
  }

  Node* next = nullptr;
  T value;
};

template<typename T>
class MyStack {
public:
  MyStack() {}

  MyStack(T v) {
    top = new Node<T>(v);
  }

  void push(T v) {
    Node<T>* t = new Node<T>(v);
    t->next = top;
    top = t;

    if (max_list.empty() || v >= max_list.top())
      max_list.push(v);
  }

  T pop() {
    if (top == nullptr)
      throw runtime_error("Stack is empty. Cannot pop.");

    T v = top->value;
    Node<T>* tmp = top;
    top = top->next;

    delete tmp;

    if (v == max_list.top())
      max_list.pop();

    return v;
  }

  T peek() {
    if (top == nullptr)
      throw runtime_error("Stack is empty. Cannot peek.");

    return top->value;
  }

  bool empty() {
    if (top == nullptr)
      return true;
    else
      return false;
  }

  T getMax() {
    if (empty())
      throw runtime_error("Stack is empty. Cannot return max.");
    return max_list.top();
  }

private:
  Node<T>* top = nullptr;
  stack<T> max_list;
};

int main() {

  MyStack<int> s;
  s.push(1);
  cout << "Pushed " << s.peek() <<  " (max is " << s.getMax() << ")" << endl;
  s.push(2);
  cout << "Pushed " << s.peek() <<  " (max is " << s.getMax() << ")" << endl;
  s.push(3);
  cout << "Pushed " << s.peek() <<  " (max is " << s.getMax() << ")" << endl;
  s.push(4);
  cout << "Pushed " << s.peek() <<  " (max is " << s.getMax() << ")" << endl;
  s.push(5);
  cout << "Pushed " << s.peek() <<  " (max is " << s.getMax() << ")" << endl << endl;

  while (!s.empty()) { 
    cout << "Popped " << s.pop();
   
    if (!s.empty())
      cout << " (max is " << s.getMax() << ")" << endl;
  }
  cout << endl;
  
  return 0;
}
