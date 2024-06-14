#include<stdio.h>
struct books
{
	char title[20],publisher[20];
	int pages,price;
	struct books*next;
	
};
int main()
{
	struct books b1,b2,b3;
	printf("enter the title of the book 1");
	scanf("%s",b1.title);
	printf("enter the publisher of the book 1");
	scanf("%s",b1.publisher);
	printf("enter the pages of the book 1");
	scanf("%d",b1.pages);
	printf("enter the price of the book 1");
	scanf("%d",b1.price);
	printf("enter the title of the book 2");
	scanf("%s",b2.title);
	printf("enter the publisher of the book 2");
	scanf("%s",b2.publisher);
	printf("enter the pages of the book 2");
	scanf("%d",b2.pages);
	printf("enter the price of the book 2");
	scanf("%d",b2.price);
	printf("enter the title of the book 3");
	scanf("%s",b3.title);
	printf("enter the publisher of the book 3");
	scanf("%s",b3.publisher);
	printf("enter the pages of the book 3");
	scanf("%d",b3.pages);
	printf("enter the price of the book 3");
	scanf("%d",b3.price);
	
	b1.next=&b2;
	b2.next=&b3;
	
	printf("BOOK 1-%s\n%s\n%d\n%d\n",b1.title,b1.publisher,b1.pages,b1.price);
	printf("BOOK 2-%s\n%s\n%d\n%d\n",b1.next->title,b1.next->publisher,b1.next->pages,b1.next->price);
	printf("BOOK 3-%s\n%s\n%d\n%d\n",b1.next->next->title,b1.next->next->publisher,b1.next->next->pages,b1.next->next->price);
	return 0;
	
	
}