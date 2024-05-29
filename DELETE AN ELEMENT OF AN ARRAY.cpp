#include <stdio.h>
int main()
{
    int i, n, index, A[10];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    for (i = 0; i < n; i++)
    {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    printf("Enter the index of the element to be deleted: ");
    scanf("%d", &index);
    if (index >= n+1)  
    {  
        printf (" \n Deletion is not possible in the array.");  
    }  
    else  
    {  
        for (i = index; i < n - 1; i++)
            A[i] = A[i + 1];
            printf("The array after deleting the element is: ");
        for (i = 0; i < n - 1; i++)
            printf("%d ", A[i]);
        return 0;
    }
}