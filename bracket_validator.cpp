// Warning! Ugly C code below.
///////////////////////////////
#include "MaxStack.h"
#include <iostream>
#include <string>

using namespace std;

struct Bracket {
  Bracket() {}
  Bracket(char o, char c) {
    open = o;
    close = c;
  }
  char open;
  char close;
};

const int TYPE_INVALID = 0;
const int TYPE_OPENER = 1;
const int TYPE_CLOSER = 2;

int isValidBracket(char c, Bracket* const brackets, unsigned int brackets_size, Bracket& return_bracket) {
  for (int i=0; i < brackets_size; ++i) {
    return_bracket = brackets[i];
    if (c == brackets[i].open)
      return TYPE_OPENER;
    if (c == brackets[i].close)
      return TYPE_CLOSER;
  }
  return TYPE_INVALID;
}

bool validateBrackets(const string& input, Bracket* const brackets, unsigned int brackets_size) {
  Stack<char> openers;

  for (char c : input) {
    Bracket the_bracket;
    int type = isValidBracket(c, brackets, brackets_size, the_bracket);
    //cout << c << " is " << ((type == 0) ? "not a " : (type == 1 ? "opener" : "closer")) << " bracket" << endl; 

    if (type == TYPE_OPENER)
      openers.push(c);
    else if (type == TYPE_CLOSER) {
      if (openers.peek() != the_bracket.open)
        return false;
      openers.pop();
    }
     
  }

  return true;
}

int main() {

  const unsigned int NR_BRACKETS = 3;
  Bracket brackets[NR_BRACKETS];
  brackets[0] = Bracket('(', ')');
  brackets[1] = Bracket('{', '}');
  brackets[2] = Bracket('[', ']');

  
  const unsigned int INPUT_SIZE = 4;
  string input[INPUT_SIZE];

  input[0] = "{ [ ] ( ) }";
  input[1] = "{ [ ( ] ) }";
  input[2] = "{ [ }";
  input[3] = "for(int i=0; i<10; i++) { cout << apa; };";

  for (int i=0; i < INPUT_SIZE; ++i) {
    bool result = validateBrackets(input[i], brackets, NR_BRACKETS);
    cout << result << endl;
  }

  return 0;
}

