#include <stdio.h>
#include <string.h>

struct employees{
	char name[20];
	char department[20];
	char dateOfBirth[15];
	int  ID;
	float salary;
};

void add(struct employees E[] , int *n){
		printf("Enter employee name:");
		scanf("%s",&E[*n].name);
		printf("Enter department name:");
		scanf("%s",&E[*n].department);
		printf("Enter date of birth:");
		scanf("%s",&E[*n].dateOfBirth);
		printf("Enter ID:");
		scanf("%d",&E[*n].ID);
		printf("Enter salary:");
		scanf("%f",&E[*n].salary);
		(*n)++;
}

void remove(struct employees E[] , int *n){
	char name[20];
	printf("Enter the name of the employee you want to add:");
	scanf("%s",&name);
	for (int i=0 ; i<*n ; i++){
		if (strcmp(name,E[i].name) == 0){
			for (int j = i; j < *n - 1; j++) {
	                E[j] = E[j + 1];
            }
            (*n)--; 
            printf("Employee %s removed successfully!\n", name);
            break;
		}else{
			printf("No such emplyee exist!!");
		}
	}
}

void display(struct employees E[] , int n){
	if (n==0){
		printf("No employee to display!!\n");
		return ;
	}
	for (int i=0 ; i<n ; i++){
		printf("Name:%s\nDepartment:%s\nDate Of Birth:%d\nID:%d\nSalary:%.2f",E[i].name,E[i].department,E[i].dateOfBirth,E[i].ID,E[i].salary);
	}
}

void initializeEmployees(struct employees E[]) {
    // Employee 1
    strncpy(E[0].name, "Ali", sizeof(E[0].name) - 1);
    E[0].name[sizeof(E[0].name) - 1] = '\0';
    strncpy(E[0].dateOfBirth, "12/4/22", sizeof(E[0].dateOfBirth) - 1);
    E[0].dateOfBirth[sizeof(E[0].dateOfBirth) - 1] = '\0';
    E[0].ID = 1;
    strncpy(E[0].department, "Finance", sizeof(E[0].department) - 1);
    E[0].department[sizeof(E[0].department) - 1] = '\0';
    E[0].salary = 24.56;

    // Employee 2
    strncpy(E[1].name, "Alyaan", sizeof(E[1].name) - 1);
    E[1].name[sizeof(E[1].name) - 1] = '\0';
    strncpy(E[1].dateOfBirth, "12/4/22", sizeof(E[1].dateOfBirth) - 1);
    E[1].dateOfBirth[sizeof(E[1].dateOfBirth) - 1] = '\0';
    E[1].ID = 2;
    strncpy(E[1].department, "Business", sizeof(E[1].department) - 1);
    E[1].department[sizeof(E[1].department) - 1] = '\0';
    E[1].salary = 25.78;

    // Employee 3
    strncpy(E[2].name, "Aliza", sizeof(E[2].name) - 1);
    E[2].name[sizeof(E[2].name) - 1] = '\0';
    strncpy(E[2].dateOfBirth, "14/4/22", sizeof(E[2].dateOfBirth) - 1);
    E[2].dateOfBirth[sizeof(E[2].dateOfBirth) - 1] = '\0';
    E[2].ID = 3;
    strncpy(E[2].department, "Marketing", sizeof(E[2].department) - 1);
    E[2].department[sizeof(E[2].department) - 1] = '\0';
    E[2].salary = 288.78;
}

int main() {
    struct employees E[10];  
    int choice, n = 3;

 	initializeEmployees(E);

    printf("-=-=-= EMPLOYEE MANAGEMENT SYSTEM -==-=\n");

    do {
        printf("1. Add an employee\n");
        printf("2. Delete an employee\n");
        printf("3. Display all employees\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(E, &n);
                break;
            case 2:
                remove(E, &n);
                break;
            case 3:
                display(E, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}