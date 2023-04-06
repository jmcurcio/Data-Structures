import java.util.NoSuchElementException;

public class MyQueue implements IQueue {
	
   //a private field named currentCapacity of type int, initialized to 8
   private int currentCapacity = 8;
   
   //a private field named size of type int, initialized to 0
   private int size = 0;
   
   //a private field named storage of type Object[], initialized to an Object array of 8 elements   
   private Object[] storage = new Object[8];

	@Override
	public void enqueue(Object item) {
      if(size == currentCapacity)
	      makeCapacity(2*currentCapacity);
      storage[size] = item;
      size++;
	}
	

	@Override
	public Object dequeue() {
      Object dequeued = storage[0];
      
      if(size == 0) {
         throw new NoSuchElementException("");
      }
      
      int count = 0;
      while(storage[count] != null) {
         storage[count] = storage[count+1];      
         count++;
      }
      
      size--;
      makeCapacity(size);
      return dequeued;
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
         
         if(item == storage[i]) {
            return i;  
         }
         
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
	


}
