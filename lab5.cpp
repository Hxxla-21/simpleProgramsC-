/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;


int sumEvenNums(int num) {
    //if the number = 0
	if (num == 0) {
		return 0;
	}//if the number even
	else if (num % 2 == 0) {
		return  num + sumEvenNums(num - 1);

	}//if the number odd
	else
		return sumEvenNums(num - 1);
}


int subNums(int num) {

	if (num==1) {
		return 1;
	}
	else if (num > 0) {
		return   subNums(num - 1) - num;

	}
}

void ArrayReverse(int array[], int firstIn, int lastIn) { 
   
    int temp; 
    temp = array[firstIn]; 
    array[firstIn] = array[lastIn]; 
    array[lastIn] = temp; 
 
   
    if (firstIn == lastIn || firstIn + 1 == lastIn) 
        return; 
 
   
    if (firstIn < lastIn) { 
        firstIn = firstIn + 1; 
        lastIn = lastIn - 1; 
    } 
   ArrayReverse(array, firstIn, lastIn); 
} 


void RevlntRecursive(int n) {
	if (n < 10) {
		cout << n;
	}
	else {
		cout << n % 10;
		RevlntRecursive(n / 10);

	}
}

 


int main()
{
    int num;
    int sub;
    int n;
    int length = 0;
    
    //fisrt method "sumEvenNums"
	cout << "Enter a non-negative number: ";
	cin >> num;
	cout << "sum of all even numbers from " << "1 " << "to " << num << " is: " << sumEvenNums(num) << "\n";
	
	
	//second method "subNums"
	cout << "Enter a non-negative number:";
	cin >> sub;
	cout << "the subtraction of all numbers from 1 to " << sub << " is: " << subNums(sub) << "\n";
    
    
    //third method "ArrayReverse"
    cout << "How many elements in the array ? "; 
    cin >> length; 
    cout << "Enter the elements of array "<< endl;
 
    int arr[length]; 
    for (int i = 0; i < length; i++) { 
        cout << "Enter element " << i + 1 << "--> "; 
        cin >> arr[i]; 
    } 
 
    cout << "Array elements before reversing are "; 
    for (int i = 0; i < length; i++) 
        cout << arr[i] << ", "; 
    cout << endl; 
 
    ArrayReverse(arr, 0, length - 1); 
 
    cout << "Array elements after reversing are "; 
    for (int i = 0; i < length; i++) 
        cout << arr[i] << ", "; 
    cout << endl; 
 
    
    //fourth method "RevIntRecursive"
	cout << "What number do you want to reverse the digits of : ";
	cin >> n;
	cout << ">reversDigits(" << n << ") is ";
	RevlntRecursive(n);
    
}



