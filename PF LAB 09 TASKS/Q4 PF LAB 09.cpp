#include <stdio.h>
#include <string.h>

int main(){
	char student[5][10]={
	"Alice",
	"Harry",
	"Charlie",
	"Diana",
	"Eve"};
	char ch[1][10];
	int found = 0;
	
	printf("Enter the name:");
	fgets(ch[1], 50, stdin);
	
	for (int i=0 ; i<5 ; i++){
		for (int j=0 ; j<10 ; j++){
			if (strstr(student[i], ch)) {
				found=1;
			} else {
				found=0;
 			}
		}
	}
	
	if (found){
		printf("Found");
	} else{
		printf("Not Found");
	}
	
	return 0;
}