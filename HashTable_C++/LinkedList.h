// Description: A simple linked list that implements a list of Employee objects. A user can
//              perform searching, insertion or deletion on the linked list.
//              //---- is where you should add your own code

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Employee
{
   string firstName, lastName;
   int id;
   double salary;
   struct Employee* next;
};

class LinkedList
{
   private:
     struct Employee* head;
     int size;      //a variable represents number of Employees inside the list
   public:
     LinkedList();
     ~LinkedList();
     Employee* getHead();
     int getSize();
     bool searchEmployee(int id);
     bool insertEmployee(string firstName, string lastName, int id, double salary);
     bool deleteEmployee(int id);
     void displayList();
};

//Constructor
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
LinkedList::~LinkedList()
{
	while (head != NULL) {
        Employee* tmp = head;
        head = head->next;
        delete tmp;
    }
}

//Return employee at head of list
Employee* LinkedList::getHead()
{
    return head;
}

//Return number of Employees inside the Linked list
int LinkedList::getSize()
{
    return size;
}

//This function does a linear search on the Employee list with the given Employee id
//it returns true if the corresponding Employee is found, otherwise it returns false.
bool LinkedList::searchEmployee(int id)
{
    Employee *tmp = head;
	while (tmp != nullptr) {

        if(id == tmp->id) {
            return true;
        } else {
            tmp = tmp->next;
        }
    }

    return false;
}

//Insert the parameter Employee at the head of the linked list.
//return true if it is inserted successfully and false otherwise
bool LinkedList::insertEmployee(string firstName, string lastName, int id, double salary)
{
    //Initialize a new employee
    Employee* newEmp = new Employee;
    newEmp->firstName = firstName;
    newEmp->lastName = lastName;
    newEmp->id = id;
    newEmp->salary = salary;

    //If employee isnt already in list, insert; else cant be inserted => return false
    if(searchEmployee(id) == 0) {
        Employee *tmp = head;
        head = newEmp;
        newEmp->next = tmp;
        size++;
        return true;
    } else {
        return false;
    }

}

//Delete the Employee with the given id from the linked list.
//Return true if it is deleted successfully and false otherwise
bool LinkedList::deleteEmployee(int id)
{
    //If employee is already in list, cannot be inserted => return false
    if(searchEmployee(id) == 0) {
        return false;
    } else {
        //Otherwise, traverse through list until tmp is node with specified id 
        // Set previous next to tmp next, and delete tmp to remove
        Employee* tmp = head;
        Employee* previous = NULL;

        while (tmp != NULL) {

            if(id == tmp->id) {
                
                if(previous == NULL) {
                    head = tmp->next;
                    delete(tmp);
                } else {
                    previous->next = tmp->next;
                    delete(tmp);
                }
                size--;
                return true;

            } else {
                previous = tmp;
                tmp = tmp->next;
            }
        }

        return false;
    }
}

//This function displays the content of the linked list.
void LinkedList::displayList()
{
   struct Employee *temp = head;
   if(head == NULL)
   {
   	//empty linked list, print nothing here
   }
   else
   {
      while(temp != NULL)
      {
         cout << left    << setw(18) << temp->firstName
              << left    << setw(18) << temp->lastName
              << right   << setw(8)  << temp->id
              << setw(10) << fixed << setprecision(2) << temp->salary << "\n";
         temp = temp->next;
      }
   }
}
