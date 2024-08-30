#include<stdio.h>
int main()
{
    int arr[5] = {34, 2, 23, 100, 60};
    int key,i,flag = 0;

    printf("Enter element to search\n");
    scanf("%d",&key);

    for(i = 0; i <=5; i++)
    {
        if(arr[i] == key)
        {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");

    return 0;
}