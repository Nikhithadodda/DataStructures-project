// program to implement the library books sorting using quick sort technique.
#include <stdio.h>
#include <stdlib.h> //standard library which includes functions involving memory allocation, process control, etc
#include <time.h> // the time.h header defines four variable types, two macro and various functions for manipulating date and time

// function to print an array 
void printBooknumbers(int books[], int a)
{
    for (int i= 0; i< a; i++)
    {
        printf("%d ",books[i]);
    }
}

// function to consider last element as pivot.. Here, place the pivot at its exact position, and place
// smaller elements to left of pivot and greater elements to right of pivot
int partition(int book[],int first,int last)
{
    int pivot = book[last]; //pivot element
    int i= (first- 1);
    for(int j = first;j<=last;j++)
    {
    	// if the current element is smaller than the pivot
        if(book[j]<pivot) 
        {
            i++; //increment the index of a smaller element
            int tmp = book[i];
            book[i] = book[j];
            book[j] = tmp;
        }
    }
    int tmp = book[i+1];
    book[i+1] = book[last];
    book[last] = tmp;
    
    return (i+1); // return the value
}

// function to implement the quick sort
void quickSort(int p[],int first,int last)
// here p is the array to be sorted, first is the starting index, last is the ending index
{
    if(first<last)
    {
        int q = partition(p,first,last); // q is the partitioning index
        quickSort(p,first,q-1);
        quickSort(p,q+1,last);
    }
}

// main function (driver code)
int main()
{
    int i;
    int j;
    int books[100]; 
    srand(time(NULL));

    for (i = 0; i < 100; i++)
    {
        books[i] = rand()%100+1;
        jump:
        for (j = 0; j <= (i - 1); j++)
        {
            if (books[j] == books[i])
            {
                books[i] = rand()%100+1;
                goto jump; // here jump statement is used to escape the section of the program
            }
        } 
    }
    printf("Before sorting : \n");
    printBooknumbers(books,100);
    // perform quicksort on data
    quickSort(books,0,100-1);
    printf("\n\nAfter Sorting : \n");
    printBooknumbers(books,100);
    return 0;
}