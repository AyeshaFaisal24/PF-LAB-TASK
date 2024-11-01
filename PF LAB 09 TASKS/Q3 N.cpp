#include <stdio.h>
#include <string.h>

int main(){
	char username[10]="admin" , _username[10];
	char password[5]="1234" , _password[5];
	
	printf("Enter your user name:");
	for (int i=0 ; i<1 ; i++){
		scanf("%s",&_username[i]);
	}
	
	printf("Enter your password:");
	scanf("%s",&_password);

	
	if ((strcmp(username, _username) == 0 ) && (strcmp(password, _password) ==  0) ) {
		printf("Access granted");
	}else {
		printf("Not granted");
	}
	
		
	return 0;
}