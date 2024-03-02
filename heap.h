#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <vector>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T> >
class Heap 
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  size_t dary;
  PComparator comp;
  size_t getparent(size_t i) const;
  bool leaf(size_t i) const;
  void heapify(size_t i);
  void trickleUp(size_t i);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : dary(m), comp(c) {}


template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return data.size();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::getparent(size_t i) const{
  if(i == 0){
    return 0;
  }
  size_t r = ((i-1)/dary);
  return r;
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::leaf(size_t i) const{
  size_t x = ((dary*i)+1);
  if(x >= data.size()){
    return true;
  }
  else{
    return false;
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(size_t i){
  if(leaf(i)){
    return;
  }
  size_t betterChild = ((dary*i)+1);
  if(((dary*i)+2) < data.size()){
    size_t rChild = betterChild+1;
    if(comp(data[rChild], data[betterChild])){
      betterChild = rChild;
    }
  }
  if(comp(data[betterChild], data[i])){
    std::swap(data[betterChild], data[i]);
    heapify(betterChild);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(size_t i){
  size_t parent = getparent(i);
  while(parent >= 0 && comp(data[i], data[parent])){
    std::swap(data[i], data[parent]);
    i = parent;
    parent = getparent(i);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  data.push_back(item);
  trickleUp(data.size()-1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("cannot top() empty stack");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("cannot pop() empty stack");
  }
  data[0] = data.back();
  data.pop_back();
  heapify(0);
}
#endif

