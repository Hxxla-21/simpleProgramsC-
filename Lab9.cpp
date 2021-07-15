/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;
/////////////////

class QueueNode {

private:
	int data;
	QueueNode* next;

public:
	// CONSTRUCTORS
	QueueNode() {
		data = 0;
		next = NULL;
	}

	QueueNode(int data) {
		this->data = data;
		next = NULL;
	}

	QueueNode(int data, QueueNode* next) {
		this->data = data;
		this->next = next;
	}

	// ACCESSORS
	int getData() {
		return data;
	}

	QueueNode* getNext() {
		return next;
	}

	// MUTATORS
	void setData(int data) {
		this->data = data;
	}

	void setNext(QueueNode* next) {
		this->next = next;
	}
};
/////////////////////////////////

// Class from which we can create fully functional Queues (using linked lists)

class QueueLL {
	// top: reference variable to the top of the stack (same as "head" of linked list)

private:
	QueueNode* front;
	QueueNode* back;

public:
	// CONSTRUCTOR
	QueueLL() {
		front = NULL;
		back = NULL;
	}

	bool isEmpty() {
		return front == NULL;
	}

	void printQueue() {

		// We need to traverse...so we need a help ptr
		QueueNode* helpPtr = front;
		// Traverse to correct insertion point
		while (helpPtr != NULL) {
			// Print the data value of the node
			cout << helpPtr->getData() << ", ";
			// Step one node over
			helpPtr = helpPtr->getNext();
		}
		cout << endl;
	}

	bool search(int data) {
		// To search, we must traverse. Therefore, we need helpPtr.
		QueueNode* helpPtr = front;
		while (helpPtr != NULL) {
			if (helpPtr->getData() == data) {
				return true;
			}
			helpPtr = helpPtr->getNext(); // step one node over
		}
		return false;
	}


	void enqueue(int data) {
		// Make a new QueueNode with "data" as the data value
		QueueNode* temp = new QueueNode(data);

		// Now, if the list is empty, return the reference for temp
		// and save this reference into both "front" and "back"
		// Why? Since this is the only node in the queue, it will be the front and back node
		if (isEmpty()) {
			front = back = temp;
		} // ELSE, the queue is not empty. We need to insert temp at the back of the queue.
		// So save the address of the new node into the next of back.
		// Then, make back "traverse" one node over, so it now points to the new back node.
		// Finally, return the updated address of back.
		else {
			back->setNext(temp);
			back = back->getNext();
		}
	}

	QueueNode* dequeue() {
		QueueNode* temp = front;
		front = front->getNext();
		if (front == NULL) {
			back = NULL;
		}
		temp->setNext(NULL);
		return temp;
	}


	int peek() {
		// Invoke the peek method with front as a parameter
		int frontValue = front->getData();

		// return topValue
		return frontValue;
	}

	void SmallestLargest() {

		int smallest = front->getData();
		int largest = front->getData();

		QueueNode* helpPtr = front;

		while (helpPtr != NULL) {
			if (smallest > helpPtr->getData()) {
				smallest = helpPtr->getData();
			}
			if (largest < helpPtr->getData()) {
				largest = helpPtr->getData();
			}
			helpPtr = helpPtr->getNext();
		}
		cout << endl;
		cout << ">\tSmallest element in the queue is " << smallest;
		cout << "\tlargest element in the queue is " << largest;
		cout << endl;
	}


	void fillQWithRandomNumber() {
		for (int i = 0; i < 10; i++)
		{
			int randomNumber = rand() % 1000;
			enqueue(randomNumber);
		}
	}

	QueueLL* deleteNode(QueueLL* myQueue, int num) {




		QueueLL* list1 = myQueue;
		QueueLL* list2 = new QueueLL;
		QueueLL* list3 = new QueueLL;

		for (int i = 0; i < 10; i++) {
			if (list1->peek() != num) {
				list2->enqueue(list1->peek());
				list1->dequeue();
			}
			else {
				list3->enqueue(list1->peek());
				list1->dequeue();
			}
		}
		cout << "> After deleting Value " << num << ", elements of the queue 1 are as follows :" << endl;
		list2->printQueue();

		return list2;

	}

	void OddEvenNode(QueueLL* myQueue) {
		QueueLL* EvenQueue = new QueueLL();
		QueueLL* OddQueue = new QueueLL();

		QueueNode* temp = front;
		while (temp != NULL)
		{
			if (temp->getData() % 2 == 0)
				EvenQueue->enqueue(temp->getData());
			else
				OddQueue->enqueue(temp->getData());
			temp = temp->getNext();
		}
		cout << "> Element of queue 1 are as follows :"<<endl;
		myQueue->printQueue();
		cout << "> Element of queue 2 are as follows :";
		EvenQueue->printQueue();
		cout << "> Element of queue 3 are as follows :";
		OddQueue->printQueue();
	}

	void reveresElement() {
		cout << "> Element of queue 1 are as follows : ";
		printQueue();

		stack<int>Stack;

		while (!isEmpty())
		{
			Stack.push(peek());
			dequeue();
		}

		while (!Stack.empty())
		{
			enqueue(Stack.top());
			Stack.pop();
		}

		cout << "> Element of the queue After reveresing  are as  follows ";
		printQueue();
	}
};


////////////////////////////////
int main()
{
	// variables
	int value; // value to enqueue, dequeue, or search for

	// Make a new Queue Linked List called testQueue
	QueueLL* testQueue = new QueueLL();

	// ENQUEUE new node into queue
	cout << "> What are values do you want to enqueue ( the input ends if it is 0): ";
	cin >> value;
	while (value != 0) {
		// Invoke enqueue method with "value" as the parameter
		testQueue->enqueue(value);
		cout << " " << value << " was successfully enqueued into the queue.";
		cin >> value;
	}
	cout << endl;
	// Print all nodes in queue
	if (testQueue->isEmpty()) {
		cout << "> Error: cannot print nodes (the queue is empty)";
	}
	else {
		cout << "> Printing All Nodes:";
		cout << " ";
		testQueue->printQueue();
	}

	cout << endl;
	// display smallest and largest node
	if (testQueue->isEmpty()) {
		cout << "> Error: cannot find largest and smallest nodes (the queue is empty)";
		cout << endl;
	}
	else {
		cout << "> Displaying smallest and largest nodes :";
		testQueue->SmallestLargest();
	}

	cout << endl;
	// Create a new Queue Linked List called myQueue
	QueueLL* myQueue = new QueueLL();

	// Lab9: Ex. a. Fill the Queue with 10 random numbers between 1 and 1000.

	myQueue->fillQWithRandomNumber();

	
	cout << ">>>>>>>> Delete Node from the queue (using 2nd queue) <<<<<<<<<\n";
	cout << "> Before deleting Value , elements of the queue are as follows :" << endl;
	myQueue->printQueue();
	cout << "\n> Please enter an int Value(Between 1 and 1000) to delete from the queue :";
	int num;
	cin >> num;
	myQueue = myQueue->deleteNode(myQueue, value);
	cout << "> After deleting Value " <<num<<", elements of the queue are as follows :" << endl;
	myQueue->printQueue();

	cout << ">>>>>>>> Even and odd value queues <<<<<<<<<\n";
	myQueue->OddEvenNode(myQueue);

	cout << ">>>>>>>> Reverse the elements of a queue <<<<<<<<<\n";
	myQueue->reveresElement();


	return 0;
}
