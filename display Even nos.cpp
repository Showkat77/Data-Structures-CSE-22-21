#include<stdio.h>

int main()
{
    int arr[5], i;
    printf("Enter any 5 array elements: ");
    for(i=0; i<5; i++)
        scanf("%d", &arr[i]);
    printf("\nAll Even Array elements are:\n");
    for(i=0; i<5; i++)
    {
        if(arr[i]%2==0)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}