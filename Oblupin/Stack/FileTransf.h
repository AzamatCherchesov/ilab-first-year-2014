#ifndef FILETRANSF_H
#define FILETRANSF_H

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


int Check_the_command(char* line)
{
    int Num_Of_The_Command;
    if ((Num_Of_The_Command=strcmp(line,"Pus"))==0)
        return 1;
    else if ((Num_Of_The_Command=strcmp(line,"Pop"))==0)
        return 100;
    else if ((Num_Of_The_Command=strcmp(line,"Add"))==0)
        return 101;
    else if ((Num_Of_The_Command=strcmp(line,"Sub"))==0)
        return 102;
    else if ((Num_Of_The_Command=strcmp(line,"Mul"))==0)
        return 103;
    else if ((Num_Of_The_Command=strcmp(line,"Div"))==0)
        return 104;
    else

    return 0;
}


void File_transform() //creates new files
{
    /*Def_File_Address(Address_key, Address_code);*/
    char *Address_key = "C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Stack_key.txt",
         *Address_code = "C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Stack_code.txt",
         *Buffer = "C:/Users/Andrey/Desktop/MIPT/IT/Class/Programs/Homeworks/Buffer.txt",
         line[10],
         symbol;
    int Num_of_operations = 0, Just_number = 0, counter = 0, Num_Of_The_Operation = 0;
    FILE *f_key=fopen(Address_key,"r"), *f_code = fopen(Address_code,"r"), *f_buffer=fopen(Buffer,"w");
    int len=filelength(fileno(f_code));
   /* fscanf(f_key,"%s %i",line,&Just_number);
    printf("%s %i",line,Just_number);
    assert(f_key>0);
    assert(f_code>0);
    assert(f_buffer>0);*/
    while (!feof(f_code))
    {
        if ((symbol=fgetc(f_code))=='\n')
            Num_of_operations++;

    }
    rewind(f_code);

    while (counter<Num_of_operations)
    {
        fscanf(f_code,"%s",line);
        Num_Of_The_Operation = Check_the_command(line);
        if (Num_Of_The_Operation < 100)
        {
            fscanf(f_code,"%i",&Just_number);
            fprintf(f_buffer, "%i %i ", Num_Of_The_Operation, Just_number);
        }
        else
            fprintf(f_buffer, "%i ", Num_Of_The_Operation);
        counter++;
    }

    printf("%i", Num_of_operations);
    fclose(f_key);
    fclose(f_code);
    fclose(f_buffer);
}


//**********************************************************
void Stack_From_File()
{
    File_transform();
};



#endif // FILETRANSF_H
