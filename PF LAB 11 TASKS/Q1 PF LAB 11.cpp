#include <stdio.h>

struct Rectangle {
    float length, width;
};

int check(struct Rectangle R) {
    if (R.length < 0.0 || R.length > 20.0 || R.width < 0.0 || R.width > 20.0) {
        printf("Error: Length and Width must be between 0 and 20.\n");
        return 0; 
    }
    return 1;
}

float calculateArea(struct Rectangle R) {
    return R.length * R.width;
}

float calculatePerimeter(struct Rectangle R) {
    return 2 * (R.length + R.width);
}

int main() {
    struct Rectangle R;

    printf("Enter the length: ");
    scanf("%f", &R.length);
    printf("Enter the width: ");
    scanf("%f", &R.width);

    if (!check(R)) {
        return 0; 
    }

    float result_area = calculateArea(R);
    float result_perimeter = calculatePerimeter(R);

    printf("Area: %.1f\n", result_area);
    printf("Perimeter: %.1f\n", result_perimeter);

    return 0;
}
