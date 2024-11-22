#include<stdio.h>
#include<string.h>
int main(){
    char studentName[50];
    FILE *fptr;
    fptr=fopen("Student_data.csv","w");

    if (fptr==NULL){
        printf("error");
        return 1;

    }
    printf("Enter student name: ");
    scanf("%[^\n]s",studentName);// gets(studentName);
    fprintf(fptr,"Student Name\n");
    fprintf(fptr,studentName,"\n");

    printf("File written and saved successfully!");

    fclose(fptr);
    return 0;
}