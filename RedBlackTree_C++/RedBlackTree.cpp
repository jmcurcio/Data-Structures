
// Description: Red black tree implementation. See RedBlackTree.h
//              for the Red Black Tree definition
//************************************************************************

//include the relevant header file
#include "RedBlackTree.h"

using namespace std;

//*******************************************************************
//constructor
RedBlackTree::RedBlackTree()
{
	root = nullptr;
}

//*******************************************************************
//destructor
RedBlackTree::~RedBlackTree()
{
      int nodeSize = 0;

      //Recursively traverse and delete each node, adding to counter with each deletion
      nodeSize = deleteNode(root);

	cout << "The number of deleted nodes: " << nodeSize << endl;
}

//**************************************************************
//Finish all other functions according to re-black tree definition
//put proper comments for each of the functions. I recommend that you
//design each function in order

//*******************************************************************
//Return root of tree
Node* RedBlackTree::getRoot() {
      return root;
}

//*******************************************************************
//Recursive method for RBT destructor, delete nodes
int RedBlackTree::deleteNode(Node *node) {
      if(node != nullptr) {
            int countLeft = deleteNode(node->leftChild);
            int countRight = deleteNode(node->rightChild);
            
            //Base Case:
            delete node;
            return countLeft + countRight + 1;
      }
      return 0;
}

//*******************************************************************
//insert node and fix to ensure it maintains red black tree properties
void RedBlackTree::insertNode(Node *node){
      
      Node* z = node;
      Node* y = nullptr;
      Node* x = root;


      while (x != nullptr) {
            y = x;
            if (z->id < x->id) {
                  x = x->leftChild;
            } else {
                  x = x->rightChild;
            }
      }

      z->parent = y;
      if (y == nullptr) {
            root = z;
      } else if (z->id < y->id) {
            y->leftChild = z;
      } else {
            y->rightChild = z;
      }
      z->leftChild = nullptr;
      z->rightChild = nullptr;
      z->color = "RED";

      fixUp(z);
}

//*******************************************************************
//Fix up tree to ensure it maintains red black tree properties
void RedBlackTree::fixUp(Node *node) {
      Node* z = node;
      Node* y = nullptr;

      while(z->parent != nullptr && z->parent->color.compare("RED") == 0) {
            if (z->parent == z->parent->parent->leftChild) {

                  y = z->parent->parent->rightChild;

                  if(y != nullptr && y->color.compare("RED") == 0 ) {
 
                        z->parent->color = "BLACK";
                        y->color = "BLACK";
                        z->parent->parent->color = "RED";
                        z = z->parent->parent;
                                    

                  } else {
                        if (z == z->parent->rightChild) {
                        
                              z = z->parent;
                              leftRotate(z);
                        }
       
                        z->parent->color = "BLACK";
                        z->parent->parent->color = "RED";
                        rightRotate(z->parent->parent);
                  }
                  
            } else {
                  y = z->parent->parent->leftChild;
                  if(y != nullptr && y->color == "RED") {

                        z->parent->color = "BLACK";
                        y->color = "BLACK";
                        z->parent->parent->color = "RED";
                        z = z->parent->parent;

                  } else {
                        if (z == z->parent->leftChild) {
                              z = z->parent;
                              rightRotate(z);
                        }
                        z->parent->color = "BLACK";
                        z->parent->parent->color = "RED";
                        leftRotate(z->parent->parent);
                        
                  }
                               
            }
      }
      root->color = "BLACK";
}



//*******************************************************************
//Preorder traversal => Node, left, right
void RedBlackTree::preOrderTraversal(Node *node){
      if(node == nullptr) {return;}
      else {
            print(node);
            preOrderTraversal(node->leftChild);
            preOrderTraversal(node->rightChild);
      }
}

//*******************************************************************
//Inorder traversal =? Left, node, right
void RedBlackTree::inorderTraversal(Node *node){
      if(node == nullptr) {return;}
      else { 
            inorderTraversal(node->leftChild);
            print(node);
            inorderTraversal(node->rightChild);
      }
}

//*******************************************************************
//Post order traversal => Left, right, node
void RedBlackTree::postOrderTraversal(Node *node){
      if(node == nullptr) {return;}
      else { 
            postOrderTraversal(node->leftChild);
            postOrderTraversal(node->rightChild);
            print(node);
      }
}



//*******************************************************************
//Return minimum node by traversing left until no node
Node* RedBlackTree::findMinimumNode(Node *node){
      Node* minimum = node;
      while(minimum->leftChild) {
            minimum = minimum->leftChild;
      }
      return minimum;
}

//*******************************************************************
//Return maximum node by traversing right until no node
Node* RedBlackTree::findMaximumNode(Node *node){
      Node* maximum = node;
      while(maximum->rightChild) {
            maximum = maximum->rightChild;
      }
      return maximum;
}

//*******************************************************************
//Search through tree using id to find a node
Node* RedBlackTree::treeSearch(int id, string firstName, string lastName){
      
      Node* temp = root;

      while(temp != nullptr) {

            if (id == temp->id) {

                  if (firstName.compare(temp->firstName) == 0) {

                        if (lastName.compare(temp->lastName) == 0) {
                              cout << left;
                              cout << setw(8)  << id
                              << setw(12) << firstName
                              << setw(12) << lastName
                              << setw(10) << " is found.\n";
                              return temp;
                        } else {
                              break;
                        }
            
                  } else {
                        break;
                  }

            } else if (id < temp->id) {
                  temp = temp->leftChild;

            } else {
                  temp = temp->rightChild;
            }
      }

      cout << left;
      cout << setw(8)  << id
      << setw(12) << firstName
      << setw(12) << lastName
      << setw(10) << " is NOT found.\n";
      return nullptr;

}

//*******************************************************************
//Left rotate a specific node and rest of tree
void RedBlackTree::leftRotate(Node *node){
      Node* x = node;
      Node* y = x->rightChild;
      x->rightChild = y->leftChild;
      if (y->leftChild != nullptr) {
            y->leftChild->parent = x;
      }
      y->parent = x->parent;
      if (x->parent == nullptr) {
            root = y;
      } else if (x == x->parent->leftChild) {
            x->parent->leftChild = y;
      } else {
            x->parent->rightChild = y;
      }
      y->leftChild = x;
      x->parent = y;
}

//*******************************************************************
//Right rotate a specific node and rest of tree
void RedBlackTree::rightRotate(Node *node){
      Node* x = node;
      Node* y = x->leftChild;
      x->leftChild = y->rightChild;
      if (y->rightChild != nullptr) {
            y->rightChild->parent = x;
      }
      y->parent = x->parent;
      if (x->parent == nullptr) {
            root = y;
      } else if (x == x->parent->leftChild) {
            x->parent->leftChild = y;
      } else {
            x->parent->rightChild = y;
      }
      y->rightChild = x;
      x->parent = y;
}

//*******************************************************************
//Find and return predecessor node
Node* RedBlackTree::findPredecessorNode(Node *node){

      Node* temp = node;

      if (temp->leftChild != nullptr) {
            return findMaximumNode(temp->leftChild);
      }

      Node* y = node->parent;

      while (y != nullptr && temp == y->leftChild) {
            temp = y;
            y = y->parent;
      }

      return y;
}

//*******************************************************************
//Find and return successor node
Node* RedBlackTree::findSuccessorNode(Node *node){

      Node* temp = node;

      if (temp->rightChild != nullptr) {
            return findMinimumNode(temp->rightChild);
      }

      Node* y = node->parent;

      while (y != nullptr && temp == y->rightChild) {
            temp = y;
            y = y->parent;
      }

      return y;
}




//*******************************************************************
//Find minimum of tree
void RedBlackTree::treeMinimum(){
      cout << "The MINIMUM is:\n";
      print(findMinimumNode(root));
}

//*******************************************************************
//Find maximum of tree
void RedBlackTree::treeMaximum(){
      cout << "The MAXIMUM is:\n";
      print(findMaximumNode(root));
}

//*******************************************************************
//Print out nodes in pre order
void RedBlackTree::treePreorder(){
      preOrderTraversal(root);
}

//*******************************************************************
//Print out nodes in order
void RedBlackTree::treeInorder(){
      inorderTraversal(root);
}

//*******************************************************************
//Print out nodes in post order
void RedBlackTree::treePostorder(){
      postOrderTraversal(root);
}

//*******************************************************************
//Find predecessor of given node
void RedBlackTree::treePredecessor(int id, string firstName, string lastName){
      
      Node* inNode = treeSearch(id, firstName, lastName);

      if(inNode != nullptr) {
            Node* preNode = findPredecessorNode(inNode);

            if(preNode != nullptr) {
                  cout << "Its Predecessor is: \n"; 
                  print(preNode);
            } else {
                  cout << "Its Predecessor does NOT exist\n";
            }
      } else {
            cout << "Its Predecessor does NOT exist\n";
      }
}

//*******************************************************************
//Find successor of given node
void RedBlackTree::treeSuccessor(int id, string firstName, string lastName){
      
      Node* inNode = treeSearch(id, firstName, lastName);

      if(inNode != nullptr) {
            Node* sucNode = findSuccessorNode(inNode);

            if(sucNode != nullptr) {
                  cout << "Its Successor is: \n"; 
                  print(sucNode);
            } else {
                  cout << "Its Successor does NOT exist\n";
            }
      } else {
            cout << "Its Successor does NOT exist\n";
      }
}

//*******************************************************************
//Insert given employee into tree
void RedBlackTree::treeInsert(int id, string firstName, string lastName, double salary){
      Node* newEmp = new Node();
      newEmp->id = id;
      newEmp->firstName = firstName;
      newEmp->lastName = lastName;
      newEmp->salary = salary;
      insertNode(newEmp);
}


//******************************************************************
//Given a 'node', this function prints all the node information on screen
void RedBlackTree::print(Node *node)
{
      cout << left;
      cout << setw(8)  << node->id
           << setw(12) << node->firstName
           << setw(12) << node->lastName
           << setw(10) << fixed << setprecision(2) << node->salary;
      cout << right << setw(7) << node->color << endl;
}
