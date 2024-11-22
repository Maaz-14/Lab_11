#include<stdio.h>
int main(){
    FILE *fptr;
    fptr= fopen("Program.txt","w");

    if (fptr==NULL){
        printf("Error");
        return 1;//exit
    }
    fprintf(fptr,"My name is: \n");
    fprintf(fptr,"Muhammad Maaz");
    return 0;
}