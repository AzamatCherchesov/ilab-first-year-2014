#include <stdio.h>
#include <math.h>

#define begin {
#define end   }
#define sqrtsol(d) ((d.b)*(d.b))-(4*(d.a)*(d.c))


const double NoSolution = -1, AnySolution = 3, OneSolution = 1, TwoSolutions = 2;

typedef struct
begin
    double a;
    double b;
    double c;
    int TypeOfPolynomial;
end coeff;

typedef struct
{
    double x1;
    double x2;
    int NumOfRoots;
} roots;

int output(roots result)
{

    switch (result.NumOfRoots)
    {
        case -1:
            {
                printf("\n Equation has no solutions \n");
                break;
            }
        case 1:
            {
                printf("\n Equation has one solution x1 = %lg \n", result.x1);
                break;
            }
        case 2:
            {
                printf("\n Equation has two solutions x1 = %lg, x2 = %lg \n", result.x1, result.x2);
                break;
            }
        case 3:
            {
                printf("\n Equation has an infinite number of solutions \n");
                break;
            }
    }

}

coeff init (void)   //< figuring out the coefficients and the type of a polynomial
{
    printf ("\n KEEP \n CALM \n and \n WRITE \n THE \n EXPRESSION \n");

    coeff def;

    char str[50]="\0";

    /*scanf(" %s", str);

    int ok=0;
    if ((sscanf (str,"%lg * x ^ 2 + %lg * x + %lg = 0", &def.a, &def.b, &def.c) == 3) ||
            (sscanf (str,"%lg , %lg , %lg", &def.a, &def.b, &def.c)                 == 3) ||
            (sscanf (str,"%lg %lg %lg", &def.a, &def.b, &def.c)                     == 3)){
        ok=1;
    };*/
    int ok=1;
    if (ok==1){
        scanf("%lg %lg %lg", &def.a, &def.b, &def.c); //************************extra info***********
        if (def.a == 0)   //figuring out the form of a poliynomial 1-squared 2-linear 3-simple 4-squared, but not full;
        {
            if (def.b == 0)
             {
                 def.TypeOfPolynomial = 3;
             }
             else
             {
                 def.TypeOfPolynomial = 2;
             }
        }
        else
        {
            if (def.b == 0)
            {
                def.TypeOfPolynomial = 4;
            }
            else
            {
                def.TypeOfPolynomial = 1;
            }
        }
    }
    else
    {
        printf("Check the spelling \n" );
        init();
    }
        return def;
    }


roots solve (coeff ent)
{
   roots Solution;
   switch (ent.TypeOfPolynomial){
        case 1:                                                             //squared
        {
            if (sqrtsol(ent)>0)
            {
                Solution.NumOfRoots = TwoSolutions;
                Solution.x1 = -ent.b+sqrt(sqrtsol(ent)) / (2*ent.a);
                Solution.x2 = -ent.b-sqrt(sqrtsol(ent)) / (2*ent.a);
                return Solution;
                break;
            }
            else
            {
                if (sqrtsol(ent)==0)
                {
                    Solution.NumOfRoots = OneSolution;
                    Solution.x1 = -ent.b/(2*ent.a);
                    return Solution;
                    break;
                }
                else
                {
                    Solution.NumOfRoots = NoSolution;
                    return Solution;
                    break;
                }

            }
        }
        case 2:                                                             //linear
        {
            Solution.NumOfRoots = OneSolution;
            Solution.x1 = -ent.c/ent.b;
            return Solution;
            break;
        }
        case 3:                                                             //Simple
        {
            if (ent.c==0)
            {
                Solution.NumOfRoots=AnySolution;
                return Solution;
                break;
            }
            else
            {
                Solution.NumOfRoots=NoSolution;
                return Solution;
                break;
            }

        }
        case 4:
        {
            if (ent.c>0)
            {
                Solution.NumOfRoots=NoSolution;
                return Solution;
                break;
            }
            else
            {
                if (ent.c==0)
                {
                    Solution.NumOfRoots = OneSolution ;
                    Solution.x1 = 0;
                    return Solution;
                    break;
                }
                else
                {
                    Solution.NumOfRoots=TwoSolutions;
                    Solution.x1=sqrt(-ent.c);
                    Solution.x2=-sqrt(-ent.c);
                    return Solution;
                    break;
                }
            }
         }

   }
   return Solution;
}


int main()
{

    coeff def=init();
    printf("A = %lg,  B = %lg, C = %lg, Type=%i \n", def.a, def.b, def.c, def.TypeOfPolynomial);
    roots result=solve(def);
    output(result);

    return 0;
}

