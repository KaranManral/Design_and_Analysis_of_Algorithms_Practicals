//WAP to implement Bubble Sort
#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;
void getArray(int *a,int n)
{
unsigned seed=time(0);
int *temp=new int[970];
for(int i=0;i<970;i++)
temp[i]=i+30;
shuffle(temp,temp+970,default_random_engine(seed));
for(int i=0;i<100;i++)
a[i]=temp[i];
}
void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
void bubbleSort(int *a,int n,int *count) //Function for bubble sort
{
for(int i=0;i<n-1;i++) //Outer loop
{
for(int j=0;j<n-i-1;j++) //Inner loop
{
count[j]++;
if(a[j+1]<a[j])
{
swap(&a[j],&a[j+1]);
swap(&count[j],&count[j+1]);
}
}
}
}
void display(int *a,int n)
{
for(int i=0;i<n;i++) //Printing sorted array
cout<<a[i]<<" ";
cout<<endl;
}
int main()
{
int n;
cout<<"Enter the size of array"<<endl;

cin>>n;
int *a=new int[n];
int count[n]={0};
getArray(a,n);
cout<<"Input Array: ";
display(a,n);
bubbleSort(a,n,count);
cout<<"Sorted Array: ";
display(a,n);
cout<<"\n Number of comparisons for each input:- \n"<<endl;
for(int i=0;i<n;i++)
cout<<"Comparisons for "<<a[i]<<" = "<<count[i]<<endl;
return 1;
}//main