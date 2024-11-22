#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fptr;
    fptr = fopen("Student_data.csv","a");
    
    if(fptr == NULL)
    {
        printf("Error");
        return 1;
    }
    
    printf("Enter Student name: ");
    
    char std_name[100];
    gets(std_name);
    
    fprintf(fptr, "Student Name\n");
    fprintf(fptr, std_name, "\n");
    
    printf("File Written and save Successfully");
    
    fclose(fptr);
    return 0;
}