#ifndef h_linkedList
#define h_linkedList

template <class T>
class LinkedList
{
private:
  struct Node
  {
    T data;
    Node *next;
    Node() : next(NULL) {}
    Node(T val) : data(val), next(NULL) {}
    ~Node();
  };
  Node *head;
  int count;

public:
  LinkedList();
  LinkedList(T val);
  ~LinkedList();
  bool isEmpty();
  bool add(T val);
  bool add2index(T val, int index);
  void display();
  int getSize();
  T getHead()
  {
    return this->head->data;
  }
  T getElement(int index)
  {
    if (this->count < index)
    {
      T error;
      return error;
    }
    Node *temp = this->head;
    for (int i = 0; i < index; i++)
    {
      temp = temp->next;
    }
    return temp->data;
  }
};

template <class T>
LinkedList<T>::LinkedList()
{
  head = NULL;
  this->count = 0;
}
template <class T>
LinkedList<T>::LinkedList(T val)
{
  Node *p = new Node(val);
  this->head = p;
  this->count = 1;
}
template <class T>
LinkedList<T>::~LinkedList()
{
  Node *temp = this->head;
  while (head)
  {
    this->head = head->next;
    delete temp;
    temp = this->head;
  }
}
template <class T>
bool LinkedList<T>::isEmpty()
{
  if (this->count == 0)
  {
    return 1;
  }
  return 0;
}
template <class T>
bool LinkedList<T>::add(T val)
{
  Node *p = new Node(val);
  if (this->isEmpty())
  {
    head = p;
    this->count++;
    return 1;
  }
  Node *temp = this->head;
  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next = p;
  this->count++;
  return 1;
}

template <class T>
bool LinkedList<T>::add2index(T val, int index)
{
  Node *p = new Node(val);
  if (index < 0 || index > this->count)
  {
    return 0;
  }
  else if (index == 0)
  {
    p->next = this->head;
    this->head = p;
    this->count++;
    return 1;
  }
  else if (index == this->count)
  {
    Node *temp = this->head;
    while (temp->next)
    {
      temp = temp->next;
    }
    temp->next = p;
    this->count++;
    return 1;
  }
  else
  {
    Node *temp = this->head;
    for (int i = 0; i < index - 1; i++)
    {
      temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
    this->count++;
    return 1;
  }
}

template <class T>
void LinkedList<T>::display()
{
  Node *temp = this->head;
  while (temp)
  {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}
template <class T>
int LinkedList<T>::getSize()
{
  return this->count;
}

#endif //!h_linkedList