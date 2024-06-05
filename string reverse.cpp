#include<stdio.h>
#include<string.h>
int main(){
   char str[25];
   int i,j,l;

   printf("Enter the string:");
   scanf("%s",str);

   l=0;
   for(i=0;str[i]!='\0';i++)
   {
   	l++;
   }
   printf("actual string : %s\n",str);
   for(i=0,j=l-1;i<j;i++,j--)
   {
   	char temp=str[i];
   	str[i]=str[j];
   	str[j]=temp;
   }
   printf("reversed string : %s\n",str);
   return 0;
}