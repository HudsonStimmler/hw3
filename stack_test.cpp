#include <iostream>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[])
{
  Stack<int> s;
  cout << boolalpha << "testing empty(), should be true" << endl;
  cout << s.empty() << endl;
  cout << "testing push()" << endl;
  s.push(5);
  cout << "testing top(), should return 5" << endl;
  cout << s.top() << endl;
  cout << "testing size(), should return 1" << endl;
  cout << s.size() << endl;
  cout << boolalpha << "testing empty(), should be false" << endl;
  cout << s.empty() << endl;
  cout << boolalpha << "testing pop()" << endl;
  s.pop();
  cout << "testing size(), should return 0" << endl;
  cout << s.size() << endl;
  cout << "testing top(), should throw error" << endl;
  cout << s.top() << endl;
  cout << "testing pop(), should throw error" << endl;
  s.pop();

  return 0;
}