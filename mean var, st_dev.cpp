#include<stdio.h>
#include<math.h>
int main()
{
   int i,n;
   float SD,sum=0,term1,mean,term2,variance,a[5];
   printf("Enter value of n : ");
   scanf("%d",&n);
   printf("\nEnter numbers : ");
   for(i=0;i<n;i++)
   {
      printf("\nNumber %d : ",i+1);
      scanf("%f",&a[i]);
      sum=sum+a[i];
   }
   mean=sum/n;
   term1=0;
   for(i=0;i<n;i++)
   {
     term2=a[i]-mean;
     term1=term2*term2;
    }
     variance=term1/n;
     SD=sqrt(variance);
     printf("\nMean of %d numbers = %f\n",n,mean);
     printf("\nVariance of %d numbers = %f\n",n,variance);
     printf("\nStandard deviation of %d numbers = %f\n",n,SD);
     return 0;
}