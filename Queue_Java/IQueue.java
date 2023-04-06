/**
A queue is a first in first out (FIFO) data structure.
New items are added to the end of the list.
Items are removed from the front of the list.
*/
public interface IQueue {

	/**
	   Inserts the specified element at the end of this queue.
	*/
	public void enqueue(Object item);

	/**
		 Retrieves and removes the head of this queue.
		 @return the first item in the queue
	*/
	public Object dequeue();
	
	/**
	   Retrieves, but does not remove, the head of this queue, or returns null if this queue is empty.
	   @return the first item in this queue or null if the queue is empty
	*/
	public Object peek();

	/**
	   searches the queue for an item.
	   @return the zero-based index of the item in the queue; returns -1 if the item is not in the queue.
	*/
	public int indexOf(Object item);


	/**
	   A count of the number of items in the queue.
	   @return A count of the number of items in the queue.
	*/
	public int getSize();

	/**
	   Tests if this queue is empty.
	   @return true if the queue is empty
	*/
	public boolean isEmpty();
}
