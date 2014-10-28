#include <stdio.h>
#include <math.h>
#include <assert.h>


/*1. Find the minimal common multiple Var 3 (A) */

long MCM (long number1, long number2) // Minimal common multiple
{
   long z; // The answer for (number1,number2)
   if (number1 > number2)
       z = number1;
   else z = number2;

   while (!( (z%number1 == 0) && (z%number2 == 0) )) z++;

   return z;
}

void Minimal_common_multiple ()
{
   long a = 0, b = 0, c = 0;
   scanf("%ld %ld %ld", &a, &b, &c);
   assert(a > 0 && b > 0 && c > 0);
   printf("\n%ld", MCM(MCM(a,b),c));
}




/*2. Transposition of a square matrix Var 2 (A) */


void Transposition_Matrix()
{
    long c = 0, a[50][50] = {};
    int i = 0, j = 0, n = 0;

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            a[i][j]=0;  // putting zeroes

    scanf("%d", &n);
    assert(n>0 && n<=50);

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            scanf("%ld", &a[i][j]); // input of the numbers

    for (i=0; i<n; i++)
    for (j=i; j<n; j++)  // transposition itself
        {
        c=a[i][j];
        a[i][j]=a[j][i];
        a[j][i]=c;
    }

    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
            printf("%ld ", a[i][j]);
        printf("\n");
    }
}





/* 3. Find numbers which dividers are not squares Var 6 (C) */


void Free_num ()
{
    int n = 0, i = 0, flag = 0;
    long number=0, j = 0;

    scanf("%d", &n);
    assert(n>0 && n<=200);
    for (i=0; i<n; i++)
    {
        flag=0;
        scanf("%ld", &number);
        assert(number>=1);
        for (j=2; j<=sqrt(number); j++)
        {
            if (number%(j*j)==0) // check the division on the j^2
            {
              flag = 1; // if numb does not meet the condition tasks
              break;
            }
        }
        if (flag == 0) printf("%ld ", number);
    }
}



/*4. Find simple numbers Var 1 (A)*/


int Simple (long number) // check the number  | 1 - simple; 0 - not;
{
    int j, flag=1;
    if (number == 1) return 0;
    for (j=2; j < sqrt(number)+1; j++)
        if (number%j == 0)
        {
            flag = 0;
            break;
        }
    return flag;
}

void Simple_numbers()
{
    int n, i;
    long number;

    scanf ("%d", &n);
    assert(n>0 && n<10000);
    for (i=0; i < n; i++)
    {
        scanf ("%ld", &number);
        assert(n>=1);
        if ( Simple(number) == 1 ) printf ("%ld ", number);
    }
}



/* 5. Find N-th simple number Var 2 (C)*/


void N_simple()
{
    int n = 0, i = 1;
    long numb = 1;

    scanf("%d", &n);
    assert(n > 0 && n <= 10000);
    do {
        numb++;
        if ( Simple(numb) == 1 ) i++; // use function "simple" which is described above | 1 - simple; 0 - not;
    }
    while (i < n);
    printf("%ld", numb);
}


/*6. Check out whether the mass can be measured Var 1 (C)*/


void Weight()
{
    long weight = 0;

    scanf("%ld", &weight);
    assert(weight>=0);
    while( weight > 1)
    {
        if ( weight%4==2 ) break; // Weight cannot be measured
        weight/=4;
    }
    if (weight == 1)
        printf("YES"); // Measuring is possible
    else
        printf("NO");
}


/*7. Put the number for the sum of four squares Var 3 (C)*/

void The_sum_of_4_squares()
{
    long number = 0;
    long a = 0, b = 0, c = 0, d = 0;
    int flag = 0; // indicator possible decomposition
    float e = 0;

    scanf("%ld", &number);
    assert(number>0);
    e = floor(sqrt(number));
    for (a=e; a>1 & flag == 0; a--) // search from e downto 1
        for (b=e; b>=0 & flag == 0; b--) // search from e downto 0
            for (c=e; c>=0 & flag == 0; c--) // search from e downto 1
                for (d=0; d<e & flag == 0; d++) // search from 0 to e because d<<numb
                    if (d*d+c*c+b*b+a*a == number)
                    {
                        printf("%ld %ld %ld %ld", d*d, c*c, b*b, a*a);
                        flag = 1;
                    }
}


/*8. Find the sum of range a(k) = x^k/k! Var 5 (A)*/

void Sum_Of_Range()
{
    int n = 0; // limit
    int k = 0; // counter
    double x, sum=1, y=1; // y - next member of range
    // s = 1 because first member = 1

    scanf("%d %lg", &n, &x);
    assert(n>0 && x>-10.0 && x<10.0);
    for (k=1; k<=n; k++) // sum from 1 to n members of range
    {
        y*=x/k;
        sum+=y;
    }
    printf("%.6lg", sum);

}


/*9. Find the sum of dividers Var 5 (B) */


void Sum_Of_Dividers()
{
    long number = 0;
    long i = 0, sum = 1; // every number divided by 1

    scanf("%ld", &number);
    assert(number>0);
    for(i=2; i<=number/2; i++) // dividers of number can't be more than numb/2
    if (number%i == 0) sum+=i;

    if (number != 1) sum+=number; // if number != 1, it can be divided by itself
    printf("%ld", sum);
}


/* 10. Sorting students. Alphabetically, then by marks Var 5 (C) */

void Organize_students()
{
    struct student // declare the new type - student
    {
        char name[10];
        int mark;
    };
    struct student list[10000];
    int i, j, k; // counters
    int n;

    scanf("%d", &n);
    assert(n>0 && n<10000);
    for (i=0; i<n; i++)
    {
        scanf("%s %d", list[i].name, &list[i].mark);
        assert(list[i].mark>=1 && list[i].mark<=10);
    }

    // sort names alphabetically (bubble method)
    for (i=0; i<n-1; i++)
        for (j=0; j<n-i-1; j++)
        {
            k=-1; // counter of letters in the name
            do
            {
                k++;
                if (list[j].name[k] > list[j+1].name[k]) // compare names in k-letter
                {
                    list[n]=list[j];
                    list[j]=list[j+1];
                    list[j+1]=list[n];
                }
            } while ( list[j].name[k] == list[j+1].name[k] ); // if k-letters are the same, repeat comparing in k+1-letter
        }

    // output sorted array
    for (i=0; i<n; i++)
        printf("\n%s %d", list[i].name, list[i].mark);
    printf("\n");

    // sort marks (bubble method)
    for (i=0; i<n-1; i++)
        for (j=0; j<n-i-1; j++)
        {
            if ( list[j].mark < list[j+1].mark )
            {
                    list[n]=list[j];
                    list[j]=list[j+1];
                    list[j+1]=list[n];
            }
            else
                if ( list[j].mark == list[j+1].mark ) // if marks are the same compare names in alphabetical order
                {
                    k=-1;
                    do
                    {
                        k++;
                        if (list[j].name[k] > list[j+1].name[k]) // same as mentioned above
                        {
                            list[n]=list[j];
                            list[j]=list[j+1];
                            list[j+1]=list[n];
                        }
                    } while ( list[j].name[k] == list[j+1].name[k] );
                }
        }

        // output sorted array
        for (i=0; i<n; i++)
            printf("\n%s %d", list[i].name, list[i].mark);
}

int main()
{
    Minimal_common_multiple();
    Transposition_Matrix();
    Free_num();
    Simple_numbers();
    N_simple();
    Weight();
    The_sum_of_4_squares();
    Sum_Of_Range();
    Organize_students();
    return 0;
}
