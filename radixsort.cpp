// WAP to implement Radix Sort

#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

int findMax(int a[], int n)
{
int max = a[0];
for (int i = 1; i < n; i++)
if (a[i] > max)
max = a[i];
return max;
}

void getArray(int *a, int n)
{
unsigned seed = time(0);
int *temp = new int[970];
for (int i = 0; i < 970; i++)
temp[i] = i + 30;
shuffle(temp, temp + 970,
default_random_engine(seed));
for (int i = 0; i < 100; i++)
a[i] = temp[i];
}

void countingSort(int a[], int n, int place)
{
const int max = 10;
int output[n];
int count[max];

for (int i = 0; i < max; i++)
count[i] = 0;

// Calculate count of elements
for (int i = 0; i < n; i++)
count[(a[i] / place) % 10]++;

// Calculate cumulative count
for (int i = 1; i < max; i++)
count[i] += count[i - 1];
// Place the elements in sorted order
for (int i = n - 1; i >= 0; i--)
{
output[count[(a[i] / place) % 10] - 1] = a[i];
count[(a[i] / place) % 10]--;
}

for (int i = 0; i < n; i++)
a[i] = output[i];
}

void radixSort(int a[], int n)
{

int max = findMax(a, n);

for (int place = 1; max / place > 0; place = place *
10)
countingSort(a, n, place);
}

void display(int *a, int n)
{
for (int i = 0; i < n; i++) // Printing sorted array
cout << a[i] << " ";
cout << endl;
}

int main()
{
int n;
cout << "Enter the size of array" << endl;
cin >> n;
int *a = new int[n];
getArray(a, n);
cout << "Input Array: ";
display(a, n);
radixSort(a, n);
cout << "Sorted Array: ";
display(a, n);
return 1;
} // main