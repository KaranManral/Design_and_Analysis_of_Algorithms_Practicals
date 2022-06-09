//WAP to implement Insertion Sort
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
void insertionSort(int *arr, int n,int *count)
{
int i, j;
int key,key1;
for (i=1;i<n;i++)
{
int temp=0;
key=arr[i];
key1=count[i];
j=i-1;
count[j]++;
while (j>=0&&arr[j]>key)
{
if(temp>0)
count[j]++;
arr[j+1]=arr[j];
count[j+1]=count[j];
j=j-1;
temp++;
}
arr[j+1]=key;
count[j+1]=key1;
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
insertionSort(a,n,count);
cout<<"Sorted Array: ";
display(a,n);
cout<<"\n Number of comparisons for each input:- \n"<<endl;
for(int i=0;i<n;i++)
cout<<"Comparisons for "<<a[i]<<" = "<<count[i]<<endl;
return 1;
}//main