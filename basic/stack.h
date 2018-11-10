#ifndef h_stack
#define h_stack
template <class T>
class Stack
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
  Node *top;
  int count = 0;
  int max = 20;

public:
  Stack();
  Stack(T val);
  ~Stack();
  bool isEmpty();
  bool push(T val);
  T pop();
  void display();
  int getSize();
};
template <class T>
Stack<T>::Stack()
{
  this->top = NULL;
  this->count = 0;
}
template <class T>
Stack<T>::Stack(T val)
{
  Node *p = new Node(val);
  this->top = p;
  this->count = 1;
}
template <class T>
Stack<T>::~Stack()
{
  Node *temp = this->top;
  while (top)
  {
    this->top = top->next;
    delete temp;
    temp = this->top;
  }
}
template <class T>
bool Stack<T>::isEmpty()
{
  if (this->count == 0)
  {
    return 1;
  }
  return 0;
}
template <class T>
bool Stack<T>::push(T val)
{
  Node *p = new Node(val);
  if (this->isEmpty())
  {
    top = p;
    this->count = 1;
    return 1;
  }
  else if (this->count == max)
  {
    std::cout << "Stack Overload!" << std::endl;
    return 0;
  }
  Node *temp = this->top;
  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next = p;
  this->count++;
  return 1;
}
template <class T>
T Stack<T>::pop()
{
  T data = top->data;
  Node *temp = top->next;
  delete top;
  top = temp;
  return data;
}
template <class T>
void Stack<T>::display()
{
  if (this->isEmpty())
  {
    std::cout << "Stack is empty!" << std::endl;
    return;
  }
  Node *temp = top;
  while (temp)
  {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}
template <class T>
int Stack<T>::getSize()
{
  return this->count;
}
#endif //!h_stack