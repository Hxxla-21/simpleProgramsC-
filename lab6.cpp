/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int countA(string str)
{
    //if the length of string = 0 then just return 0
	if (str.length() == 0)
		return 0;
	//if the length of string bigger than 0 it will reach here 
	if (str.at(0) == 'A') {
		return 1 + countA(str.substr(1, str.length()));
	}// here will continue to detect for any A's  
	else
	{
		return countA(str.substr(1, str.length()));
	}
}

int count7(int number) {
	
	if (number == 0) {
		return 0;
	}
	if (number%10 == 7 ) {
		return 1+ count7(number / 10);
		
	}
	else {
		count7(number / 10);
		
	}
}

string changeXY(string str)
{
	char ch;
	if (str.length() == 0)
		return str;
	ch = str.at(0);
	if (ch == 'x')
		return 'y' + changeXY(str.substr(1, str.length()));
	else
		return ch + changeXY(str.substr(1, str.length()));
}



int main()
{
    //for first method "countA"
    string str;
	cout << "Please enter any string: ";
	cin >> str;
	cout << "Number of A's in the String "<< str <<" is "<<countA(str)<<endl<<"\n";

    //for second method "count7"
	int num;
	cout << "Please enter any number: ";
	cin >> num;
	cout << "Number of 7's in the number " << num << " is " << count7(num) << endl << "\n";
	
	//for third method "changeXY"
	string str2;
	cout << "Please enter any string in lower case: ";
	cin >> str2;
	cout <<"Old String was "<<str2<<endl<<"New string after changing x's into y's is "<<changeXY(str2) << endl << "\n";



    return 0;
}

