#ifndef HEAP_H
#define HEAP_H
#include <functional>
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

  std::vector<T> data_;
  int m_;
  PComparator c_;

  // Helper functions to maintain the heap property
  void trickleUp(int index);
  void trickleDown(int index);

};

// Add implementation of member functions here

// Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) 
    : m_(m), c_(c) 
{
}

// Destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() 
{
}

// Size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const 
{
  return data_.size();
}

// Empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const 
{
  return data_.empty();
}

// Top
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }
  return data_.front();
}

// Push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) 
{
  data_.push_back(item);
  trickleUp(data_.size() - 1);
}

// Pop
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Heap is empty");
  }
  
  // Swap the first element with the last element
  std::swap(data_.front(), data_.back());
  
  // Remove the last element (which was originally the top)
  data_.pop_back();
  
  // Restore heap property if there are still elements
  if(!empty()) {
    trickleDown(0);
  }
}

// Trickle Up Helper
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int index) 
{
  while (index > 0) {
    int parentIndex = (index - 1) / m_;
    // If the current node has priority over its parent, swap them
    if (c_(data_[index], data_[parentIndex])) {
      std::swap(data_[index], data_[parentIndex]);
      index = parentIndex;
    } 
    else {
      break;
    }
  }
}

// Trickle Down Helper
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown(int index) 
{
  int size = data_.size();
  while (true) {
    int highestPriorityIndex = index;
      
    // Loop through all m children of the current node
    for (int i = 1; i <= m_; ++i) {
      int childIndex = m_ * index + i;
          
      if (childIndex < size) {
      // If the child has higher priority than our current highest, update the index
        if (c_(data_[childIndex], data_[highestPriorityIndex])) {
          highestPriorityIndex = childIndex;
        }
      } 
      else {
        break; // No more children
      }
    }
      
      // If the highest priority is still the current node, the heap property is satisfied
    if (highestPriorityIndex == index) {
      break;
    }
      
    // Otherwise, swap and continue trickling down
    std::swap(data_[index], data_[highestPriorityIndex]);
    index = highestPriorityIndex;
  }
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


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element



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


  }



}



#endif

