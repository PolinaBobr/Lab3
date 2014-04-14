#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	int Value;
	List *next;
	List *prev;
	int number;
}Catalog;

Catalog *Begin ()
{
 int n, i;
 Catalog *new_Catalog=new Catalog;
 List *first;
 new_Catalog->next=0;
 new_Catalog->prev=0;
 printf("\n Enter number of cells you want to create \n\t");
 scanf ("%d", &n);
 first=new_Catalog;
 printf("\n Enter elements \n\t");

 for (i=0; i<n; ++i)
 {
  new_Catalog->number=i;
  scanf("%d", &new_Catalog->Value);
  new_Catalog->next=new Catalog;
  new_Catalog->next->prev=new_Catalog;
  new_Catalog->next->next=0;
  new_Catalog=new_Catalog->next;
 }

 first->prev=new_Catalog->prev;
 new_Catalog=first;
 return new_Catalog;
}

void print(Catalog *copyCatalog)
{
	int b=0;
	while (copyCatalog->number!=0) 
		copyCatalog=copyCatalog->prev;

	printf ("\n Your list is \n\t");
	do
	{
		if (b) copyCatalog=copyCatalog->next;
		printf("%d", copyCatalog->Value);
		b=1;
	} while (copyCatalog->number <= copyCatalog->next->number);
}

void AddToCatalog (Catalog *copyCatalog)
{
	Catalog *New=new Catalog;

	int numb;
	printf ("\n Enter number of cell after what new element will be created \t");
	scanf ("%d", &numb);
	--numb;

	while (copyCatalog->number!=numb) copyCatalog=copyCatalog->next;
	New->number=numb+2;

	printf("\n Enter value \t ");
	scanf ("%d", &New->Value);
	New->prev=copyCatalog;
	New->next=copyCatalog->next;
	New->prev->next=New;	
	New->next->prev=New;
	while (New->number)
	{
		New->number=New->prev->number+1;
		New=New->prev;
	}
}

void DeleteFromCatalog (Catalog *copyCatalog)
{
	int numb;
	Catalog *temp;
	printf("\n Enter number of cells you want to change \t");
	scanf ("%d", &numb);
	--numb;

	while (copyCatalog->number!=numb) copyCatalog=copyCatalog->next;
	temp=copyCatalog->next;
	copyCatalog=copyCatalog->prev;
	copyCatalog->next=temp;
	copyCatalog->next->prev=copyCatalog;
}

int main()
{
 int i=0;
 Catalog *Catalog1=new List;
 Catalog1=Begin();
 print(Catalog1);
 AddToCatalog(Catalog1);
 print(Catalog1);
 DeleteFromCatalog(Catalog1);
 print(Catalog1);
 
 system ("pause");
 return 0;

}
