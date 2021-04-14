#include<stdio.h>
#include<stdlib.h>

void Counting_sort_exponent(int *arr, int length, int exp)
{
    //Stabe version

    int *output = (int*)calloc(length, sizeof(int));
    int frequency[10] = {0};
 
    //calculating frequencies
    for (int i = 0; i < length; i++)
        frequency[(arr[i] / exp) % 10]++;

    //adding frequencies
    for (int i = 1; i < 10; i++)
        frequency[i] = frequency[i] + frequency[i-1];

    //Hashing voodo
    for (int i = length-1; i >= 0; i--)
    {
        output[frequency[(arr[i] / exp) % 10] - 1] = arr[i];
        frequency[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < length; i++)
        arr[i] = output[i];
}

void Radix_sort(int *arr, int length)
{
    //find biggest number 
    int max = arr[0];
    for (int i = 1; i < length; i++)
        if (max < arr[i])
            max = arr[i];


    for(int i = 1; max / i > 0; i = i * 10)
        Counting_sort_exponent(arr, length, i);
}

int main()
{
    int arr[] = {32,  1, 1560, 959, 98, 0, 9, 4, 56776, 90998, 3, 888765};
    Radix_sort(arr, 12);
    for(int i = 0; i < 12; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}