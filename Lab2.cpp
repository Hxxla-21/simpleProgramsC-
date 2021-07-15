/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
#include<cstdlib>
#include <algorithm>
#include<time.h>


using namespace std;

int linearSearch(int array[], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (key == array[i])
			return i; //If found, return index of that element
	}
	return -1; //if not found, return -1
}

int binarySearch(int array[], int size, int key)
{
	int low = 0; 
	int high = size - 1; 
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == array[mid])
			return mid;
		else if (key < array[mid]) // change
			high = mid - 1;
		else // change low
			low = mid + 1;
	}
	return -1; // if key not found above
}


void fillArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = (rand() % size);
	}
}

int main() {
    
	int key;
	int test[100000];
	fillArray(test,100000);


	cout << "\nEnter number :";
	cin >> key;

	int resultli = linearSearch(test, 100000, key);
	(resultli == -1) ? cout << "in linearSearch not found \n"
		: cout << "in linearSearch found at index : " << resultli <<"\n";
		
	clock_t start2 = clock();
	int y = linearSearch(test, 1000, key);
	clock_t stop2 = clock();
	double totalTime2 = (double(stop2) - double(start2)) / CLOCKS_PER_SEC;
	cout << "total time in linearSearch : " << totalTime2 << "\n";


	//sort
	sort(test, test + 1000);

	int resultby = binarySearch(test, 100000, key);
	(resultby == -1) ? cout << "in binarySearch not found\n "
		: cout << "in binarySearch found at index : " << resultby << "\n";

	clock_t start = clock();
	int x = binarySearch(test, 1000, key);
	clock_t stop = clock();
	double totalTime = (double(stop) - double(start)) / CLOCKS_PER_SEC;
	cout << "total time in binarySearch : " << totalTime<<"\n";
	
	return 0;
}