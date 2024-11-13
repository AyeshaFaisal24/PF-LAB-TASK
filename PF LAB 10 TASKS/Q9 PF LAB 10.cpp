#include <stdio.h>
#include <string.h>

struct employee {
    int ID;
    char name[50], department[50];
    float salary;
};

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);
    getchar();

    struct employee Emp[n];

    for (int i = 0; i < n; i++) {
        printf("Enter employee ID of %d: ", i + 1);
        scanf("%d", &Emp[i].ID);
        getchar(); 
        
        printf("Enter employee %d name: ", i + 1);
        fgets(Emp[i].name, 50, stdin);
        Emp[i].name[strcspn(Emp[i].name, "\n")] = 0; 

        printf("Enter employee %d department: ", i + 1);
        fgets(Emp[i].department, 50, stdin);
        Emp[i].department[strcspn(Emp[i].department, "\n")] = 0; 

        printf("Enter employee %d salary: ", i + 1);
        scanf("%f", &Emp[i].salary);
        getchar(); 
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("ID of employee %d is: %d\n", i + 1, Emp[i].ID);
        printf("Name of employee %d is: %s\n", i + 1, Emp[i].name);
        printf("Department of employee %d is: %s\n", i + 1, Emp[i].department);
        printf("Salary of employee %d is: %.2f\n", i + 1, Emp[i].salary);
        printf("\n");
    }

    return 0;
}
