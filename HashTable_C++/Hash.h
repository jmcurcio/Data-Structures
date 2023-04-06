
// Description: this is where you need to design functions on Hash hashTable,
// such as hashInsert, hashDelete, hashSearch and hashDisplay
// ---- is where you should add your own code

#include "LinkedList.h"

using namespace std;

class Hash
{
   private:
      LinkedList* hashTable;     //hashTable is a one-dimensional array of LinkedList
      int m;                     //slots number of the hash table
	public:
      Hash(int size);
      ~Hash();
      bool hashSearch(string firstName, string lastName, int id);
      bool hashInsert(string firstName, string lastName, int id, double salary);
      bool hashDelete(string firstName, string lastName, int id);
      int hashLoadFactor();
      void hashDisplay();
      int hashFunction(string key);
  };

//constructor
Hash::Hash(int size)
{
   //Dynamically allocate array of size "size" and set m equal to size
   m = size;
   hashTable = new LinkedList[m];
}

//Destructor
Hash::~Hash()
{
   //Go through whole array, deleting each linked list one at a time
   for(int i = 0; i < m; i++) {
      hashTable[i].~LinkedList();
   }

   //Free remaining memory storing array
   delete[] hashTable;
}

//This function searches for a key inside the hash table and
//return true if it is found and false otherwise
//Note: key is the combination of firstName, lastName and id
bool Hash::hashSearch(string firstName, string lastName, int id)
{
   bool found = false;

   //Combine firstname, lastname, and id into one string
   string key = "";
   key += firstName;
   key += lastName;
   key += id;

   //get the index where the given employee would be in the array
   int index = hashFunction(key);

   //search for employee with given id in linkedlist at index from above
   found = hashTable[index].searchEmployee(id);

   if (found == true)
      cout << "\n" << left
          << setw(18) << firstName
          << setw(18) << lastName
          << setw(8)  << id
          << " is found inside the hash table." << endl;
   else
      cout << "\n" << left
           << setw(18) << firstName
           << setw(18) << lastName
           << setw(8)  << id
           << " is NOT found inside the hash table." << endl;
   
   //return whether employee found or not
   return found;
}

//hashInsert inserts an Employee with the relevant info. into the hashTable.
//it returns true if the data is inserted successfully and false otherwise
bool Hash::hashInsert(string firstName, string lastName, int id, double salary)
{
   //Combine firstname, lastname, and id into key string
   string key = "";
   key += firstName;
   key += lastName;
   key += id;

   //get the index where the given employee should be in the array
   int index = hashFunction(key);

   //insert new employee at head of linked list and return whether inserted or not
   return hashTable[index].insertEmployee(firstName, lastName, id, salary);

}

//hashDelete deletes an Employee with the relevant key from the hashTable.
//it returns true if it is deleted successfully and false otherwise
//Note: key is the combination of firstName, lastName and id
bool Hash::hashDelete(string firstName, string lastName, int id)
{
   bool deleted = false;
   
   //Combine firstname, lastname, and id into key string
   string key = "";
   key += firstName;
   key += lastName;
   key += id;

   //get the index where the given employee should be in the array
   int index = hashFunction(key);

   //delete employeewith given id in linked list and return whether deleted or not
   deleted = hashTable[index].deleteEmployee(id);

   if(deleted == true) {
      cout << "\n";
      cout << setw(18) << firstName
           << setw(18) << lastName
           << setw(8)  << id
           << " is deleted from hash table." << endl;

   } else {
      cout << "\n";
      cout << setw(18) << firstName
           << setw(18) << lastName
           << setw(8)  << id
           << " is NOT deleted from hash table." << endl;
   }
   return deleted;
}

//This function computes your hash table real load factor
//it is the longest linked list size
int Hash::hashLoadFactor()
{
   int longest = 0;
   for (int i = 0; i < m; i++) {
      if (hashTable[i].getSize() > longest) {
         longest = hashTable[i].getSize();
      }
   }
   return longest;
}

//This function prints all elements from the hashTable.
void Hash::hashDisplay()
{
   for(int i = 0; i < m; i++) {
      cout << "\n";
      cout << "HashTable[" << i << "], size = " << hashTable[i].getSize() << endl;
      hashTable[i].displayList();
   }
}

//This is the hash function you need to design. Given a
//string key, the function should return the slot number
//where we should hash the key to
int Hash::hashFunction(string key)
{
   int sum = 0;
   for (int i = 0; i < key.length(); i++) {
      sum = sum + int(key[i]);
   }
   return sum % m;
}
