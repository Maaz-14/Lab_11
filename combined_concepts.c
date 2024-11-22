
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Student {
    int id;
    char name[50];
    float grade;
};


void addStudent();
void viewStudents();
void updateStudent();
void deleteStudent();

int main() {
    int choice;
    while (1) {
       
        printf("\n--- Student Record Management ---\n");
        printf("1. Add Student Record\n");
        printf("2. View Student Records\n");
        printf("3. Update Student Record\n");
        printf("4. Delete Student Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


void addStudent() {
    struct Student s;
    FILE *file = fopen("students.dat", "ab"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Student Name: ");
    getchar(); 
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; 
    printf("Enter Student Grade: ");
    scanf("%f", &s.grade);

    fwrite(&s, sizeof(struct Student), 1, file); 
    fclose(file);
    printf("Student record added successfully.\n");
}


void viewStudents() {
    struct Student s;
    FILE *file = fopen("students.dat", "rb"); 
    if (file == NULL) {
        printf("Error opening file or no records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(struct Student), 1, file)) { 
        printf("ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Grade: %.2f\n", s.grade);
        printf("--------------------------\n");
    }
    fclose(file);
}


void updateStudent() {
    struct Student s;
    int id, found = 0;
    FILE *file = fopen("students.dat", "rb+"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(struct Student), 1, file)) {
        if (s.id == id) { 
            printf("Enter New Name: ");
            getchar();
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = '\0';
            printf("Enter New Grade: ");
            scanf("%f", &s.grade);

            fseek(file, sizeof(struct Student), SEEK_CUR); 
            fwrite(&s, sizeof(struct Student), 1, file);
            found = 1;
            printf("Student record updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student record with ID %d not found.\n", id);
    }

    fclose(file);
}


void deleteStudent() {
    struct Student s;
    int id, found = 0;
    FILE *file = fopen("students.dat", "rb"); 
    FILE *temp = fopen("temp.dat", "wb"); 
    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    while (fread(&s, sizeof(struct Student), 1, file)) {
        if (s.id == id) {
            found = 1; 
        } else {
            fwrite(&s, sizeof(struct Student), 1, temp); 
        }
    }

    fclose(file);
    fclose(temp);

    remove("students.dat"); 
    rename("temp.dat", "students.dat"); 

    if (found) {
        printf("Student record deleted successfully.\n");
    } else {
        printf("Student record with ID %d not found.\n", id);
    }
}