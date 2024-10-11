#include <stdio.h>

//Function that sorts an array with the bubble sort method
void bubbleSort(int array[], int arrayLength)
{
    //Using two for-loops to compare elements in the array
    //The first iteration of the loop outside will look like this: i=0 j=0, i=0 j=1, i=0 j=2 etc.
    for (int i = 0; i < arrayLength-1; i++)
    {
        //The size of j will decrease for each time the outside loop iterates
        //Allowing us to place the largest numbers more to the right of the array
        for (int j = 0; j < arrayLength-i-1; j++)
        {
            if (array[j] > array[j+1]) //If element on index j is greater then element on index j+1 -> switch
            {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

//Function that prints elements in an array
void printArray(int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {2,5,3,6,7,5,1};
    int arrayLength = sizeof(array)/sizeof(array[0]); //Finding the length of the array

    printf("Unsorted array:\n");
    printArray(array, arrayLength);

    bubbleSort(array, arrayLength);

    printf("Sorted array:\n");
    printArray(array, arrayLength);

    return 0;
}