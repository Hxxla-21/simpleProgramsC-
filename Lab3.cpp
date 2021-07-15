/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream> 
using namespace std; 
struct node 
{ 
 int data; 
 node *next; 
 
}; 

class list 
{ 
private: 
    node* head, * tail; 
    
public : 
    list() 
    { 
        head = tail = NULL; 
    } 
}; 
 

void printAllNodes(node* head) { 
    node* helpPtr = new node(); 
    helpPtr = head; 
    while (helpPtr != NULL) { 
        // Print the data value of the node 
        cout << helpPtr->data << endl; 
        // Move to next node 
            helpPtr = helpPtr->next; 
    } 
} 

int findLargest(node* head) { 
    int largest = head->data; 
    while (head != NULL) 
    { 
        if (head->data > largest) 
            largest = head->data; 
            head = head->next; 
    } 
    return largest; 
} 
node* data2ndNode(node* head) { 
    return head->next; 
} 
 
node* data2ndLastNode(node* head) { 
    // Find the second last node  
    node* second_last = head; 
    while (second_last->next->next != NULL) 
        second_last = second_last->next; 
    
    return second_last; 
} 
 
void deleteLastNode(node* head) { 
    if (head == NULL) 
        return; 
    if (head->next == NULL) 
    { 
        delete(head); 
        return; 
    } 
 
    // Find the second last node  
    node* second_last = head; 
    while (second_last->next->next != NULL) 
        second_last = second_last->next; 
 
    // Delete last node  
    delete (second_last->next); 
 
    // modify the second_last 
    second_last->next = NULL; 
} 
void odd2Even2Odd(node* head)  
{ 
    while (head != NULL) 
    { 
        if (head->data % 2 ==0) 
             head->data++; 
        else 
            head->data--; 
        
        head = head->next; 
    } 
    
} 
int main() 
{  
    node* first = new node(); 
    node* second = new node(); 
    node* third = new node(); 
    node* fourth = new node(); 
 
    first->data = 10; 
    first->next = second;    
     
    second->data = 21; 
    second->next = third; 
     
    third->data = 6; 
    third->next = fourth; 
     
    fourth->data = 8; 
       
    // display the nodes values using printAllNodes() 
    cout << "The Four Node Constructed with the following values \n"; 
    printAllNodes(first); 
    
 // print the largest value in the linked list 
    cout << "The Largest value in All nodes  = " << findLargest(first)<<endl; 
    
 // print the value of the second node 
    cout << "the Value of the second node is " << data2ndNode(first)->data <<endl;
    
 // print the value of the second last node 
    cout << "the Value of the second last node is " << data2ndLastNode(first)->data<<endl; 
    
 // delete the last node 
    deleteLastNode(first); 
    
 // display the nodes values using printAllNodes() 
    cout << "The list after deleteing the last node \n"; 
    printAllNodes(first); 
    
 // modify the nodes values by using odd2Even2Odd method 
    odd2Even2Odd(first); 
    
 // display the nodes values using printAllNodes() 
    cout << "The list after Modifying the Nodes Values  \n"; 
    
    printAllNodes(first); 
    return 0; 
}
