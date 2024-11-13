#include <stdio.h>
#include <string.h>

void reverse(char str[], int n){
    if(n < 0){ 
        return;
    } else {
        printf("%c", str[n]); 
        reverse(str, n - 1); 
    }
}

int main(){
    char str[20];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin); 
    
    // Remove newline character from fgets input
    str[strcspn(str, "\n")] = '\0'; 

    reverse(str, strlen(str) - 1); 
    printf("\n");
    return 0;
}
