#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int bookID;
    char title[100];
    char author[100];
    int quantity;
    float price;
};

void addBook() {
    FILE *file = fopen("books.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.bookID);
    getchar();  // consume newline character
    printf("Enter Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;  // remove trailing newline
    printf("Enter Author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;  // remove trailing newline
    printf("Enter Quantity: ");
    scanf("%d", &newBook.quantity);
    printf("Enter Price: ");
    scanf("%f", &newBook.price);

    fprintf(file, "%d,%s,%s,%d,%.2f\n", newBook.bookID, newBook.title, newBook.author, newBook.quantity, newBook.price);
    fclose(file);

    printf("Book added successfully.\n");
}

void viewBooks() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    struct Book book;
    printf("Book ID | Title | Author | Quantity | Price\n");
    while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        printf("%d | %s | %s | %d | %.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
    }

    fclose(file);
}

void initializeBooks() {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Book books[2] = {
        {101, "C Programming", "Dennis Ritchie", 50, 29.99},
        {102, "Data Structures", "Robert Lafore", 30, 35.99}
    };

    for (int i = 0; i < 2; i++) {
        fprintf(file, "%d,%s,%s,%d,%.2f\n", books[i].bookID, books[i].title, books[i].author, books[i].quantity, books[i].price);
    }

    fclose(file);
    printf("Books initialized successfully.\n");
}

void searchBook() {
    int choice;
    printf("Search by: 1. ID 2. Title\n");
    scanf("%d", &choice);
    getchar();  // consume newline character

    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    struct Book book;
    int found = 0;

    if (choice == 1) {
        int searchID;
        printf("Enter Book ID to search: ");
        scanf("%d", &searchID);
        while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
            if (book.bookID == searchID) {
                printf("Book ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        char searchTitle[100];
        printf("Enter Title to search: ");
        fgets(searchTitle, sizeof(searchTitle), stdin);
        searchTitle[strcspn(searchTitle, "\n")] = 0;  // remove trailing newline
        while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
            if (strstr(book.title, searchTitle)) {
                printf("Book ID: %d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}

void updateBook() {
    int bookID;
    printf("Enter Book ID to update: ");
    scanf("%d", &bookID);

    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    struct Book book;
    int found = 0;

    while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        if (book.bookID == bookID) {
            found = 1;
            printf("Enter new Quantity: ");
            scanf("%d", &book.quantity);
            printf("Enter new Price: ");
            scanf("%f", &book.price);
        }
        fprintf(tempFile, "%d,%s,%s,%d,%.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
    }

    if (!found) {
        printf("Book not found.\n");
    } else {
        printf("Book updated successfully.\n");
    }

    fclose(file);
    fclose(tempFile);

    remove("books.txt");
    rename("temp.txt", "books.txt");
}

void deleteBook() {
    int bookID;
    printf("Enter Book ID to delete: ");
    scanf("%d", &bookID);

    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }

    struct Book book;
    int found = 0;

    while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        if (book.bookID != bookID) {
            fprintf(tempFile, "%d,%s,%s,%d,%.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
        } else {
            found = 1;
        }
    }

    if (found) {
        printf("Book deleted successfully.\n");
    } else {
        printf("Book not found.\n");
    }

    fclose(file);
    fclose(tempFile);

    remove("books.txt");
    rename("temp.txt", "books.txt");
}

void calculateInventoryValue() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("No records found.\n");
        return;
    }

    struct Book book;
    float totalValue = 0;

    while (fscanf(file, "%d,%99[^,],%99[^,],%d,%f\n", &book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        totalValue += book.quantity * book.price;
    }

    printf("Total Inventory Value: %.2f\n", totalValue);

    fclose(file);
}

int main() {
    int choice;
    initializeBooks();
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add New Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Delete Book\n");
        printf("6. Calculate Total Inventory Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                viewBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                calculateInventoryValue();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
