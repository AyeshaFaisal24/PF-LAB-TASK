#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100

struct TravelPackage {
    char name[50];
    char destination[50];
    int duration;      
    float cost;         
    int seatsAvailable; 
};

struct TravelPackage packages[MAX_PACKAGES];
int packageCount = 0;

void addPackage(char name[], char destination[], int duration, float cost, int seatsAvailable) {
    if (packageCount < MAX_PACKAGES) {
        strcpy(packages[packageCount].name, name);
        strcpy(packages[packageCount].destination, destination);
        packages[packageCount].duration = duration;
        packages[packageCount].cost = cost;
        packages[packageCount].seatsAvailable = seatsAvailable;
        packageCount++;
        printf("Package added successfully!\n");
    } else {
        printf("Cannot add more packages. Maximum limit reached.\n");
    }
}

void displayPackages() {
    if (packageCount == 0) {
        printf("No travel packages available.\n");
    } else {
        printf("Available Travel Packages:\n");
        for (int i = 0; i < packageCount; i++) {
            struct TravelPackage pkg = packages[i];
            printf("%d. %s - %s, Duration: %d days, Cost: $%.2f, Seats Available: %d\n",
                   i + 1, pkg.name, pkg.destination, pkg.duration, pkg.cost, pkg.seatsAvailable);
        }
    }
}

void bookPackage(int packageIndex) {
    if (packageIndex < 1 || packageIndex > packageCount) {
        printf("Invalid package selection.\n");
    } else if (packages[packageIndex - 1].seatsAvailable > 0) {
        packages[packageIndex - 1].seatsAvailable--;
        printf("Booking successful for %s.\n", packages[packageIndex - 1].name);
    } else {
        printf("No seats available for this package.\n");
    }
}

int main() {
    int choice;
    int packageIndex;
    char name[100], destination[100];
    int duration, seatsAvailable;
    float cost;

    addPackage("Escape Land", "Hawaiyann", 7, 1500.0, 20);
    addPackage("European Escape", "Francisco", 10, 2500.0, 15);

    do {
        printf("\n--- Travel Package Management ---\n");
        printf("1. Add a new travel package\n");
        printf("2. Display available packages\n");
        printf("3. Book a travel package\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character left in the input buffer by scanf

        switch (choice) {
            case 1:
                printf("Enter package name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';  // Remove newline character at the end

                printf("Enter destination: ");
                fgets(destination, sizeof(destination), stdin);
                destination[strcspn(destination, "\n")] = '\0';  // Remove newline character at the end

                printf("Enter duration (in days): ");
                scanf("%d", &duration);
                
                printf("Enter cost: ");
                scanf("%f", &cost);

                printf("Enter number of seats available: ");
                scanf("%d", &seatsAvailable);
                
                addPackage(name, destination, duration, cost, seatsAvailable);
                break;
                
            case 2:
                displayPackages();
                break;
                
            case 3:
                displayPackages();
                printf("Enter the package number to book: ");
                scanf("%d", &packageIndex);
                bookPackage(packageIndex);
                break;
                
            case 4:
                printf("Exiting the program.\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
