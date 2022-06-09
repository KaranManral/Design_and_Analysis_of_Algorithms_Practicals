//WAP to implement Quick Sort
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
int partition (int *a, int l, int u, int *count)// places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
{
int p = a[u];
int i = (l - 1); // Index of smaller element and indicates the right position of pivot found so far
for (int j = l; j <= u - 1; j++)
{
count[j]++;
if (a[j] < p)
{
i++;
swap(&a[i], &a[j]);
swap(&count[i],&count[j]);
}
}
swap(&a[i + 1], &a[u]);
return (i + 1);
}
void quickSort(int *a, int l, int u,int *count)
{
if (l < u)
{
int pi = partition(a, l, u, count);
quickSort(a, l, pi - 1, count);
quickSort(a, pi + 1, u, count);
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
cout<<"\nInput Array: ";
display(a,n);
quickSort(a,0,n-1,count);
cout<<"\nSorted Array: ";
display(a,n);
cout<<"\n Number of comparisons for each input:- \n"<<endl;
for(int i=0;i<n;i++)
cout<<"Comparisons for "<<a[i]<<" = "<<count[i]<<endl;
return 1;
}//main