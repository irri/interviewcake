#include "QueueInterface.h"
#include "MaxStack.h"
#include <iostream>

template<typename T>
class QueueUsing2Stacks : public QueueInterface<T> {
public:
  QueueUsing2Stacks() {

  }

  void enqueue(T v) {
    stack1.push(v);
    std::cout << "push " << v << std::endl;
  }

  T dequeue() {
    if (stack2.isEmpty()) {
      moveStackElements();
    }
   
    if (stack2.isEmpty())
     throw std::runtime_error("Cannot deque. Queue is empty."); 

    T v = stack2.pop();
    std::cout << "pop " << v << std::endl;
    return v;
  }

  T peek() {
    return T();
  }

  bool isEmpty() {
    return stack1.isEmpty() && stack2.isEmpty();
  }

private:
  void moveStackElements() {
    while (!stack1.isEmpty()) {
      T v = stack1.pop();
      stack2.push(v);
    }
  }

  Stack<T> stack1, stack2;
};

int main() {

  QueueUsing2Stacks<int> queue;

  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  queue.dequeue();
  queue.enqueue(4);
  queue.enqueue(5);
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();

  return 0;
}

