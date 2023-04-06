
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.

#include "LinkedList.h"

using namespace std;

void printMenu();

int main()
 {
       // local variables, can be accessed anywhere from the main method
       char input1 = 'Z';
       string inputInfo;
       string firstName, lastName, oldFirstAndLastName, newfirstAndLastName;
       int id;
       double salary;
       string line;
       //bool success = false;

       // instantiate a Linked List object
       LinkedList* list1 = new LinkedList();

       printMenu();

       do  //ask for user input
        {
           cout << "\nWhat action would you like to perform?\n";
           cin.get(input1);
           input1 = toupper(input1);    //change it to upper case
           cin.ignore(20, '\n'); //flush the buffer

           // matches one of the following cases
           switch (input1)
           {
             case 'A':   //Add the Employee
               cout << "\nEnter the employee information: ";
               cout << "\nEnter first name: ";
               getline(cin, firstName);
               cout << "\nEnter last name: ";
               getline(cin, lastName);
               cout << "\nEnter employee id: ";
               cin >> id;
               cout << "\nEnter employee salary: ";
               cin >> salary;
               cin.ignore(20, '\n'); //flush the buffer

               if (list1->addEmployee(firstName,lastName,id,salary) == true) {
                  cout << "\nEmployee \"" << firstName << " " << lastName << "\" is added\n";
               } else
                  cout << "\nEmployee \"" << firstName << " " << lastName << "\" is NOT added\n";

               break;

            case 'C':  //Change Employee name
                cout << "\nEnter the Employee id which you want to change the name: ";
                cin >> id;
                cin.ignore(20, '\n'); //flush the buffer

                //add your own code to finish this case
                if(list1->findEmployee(id) == true) {
                  cout << "\nPlease enter the new name: ";

                  getline(cin >> ws, newfirstAndLastName);
                  //cin.ignore(20, '\n'); //flush the buffer

                }

                  if (list1->changeEmployeeInfo(id, newfirstAndLastName) == true) {
                    cout << "\nEmployee id #: " << id << " name was changed\n";
                  } else {
                    cout << "\nEmployee id #: ";
                    cout << id;
                    cout << " does not exist\n";
                  }

                break;

             case 'D':   //Display all Employees
               //add your own code
               list1->printEmployeeList();
               break;

             case 'E':   //Display Employees by last name
                cout << "\nEnter the last name which you want to display: ";
                getline(cin, lastName);
                cout << "\n";
                //add your own code
                list1->printEmployeeListByLastName(lastName);

               break;

              case 'F':   //Find an Employee
                cout << "\nPlease enter the employee id you want to search: ";
                cin >> id;
                cin.ignore(20, '\n');   //flush the buffer

                if(list1->findEmployee(id) == true) {
                  cout << "Employee with ID #: ";
                  cout << id; 
                  cout << " was found";
                } else {
                  cout << "Employee with ID #: ";
                  cout << id;
                  cout << " was NOT found";
                }

                break;

             case 'U':  //Update a Employee salary
                cout << "\nPlease enter the employee id whose salary you want to update: \n";
                cin >> id;
                cin.ignore(20, '\n');   //flush the buffer

                //add your own code
                if(list1->findEmployee(id) == true) {
                  cout << "Please enter the new salary: \n";
                  cin >> salary;
                  cin.ignore(20, '\n');   //flush the buffer
                }

                  if(list1->updateEmployeeSalary(id, salary) == true) {
                    cout << "Employee with id #: ";
                    cout << id;
                    cout << " salary was updated\n";
                  } else {
                    cout << "Employee with id #: ";
                    cout << id;
                    cout << " does NOT exist\n";
                  }

                break;

            case 'R':  //Remove an employee from the list by id
               cout << "\nPlease enter the employee id to remove: ";
               cin >> id;
               cin.ignore(20, '\n');   //flush the buffer

               //add your own code
               if(list1->removeById(id) == true) {

                  cout << "Employee with ID #: ";
                  cout << id;
                  cout << " was removed";
                  
                } else {
                  cout << "Employee with ID #: ";
                  cout << id;
                  cout << " does NOT exist";
               }


               break;

            case 'N':  //Remove an employee from the list by first and last name
               cout << "\nPlease enter employee first name which you want to remove: ";
               getline(cin, firstName);
               cout << "\nPlease enter employee last name which you want to remove: ";
               getline(cin, lastName);

               //add your own code
               if(list1->removeByFirstAndLastName(firstName, lastName) == true) {

                  cout << "\nEmployee: ";
                  cout << firstName;
                  cout << " ";
                  cout << lastName;
                  cout << " was removed\n";
                  
                } else {
                  cout << "\nEmployee: ";
                  cout << firstName;
                  cout << " ";
                  cout << lastName;
                  cout << " does NOT exist\n";
                }

               break;

             case 'Q':   //Quit
                    list1->~LinkedList();
                    break;

             case '?':   //Display Menu
                    printMenu();
                    break;

             default:
               //cout << "Unknown action\n";
               break;
            }

        } while (input1 != 'Q');
      return 0;
   }

  /** The method printMenu displays the menu to a user**/
  void printMenu()
   {
     cout << "Choice\t\tAction\n";
     cout << "------\t\t------\n";
     cout << "A\t\tAdd an Employee\n";
     cout << "C\t\tChange an Employee Name\n";
     cout << "D\t\tDisplay All Employees\n";
     cout << "E\t\tDisplay Employees by Last Name\n";
     cout << "F\t\tFind an Employee by ID\n";
     cout << "U\t\tUpdate an Employee Salary\n";
     cout << "R\t\tRemove an Employee by ID\n";
     cout << "N\t\tRemove an Employee by Name\n";
     cout << "Q\t\tQuit\n";
     cout << "?\t\tDisplay Help\n\n";
   }
