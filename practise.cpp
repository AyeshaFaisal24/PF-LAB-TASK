#include <stdio.h>
#include <string.h>

struct book {
    char title[10], author[10];
    int ISBN, publication_year;
    char isAvailable;
};

int add(struct book B[], int n) {
    if (n >= 10) {  
        printf("No more books can be added!\n");
    } else {
        printf("Enter title: ");
        scanf("%s", B[n].title);  
        printf("Enter author name: ");
        scanf("%s", B[n].author);  
        printf("Enter ISBN: ");
        scanf("%d", &B[n].ISBN);
        printf("Enter year of publication: ");
        scanf("%d", &B[n].publication_year);
        n++;  
        printf("Book added successfully!!\n");
    }
    return n;
}

void search(struct book B[], int n) {
    char author[10], title[10];
    printf("Enter title: ");
    scanf("%s", title);  
    printf("Enter author: ");
    scanf("%s", author);  
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(B[i].author, author) == 0 && strcmp(B[i].title, title) == 0) {
            printf("Author: %s, Title: %s, ISBN: %d, Year: %d\n", B[i].author, B[i].title, B[i].ISBN, B[i].publication_year);
            found = 1;
        }
    }
    if (!found) {
        printf("No such book found.\n");
    }
}
void display(struct book B[], int n) {
    if (n == 0) {
        printf("No books available.\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("Author: %s, Title: %s, ISBN: %d, Year: %d, Availability: %c\n", 
                   B[i].author, B[i].title, B[i].ISBN, B[i].publication_year, B[i].isAvailable);
        }
    }
}
void updateAvailability(struct book B[], int n) {
    char title[10], author[10];
    printf("Enter title: ");
    scanf("%s", title);
    printf("Enter author: ");
    scanf("%s", author);
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(B[i].author, author) == 0 && strcmp(B[i].title, title) == 0) {
            if (B[i].isAvailable == 'Y') {
                printf("The book is available. Checking out...\n");
                B[i].isAvailable = 'N';  
            } else {
                printf("The book is already checked out. Returning the book...\n");
                B[i].isAvailable = 'Y';  
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No such book found.\n");
    }
}

int main() {
    struct book B[10] = {
        {"Sad", "Anuv", 123, 2022},
        {"Happy", "Alexa", 234, 2090},
        {"Angry", "Me", 56, 2034},
    };

    int choice, n = 3; 

    do {
        printf("1. Add a new book.\n");
        printf("2. Search.\n");
        printf("3. Display all books and check availability.\n");
        printf("4. Quit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = add(B, n); 
                break;
            case 2:
                search(B, n);
                break;
            case 3:
                display(B, n);
                updateAvailability(B, n); 
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
