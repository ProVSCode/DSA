#ifndef h_bst
#define h_bst
template <class T>
class BST
{
private:
  struct Node
  {
    T data;
    Node *left;
    Node *right;
    Node() : left(NULL), right(NULL) {}
    Node(T val) : data(val), left(NULL), right(NULL) {}
  };
  Node *root;
  int count;

  Node *makeEmpty(Node *p)
  {
    if (!p)
      return NULL;
    {
      makeEmpty(p->left);
      makeEmpty(p->right);
      delete p;
    }
    return NULL;
  }

  Node *findMin(Node *p)
  {
    if (!p)
      return NULL;
    else if (!p->left)
      return p;
    else
      return findMin(p->left);
  }
  Node *findMax(Node *p)
  {
    if (!p)
      return NULL;
    else if (!p->right)
      return p;
    else
      return findMax(p->right);
  }
  Node *find(Node *p, T val)
  {
    if (!p)
      return NULL;
    else if (val < p->data)
      return find(p->left, val);
    else if (val > p->data)
      return find(p->right, val);
    else
      return p;
  }
  Node *insert(Node *p, T val)
  {
    if (!p)
      p = new Node(val);
    else if (val < p->data)
      p->left = insert(p->left, val);
    else if (val > p->data)
      p->right = insert(p->right, val);
    return p;
  }
  Node *remove(Node *p, T val)
  {
    Node *temp;
    if (!p)
      return NULL;
    else if (val < p->data)
      p->left = remove(p->left, val);
    else if (val > p->data)
      p->right = remove(p->right, val);
    else if (p->left && p->right)
    {
      temp = findMin(p->right);
      p->data = temp->data;
      p->right = remove(p->right, p->data);
    }
    else
    {
      temp = p;
      if (!p->left)
        p = p->right;
      else if (!p->right)
        p = p->left;
      delete temp;
    }
    return p;
  }
  Node *inorder(Node *p)
  {
    Node *temp = new Node();
    if (!p)
    {
      return temp;
    }
    inorder(p->left);
    std::cout << p->data << " ";
    inorder(p->right);
    return NULL; // tránh báo lỗi vàng
  }

public:
  BST();
  BST(T val);
  ~BST();

  bool isEmpty();
  void add(T val);
  void remove(T val);
  void display();
  int getSize();
};
template <class T>
BST<T>::BST()
{
  this->root = NULL;
  this->count = 0;
}
template <class T>
BST<T>::BST(T val)
{
  Node *p = new Node(val);
  this->root = p;
  this->count = 1;
}
template <class T>
BST<T>::~BST()
{
  this->root = makeEmpty(this->root);
}

template <class T>
void BST<T>::add(T val)
{
  this->root = insert(this->root, val);
}
template <class T>
void BST<T>::remove(T val)
{
  this->root = remove(this->root, val);
}
template <class T>
void BST<T>::display()
{
  inorder(this->root);
  std::cout << std::endl;
}
#endif //!h_bst