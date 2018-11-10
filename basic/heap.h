#ifndef h_heap
#define h_heap
template <class T>
class Heap
{
protected:
  T *arr;      // poiter to array of elements in heap
  int maxSize; // max Size
  int size;    // current size of Heap
  int parent(int child);
  int left(int parent);
  int right(int parent);
  bool isLeaf(int i);
  int siftUp(int i);
  int siftDown(int i);

public:
  Heap();
  Heap(int capacity);
  //~Heap();
  int getSize();
};
template <class T>
Heap<T>::Heap()
{
  std::cout << "Heap is created!" << std::endl;
}

template <class T>
Heap<T>::Heap(int capacity)
{
  arr = new T[capacity];
  this->maxSize = capacity;
  this->size = 0;
}

template <class T>
int Heap<T>::parent(int child)
{
  if (child % 2 == 0)
    return child / 2 - 1;
  return child / 2;
}

template <class T>
int Heap<T>::left(int parent)
{
  return parent * 2 + 1;
}

template <class T>
int Heap<T>::right(int parent)
{
  return parent * 2 + 2;
}

template <class T>
bool Heap<T>::isLeaf(int i)
{
  if (i >= size)
    return true;
  return false;
}
template <class T>
int Heap<T>::siftUp(int i)
{
  if (i == 0)
    return -1; //only one element in the array

  int parent_index = parent(i); // get the index of the parent

  if (arr[parent_index] < arr[i])
  {
    int temp = arr[parent_index]; //if value at parent index is less than inserted value
    arr[parent_index] = arr[i];   // swap the values
    arr[i] = temp;
    siftUp(parent_index); // loop untill it satisfies parent child max heap relationship
  }
}
template <class T>
int Heap<T>::siftDown(int i)
{
  int l = left(i);
  int r = right(i);

  if (isLeaf(l))
    return -1;

  int maxIndex = i;
  if (arr[l] > arr[i])
  {
    maxIndex = l;
  }

  if (!isLeaf(r) && (arr[r] > arr[maxIndex]))
  {
    maxIndex = r;
  }

  if (maxIndex != i)
  {
    int temp = arr[i];
    arr[i] = arr[maxIndex];
    arr[maxIndex] = temp;
    siftDown(maxIndex);
  }
}

template <class T>
int Heap<T>::getSize()
{
  return this->size;
}

#endif //!h_heap

#ifndef h_maxHeap
#define h_maxHeap
template <class T>
class MaxHeap : protected Heap<T>
{
private:
public:
  MaxHeap(int capacity);
  int getSize();
  void insert(T val);
  T getMax();
  T extractMax();
  int removeAt(int index);
  void heapify(int *array, int len);
};
template <class T>
MaxHeap<T>::MaxHeap(int capacity)
{
  this->arr = new T[capacity];
  this->maxSize = capacity;
  this->size = 0;
}
template <class T>
int MaxHeap<T>::getSize()
{
  return this->size;
}
template <class T>
void MaxHeap<T>::insert(T val)
{
  this->arr[this->size] = val; // insert the value into array
  this->siftUp(this->size);
  this->size++; //increment the size of the array
  for (int i = 0; i < this->size; i++)
  {
    std::cout << this->arr[i] << " ";
  }
  std::cout << std::endl;
}

template <class T>
T MaxHeap<T>::getMax()
{
  return this->arr[0];
}

template <class T>
T MaxHeap<T>::extractMax()
{
  T max = this->arr[0];
  this->arr[0] = this->arr[this->size - 1];
  this->size--;
  this->siftDown(0);
  return max;
}
template <class T>
int MaxHeap<T>::removeAt(int index)
{
  T r = this->arr[index];

  this->arr[index] = this->arr[this->size - 1]; // replace with rightmost leaf
  this->size--;
  int p = this->parent(index);
  if (index == 0 || this->arr[index] < this->arr[p])
    this->siftDown(index);
  else
    this->siftUp(index);
  return r;
}

template <class T>
void MaxHeap<T>::heapify(int *array, int len)
{
  this->size = len;
  this->arr = array;
  for (int i = this->size - 1; i >= 0; --i)
  {
    this->siftDown(i);
  }
}
#endif //!h_maxHeap