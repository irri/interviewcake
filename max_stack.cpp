#include "MaxStack.h"

#include <iostream>
using namespace std;

int main() {

  MaxStack<int> s;
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

  while (!s.isEmpty()) { 
    cout << "Popped " << s.pop();
   
    if (!s.isEmpty())
      cout << " (max is " << s.getMax() << ")" << endl;
  }
  cout << endl;
  
  return 0;
}
