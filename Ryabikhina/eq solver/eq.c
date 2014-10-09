# include <stdio.h>
# include <math.h>

int main(){
   double a,b,c;
   double D;
   double x1,x2;
   
   scanf("%lg,%lg,%lg", &a, &b, &c);
   
   if (a==0 && b!=0){
		x1=-c/b;
		printf("%lg",x1);
   }
   
   if (a!=0){
		D = b*b-4*a*c;
		if (D<0)
			printf("решений нет");
		if (D==0){
        	x1=-b/(2*a);
			printf("%lg",x1);
			}
		if (D>0){
            x1 = (sqrt(D)-b)/(2*a);
            x2 = (-sqrt(D)-b)/(2*a);
            printf("%lg,%lg",x1,x2);
			}
    }
    if ((a==0)&&(b==0))
	   printf("бесконечно");
	   
	perintf("%lg, %lg, %lg", a, b, c);   
	getchar();
	return 0;
	
}

