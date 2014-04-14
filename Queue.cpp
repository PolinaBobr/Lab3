#include <stdlib.h>
#include <stdio.h>


int max=1, stage;
int *Queue;

void Add(int i)
{
  ++stage;
  if (stage > max)
  {
	  realloc(Queue,stage*sizeof(int));
	  max=stage;
  }

  for (i=1; i<stage; ++i) 
	  Queue[stage-i]=Queue[stage-i-1];
  Queue[0]=i;
}

int Get()
{
 --stage;
 return Queue[stage];
}

void Print(int Numb)
{
	printf("\n Your queue is \n");

	for (int i=0; i<Numb; ++i) 
		printf("%d\t", Queue[i]);
}

void main()
{
	int Numb=0, dlt=0, temp=0;

	Queue=(int *)calloc(65536,sizeof(int));

	printf("\n How many elements you want to add? \n");
	scanf ("%d", &Numb);
	printf("\n Enter your elements \n");

	for (int i=0; i<Numb; ++i)
	{
		scanf ("%d", &temp);
		Add(temp);
	}

	Print(Numb);
	printf("\n How many elements you want to get? \n");
	scanf("%d", &dlt);
	printf("\n Your elements are \n");

	for (int i=0; i<dlt; ++i)
	{
		if (!dlt) 
		{
			printf ("\n Error! Queue is empty! \n");
			break;
		}
		else printf("%d\t", Get());
	}
	
	free (Queue);

	system ("pause");

}
