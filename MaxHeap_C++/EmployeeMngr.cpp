
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
//             	//---- is where you should add your own code
//********************************************************************************

#include "MaxHeap.h"

using namespace std;

void printMenu();
void heapSort(MaxHeap* oneMaxHeap);

int main()
{
	char input1 = 'Z';
	int id , newID;
	string firstName, lastName;
    double salary;
	int capacity;   //array capacity and index
	bool success = false;

	//declare any other variables in case you need them
	//----

    Employee anEmployee;

	// instantiate an empty Heap
	MaxHeap* heap1 = nullptr;
	printMenu();

	do {
		cout << "\nWhat action would you like to perform?" << endl;
		cin.get(input1);
		input1 = toupper(input1);
		cin.ignore(20, '\n');	//flush the buffer

		// matches one of the cases
		switch (input1)
		{
			case 'C':	//create empty Heap with the relevant capacity
				cout << "\nPlease enter the heap capacity: ";
				cin >> capacity;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				heap1 = new MaxHeap(capacity);

				break;

			case 'D':	//delete the heap, call the destructor explicitly
				cout << "\nDelete the heap" << endl;
				//Add your own code
				heap1->~MaxHeap();

				//re-initialize it with capacity 4
				//Add your own code
				heap1 = new MaxHeap(4);
				break;

			case 'E':	//Extract the maximum node
                if (heap1 == nullptr)
                    cout << "\nEmpty heap, can NOT extract max" << endl;
                else
                {
                    //Add your own code
                    //Show user initial heap -- before extracting max
					cout << "\nBefore extract heap max operation:" << endl;
					heap1->printHeap();

					//Remove max and reform Heap
					heap1->extractHeapMax();

					//Show user new heap
					cout << "\nAfter extract heap max operation:" << endl;
					heap1->printHeap();
                }
				break;

			case 'F':	//Find an Employee
				cout << "\nEnter the Employee id you want to search: ";
				cin >> id;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//if ifFound returns -1, employee is not found, output accordingly
				if(heap1->isFound(id) >= 0) {
					cout << "\nEmployee with id: " << id << " is found" << endl;
				} else {
					cout << "\nEmployee with id: " << id << " is NOT found" << endl;
				}

				break;

			case 'I':	//Insert an Employee
				cout << "\nEnter the Employee firstName: ";
				cin >> firstName;

				cout << "\nEnter the Employee lastName: ";
				cin >> lastName;

				cout << "\nEnter the Employee id: ";
				cin >> id;

				cout << "\nEnter the Employee salary: ";
				cin >> salary;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//if employee doesnt exist, add and tell user they were added
				if(heap1->isFound(id) < 0) {
					if(heap1->heapInsert(id, firstName, lastName, salary)) {
						cout << "\nEmployee \"" << firstName << " " << lastName << "\" is added" << endl;
					} else {
						//if employee already exists, tell user they were not added
						cout << "\nEmployee \"" << firstName << " " << lastName << "\" is NOT added" << endl;
					}
				} else {
					cout << "\nDuplicated Employee. Not added" << endl;
					//if employee already exists, tell user they were not added
					cout << "\nEmployee \"" << firstName << " " << lastName << "\" is NOT added" << endl;
				}

				break;

			case 'K':	//increase the ID
				cout << "\nEnter the old employee id you want to increase: ";
				cin >> id;
				cout << "\nEnter the new employee id: ";
				cin >> newID;
				cin.ignore(20, '\n');	//flush the buffer

				//Add your own code
				//Check if newID is less than old ID
				if(newID <= id) {
					cout << "\nIncrease ID error: new id is smaller than current id" << endl;
					break;
				}

				//Check if newID already exists
				if(heap1->isFound(newID) >= 0) {
					cout << "\nThe new ID you entered already exist, increase id operation failed" << endl;
					break;
				}


				if(heap1->isFound(id) > 0) {

					cout << "\nBefore increase ID operation:" << endl;
					heap1->printHeap();

					//If employee exists, get info of that employee, update ID, then call heapIncreaseID
					Employee* employeeArr = heap1->getEmployeeArr();
					anEmployee = employeeArr[heap1->isFound(id)];
					anEmployee.id = newID;
					heap1->heapIncreaseID(heap1->isFound(id),anEmployee);

					//tell user employee was added
					cout << "\nEmployee with old id: " << id << " is increased to new id: " << newID << endl;
					
					cout << "\nAfter increase id operation: " << endl;
					heap1->printHeap();

				} else {
					//if employee with requested ID doesnt exist, tell user
					cout << "\nThe old ID you try to increase does not exist" << endl;
				}

				break;

			case 'M':	//get maximum node
			    //Add your own code

				anEmployee = heap1->getHeapMax();
				//Check if heap is empty and let user know; if not, print max node
				if(anEmployee.id == -9999) {
					cout << "Empty heap, can NOT get max node" << endl;
				} else {
					cout <<"\nThe maximum heap node is:" << endl;
					cout << left;
					cout << setw(8) << anEmployee.id
						<< setw(12) << anEmployee.firstName
						<< setw(12) << anEmployee.lastName
						<< setw(8) << fixed << setprecision(2) << anEmployee.salary << endl;
				}
				break;

			case 'P':	//Print heap contents
			    //Add your own code
				heap1->printHeap();

				break;

			case 'S':	//HeapSort
				cout << "\nHeap sort. Employees will be sorted in increasing order of their IDs" << endl;
				//Add your own code
				heapSort(heap1);

				break;

			case 'Q':	//Quit
				delete heap1;
				break;

			case '?':	//Display Menu
				printMenu();
				break;

			default:
				cout << "Unknown action\n";
				break;
		}
	} while (input1 != 'Q');
	return 0;
}

//*****************************************************
//Given a max heap, we want to sort it in increasing order according to ID, put the
//sorting result inside another array and print it out
void heapSort(MaxHeap* oneMaxHeap)
{
	int size = oneMaxHeap->getSize();

	//Create new employee array in order to place sorted elements
	Employee* sorted = new Employee[size];

	//place the largest element in last position of sorted array,
	//pop off largest element and heapify in order to maintain maxheap
	for(int i = oneMaxHeap->getSize()-1; i >= 0; i--) {

		sorted[i] = oneMaxHeap->getHeapMax();
		oneMaxHeap->extractHeapMax();
		oneMaxHeap->heapify(0);
	}

	//Traverse through whole sorted array and print in order
	for(int i = 0; i < size; i++) {

		cout << left;
		cout << setw(8) << sorted[i].id
			<< setw(12) << sorted[i].firstName
			<< setw(12) << sorted[i].lastName
			<< setw(8) << fixed << setprecision(2) << sorted[i].salary << endl;
	}
	
}

//**The function displays the menu to a user**
void printMenu()
{
	cout << "Choice\t\tAction\n";
	cout << "------\t\t------\n";
	cout << "C\t\tCreate a heap\n";
	cout << "D\t\tDelete the heap\n";
	cout << "E\t\tExtract max node\n";
	cout << "F\t\tFind an Employee by ID\n";
	cout << "I\t\tInsert an Employee\n";
	cout << "K\t\tIncrease the ID\n";
	cout << "M\t\tGet the max node\n";
	cout << "P\t\tPrint the heap\n";
	cout << "S\t\tHeap Sort\n";
	cout << "Q\t\tQuit\n";
	cout << "?\t\tDisplay Help\n\n";
}
