#include <stdio.h>
#include <string.h>

void reverse(int n , char a[]){
	
	if(n<0){
		return;
	}else{
		printf("%c",a[n]);
		n--;
		reverse(n , a);
	}
}


int main(){
	
	char password[10];
	
	printf("Enter the password:");
	fgets(password , 10 , stdin);
	
	reverse(10 , password);
}