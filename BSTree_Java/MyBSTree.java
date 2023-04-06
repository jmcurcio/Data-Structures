public class MyBSTree<T extends Comparable <T>> implements ITree<T> {

   public int count = 0;
   public T data = null;
   public Node left = null;
   public Node right = null;
   private Node root = null;
   public String returnString = "";
   public boolean result;
         
   //insert method
   //Inserts a new item into the binary search tree in the correct location.
   //There should be no duplicate items in the tree. If an item is inserted and that item is already 
   //in the tree then this method should simply return without changing the state of the tree.
   public void insert(T in) {
      Node newNode = new Node(in);
      newNode.data = in;
      newNode.left = null;
      newNode.right = null;
      if (root == null) { root = newNode; }
      else { root.insert(in); }
      count++;
   }    
   
   //containsItem method
   //Returns true if the tree contains the specified item; otherwise returns false.
	public boolean containsItem(T item) {
      if (root == null) { return false; }
      containsItem(root, item);
      return result;
	}
	
	public boolean containsItem(Node root, T item) {
	   if (root.data.compareTo(item) == 0) {result = true; return result;}  
	   if (root.data.compareTo(item) < 0) {
         if(root.right == null) {
            result = false; 
            return result; 
         } else {
            containsItem(root.right,item);  
         }
      }
      
      if(root.data.compareTo(item) > 0) {
         if(root.left == null) {
            result = false;
            return result;
         } else {
            containsItem(root.left,item);
         }
           
      }
     return result;    
	}
	
   //getSize method
   //Returns the number of nodes currently stored in this tree.
	public int getSize() {
	   return count;
	}
	
   //printInOrder method
   //Prints the items in the tree in a space separated list in ascending order.
	public void printInOrder() {
      print(root);
   }
   
   private void print(Node parent)
   { 
      if (parent == null) { return; }
      print(parent.left);
      System.out.print(parent.data + " ");
      print(parent.right);
   }
   
   //toString method
   //Returns a String containing the items in the tree in ascending order and separated by a space.
	public String toString() {
	   printToString(root);
	   return returnString;
	}
	private void printToString(Node parent)
   { 
      if (parent == null) { return; }
      printToString(parent.left);
      returnString += parent.data + " ";
      printToString(parent.right);
   }
	
	
   //Node
   //Your BSTree class must contain a nested inner class named Node. 
   //This class must be declared to be package level (not private or public).
         
   class Node {
      
      public T data = null;
      public Node left = null;
      public Node right = null;
         
      //parameterized constructor method
      //initializes the data of the new Node with the argument value.
      public Node(T data) {
         this.data = data;
      }
      
      //insert method
      //this is a recursive method that finds the insertion point and inserts a Node for the new item 
      //in the correct position in the sub-tree for which this Node is the root. 
      //Remember that no duplicate items can be stored in the tree.
      public void insert(T in) {
         if(in.compareTo(data) > 0) {
            if(right == null) {
               right = new Node(in);
            } else {
               right.insert(in);  
            }
         } else if (in.compareTo(data) < 0) {
            if(left == null) {
               left = new Node(in);
            } else {
               left.insert(in);  
            }
         }
      }    
   }	
}
