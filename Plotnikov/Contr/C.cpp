#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//problem C var #5
struct students { char name[30]; int score; };

/*void swap(int *a, int *b)
{
	int c;
		c = *a;
		*a = *b;
		*b = c;
}*/

int compare_name(const void *a, const void *b)
{
	return(strcmp(((students*)a)->name, ((students*)b)->name));
}

int compare_score(const void *a, const void *b)
{
	if ( ((students*)a)->score != ((students*)b)->score) 
	{ 
		return(((students*)b)->score - ((students*)a)->score);
	}
	else return(strcmp(((students*)a)->name, ((students*)b)->name));
}

int main()
{
	students student[10001];

	/*for (i = 0; i <= 10001; i++)
	{
		student[i].name = "";
		student[i].score = 0;
	}*/

	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i <= (n - 1); i++)
	{
		scanf("%s", &student[i].name);
		scanf("%d", &student[i].score);
	};
	
	qsort(student, n, sizeof(students), compare_name);

	for (int i = 0; i <= (n - 1); i++)
	{
		printf("%s %d\n", student[i].name, student[i].score);
	};

	printf("\n");

	qsort(student, n, sizeof(students), compare_score);

	for (int i = 0; i <= (n - 1); i++)
	{
		printf("%s %d\n", student[i].name, student[i].score);
	};
	/*if ('a' > 'b') { printf("%c\n", student[1].name[0]); }
	else { printf("%c\n", student[1].name[1]); };*/
}