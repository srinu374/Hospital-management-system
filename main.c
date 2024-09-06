#include <stdio.h>
#include <string.h>

// Define a structure to represent a patient
struct Patient {
    int id;
    char name[100];
    int age;
    char disease[100];
};

// Function prototypes
void addPatient(struct Patient patients[], int *count);
void displayPatients(struct Patient patients[], int count);

int main() {
    struct Patient patients[100]; // Array to store patient records
    int patientCount = 0; // Number of patients
    int choice;

    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(patients, &patientCount);
                break;
            case 2:
                displayPatients(patients, patientCount);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a patient record
void addPatient(struct Patient patients[], int *count) {
    struct Patient newPatient;

    printf("Enter patient ID: ");
    scanf("%d", &newPatient.id);
    printf("Enter patient name: ");
    scanf(" %[^\n]", newPatient.name); // Read string with spaces
    printf("Enter patient age: ");
    scanf("%d", &newPatient.age);
    printf("Enter disease: ");
    scanf(" %[^\n]", newPatient.disease); // Read string with spaces

    patients[*count] = newPatient;
    (*count)++;

    printf("Patient added successfully.\n");
}

// Function to display all patient records
void displayPatients(struct Patient patients[], int count) {
    if (count == 0) {
        printf("No patients to display.\n");
        return;
    }

    printf("\nPatient Records:\n");
    printf("ID\tName\t\tAge\tDisease\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t%s\n", patients[i].id, patients[i].name, patients[i].age, patients[i].disease);
    }
}
