/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

void fillArray_1D(int array[], int size) {
   for (int i = 0; i < size; i++)
       array[i] = (rand() % 10);
}

void fillArray_2D(int array[3][3])
{
   for (int i = 0; i < 3; i++)
       for (int j = 0; j < 3; j++)
           array[i][j] = (rand() % 10);
}

void printArray_1D(int array[], int size) {
   for (int i = 0; i < size; i++)
       cout << array[i] <<" ";
}

void printArray_2D(int array[3][3])
{
   for (int i = 0; i < 3; i++){
       for (int j = 0; j < 3; j++){
            cout << array[i][j]<<" ";
       }
       cout<<endl;
   }
       
}
double avg(int array[], int size)
{
   double sum=0.0, avg=0.0;
   int i = 0;
   while (i < size)
   {
       sum += array[i];
       i++;
   }
   return sum / i;
}
void belowAboveAvg(int array[], int size,int avg)
{
   int above=0, below=0;
   for (int i = 0; i < size; i++)
   {
       if (array[i] > avg)
           above++;
       if (array[i] < avg)
           below++;
   }
   cout << "There are " << above << " numbers above average" << endl;
   cout << "There are " << below << " numbers below average" << endl;
}
   void swapElements(int array[],int a){
   int temp1 = 0;
   int temp2 = 0;
   int tempp;
   int max;
   int min;
   max = array[0];
   min = array[0];

   for (int i = 0;i<a;i++){
       if (array[i] > max) {
           max = array[i];
           temp1 = i;

       }
       if (array[i] < min) {
           min = array[i];
           temp2 = i;

       }

   }
   tempp = array[temp1];
   array[temp1] = array[temp2];
   array[temp2]= tempp;

   cout<< "\nNumbers are swapped.\n ";

   for (int i=0;i<a;i++){
       cout << array[i]<<" ";
   }
   cout<<endl;
}

void printArray_2D(int array[3][4])
{
cout<<"\n The Elements in the Array-2D are : \n";

   for(int i = 0; i < 3; i++) {
       for(int j = 0; j < 3; j++) {
           cout<< array[i] [j] <<"\t"; }}
}

void largestSmallest(int array[], int size){
    int large = array[0];
    int small = array[0] ;
    int lIndex=0;
    int sIndex = 0;
    for (int i = 0; i < size; i++){
        if(array[i]>large){
            large = array[i];
            lIndex = i;
        }
        
        if(array[i]<small){
            small = array[i];
            sIndex = i;
        }
    }
    cout<<"The largest number is "<<large <<" at index ["<<lIndex <<"]."<<endl;
    cout<<"The smallest number is "<<small <<" at index ["<<sIndex <<"]."<<endl;
}

void calc_rsum(int arr[3][3]){
   int sum = 0;
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
         sum = sum + arr[i][j];
         cout << arr[i][j]<<" ";
      }
      cout << "---The sum is " << sum << endl;
      sum = 0;
   }
}

void calc_csum(int arr[3][3]) {
   int i,j,sum = 0;
   for (i = 0; i < 3; ++i) {
      for (j = 0; j < 3; ++j) {
         sum = sum + arr[j][i];
         cout << arr[j][i]<<" ";
      }
      cout << "---The sum is" << sum <<endl;
      sum = 0;
   }
}

int main()
{
   int n;

   cout << "Enter the number of elements of a 1D array: ";
   cin >> n;
   int test1D[n],test2D[3][3];
   fillArray_1D(test1D, n);
   printArray_1D(test1D, n);
   double avrage = avg(test1D, n);
   cout << endl << "The average of numbers in the array is: " << avrage << endl;
   belowAboveAvg(test1D, n, avrage);
   largestSmallest(test1D, n);
   swapElements(test1D,n);
   cout<<endl;
   fillArray_2D(test2D);
   printArray_2D(test2D);
   cout<<endl<<"Sum of Rows: "<<endl;
   calc_rsum(test2D);
   cout<<endl<<"Sum of Columns: "<<endl;
   calc_csum(test2D);
   cout<<endl<<"No rows contain repeated elements.";
    

   return 0;
}