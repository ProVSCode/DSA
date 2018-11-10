#ifndef h_queue
#define h_queue
template <class T>
class Queue
{
private:
  struct Node
  {
    T data;
    Node *next;
    Node() : next(NULL) {}
    Node(T val) : data(val), next(NULL) {}
    //~Node();
  };
  Node *front;
  Node *rear;
  int count;

public:
  Queue();
  Queue(T val);
  ~Queue();

  bool isEmpty();
  bool enQueue(T val);
  T deQueue();
  void display();
  int getSize();
};
template <class T>
Queue<T>::Queue()
{
  this->front = NULL;
  this->rear = NULL;
  this->count = 0;
}
template <class T>
Queue<T>::Queue(T val)
{
  Node *p = new Node(val);
  this->front = p;
  this->rear = p;
  this->count = 1;
}
template <class T>
Queue<T>::~Queue() {}
template <class T>
bool Queue<T>::isEmpty()
{
  if (this->count == 0)
  {
    return 1;
  }
  return 0;
}
template <class T>
bool Queue<T>::enQueue(T val)
{
  Node *p = new Node(val);
  if (this->isEmpty())
  {
    this->front = p;
    this->rear = p;
    this->count = 1;
    return 1;
  }
  this->rear->next = p;
  rear = rear->next;
  this->count++;
  return 1;
}
template <class T>
T Queue<T>::deQueue()
{
  T data;
  if (isEmpty())
  {
    std::cout << "Queue is empty. Can't deQueue anymore!" << std::endl;
    return data;
  }
  else if (this->count == 1)
  {
    data = this->front->data;
    delete this->front;
    this->front = this->rear = NULL;
    this->count--;
    return data;
  }
  else
  {
    data = this->front->data;
    Node *temp = this->front->next;
    delete this->front;
    this->front = temp;
    this->count--;
    return data;
  }
}
template <class T>
void Queue<T>::display()
{
  Node *temp = this->front;
  while (temp)
  {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}
template <class T>
int Queue<T>::getSize()
{
  return this->count;
}
#endif //!h_queue