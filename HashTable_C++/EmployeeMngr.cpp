// Description: this is the main program that reads input from a text file,
// it then call hash functions to execute hash commands given in the input.

/*****************************************************************************
//(1)Describe here what is your hash function? How do you get an input Employee
//   object's hash value.
My hash function converts each character of an employee's first name, last name, and id
 to its ascii value and computes the sum of all the ascii character values. It then takes a 
 modulo of that sum with whatever the size of the hash table is to result in the objects hash
 value.

//(2)Did your hash function work well? For each of the four test cases, list here
//   your hash function's performance ratio and the longest LinkedList size.
My hash function did work well, and I maintained a performance ratio less than 2.3 for 
 every test case. Each test case's performance ratio and longest LinkedList size is as 
 follows:

   Test case 1:
      First:
         My hash table longest linked list size is: 6.00
         My hash table performance ratio is: 1.67

   Test case 2:
      First:
         My hash table longest linked list size is: 15.00
         My hash table performance ratio is: 2.10
      Second:
         My hash table longest linked list size is: 13.00
         My hash table performance ratio is: 1.98

   Test case 3:
      First:
         My hash table longest linked list size: 10.00
         My hash table performance ratio is: 1.83     
      Second:
         My hash table longest linked list size: 9.00
         My hash table performance ratio is: 1.77

   Test case 4:
      First:
         My hash table longest linked list size is: 13.00
         My hash table performance ratio is: 1.23
      Second:
         My hash table real load factor is: 13.00
         My hash table performance ratio is: 1.29


//(3)If you had to change your hash function to reduce the number of collisions,
//   how will you change it?
I would change it to inclue a factor of the current number of employees in the table.
 I think if I factored in the amount of current employees in the table it would allow for
 a more evenly distributed hash since it would result in a more uniform distribution of 
 modulo calculations.
********************************************************************************/

#include "Hash.h"
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

//This function used to get an Employee key which is the combination of firstName, lastName and id
void getKey(string oneLine, string&firstName, string& lastName, int& id);

int main()
{
   int size = 0 ;
   int numOfCommand = 0;
   string firstName, lastName;
   string firstToken, command;
   int id;
   double salary;

   //declare any other necessary variables here
   //ifstream inFile;
   //inFile.open("input.txt");
   int currentAmount = 0;

   cout << "Enter the size of the hash table: ";
   cin >> size;
   cin.ignore(20, '\n');


   //Instantiate the hash table with the relevant number of slots
   Hash* hashTable = new Hash(size);

   do {
         //use this do..while loop to repeatly get one line Employee info. and extract tokens
         //create one Employee object and insert it inside the hashTable until seeing the message
         //"InsertionEnd", then terminate
         string currentLine;
         getline(cin, currentLine); 

         if(currentLine.compare("InsertionEnd") == 0) {
            break;
         }

         string delimiter = ",";
         int pos=currentLine.find(delimiter);
         string token = currentLine.substr(0,pos);
         firstName = token;
         currentLine.erase(0, pos+delimiter.length());

         pos=currentLine.find(delimiter);
         token = currentLine.substr(0,pos);
         lastName = token;
         currentLine.erase(0, pos+delimiter.length());

         pos=currentLine.find(delimiter);
         token = currentLine.substr(0,pos);
         id = stoi(token);
         currentLine.erase(0, pos+delimiter.length());

         pos=currentLine.find(delimiter);
         token = currentLine.substr(0,pos);
         salary = stod(token);
         currentLine.erase(0, pos+delimiter.length());

         if(hashTable->hashInsert(firstName, lastName, id, salary) == 1) {
            currentAmount++;
         }

   } while(true);

   //cout << "\nEnter number of commands: ";   //***need to comment out in submitting
   cin >> numOfCommand;
   cin.ignore(20, '\n');

   for(int i= 0; i < numOfCommand; i++)
   {
   	//get one line command, extract the first token, if only one token
      string currentLine;
      getline(cin, currentLine); 

      string delimiter = ",";
      int pos=currentLine.find(delimiter);
      string token = currentLine.substr(0,pos);
      string command = token;
      currentLine.erase(0, pos+delimiter.length());


      if(command.compare("hashDisplay") == 0)
      {
         hashTable->hashDisplay();
      }
      else  //more than one tokens, check the command name, extract the remaining tokens
      {
         //Get firstname, lastname, id from getKey
         if(command.compare("hashSearch")==0) {
            getKey(currentLine, firstName, lastName, id);
            hashTable->hashSearch(firstName, lastName, id);
         }
         else if(command.compare("hashDelete")==0) {
            getKey(currentLine, firstName, lastName, id);
            if(hashTable->hashSearch(firstName, lastName, id) == 0) {
               hashTable->hashDelete(firstName, lastName, id);
            }
            else if (hashTable->hashDelete(firstName, lastName, id) == 1){
               currentAmount--;
            } 
         }
         //compute ideal and actual performance, and use both to compute performance ratio
         else if(command.compare("hashLoadFactor")==0) {
            double ideal = currentAmount/double(size);
            double actual = hashTable->hashLoadFactor();
            double ratio = actual/ideal;
            cout << fixed;
            cout << setprecision(2);
            cout << "\nThe ideal load factor is: " << ideal << endl;
            cout << "My hash table real load factor is: " << actual << endl;
            cout << "My hash table performance ratio is: " << ratio << endl;
         }
         else {
            cout<<"Invalid command"<<endl;
         }
      }
   } //end for loop
   return 0;
}

//****************************************************************************************
//Given one line, this function extracts firstName, lastName, id info. of an Employee
//This function is completed and given here as a study guide for extracting tokens
void getKey(string oneLine, string& firstName, string& lastName, int& id)
{
   string delimiter = ",";
   int pos=oneLine.find(delimiter);
   string token = oneLine.substr(0,pos);
   firstName = token;
   oneLine.erase(0, pos+delimiter.length());

   pos=oneLine.find(delimiter);
   token = oneLine.substr(0,pos);
   lastName = token;
   oneLine.erase(0, pos+delimiter.length());

   pos=oneLine.find(delimiter);
   token = oneLine.substr(0,pos);
   id = stoi(token);
   oneLine.erase(0, pos+delimiter.length());
}
