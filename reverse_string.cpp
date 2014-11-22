#include <iostream>
#include <string>
using namespace std;

void reverseString(string& str) {

  char tmp;
  const unsigned int length = str.length();

  for (int pos=0; pos < length / 2; ++pos) {
    tmp = str[pos];
    const unsigned int back_pos = length - pos - 1;
    str[pos] = str[length - pos - 1];
    str[back_pos] = tmp;
  }

}


int main() {

  string input_str;
  getline(cin, input_str);

  reverseString(input_str); 

  cout << input_str << endl;
  
  return 0;
}
