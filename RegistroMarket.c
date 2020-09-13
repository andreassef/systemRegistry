#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

typedef struct superUser {
	char name[20];
	char password[20];
	char registration[20];
}Employee;

typedef struct usuario {
	char name[20];
	char registration[20];
}Salesman;

typedef struct iten {
	char name[20];
	int quantity;
	float price;
}Product;

typedef struct resume {
	char produtoVendido[20];
	int quantidade;
	float total;
}Report;

// Attributes
int typeUser;
Employee employee[0];
Salesman salesman[2];
char leave[5];

// Procedures
void welcomeMessage();
void await();
void createRoot();
void home();
void login();
void createEmployee();

int main() {
	createRoot();
	home();
	return 0;
}

void await() {
	sleep(2);
}

void welcomeMessage() {
	printf("\nWait a moment [#.........] - 10");
	printf("\no__(*--*)/ WELCOME \(*--*)/");
	await();
	system("cls");
	
	printf("\nWait a moment [###.......] - 30");
	printf("\no__(*--*)/ BEM-VINDO \(*--*)/");
	await();
	system("cls");
	
	printf("\nWait a moment [######....] - 60");
	printf("\no__(*--*)/ BIENVENUE \(*--*)/");
	await();
	system("cls");
		
	printf("\nWait a moment [##########] - 100");
	printf("\no__(*--*)/ OI, CASADA! \(*--*)/");
	await();
	system("cls");
} 

void createRoot() {
	char confirmPassword[20];
	welcomeMessage();
	printf("\nSign on - to start the system create a Admin. ");
	printf("\nName: ");
	fflush(stdin);
	gets(employee[0].name);
	
	printf("\nPassword: ");
	fflush(stdin);
	gets(employee[0].password);
	
	do{
		//system("cls");
		printf("\nConfirm password: ");
		fflush(stdin);
		gets(confirmPassword);
		if(strcmp(employee[0].name, confirmPassword) != 0) {
			printf("\nPasswords don't match! Try Again!!");
			await();
		}
	} while(strcmp(employee[0].name, confirmPassword) != 0);
	printf("\nRegistration successfully!!");
	await();
}

void createEmployee() {
	
	do{
		printf("\nSign on - create a new Salesman. ");
		printf("\nName: ");
		fflush(stdin);
		gets(salesman[0].name);
	
		printf("\nRegistration: ");
		fflush(stdin);
		gets(salesman[0].registration);
		
		printf("\nDo you wanna save another salesman (yes)? - to exit: (sair)\n-->");
		fflush(stdin);
		gets(leave);
		if(strcmp(leave, "sair") == 0) {
			break;
		}
	}while(strcmp(leave, "sair") != 0);
	printf("Success saving new salesman!");
	sleep(3);
}



void home(){
	int count;
	do{
		system("cls");
		printf("\nWelcome!");
		printf("\n1 - Run as admin. ");
		printf("\n2 - Run as employee.\n--> ");
		scanf("%d", &typeUser);
		
		switch(typeUser){
			case 1:
				printf("\nWelcome Admin!");
				login();
				printf("\nDashboard -");
				// criar funcao com switch case para interface do superusario
				printf("\n1- Create a Salesman:");
				await();
				createEmployee();
				
				break;
			case 2:
				printf("\nWelcome Employee!");
				login();
				break;
			default:
				printf("Invalid choice!");
		}
		
		count++;
		if(strcmp(leave, "sair") == 0) {
			break;
		}
		printf("Remain on loop %d", count);
		sleep(5);	
	}while(strcmp(leave, "sair") != 0);
	
	printf("\nWe get out loop");	
}

void login() {
	char username[20];
	char password[20];
	printf("\nSign in (*---*)/)");
	printf("\nlogin: ");
	fflush(stdin);
	gets(username);
	
	printf("\nPassword: ");
	fflush(stdin);
	gets(password);
	
	if ( (strcmp(username, employee[0].name) != 0) || (strcmp(password, employee[0].password) != 0 )) {
		do{
			system("cls");
			printf("\nUser or password incorrect - Try again!");
			printf("\nlogin: ");
			fflush(stdin);
			gets(username);
			
			printf("\nPassword: ");
			fflush(stdin);
			gets(password);
			
		}while( (strcmp(username, employee[0].name) != 0) || (strcmp(password, employee[0].password) != 0 ) );
	}
	
	printf("\nSuccess!");
	await();
				
}





