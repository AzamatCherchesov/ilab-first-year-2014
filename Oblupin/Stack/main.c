#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Stack.h>
#include<FileTransf.h>




int main()
{
    int choice;
    while(choice!=6)
    {
        printf("====================================\n");
        printf("| What operations are available    |\n");
        printf("====================================\n");
        printf("| 1 to Push                        |\n");
        printf("|__________________________________|\n");
        printf("| 2 to Pop                         |\n");
        printf("|__________________________________|\n");
        printf("| 3 to Peep                        |\n");
        printf("|__________________________________|\n");
        printf("| 4 to Change                      |\n");
        printf("|__________________________________|\n");
        printf("| 5 to Display                     |\n");
        printf("|__________________________________|\n");
        printf("| 6 to read the Stack from the file|\n");
        printf("|__________________________________|\n");
        printf("| 7 for exit                       |\n");
        printf("====================================\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: Stack_Push();
            break;
        case 2: Stack_Pop();
            break;
        case 3: Stack_Peep();
            break;
        case 4: Stack_Change();
            break;
        case 5: Stack_Display();
            break;
        case 6: Stack_From_File();
            break;
        case 7: break;
        case 8:Factorial(5);
        }

    }
    return 0;
}


/*void Stack_is_fine()*/



