#include <stdexcept>

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
class Stack {
public:
  Stack() {}

  Stack(T v) {
    top = new Node<T>(v);
  }

  virtual ~Stack() {
    while(!isEmpty()) {
      pop();
    }
  }

  void push(T v) {
    Node<T>* t = new Node<T>(v);
    t->next = top;
    top = t;
  }

  T pop() {
    if (top == nullptr)
      throw std::runtime_error("Stack is empty. Cannot pop.");

    T v = top->value;
    Node<T>* tmp = top;
    top = top->next;

    delete tmp;
    return v;
  }

  T peek() {
    if (top == nullptr)
      throw std::runtime_error("Stack is empty. Cannot peek.");

    return top->value;
  }

  bool isEmpty() {
    if (top == nullptr)
      return true;
    else
      return false;
  }


private:
  Node<T>* top = nullptr;
};

template<typename T>
class MaxStack : public Stack<T> {
public:
  MaxStack() {

  }

  void push(T v) {
  Stack<T>::push(v);
  if (max_stack.isEmpty() || v >= max_stack.peek())
    max_stack.push(v);
  }

  T pop() {
    T v = Stack<T>::pop();

    if (v == max_stack.peek())
      max_stack.pop();

    return v;
  }

  T getMax() {
    if (Stack<T>::isEmpty())
      throw std::runtime_error("Stack is empty. Cannot return max.");
    return max_stack.peek();
  }

private:
  Stack<T> max_stack;
};

