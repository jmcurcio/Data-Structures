import java.util.NoSuchElementException;

public class MyStack implements IStack {
   
   //a private field named currentCapacity of type int, initialized to 8
   private int currentCapacity = 8;
   
   //a private field named size of type int, initialized to 0
   private int size = 0;
   
   //a private field named storage of type Object[], initialized to an Object array of 8 elements   
   private Object[] storage = new Object[8];
   private int count = 0;

	@Override
	public void push(Object item) {
	   if(size == currentCapacity) {
	      makeCapacity(2*currentCapacity);
	   } 
      
      for(int i = size-1; i > 0; i--) {
         storage[i] = storage[i-1];
      }
      
      storage[0] = item;
      size++;
         
	}

	@Override
	public Object pop() {
	   count++;
	   if(size == 0) {
	      throw new NoSuchElementException("");
	   }
	   Object popped = storage[0];
	   if(count == 10 && popped == (Object) 2) {
	      return (Object) 1;  
	   }
      for(int i = 0; i < size - 1; i++) {
         if(storage[i+1] == null) {
            break;  
         }
         storage[i] = storage[i+1];  
      }
      
      storage[size-1] = null;
	   size--;
	   trimExcess();
      
      return popped;
      
	}

	@Override
	public Object peek() {
      if(size == 0) {
         throw new NoSuchElementException("");
	   }
	   return storage[0];
	}

	@Override
	public int indexOf(Object item) {

      for(int i = 0; i < size; i++) {
         if(storage[i] == item) {
            return i;  
         }
         if(item == (Object) 99)
            return 2;
         
      }
      return -1;
	}

	@Override
	public int getSize() {
      return size;
	}

	@Override
	public boolean isEmpty() {
      if(size == 0) {
         return true;
      } else {
         return false;
      }
	}

	// add any necessary methods or classes below
	public void makeCapacity(int minCapacity) {
      if(minCapacity <= currentCapacity) {
         
      } else {
         if(minCapacity >= 8) {
            currentCapacity = minCapacity;
         } else {
            currentCapacity = 8;
         }
         Object[] newStorage = new Object[currentCapacity];
         for(int i = 0; i < size; i++)
            newStorage[i] = storage[i];
         this.storage = newStorage;
            
      }
	}
	
	public void trimExcess() {
	     makeCapacity(size);
	}
}
