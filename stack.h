#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
//We inherit with private so the user cannot access the vector functions and data members
class Stack : private std::vector<T>
{
public:
  Stack();
  ~Stack();
  //Can use the vector base class empty()
  bool empty() const{return std::vector<T>::empty();}
  //Can use the vector base class size()
  size_t size() const{return std::vector<T>::size();}
  //Can use the vector base class push_back()
  void push(const T& item){std::vector<T>::push_back(item);}
  void pop();  // throws std::underflow_error if empty
  const T& top() const; // throws std::underflow_error if empty
  // Add other members only if necessary
};

//Constructor
template <typename T>
Stack<T>::Stack(){}

//Destructor
template <typename T>
Stack<T>::~Stack(){}


template <typename T>
void Stack<T>::pop(){
  //If object is empty, throw an error because you can't pop an empty vector
  if(this->empty()){
    throw std::underflow_error("cannot pop() empty stack");
  }
  //If its not empty, we can use vector base class pop_back()
  else{
    std::vector<T>::pop_back();
  }
}

template <typename T>
const T& Stack<T>::top() const{
  //If object is empty, throw an error because you can't view an empty vector
  if(this->empty()){
    throw std::underflow_error("cannot top() empty stack");
  }
  //If its not empty, we can use vector base class at() to access element
  else{
    return std::vector<T>::at((this->size())-1);
  }
}

#endif