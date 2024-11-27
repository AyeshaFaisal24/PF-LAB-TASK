#include <stdio.h>
#include <string.h>

struct Course {
    int courseID, credits;
    char courseName[50], instructorName[50];
};

struct Department {
    char departmentName[50];
    int courseCount;
    struct Course courses[10];
};

struct University {
    struct Department departments[5];
    int departmentCount;
};

void initializeUniversity(struct University *uni) {
    struct Department csDept = { "Computer Science", 2 };
    csDept.courses[0] = (struct Course) { 101, 4, "Data Structures", "Dr. Smith" };
    csDept.courses[1] = (struct Course) { 102, 3, "Algorithms", "Dr. Jones" };
    uni->departments[uni->departmentCount++] = csDept;

    struct Department eeDept = { "Electrical Engineering", 2 };
    eeDept.courses[0] = (struct Course) { 201, 4, "Circuit Analysis", "Prof. Green" };
    eeDept.courses[1] = (struct Course) { 202, 3, "Signal Processing", "Prof. White" };
    uni->departments[uni->departmentCount++] = eeDept;
}

void addDepartment(struct University *uni) {
    if (uni->departmentCount >= 5) return;
    struct Department newDepartment;
    getchar(); // To consume the newline left by previous input
    printf("Enter department name: ");
    fgets(newDepartment.departmentName, sizeof(newDepartment.departmentName), stdin);
    newDepartment.departmentName[strcspn(newDepartment.departmentName, "\n")] = 0;
    newDepartment.courseCount = 0;
    uni->departments[uni->departmentCount++] = newDepartment;
}

void addCourse(struct University *uni) {
    char deptName[50];
    getchar(); // To consume the newline left by previous input
    printf("Enter department name to add course: ");
    fgets(deptName, sizeof(deptName), stdin);
    deptName[strcspn(deptName, "\n")] = 0;

    int deptIndex = -1;
    for (int i = 0; i < uni->departmentCount; i++) {
        if (strcmp(uni->departments[i].departmentName, deptName) == 0) {
            deptIndex = i;
            break;
        }
    }

    if (deptIndex == -1 || uni->departments[deptIndex].courseCount >= 10) return;

    struct Course newCourse;
    printf("Enter course ID: ");
    scanf("%d", &newCourse.courseID);
    getchar(); // Consume the newline left by scanf
    printf("Enter course name: ");
    fgets(newCourse.courseName, sizeof(newCourse.courseName), stdin);
    newCourse.courseName[strcspn(newCourse.courseName, "\n")] = 0;
    printf("Enter instructor name: ");
    fgets(newCourse.instructorName, sizeof(newCourse.instructorName), stdin);
    newCourse.instructorName[strcspn(newCourse.instructorName, "\n")] = 0;
    printf("Enter number of credits: ");
    scanf("%d", &newCourse.credits);
    uni->departments[deptIndex].courses[uni->departments[deptIndex].courseCount++] = newCourse;
}

void displayCourses(struct University *uni) {
    char deptName[50];
    getchar(); // To consume the newline left by previous input
    printf("Enter department name to display courses: ");
    fgets(deptName, sizeof(deptName), stdin);
    deptName[strcspn(deptName, "\n")] = 0;

    int deptIndex = -1;
    for (int i = 0; i < uni->departmentCount; i++) {
        if (strcmp(uni->departments[i].departmentName, deptName) == 0) {
            deptIndex = i;
            break;
        }
    }

    if (deptIndex == -1) return;
    for (int i = 0; i < uni->departments[deptIndex].courseCount; i++) {
        printf("ID: %d, Name: %s, Instructor: %s, Credits: %d\n",
               uni->departments[deptIndex].courses[i].courseID,
               uni->departments[deptIndex].courses[i].courseName,
               uni->departments[deptIndex].courses[i].instructorName,
               uni->departments[deptIndex].courses[i].credits);
    }
}

void calculateTotalCredits(struct University *uni) {
    char deptName[50];
    getchar(); // To consume the newline left by previous input
    printf("Enter department name to calculate total credits: ");
    fgets(deptName, sizeof(deptName), stdin);
    deptName[strcspn(deptName, "\n")] = 0;

    int deptIndex = -1;
    for (int i = 0; i < uni->departmentCount; i++) {
        if (strcmp(uni->departments[i].departmentName, deptName) == 0) {
            deptIndex = i;
            break;
        }
    }

    if (deptIndex == -1) return;
    int totalCredits = 0;
    for (int i = 0; i < uni->departments[deptIndex].courseCount; i++) {
        totalCredits += uni->departments[deptIndex].courses[i].credits;
    }
    printf("Total credits: %d\n", totalCredits);
}

int main() {
    struct University uni = { .departmentCount = 0 };
    initializeUniversity(&uni);
    int choice;

    do {
        printf("\n-=-=University Course Enrollment System-=-=\n1. Add Department\n2. Add Course\n3. Display Courses\n4. Total Credits\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addDepartment(&uni); break;
            case 2: addCourse(&uni); break;
            case 3: displayCourses(&uni); break;
            case 4: calculateTotalCredits(&uni); break;
        }
    } while (choice != 5);

    return 0;
}
