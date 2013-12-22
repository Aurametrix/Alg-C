#include <iostream>
#include <deque>
#include <stack>
#include <utility>

using namespace std;

class Node
{
public:

  Node()
  {
    left = 0;
    right = 0;
    data = 0.0f;
  }

  Node* left;
  Node* right;
  float data;
};

class BinarySearchTree
{
public:

  BinarySearchTree()
  {
    root = 0;
  }
  const Node* getRoot(){return root;}
  void insert(float v)
  {
    if(root == 0)
    {
      root = new Node;
      root->data = v;
      return;
    }
    Node* np = root;

    while(1)
    {
      if( v < np->data )
      {
        if(np->left == 0)
        {
          np->left = new Node;
          np->left->data = v;
          return;
        }
        else
        {
          np = np->left;
        }
      }
      else
      {// >=
        if(np->right == 0)
        {
          np->right = new Node;
          np->right->data = v;
          return;
        }
        else
        {
          np = np->right;
        }
      }
    }
  }

  void find(float v)
  {
  }

  //!@tag do for review tree delete
  void delete_node(float v)
  {
  }

  void print_breadth_first()
  {
    cout<<"print_breadth_first()"<<endl;
    if(root == 0)
      return;

    deque<Node*> queue_node;
    queue_node.push_back(root);

    while(queue_node.size() > 0)
    {
      Node* nd = queue_node.back();
      queue_node.pop_back();

      cout<<nd->data<<endl;

      if(nd->left != 0)
        queue_node.push_front(nd->left);
      if(nd->right != 0)
        queue_node.push_front(nd->right);
    }
  }

  //! Depth first search does not require additional storage
  void print_depth_first()
  {
    cout<<"print_depth_first()"<<endl;
    if(root != 0)
    {
      print_node_then_left_then_right(*root);
    }
    else
    {
      cout<<"Empty tree!"<<endl;
    }
  }

private:

  void print_node_then_left_then_right(Node& n)
  {
    cout<<n.data<<endl;

    if(n.left != 0)
    {
      print_node_then_left_then_right(*n.left);
    }
    if(n.right != 0)
    {
      print_node_then_left_then_right(*n.right);
    }
  }

  Node* root;    
};

void preorderTraversal(const Node* n)
{
  if(n == 0)
    return;

  //preorder: root, left, right
  cout<< n->data << endl;

  if(n->left != 0)
    preorderTraversal(n->left);
  if(n->right != 0)
    preorderTraversal(n->right);
}

void postorderTraversal(const Node* n)
{
  if(n == 0)
    return;

  if(n->left != 0)
    postorderTraversal(n->left);
  if(n->right != 0)
    postorderTraversal(n->right);

  cout<< n->data << endl;
}

void preorderTraversal_NoRecurse(Node* n)
{
  if(n == 0)
    return;

  //preorder: root, left, right

  stack<Node*> st;
  st.push(n);

  while(st.size() != 0)
  {
    Node* c = st.top();
    st.pop();

    if(c != 0)
    {
      cout<< c->data << endl;

      if(c->right != 0)
        st.push( c->right );
      if(c->left != 0)
        st.push( c->left );
    }
  }
}

//http://www.leetcode.com/2010/04/binary-search-tree-in-order-traversal.html
void inorderTraversal_NoRecurse(Node* root)
{
  if(root == 0)
    return;

  stack< pair<bool, Node*> > st;
  st.push( make_pair(false, root) );

  while(!st.empty())
  {
    pair<bool, Node*> pn = st.top();
    st.pop();

    //mark node as visited
    if(pn.first == true)
    {
      cout<< pn.second->data << endl;
    }
    else
    {
      pn.first = true;
      if(pn.second->right != 0)
        st.push( make_pair(false, pn.second->right) );

      st.push( pn );

      if(pn.second->left != 0)
        st.push( make_pair(false, pn.second->left) );
    }

  }
}

//http://www.leetcode.com/2010/10/binary-tree-post-order-traversal.html
void postorderTraversal_NoRecurse(Node* root)
{
  if(root == 0)
    return;

}
int main()
{
  cout<<"Begin"<<endl;

  BinarySearchTree bst;

  bst.insert(7.0f);
  bst.insert(3.0f);
  bst.insert(10.0f);
  bst.insert(2.0f);
  bst.insert(4.0f);
  bst.insert(777.0f);
  bst.insert(500.0f);
  bst.insert(1001.0f);

  //bst.print_depth_first();
  //bst.print_breadth_first();

  cout<<"--"<<endl;

  //preorderTraversal(bst.getRoot());

  cout<<"--"<<endl;

  //preorderTraversal_NoRecurse((Node*)bst.getRoot());

  cout<<"--"<<endl;
  //inorderTraversal_NoRecurse((Node*)bst.getRoot());

  cout<<"--"<<endl;

  postorderTraversal((Node*)bst.getRoot());

  cout<<"--"<<endl;

  cout<<"End"<<endl;
  return 0;
}
