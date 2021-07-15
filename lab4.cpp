/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Node {

private:

    int data;
    Node* next;

public:

    // Constructors
    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        next = NULL;
    }
    Node(Node* next, int data)
    {
        this->data = data;
        this->next = next;
    }

    //Getters
    int getData()
    {
        return data;
    }

    Node* getNext()
    {
        return next;
    }

    //Setters
    void setData(int data)
    {
        this->data = data;
    }

    void setNext(Node* next)
    {
        this->next = next;
    }
};


class LinkedList
{

private:
    Node* head;

public:
    // Constructor
    LinkedList()
    {
        head = NULL;
    }

    /* Below are MANY methods that are used on Linked Lists.
     *
     * Examples:
     * search, insert, delete, isEmpty, sumNodes, and many more
    */


    bool isEmpty()
    {
        return head == NULL;
    }



    bool search(int data)
    {
        Node* helpPtr = head;
        while (helpPtr != NULL)
        {
            if (helpPtr->getData() == data)
            {
                return true;
            }
            helpPtr = helpPtr->getNext();
        }
        return false;
    }


    Node* insertNode(int data)
    {
        // IF there is no list, newNode will be the first node, so just return it
        if (head == NULL || head->getData() > data)
        {
            head = new Node(head, data);
            return head;
        }// ELSE, we have a list. Insert the new node at the correct location
        else
        {
            // We need to traverse to the correct insertion location...so we need a help ptr
            Node* helpPtr = head;
            while (helpPtr->getNext() != NULL)
            {
                if (helpPtr->getNext()->getData() > data)
                    break;
                helpPtr = helpPtr->getNext();
            }
            // Now make the new node. Set its next to point to the successor node.
            // And then make the predecessor node point to the new node
            Node* newNode = new Node(helpPtr->getNext(), data);
            helpPtr->setNext(newNode);
        }
        return head;
    }


    void printAllNodes()
    {
        // We need to traverse...so we need a help ptr
        Node* helpPtr = head;
        // Traverse to correct insertion point
        while (helpPtr != NULL)
        {
            // Print the data value of the node
            cout << helpPtr->getData() << ", ";
            // Step one node over
            helpPtr = helpPtr->getNext();
        }
        cout << endl;
    }
        int countNodes() {
        Node* helpPtr = head;
        int count = 0;
        while (helpPtr != NULL) {
            count++;
            helpPtr = helpPtr->getNext();


        }
        return count;
    }
    void swapFirstLast()
    {
         if (countNodes() <= 1) {
            cout << "Error : cannot swap(the list has less than two nodes)";
        }
        Node* helpPtr = head;
        int first = 0;
        int temp = helpPtr->getData();
        int last = 0;
        while (helpPtr != NULL)
        {
            if (helpPtr->getNext() == NULL)
            {
                first = helpPtr->getData();
                helpPtr->setData(temp);
            }
            helpPtr = helpPtr->getNext();
        }
        Node* helpPtr2 = head;
        helpPtr2->setData(first);

    }

    void countEvenOddNodes()
    {
        Node* helpPtr = head;
        int even = 0;
        int odd = 0;
        while (helpPtr != NULL)
        {
            if (helpPtr->getData() % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
            helpPtr = helpPtr->getNext();
        }
        cout << "\nNumbers of Even nodes in the list is " << even;
        cout << "\nNumbers of Odd nodes in the list is " << odd << endl;
    }


    void addNodeAfter(int data)
    {

    }

    void deleteNodeAfter(int data)

    {

    }

};



int main()
{
    // Make a new Linked List called myList
    LinkedList* myList = new LinkedList();

    int value = 0;
    int numNode = 0;
    int val = 0;
    int v = 0;

    cout << ">   How many values do you want to insert: ";
    cin >> numNode;


    for (int i = 0; i < numNode; i++)
    {
        cout << ">    value " << (i + 1) << ": ";
        cin >> value;

        if (myList->search(value))
        {
            cout << ">    " << value << " already exists in the list. Duplicates are not allowed.";
            i--;
        }
        else
        {
            myList->insertNode(value);
            cout << ">    " << value << " was successfully inserted into the list.";
        }
        cout << endl;

    }
    cout << ">    Printing All Nodes:";
    if (myList->isEmpty()) {
        cout << ">    The list is empty";
    }
    else
    {
        cout << ">    ";
        myList->printAllNodes();
        cout << endl;

    }

    cout << "\n>    Task1: swapFirstLast()";
    // implement task 1 here
    myList->swapFirstLast();
    cout << "\nFirst and Last element had been swaped successfully!";
    myList->printAllNodes(); 

    
    cout << "\n>    Task2: countEvenOddNodes()";
      // implement task 2 here
    myList->countEvenOddNodes();
   
    cout << "\n>    Task3: addNodeAfter()";
    // implement task 3 here
    


    cout << "\n>    Task4: deleteNodeAfter()";
    // implement task 4 here

    

}

