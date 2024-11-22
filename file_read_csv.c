#include<stdio.h>
#include<string.h>

int main(){
    FILE *fptr;
    fptr = fopen("Student_data.csv","r");
    if (fptr==NULL){
        printf("Error");
        return 1;
    }
    
}