#include <stdio.h>
#include <string.h>

struct car{
	char make[10] , model[10];
	int year;
	float price , mileage;
};

int main(){
	struct car C[10]={
		{"Toyota","01",2002,24.56,100.0},
		{"Kia","02",2004,456.7,800.6},
		{"Suzuki","03",2007,456.7,89.0},
		{"Honda","08",2022,456.7,89.0},
		{"Ford","07",1020,4512.3,56.8}
	};
	
	int choice , n=5;
	int found = 0;
	char make[10] , model[10];
	do{
		printf("ENTER YOUR CHOICE!!\n");
		printf("1.Display\n");
		printf("2.Search\n");
		printf("3.Add\n");
		printf("4.End\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch (choice){
			case 1:
				for (int i=0 ; i<n ; i++){
					printf("Make:%s , Model:%s , Year:%d , Price:%.1f , Mileage:%.1f\n",C[i].make,C[i].model,C[i].year,C[i].price,C[i].mileage);
				}
				break;
			case 2:
				printf("Enter make:");
				scanf("%s",&make);
				printf("Enter model:");
				scanf("%s",&model);
				
                for (int i = 0; i < n ; i++) {
                    if ((strcmp(C[i].make, make) == 0) && (strcmp(C[i].model, model) == 0)) {
                        printf("Make: %s, Model: %s, Year: %d, Price: %.1f, Mileage: %.1f\n", 
                               C[i].make, C[i].model, C[i].year, C[i].price, C[i].mileage);
                        found = 1;
                    }
                }
                if(!found){
                    printf("No such car is here which matches your entered make and model\n");
                }
                break;
            case 3:
            	if (n<10){
            		printf("Enter make:");
            		scanf("%s",&C[n].make);
            		printf("Enter model:");
            		scanf("%s",&C[n].model);
            		printf("Enter year:");
            		scanf("%d",&C[n].year);
            		printf("Enter price:");
            		scanf("%f",&C[n].price);
            		printf("Enter mileage:");
            		scanf("%f",&C[n].mileage);
            		n++;
            		printf("Car added successfully.\n");
				}else{
					printf("No enough space left for addtional cars!!\n");
				}
				break;
            case 4:
	            printf("Exiting the program.\n");
	            break;
           	default:
                printf("Invalid choice. Please try again.\n");     		
			}
	}while(choice!=4);
	
	return 0;
}