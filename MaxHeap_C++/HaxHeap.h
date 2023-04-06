// Description: MaxHeap Header file. Contains all classes for the required 
//				properties/operations of a MaxHeap
//********************************************************
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Each Employee has a unique id
struct Employee
{
    string firstName, lastName;
    int id;
    double salary;
};

//class MaxHeap represents a max heap that contains Employee objects. The underline data structure
//is a one dimensional array of Employee.
class MaxHeap
{
    private:
    struct Employee* employeeArr;	//an array of Employees
    int capacity, size;

	public:
    MaxHeap(int capacity);
    ~MaxHeap();

	Employee* getEmployeeArr();
	int getSize();
	int getCapacity();
	int isFound(int anID);
	bool heapIncreaseID(int index, Employee oneEmployeeWithNewID);
	bool heapInsert(int id, string firstName, string lastName, double salary);
	void heapify(int index);
	Employee getHeapMax();
	void extractHeapMax();
	int leftChild(int parentIndex);
	int rightChild(int parentIndex);
	int parent(int childIndex);
	void printHeap();
	void doubleCapacity(Employee *& employeeArr, int capacity);

};

//Constructor to dynamically allocate memory for a heap with the specified capacity
MaxHeap::MaxHeap(int capacityIn)
{
	//Dynamically allocate array of size capacity
	capacity = capacityIn;
 	employeeArr = new Employee[capacity];

	//Initialize size of heap to be 0
	int size = 0;
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the heap.
//and prints the number of nodes deleted by it.
MaxHeap::~MaxHeap()
{
	//Free memory of whole array
	delete[] employeeArr;

	//Output how many employees were deleted
	cout << "\nThe number of deleted Employees is: " << size << endl;
}

//*******************************************************************
//increase the Employee's id located at the specific index
bool MaxHeap::heapIncreaseID(int index, Employee oneEmployeeWithNewID)
{
	if(size == 1) {
		employeeArr[0] = oneEmployeeWithNewID;
		return true;
	}

	if (employeeArr[index].id > oneEmployeeWithNewID.id ) {
        cout << "\nIncrease id error: index out of range" << endl;
        return false;
	}

	//Declare parent employee for upcoming switches
	Employee* parentEmp = new Employee();

	//A[i] = key
	employeeArr[index] = oneEmployeeWithNewID;

	//"Float Up" through whole heap until new ID is at proper location
	while(index >= -1 && employeeArr[parent(index)].id < employeeArr[index].id) {

		Employee temp = employeeArr[index];
		employeeArr[index] = employeeArr[parent(index)];
		employeeArr[parent(index)] = temp;
		index = parent(index);

	}
	return true;
}


Employee* MaxHeap::getEmployeeArr() 
{
	//Employee Array accessor
	return employeeArr;
}

int MaxHeap::getSize() 
{
	//Size accessor
	return size;
}

int MaxHeap::getCapacity() 
{
	//Capacity Accessor
	return capacity;
}

int MaxHeap::isFound(int anID) 
{
	//Go though whole array until an ID is found
	for(int i = 0; i < size; i++) {
		if(employeeArr[i].id == anID) {
			return i;
		}
	}

	//return -1 if not found
	return -1;
}

bool MaxHeap::heapInsert(int id, string firstName, string lastName, double salary) 
{ 
	//Instantiate a new employee
	Employee newEmp;

	//Initialize corresponding info to new employee
	newEmp.firstName = firstName;
	newEmp.lastName = lastName;
	newEmp.id = id;
	newEmp.salary = salary;

	//Max heap insert
	size++;    

	if(size > capacity) {

		cout << "\nReach the capacity limit, double the capacity now." << endl;
		
		doubleCapacity(employeeArr, capacity);
		capacity = 2*capacity;

		cout << "\nThe new capacity now is " << (capacity) << endl;
	}

	employeeArr[size-1].id = -999999; 
	return heapIncreaseID(size-1, newEmp); 
	
}

void MaxHeap::heapify(int index) 
{
	//Instantiate variable to hold largest Id for later comparison
	//int largestIndex;

	//Initialize variables to each employees index for comparisons
	int largestIndex = index;
	int leftIndex = leftChild(index);
	int rightIndex = rightChild(index);

	//Since comparison is between Id's, initialize variables to each employee's ID
	int largestId = employeeArr[largestIndex].id;
	int leftId = employeeArr[leftIndex].id;
	int rightId = employeeArr[rightIndex].id;

	//perform Heapify -- find largest of three ID's and make that parent Employee

	if(rightId > leftId && rightId > largestId && rightIndex <= size-1) {
		largestIndex = rightIndex;
	} else if (leftId > rightId && leftId > largestId && leftIndex <= size-1) {
		largestIndex = leftIndex;
	} 

	if(largestIndex != index) {

		Employee temp = employeeArr[largestIndex];
		employeeArr[largestIndex] = employeeArr[index];
		employeeArr[index] = temp;

		//Recursively call Heapify to "float down" through whole array
		heapify(largestIndex);
	}

}

Employee MaxHeap::getHeapMax() 
{
	//initialize id of max to be -9999 in order to test for empty heap
	Employee max;
	max.id = -9999;

	if (size < 1) {
		return max;
	} else {
		max = employeeArr[0];
		return max;
	}

}

void  MaxHeap::extractHeapMax() 
{
	//make top the last element, heapify to restore maxheap properties
	employeeArr[0] = employeeArr[size-1];
	size--;
	heapify(0);
	
}

int MaxHeap::leftChild(int parentIndex) 
{
	//left = i * 2 + 1
	return (parentIndex * 2) + 1;
	
}

int MaxHeap::rightChild(int parentIndex) 
{	
	//right = 1 * 2 + 2
	return (parentIndex * 2) + 2;
	
}

int MaxHeap::parent(int childIndex) 
{
	//Check error cases; child at index 0 is its own parent
	if(childIndex == 0) {
		return 0;
	}

	//Check cases if integer division would result in invalid value
	if(childIndex == 1 || childIndex == 2) {
		return 0;
	}

	//Otherewise, do standard cases
	if (childIndex % 2 == 0) {
		return (childIndex/2) - 1;
	} else {
		return ((childIndex-1)/2);
	}
}

void  MaxHeap::printHeap() 
{

	//Check if array is empty, if so output no elements
	if (size < 1) {
		cout << "\nEmpty heap, no elements" << endl;
	} else {

		//If not empty, loop through whole array and print according to format
		cout << "\nHeap capacity = " << capacity << endl;
		cout << "\nHeap size = " << size << "\n" << endl;

		for(int i = 0; i < size; i++) {
			cout << left;
			cout << setw(8) << employeeArr[i].id
				<< setw(12) << employeeArr[i].firstName
				<< setw(12) << employeeArr[i].lastName
				<< setw(8) << fixed << setprecision(2) << employeeArr[i].salary << endl;
		}
	}

}

//Method for doubling capacity in cases where size exceeds capacity
void MaxHeap::doubleCapacity(Employee *& employeeArr, int capacity) {

	//Dynamically allocate a new array of double the capacity
	Employee* temp = new Employee[2*capacity];
	
	for(int i = 0; i < capacity; i++) {
		temp[i] = employeeArr[i];
	}
	//Free memory of former array
	delete[] employeeArr;

	employeeArr = temp;

}
