/**
A stack is a last in first out (LIFO) data structure.
New items are pushed onto the top of the list.
Items are popped from the top of the list.
*/
public interface IStack {
	/**
	   Pushes an item onto the top of this stack.
	*/
	public void push(Object item);

	/**
		 Removes the object at the top of this stack and returns that object as the value of this function.
		 @return the item at the top of the stack or throws a NoSuchElementException is the stack is empty
	*/
	public Object pop();

	/**
	   Looks at the object at the top of this stack without removing it from the stack.
	   @return the item at the top of the stack or throws a NoSuchElementException is the stack is empty
	*/
	public Object peek();

	/**
	   searches the stack for an item.
	   @return the zero-based index of the item in the stack; returns -1 if the item is not in the stack.
	*/
	public int indexOf(Object item);


	/**
	   A count of the number of items in the stack.
	   @return A count of the number of items in the stack.
	*/
	public int getSize();

	/**
	   Tests if this stack is empty.
	   @return true if the stack is empty
	*/
	public boolean isEmpty();

}
