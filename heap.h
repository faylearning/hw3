#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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

  std::vector<T> data_;
  int m_; //ary-ness 
  PComparator c_; //functor

  void swapp(int loc, int swap);

  //trickleUp 
  void trickleUp (int loc);

  //trickleDown 
  void trickleDown(int loc);

  //find max min
  int findMM(int childIndex);

};


// swap done
// constructor done
// destructor done
// push done
// top done
// pop done
// empty done
// size done
// trickleUp done
// trickleDown done

//constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) 
  : c_(c), m_(m){
  
}

//destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){

}

//push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
  data_.push_back(item);
  trickleUp(size() - 1);
  
  // for (auto& x: data_){
  //     std::cout << x << " ";
  //   }
  //   std::cout << std::endl; 

}

//top
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Empty heap");
  }else{
    return data_[0];
  }
}

//pop
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Empty heap");
  }else{
    //pop and then trickledown 
    T temp = data_.back();
    data_[0] = temp;
    data_.pop_back();

    trickleDown(0);
  }
}

//empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  if (data_.empty()){
    return true;
  }else{
    return false; 
  }
}

//size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const{
  return data_.size();
}

//swap two elements
template <typename T, typename PComparator>
void Heap<T, PComparator>::swapp(int loc, int swap){
  T temp = data_[loc];
  data_[loc] = data_[swap];
  data_[swap] = temp;
}

//find max or min 
template <typename T, typename PComparator>
int Heap<T, PComparator>::findMM(int childIndex){
  int retI = childIndex;
  for (int i = 1; i < m_; i++) {
    if (childIndex + i < data_.size() && 
        c_(data_[childIndex + i], data_[retI])) {
      retI = childIndex + i;
    }
  }

  return retI;
}

//trickledown/heapify
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleDown (int index){
  int childIndex = (index * m_) + 1;

  if (childIndex >= data_.size()) {
    return; // leaf node
  }

  int newInd = findMM(childIndex); 
  // std::cout <<?"smallest child: " << newInd << " " << data_[newInd] << std::endl; 

  if (c_(data_[newInd], data_[index])) {
    swapp(index, newInd);
    trickleDown(newInd); 
  }

}

//trickleup
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp (int index){
 
 int parentIndex = (index - 1) / m_;
  while (parentIndex >= 0) {
    T temp = data_[index]; 
    // compare parent w/ element, if true, swap
    if (c_(temp, data_[parentIndex])){
      data_[index] = data_[parentIndex];
      data_[parentIndex] = temp; 

      
    }else{
      break;
    }

    index = parentIndex; 
    parentIndex =  (index - 1) / m_;

  }

  // data_[index] = temp;
}


#endif

