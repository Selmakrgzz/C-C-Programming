#include <stdio.h>

void compare(int firstArray[], int secondArray[], int firstArray_length)
{
    for (int i = 0; i < firstArray_length; i++)
    {
        if (firstArray[i] == secondArray[i])
        {
            printf("Element %d in array 1 and array 2 are equal: %d\n", i, firstArray[i]);
        } else {
            printf("Element %d in array 1 and array 2 are not the same: array 1 = %d, array 2 = %d\n", i, firstArray[i], secondArray[i]);
        }
    }
}

int main()
{
    int firstArray[] = {3,2,6,8,4,6};
    int secondArray[] = {7,5,3,8,3,2};

    int firstArray_length = sizeof(firstArray)/sizeof(firstArray[0]);
    
    compare(firstArray, secondArray, firstArray_length);
    
    return 0;
}