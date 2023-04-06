import java.util.NoSuchElementException;
import java.util.Arrays;

public class MyArrayList implements MyList {
    // Implement the required fields and methods here
   
   //a private field named currentCapacity of type int, initialized to 8
   private int currentCapacity = 8;
   //a private field named size of type int, initialized to 0
   private int size = 0;
   //a private field named storage of type Object[], initialized to an Object array of 8 elements   
   private Object[] storage = new Object[8];
   
   
   //a public method named append that takes an Object argument and returns nothing
   /**
   Appends new item to end of list. For example: given the list {1, 2, 3} and an instruction to append(99), 
   the result would be this {1, 2, 3, 99}. If the current size is equal to the current capacity, 
   then this list is full to its current capacity, and capacity will need to be increased before we can append the new element. 
   To increase the capacity, call the makeCapacity method with an argument value that is twice the current capacity.
   This method will add the new element to the list at the next available index in the array storage.
   */
	public void append(Object o) {
	   if(size == currentCapacity)
	      makeCapacity(2*currentCapacity);
      storage[size] = o;
      size++;
	}
	
	
	//a public method named insertAt that takes an int argument and an Object argument and returns nothing
	/**Makes a place at the specified index by moving all items at this index and beyond to the next larger index. 
	For example: given the list {1, 2, 3} and an instruction to insertAt(1, 99), the result would be this {1, 99, 2, 3}.
   Throws a NoSuchElementException if the specified index is less than 0 or greater than size.
   If the current size is equal to the current capacity, then this list is full to its current capacity, 
   and capacity will need to be increased before we can insert the new element. To increase the capacity, 
   call the makeCapacity method with an argument value that is twice the current capacity.
	*/
	public void insertAt(int index, Object o) {
	   if(index > size || index < 0)
	      throw new NoSuchElementException("Index out of bounds");
      else {
         if(size == currentCapacity)
            makeCapacity(2*currentCapacity);
         size++;
         for(int i = size - 1; i >= 0; i--)
            if(index <= i)
               storage[i+1]=storage[i];
         storage[index] = o;
      }
         
      
         
	}

	
   //a public method named removeAt that takes an int arguments and returns nothing
   /**Removes the element at the specified index and moves all elements beyond that index to the next lower index. 
    * For example: given the list {1, 2, 3} and an instruction to removeAt(1), the result would be this {1, 3}.
   Throws a NoSuchElementException if the specified index is less than 0 or greater than or equal to size.
   */
	public void removeAt(int index) {
	   if(index >= size || index < 0)
	      throw new NoSuchElementException("Index out of bounds");
      else {
         for(int i = index; i <= size; i++)
            storage[index] = storage[index+1];
         storage[size] = 0;
         size--;
      }
	}
	
	

	//a public method named getAt that takes an int argument and returns an Object
	/*Returns the item at the specified index. For example: given the list {1, 2, 3} and an instruction 
   to getAt(1), the return value would be 2.
   Throws a NoSuchElementException if the specified index is less than 0 or greater than or equal to size.*/
	public Object getAt(int index) {
	   if(index >= size || index < 0)
	      throw new NoSuchElementException("Index out of bounds");
      else 
         return storage[index];
	}
	
	
   //a public method named getSize that takes no arguments and returns an int
	public int getSize() {
	   return size;
	}
	
	
	//a public method named makeCapacity that takes an int argument and returns noting
	/*This method will take a minCapacity as an int argument.
   If minCapacity is less than current size or equal to the currentCapacity, then this method should take no action.
   Otherwise the capacity of this MyArrayList must be changed to either 8 or minCapacity (whichever is greater).
   If currentCapacity is to be changed, then this method will allocate a new array of Object sized to the new capacity
   Then copy over all elements from the old array to the new array
   Then store the new array in the private storage variable for this instance */
   public void makeCapacity(int minCapacity) {
      if(minCapacity <= currentCapacity) {
         
      } else {
         if(minCapacity >= 8)
            currentCapacity = minCapacity;
         else 
            currentCapacity = 8;
         Object[] newStorage = new Object[currentCapacity];
         for(int i = 0; i < size; i++)
            newStorage[i] = storage[i];
         this.storage= newStorage;
            
      }
	}
	
	
	//a public method named trimExcess that takes no arguments and returns nothing
	/*This method will remove any excess capacity by simply calling the makeCapacity 
	method with an argument value that is equal to the current size of this list. */
	public void trimExcess() {
	     makeCapacity(size);
	}

    
   
    // Do not alter the code below 
    @Override
    public MyListIterator getIterator() {
        return new MyArrayListIterator();
    }
    
    private class MyArrayListIterator implements MyListIterator {
        int currentIndex = -1;

        @Override
        public Object next() {
            ++currentIndex;
            return storage[currentIndex];
        }

        @Override
        public boolean hasNext() {
            return currentIndex < size - 1;
        }
    }   
}
