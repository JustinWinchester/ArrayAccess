/* ***************************************************************
*	Author:		Zhao
*	Date:		Jan. 9, 2020
*	Class:		Cs3003
*	Synposis:	This program fills an array with 100 integers
			and then find the max and min.  Also allow the
			user to enter a positive, and then program returns 
			its recursive value.
********************************************************************** */
//libraries
#include <iostream> //cin/cout
#include <cstdlib> //for rand() function
#include <ctime> //for srand() function
#define SIZE 100

using namespace std;

// function prototypes
void find_min_min2(int[]);
void fill_array(int[], int[]);
void print_array(int[]);
void find_max_min(int[]);
void bubble_sort(int[]);
void bubble_sort2(int[]);
int imagine(int);

int main()
{
	int arr[SIZE], arr2[SIZE], num;

	fill_array(arr, arr2);

	print_array(arr);
	find_max_min(arr);
	bubble_sort(arr);
	print_array(arr);
	cout<<"\nEnter a positive integer: ";
	cin >> num;
	cout<<"The value is: "<<imagine(num)<<endl<<endl;

	print_array(arr2);
	find_max_min(arr2);
	bubble_sort2(arr2);
	print_array(arr2);
	cout<<"\nEnter a positive integer: ";
	cin >> num;
	cout<<"The value is: "<<imagine(num)<<endl;

	find_min_min2(arr);
	return 0;
}
//fill the array with positive numbers between 1 and 100
void fill_array(int arr[], int arr2[])
{
	int i;
	srand(time(NULL));//use system time as seed
	for ( i = 0; i < SIZE; i++)
	{
		arr[i] = rand()%100+1;
		arr2[i] = arr[i];
	}
}
//print the array
void print_array(int arr[])
{
	int i;
	for(i = 0; i < SIZE; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//find max and min from the array
void find_max_min(int arr[])
{
	int max, min, i;
	max = min = arr[0];
	for(i = 1; i < SIZE; i++)
	{
		if(arr[i] > max)
			max = arr[i];
		else if(arr[i] < min)
			min = arr[i];
	}

	cout<<"\nMax is: "<<max<<endl;
	cout<<"\nMin is: "<<min<<endl;
}

void bubble_sort(int arr[])
{
	int i, j;
	int cnt = 0;
	for ( i = 0; i < SIZE; i++)
	{
		for(j = SIZE-1; j > i; j--)
		{
			if(arr[j] < arr[j-1])//not in order
				swap(arr[j], arr[j-1]); //swap them
			cnt++;
		}
	}
	cout<<"\nNumber of comparisons was: "<<cnt<<endl;

}
void bubble_sort2(int arr[])
{
	int i, j;
	int cnt = 0;
	bool sorted = false;

	for ( i = 0; i < SIZE-1&&!sorted; i++)
	{
		sorted = true;
		for(j = SIZE-1; j > i; j--)
		{
			if(arr[j] < arr[j-1])//not in order
			{
				swap(arr[j], arr[j-1]); //swap them
				sorted = false;
			}
			cnt++;
		}
	}
	cout<<"\nNumber of comparisons was: "<<cnt<<endl;

}
int imagine(int n)
{
	if( n == 0)
		return 1;
	else
		return n * imagine(n-1);
}
void find_min_min2(int arr[])
{
	int min, min2, i;
	if(arr[0]<arr[1])
	{
		min = arr[0];
		min2 = arr[1];
	}
	else
	{
		min = arr[1];
		min2 = arr[0];
	}

	for ( i = 2; i < SIZE; i++)
	{
		if(arr[i] < min)
		{
			min2 = min;//update min2 
			min = arr[i];//update min
		}
		else if( arr[i] < min2)
		{
			min2 = arr[i];//update min2 only
		}
	}
	cout<<"\nMin is: "<<min<<endl;
	cout<<"\nMin2 is: "<<min2<<endl;
}

