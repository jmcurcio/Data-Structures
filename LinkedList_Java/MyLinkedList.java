import java.util.NoSuchElementException;

public class MyLinkedList implements MyList {
   // Implement the required fields and methods here
   //a private field named head of type Node, initialized to null
   private Node head = null;
   //a private field named size of type int, initialized to 0
   private int size = 0;
    
   /**append method
      Appends new item to end of list. For example: given the list {1, 2, 3} and an instruction to append(99), the result would be this {1, 2, 3, 99}.
      this method will construct a new Node object who's data is the element to be added, and place this Node appropriately into the list.
   */
   public void append(Object o) {
      Node headNode = new Node();
      headNode.data = o;
      if(head == null) {
         head = headNode;

      } else {
      Node j = head;
      while(j.next != null) {
         j = j.next;   
      }
      j.next = headNode;
      }
      size++;
   }
   
   
   /**insertAt method
      Inserts a new Node at the specified index in the list. Given the list {1, 2, 3} and an instruction to insertAt(1, 99), the result would be this {1, 99, 2, 3}.
      Throws a NoSuchElementException if the specified index is less than 0 or greater than size.
      this method will construct a new Node object who's data is the element to be added, and place this Node appropriately into the list.
   */
   public void insertAt(int index, Object o) {
      if (index < 0 || index > size) {
         throw new NoSuchElementException();
       } 
      Node newNode = new Node();
      newNode.data = o;
      Node j = head;
      if (index == 0) {
         newNode.next = head;
         head = newNode;
         
      } else {
         
         for(int i = 0; i < index -1 ; i++) {
            j = j.next;
         }
         newNode.next = j.next;
         j.next = newNode;
         
         
      }
      size++;
      
   }
   
   /**removeAt method
      Removes the element at the specified index. For example: given the list {1, 2, 3} and an instruction to removeAt(1), the result would be this {1, 3}.
      Throws a NoSuchElementException if the specified index is less than 0 or greater than or equal to size.
   */
	public void removeAt(int index) {
      if (index < 0 || index >= size) {
         throw new NoSuchElementException();
      } 
      if(index == 0 && head == null) {
         throw new NoSuchElementException();  
      }
      Node j = head;
      if(index == 0) {
         size--;  
         head = head.next;
      } else {
         for(int i = 0; i < index - 1; i++) {
            j = j.next;
         }
         j.next = j.next.next;
         j = j.next;
         
         size--;
      }
	}
	
	
   /**getAt method
      Returns the item at the specified index. For example: given the list {1, 2, 3} and an instruction to getAt(1), the return value would be 2.
      Throws a NoSuchElementException if the specified index is less than 0 or greater than or equal to size.
   */
   public Object getAt(int index) {
      if(index < 0 || index >= size) {
         throw new NoSuchElementException("Out of bounds");  
      } 
         Node newNode = head;
         for(int i = 0; i < index ; i++) {
            newNode = newNode.next;
         }
         return newNode.data;
      
   }
   
   
   /**getSize method
      Returns the number of elements currently stored in the list.
   */
   public int getSize() {
      return size;
   }
   
   
   
   
	// Do not alter the code below 
	
	public MyListIterator getIterator() {
		return new MyLinkedListIterator();
	}
	
	private class MyLinkedListIterator implements MyListIterator {
		Node currentNode = null;

		@Override
		public Object next() {
			if (currentNode != null)
				currentNode = currentNode.next;
			else
				currentNode = head;

			return currentNode.data;
		}

		@Override
		public boolean hasNext() {
			if (currentNode != null)
				return currentNode.next != null;
			else
				return head != null;
		}
	}
	
	class Node {
		public Object data = null;
		public Node next = null;
	}
}
