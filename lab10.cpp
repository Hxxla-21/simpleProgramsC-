/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>


using namespace std;

class Student {

private:

    string name;
    int id;
    double gpa;
    Student* next;

public:

    // Constructors
    Student()
    {
        name = "";
        id = 0;
        gpa = 0;
        next = NULL;
    }


    Student(Student* next, string name, int id,
        double gpa)
    {
        this->name = name;
        this->id = id;
        this->gpa = gpa;
        this->next = next;
    }

    //Getters
    int getid()
    {
        return id;
    }

    Student* getNext()
    {
        return next;
    }
    double getGPA()
    {
        return gpa;
    }
    string getName()
    {
        return name;
    }

    //Setters
    void setid(int id)
    {
        this->id = id;
    }
    void setGPA(double gpa)
    {
        this->gpa = gpa;
    }
    void setName(string name)
    {
        this->name = name;
    }

    void setNext(Student* next)
    {
        this->next = next;
    }
};
class StudentList {

public:
    Student* head;

public:
    // Constructor
    StudentList()
    {
        head = NULL;
    }

    void printList() {
        //to traverse we need a help pointer(helpPtr)
        Student* helpPtr = head;
        // we make Traverse to correct insertion point
        while (helpPtr != NULL) {
            // Print the data value of the node
            cout << "Student Name:" << helpPtr->getName() << endl;
            cout << "Student ID:" << helpPtr->getid() << endl;
            cout << "Student GPA:" << helpPtr->getGPA() << endl;
            cout << "\n";
            // Step one node over
            helpPtr = helpPtr->getNext();
        }
        cout << endl;
    }

    void addStudent(int id, string name, double gpa)
    {
        
        Student* helperpoint = new Student();
        helperpoint->setid(id);
        helperpoint->setGPA(gpa);
        helperpoint->setName(name);
        Student* temp = head;

        // IF there is no list, newNode will be the first node, so just return it
        if (head == NULL || head->getid() >= helperpoint->getid())
        {
            helperpoint->setNext(head);
            head = helperpoint;
            return;

        }
        else
        {
            while (temp->getNext() != NULL && temp->getNext()->getid() < helperpoint->getid())
            {
                temp = temp->getNext();
            }
           
            helperpoint->setNext(temp->getNext());
            temp->setNext(helperpoint);

        }

    }

    void studentInfo(int id) {
        Student* helpPtr = head;
        
            while (helpPtr != NULL) {
                if (helpPtr->getid() == id) {
                    cout << "Student found\n\n";
                    cout << "Student Name:" << helpPtr->getName() << endl;
                    cout << "Student ID:" << helpPtr->getid() << endl;
                    cout << "Student GPA:" << helpPtr->getGPA() << endl;
                    break;
                }
                helpPtr = helpPtr->getNext();
            }
           
    }

    bool isEmpty()
    {
        if (head == NULL) {
            return true;
       }
        else
        {
            return false;
        }
    }
    bool isfound(int id)
    {
        Student* helpPtr = head;
        while (helpPtr != NULL) {
            if (helpPtr->getNext()->getid() == id) {
                return true;
            }
            helpPtr = helpPtr->getNext();
        }
        return false;
        
    }

    void deleteStudent(int id) {
        if (head->getid() == id)
            head = head->getNext();
        else  
        {
            Student* helpPtr = head;
            // also here we made Traverse to correct deletion point
            while (helpPtr->getNext() != NULL) {
                if (helpPtr->getNext()->getid() == id) {
                    helpPtr->setNext(helpPtr->getNext()->getNext());
                    break;
                }
                helpPtr = helpPtr->getNext();
            }
        }
    }


    void findLargest() {
        Student* helpPtr = head;
        Student* largest = head;
        double max = 0;
        while (helpPtr != NULL) {
            if (helpPtr->getGPA() > max) {
                max = helpPtr->getGPA();


            }
            helpPtr = helpPtr->getNext();
        }

        while (largest != NULL) {
            if (largest->getGPA() == max) {
                cout << "Student Name:" << largest->getName() << endl;
                cout << "Student ID:" << largest->getid() << endl;
                cout << "Student GPA:" << largest->getGPA() << endl;
                cout << "\n";
            }
            largest = largest->getNext();
        }

        
    }

    void reversePrintlist(Student* next) {
        if (next == NULL) {
            return;
        }
        else {
            reversePrintlist(next->getNext());
            cout << "Student Name:" << next->getName() << endl;
            cout << "Student ID:" << next->getid() << endl;
            cout << "Student GPA:" << next->getGPA() << endl;
            cout << "\n";


        }

    }
  
};


int main()
{
    int choice;
    string name1;
    string name2;
    int id;
    double gpa;
    int studintid;
    int deletedstu;

    StudentList* myList = new StudentList();
    do {
        cout << "********************************************" << endl << "***** Name: Hla Mohammed Almakhlafi      *****" << endl
            << "***** ID: 1911033                      *****" << endl << "***** Section: SEB                      *****" << endl;
        cout << "********************************************" << endl << "******   Student Management System    ******" << endl << "******            Main Menu           ******" << endl <<
            "********************************************" << endl;

        cout << "Press '1' to ADD STUDENT" << endl
            << "Press '2' to STUDENT INFO" << endl
            << "Press '3' to DELETE STUDENT" << endl
            << "Press '4' to FIND LARGEST" << endl
            << "Press '5' to PRINT LIST" << endl
            << "Press '6' to REVERSE PRINTLIST" << endl
            << "Press '7' to EXIT SYSTEM" << endl << "\n" << "********************************************" << endl;

        cout << "Enter a Number from the menu (1-7):";

        cin >> choice;


        switch (choice) {
        case 1:
            cout <<"\n********************************************\n"
                <<"****   The First Command ADD STUDENT    ****\n"
                <<"********************************************\n";
            cout << "Enter Student Name:";
            
            cin.ignore();

            getline(cin, name1);

            cout << "Enter Student ID:";
            cin >> id;
            cout << "Enter Student GPA:";
            cin >> gpa;
            myList->addStudent(id, name1, gpa);
            cout << "The Student was successfully added to the List\n\n";
            break;
        case 2:
            cout << "********************************************\n"
                << "**** The Second Command STUDENT INFO ****\n"
                << "********************************************\n";
            
            
            if (myList->isEmpty()==false) {
                cout << "Enter Student Id :";
                cin >> studintid;
                myList->studentInfo(studintid);
                
               
            }
            else
            {
                cout << "The List is Empty"<<endl;
            }

            break;
        case 3:
            cout << "********************************************\n"
                << "**** The Third Command DELETE STUDENT ****\n"
                << "********************************************\n";

            if (myList->isEmpty() == false) {
                
                cout << "Enter Student Id :";
                cin >> deletedstu;

                myList->deleteStudent(deletedstu);
                cout << "The Student With ID " << deletedstu << " was successfully deleted from the List "<<endl;
            }
            else
            {
                cout << "The List is Empty"<<endl;
            }
            break;
        case 4:
            cout << "********************************************\n"
                << "****   The Forth Command FIND LARGEST    ****\n"
                << "********************************************\n";
            if (myList->isEmpty() == false) {
                myList->findLargest();
            }
            else
            {
                cout << "The List is Empty"<<endl;
            }
            break;
        case 5:
            cout << "********************************************\n"
                << "****   The Fifth Command Print List    ****\n"
                << "********************************************\n";

            if (myList->isEmpty() == false) {
                myList->printList();
            }
            else
            {
                cout << "The List is Empty"<<endl;
            }
            
            break;
        case 6:
            cout << "********************************************\n"
                << "****  The Sixth Command REVERSE PRINTLIST   ****\n"
                << "********************************************\n";
            if (myList->isEmpty() == false) {
                Student* helpPtr = myList->head;
                myList->reversePrintlist(helpPtr);
            }
            else
            {
                cout << "The List is Empty"<<endl;
            }
            break;
        case 7:
            cout << "...Exiting the System....\n"<<"...Have a Nice Day....";
            break;
        default:
            cout << "Wrong Number!! Enter agine"<<endl;

        }

    } while (choice != 7);


    return 0;
}

