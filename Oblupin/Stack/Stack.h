#ifndef STACK_H
#define STACK_H

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<FileTransf.h>
#include<assert.h>
#include<io.h>

struct stack
{
    int value;
    struct stack *link;
};

struct stack *Top=NULL;

void Stack_Push();
void Stack_Pop();
void Stack_Display();
void Stack_Peep();
void Stack_Change();
void Stack_From_File();

void Stack_Push()
{

    struct stack *NewElement,*Temporary;
    int i=0;
    for(Temporary=Top;Temporary!=NULL;Temporary=Temporary->link)
    {
        i++;
    }
    NewElement=(struct stack *)calloc(1,sizeof(struct stack));
    printf("Enter value for stack: ");
    scanf("%d",&NewElement->value);
    NewElement->link=Top;
    Top=NewElement;

}

void Stack_Pop()
{
    struct stack *Temporary,*Temporary2;
    int i=0;
    for(Temporary=Top;Temporary!=NULL;Temporary=Temporary->link)
    {
        i++;
    }
    if(i==0)
    {
        printf("Underflow");
        getch();
    }
    else
    {
        Temporary2=Top->link;
        Top=Temporary2;
        free(Temporary2);
        printf("\n***The value has been poped***\n");
    }
}

void Stack_Display()
    {
    struct stack *Temporary;
    printf("\n****Stack Values****\n");
    for(Temporary = Top; Temporary != NULL; Temporary = Temporary->link)
       {
       printf("%d\n",Temporary->value);
       }
    getch();
    }

void Stack_Peep()
    {
    struct stack *Temporary;
    int Position,i=0,j=0;
    printf("Please enter the position number: ");
    scanf("%d",&Position);
    for(Temporary=Top;Temporary!=NULL;Temporary=Temporary->link)
     {
     i++;
     }
    if(Position>i)
       {
       printf("\n Over Limit\n");
       getch();
       }
     else
       {
       Temporary=Top;
       for(j=0;j<Position-1;j++)
           {
          Temporary=Temporary->link;
           }
        printf("\nThe value of position %d is :%d",Position,Temporary->value);
        getch();
       }
    }

void Stack_Change()
{
    struct stack *Temporary,*NewElement;
    int Position,i=0,j=0;
    printf("Please enter the position number: ");
    scanf("%d",&Position);
    for(Temporary=Top;Temporary!=NULL;Temporary=Temporary->link)
     {
     i++;
     }
    if(Position>i)
       {
       printf("\n Over Limit \n");
       getch();
       }
     else
       {
       NewElement=(struct stack *)malloc(sizeof(struct stack));
       printf("Enter value for stack: ");
       scanf("%d",&NewElement->value);
       Temporary=Top;
       for(j=0;j<Position-1;j++)
           {
          Temporary=Temporary->link;
           }
        Temporary->value=NewElement->value;
        }
}

//------------------------Working with the sStack elements--------------------

void Stack_Add()
{
    struct stack *Second,*First;
    First=Top;
    Second=First->link;
    Second->value=Second->value+First->value;
    Top=Second;

}

void Stack_Sub()
{
    struct stack *Second,*First;
    First=Top;
    Second=First->link;
    Second->value=Second->value-First->value;
    Top=Second;

}

void Stack_Mul()
{
    struct stack *Second,*First;
    First=Top;
    Second=First->link;
    Second->value=Second->value*First->value;
    Top=Second;

}

void Stack_Div()
{
    struct stack *Second,*First;
    First=Top;
    Second=First->link;
    assert(First->value!=0);
    Second->value=Second->value/First->value;
    Top=Second;

}

void Factorial(int num)
{
    int i;
    struct stack *First;
    /*Second->link=NULL;
    Second->value=1;
    First->link=Third;
    First->value=1;*/
    for (i=0;i<num-2;i++)
    {
        First=(struct stack *)calloc(1,sizeof(struct stack));
        First->value=Top->value+Top->link->value;
        First->link=Top;
        Top=First;
    }
}

//----------------------Working with the Stack elements --------------------

//****************************************************************
/*void Def_File_Address(char* key, char* code)
{
    int i = 0, success = 0;
    printf("Choose the option: \n");
    printf("1. Stack_key has an adress <C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Stack_key.txt> \n Stack_code has an adress <C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Stack_code.txt>\n");
    printf("2.Address is different. \n");
    scanf("%i", &i);
    while (success!=1)
    {if (i==1)
    {
        key="C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Stack_key.txt";
        code="C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Stack_code.txt";
        success = 1;
    }
    else
    {
        printf("Enter the adress of both key and code files");
        scanf("%s",key);
        scanf("%s", code);
        success = 1;
    }
    if ((i!=1)&&(i!=2))
        printf("Check the option! ");
    }
}*/


void Create_array_of_commands()
{

}


void File_transform() //creates new files
{
    /*Def_File_Address(Address_key, Address_code);*/
    char *Address_key = "C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Stack_key.txt",
         *Address_code = "C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Stack_code.txt",
         *Buffer = "C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Buffer.txt",
         symbol;
    int Num_of_operations = 0;
    FILE *f_key=fopen(Address_key,"r"), *f_code = fopen(Address_code,"");
    int len=filelength(fileno(f_key));
    while ((symbol=fgetc(f_key))!=EOF)
    {
        if (symbol=='\n')
            Num_of_operations++;

    }
    printf("%i", Num_of_operations);



}


//**********************************************************
void Stack_From_File()
{
    File_transform();
};





#endif // STACK_H
