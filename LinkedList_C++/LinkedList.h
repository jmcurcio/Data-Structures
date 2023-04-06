// Description: LinkedList header file

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Employee represents an Employee information
struct Employee
{
    public:
        string firstName, lastName;
        int id;
        double salary;
        struct Employee* next;
    
};


//class LinkedList will contains a linked list of Employees
class LinkedList
{
    private:
        Employee *head, *tail;

    public:
        LinkedList(); // {head = NULL; tail = NULL;};
        ~LinkedList();
        bool findEmployee(int anId);
        bool addEmployee(string firstName, string lastName, int id, double salary);
        bool removeById(int anId);
        bool removeByFirstAndLastName(string firstName, string lastName);
        bool changeEmployeeInfo(int anId, string newFirstAndLastName);
        bool updateEmployeeSalary(int anId, double newSalary);
        void printEmployeeListByLastName(string lastName);
        void printEmployeeList();
};

//Constructor to initialize an empty linked list
LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the existing linked list.
//It deletes all the nodes including the head and finally prints the number of nodes deleted by it.
//Return value: Prints the number of nodes deleted by it.
LinkedList::~LinkedList()
{
    int EmployeeCount = 0;

	while (head != NULL) {
        Employee* temp = head;
        head = head->next;
        delete temp;
        EmployeeCount++;
    }
    cout << "\nThe number of deleted Employee is: " << EmployeeCount << "\n";
}

//A function to identify if the parameterized employee is inside the LinkedList or not.
//Return true if it exists and false otherwise.
bool LinkedList::findEmployee(int anId)
{
    Employee *tmp = head;
	while (tmp != nullptr) {

        if(anId == tmp->id) {
            return true;
        } else {
            tmp = tmp->next;
        }
    }

    return false;
}

//Creates a new node and inserts it into the list at the right place.
//It also maintains an alphabetical ordering of employees by their lastName and firstName, i.e.
//first by lastName, if two Employees have same lastNames, then we will list them in alphabetical order
//of firstName. Note: each Employee has a unique id, but may have the same lastName and firstName.
//In case two employees have same lastName and firstName, they should be inserted according to the
//increasing order of their ids.
//Return value: true if it is successfully inserted and false in case of failures.
bool LinkedList::addEmployee(string firstName, string lastName, int id, double salary)
{
     //if the Employee already exist, return false
     if(findEmployee(id) == true) {
        cout << "Duplicated Employee. Not added.";
        return false;
     }

    //allocate node and put data into employee
    Employee* newEmp = new Employee;
    newEmp->firstName = firstName;
    newEmp->lastName = lastName;
    newEmp->id = id;
    newEmp->salary = salary;
    newEmp->next = NULL;

    if(head == NULL)
    {
        head = newEmp;
        tail = newEmp;
        return true;
    }

    Employee* current = head;
    Employee* previous = NULL;

    while (current != NULL) {

        if(lastName < current->lastName) {

            if(previous == NULL) {
                newEmp->next = head;
                head = newEmp;
            } else {
                newEmp->next = current;
                previous->next = newEmp;
                
            }
            return true;

        }  else if (lastName == current->lastName) {

            if (firstName < current->firstName) {

                if(previous == NULL) {
                    newEmp->next = head;
                    head = newEmp;
                } else {
                    newEmp->next = current;
                    previous->next = newEmp;
                }
                return true;

            } else if (firstName == current->firstName) {

                if (id < current->id) {

                    if(previous == NULL) {
                        newEmp->next = current;
                        previous->next = newEmp;
                    } else {
                        newEmp->next = current;
                        previous->next = newEmp;
                    }
                    return true;

                } 
                
            }
            //head = head->next;
        }
        previous = current;
        current = current->next;
    }
    previous->next = newEmp; 
    return true;
    
}

//Removes the specified employee from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise.
bool LinkedList::removeById(int anId)
{
    
    //if Employee doesn't exist, return false
    if(findEmployee(anId) == false) {
        return false;
    }

    Employee* tmp = head;
    Employee* previous = NULL;

    while (tmp != NULL) {

        if(anId == tmp->id) {
            
            if(previous == NULL) {
                head = tmp->next;
                delete(tmp);
            } else {
                previous->next = tmp->next;
                delete(tmp);
                
            }
            return true;

        } else {
            previous = tmp;
            tmp = tmp->next;
        }
    }

    return true;
}

//Removes the given Employee from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise. Note: all Employees with
//the same firstName and lastName should be removed from the list.
bool LinkedList::removeByFirstAndLastName(string firstName, string lastName)
{
	
    int removeCount = 0;

    Employee* tmp = head;
    Employee* previous = NULL;

    while (tmp != NULL) {

        if(firstName == tmp->firstName && lastName == tmp->lastName) {

            if(previous == NULL) {
                head = tmp->next;
                delete(tmp);
            } else{
                previous->next = tmp->next;
                delete(tmp);
                tmp = tmp->next;
            }
            removeCount++;

        } else {
            previous = tmp;
            tmp = tmp->next;
        }
    }
    
    if(removeCount > 0) {
        return true;
    } else {
        cout << "\nNo such Employee found.\n";
        return false;
    }

}


//Modifies the data of the given Employee. Return true if it modifies successfully and
//false otherwise. Note: after changing a Employee firstName and lastName, the linked list must still
//maintain the alphabetical order.
bool LinkedList::changeEmployeeInfo(int anId, string newFirstAndLastName)
{
   
   //add your own code
   //----
    string delim = " ";

    if(findEmployee(anId) == false) {
        return false;
    }

    Employee *tmp = head;
    while (tmp != NULL) {

        if(anId == tmp->id) {
            
            string newFirst, newLast;

            //split newFirstAndLastName string to get firstName and lastName accordingly
            newFirst = newFirstAndLastName.substr(0, newFirstAndLastName.find(delim));
            newLast = newFirstAndLastName.substr(newFirstAndLastName.find(delim) + 1, newFirstAndLastName.length() - newFirstAndLastName.find(delim) + 1);

            double empSalary = tmp->salary;

            removeById(anId);
            addEmployee(newFirst, newLast, anId, empSalary);

            return true;

        } else {
            tmp = tmp->next;
        }
    }

    return false;

}

bool LinkedList::updateEmployeeSalary(int anId, double newSalary)
{
	Employee* tmp = head;
    while (tmp != NULL ) {

        if(anId == tmp->id) {
            
            tmp->salary = newSalary;
            return true;

        } else {
            tmp = tmp->next;
        }
    }

    //if the Employee is not inside the linked list
    //cout << "\nEmployee is NOT inside the list, cannot change his salary.\n";
    return false;
    
}

//Prints all Employees in the list with the same lastName.
void LinkedList::printEmployeeListByLastName(string lastName)
{
    //add your own code 

    int printCount = 0;

    if (head == NULL) {
        cout << "\nThe list is empty\n";
    } else {

        Employee* tmp = head;

        while (tmp != NULL) {

            if (tmp->lastName == lastName) {

                cout << left    << setw(12) << tmp->firstName
                    << left    << setw(12) << tmp->lastName
                    << right   << setw(8) << tmp->id
                    << setw(10) << fixed << setprecision(2) << tmp->salary << "\n";
                printCount++;
                tmp = tmp->next;

            } else {
                tmp = tmp->next;
            }

        }

        if(!(printCount > 0)) {
            cout << "No Employees with the specified lastName found.";
        }       

    }
 }

//Prints all Employees in the linked list starting from the head node.
void LinkedList::printEmployeeList()
{
    if (head == NULL) {
        cout << "\nThe list is empty\n";
    } else {

        Employee* current = head;

        while(current != NULL) {

            cout << left    << setw(12) << current->firstName
                << left    << setw(12) << current->lastName
                << right   << setw(8) << current->id
                << setw(10) << fixed << setprecision(2) << current->salary << "\n";
            current = current->next;

        }

    }

}
