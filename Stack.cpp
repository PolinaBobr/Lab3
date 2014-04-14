#include <stdlib.h>
#include <stdio.h>

int max=1, stage;
int *Stack;

void pushup(int i)
{
  ++stage;
  if (stage > max)
  {
	  realloc(Stack,stage*sizeof(int));
	  max=stage;
  }
  Stack[stage-1]=i;
}

int popup()
{
 --stage;
 return Stack[stage];
}

void Print(int Numb)
{
	printf("\n Your list is \n");

	for (int i=0; i<Numb; ++i) 
		printf ("%d\t", Stack[i]);
}

void main()
{
	int Numb=0, dlt=0, temp=0;
	Stack=(int *)calloc(65536,sizeof(int));
	printf("\n How many elements you want to push up? \n");
	scanf ("%d", &Numb);
	printf("\n Enter your elements \n");

	for (int i=0; i<Numb; ++i)
	{
		scanf ("%d", &temp);
		pushup(temp);
	}

	Print(Numb);
	printf ("\nHow many elements you want to pop up? \n");
	scanf ("%d", &dlt);
	printf("\n Your elements are \n");

	for (int i=0; i<dlt; ++i)
	{
		if (!stage) 
		{
			printf("\nError! Stack is empty! \n");
			break;
		}
		else printf ("%d\t", popup());
	}
	
	free(Stack);

	system ("pause");

}