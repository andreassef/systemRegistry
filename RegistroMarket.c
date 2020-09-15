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
	char name[20];
	int quantity;
	float total;
}Report;

// Attributes
int typeUser;
int menuOptionRoot;
char leave[5];
char sair[5];
char logoutRoot[5];

// Structs
Employee employee[0];
Salesman salesman[2];
Product product[5];
Report report[5];

// Procedures
void welcomeMessage();
void await();
void createRoot();
void home();
void login();
void createEmployee();
void salesmanLogin();
void menuRoot();
void createProduct();
void sale();
void showReport();

int main() {
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
	int i = 0;
	do{
		system("cls");
		printf("\nSign on - create a new Salesman. ");
		printf("\nName: ");
		fflush(stdin);
		gets(salesman[i].name);
	
		printf("\nRegistration: ");
		fflush(stdin);
		gets(salesman[i].registration);
		
		if (i == 2) {
			break;
		}
		
		printf("\nDo you wanna save another salesman (yes)? - to exit: (sair)\n-->");
		fflush(stdin);
		gets(sair);
		//if( (strcmp(sair, "nao") == 0) ) {
			//break;
		//}
		i++;
	}while( (strcmp(sair, "sair") != 0));
	
	printf("\nSuccess saving new salesman: %d", i);
	printf("\nSalesman's data - 2: %s", salesman[1].name);
	sleep(3);
}



void home(){
	int count = 0;
	do{
		if(count == 0){
			createRoot();	
		}
		
		system("cls");
		printf("\nWelcome!");
		printf("\n1 - Run as admin. ");
		printf("\n2 - Run as employee.\n--> ");
		scanf("%d", &typeUser);
		
		switch(typeUser){
			case 1:
				printf("\nWelcome Admin!");
				login();
				printf("\nDashboard - Root");
				// criar funcao com switch case para interface do superusario
				menuRoot();
				break;
			case 2:
				if ( strcmp(salesman[0].name, "") == 0) {
					printf("\nNo salesman yet! Create a new Salesman firts!");
					await();
					break;
				}else {
					printf("\nWelcome Employee!");
					salesmanLogin();
					sale();
				}
				break;
			default:
				printf("Invalid choice!");
		}
		
		count++;
		//if(strcmp(sair, "sair") == 0) {
			//break;
		//}
		printf("\nRemain on loop %d", count);
		sleep(2);	
	}while(strcmp(leave, "sair") != 0);
	
	printf("\nWe get out loop");	
}

void login() {
	char username[20];
	char password[20];
	printf("\nSign in (*---*)/");
	printf("\nlogin: ");
	fflush(stdin);
	gets(username);
	
	printf("\nPassword: ");
	fflush(stdin);
	gets(password);
	
	strcpy(username, employee[0].name); 
	strcpy(password, employee[0].password);
	
	
	if ( (strcmp(username, employee[0].name) != 0 ) || (strcmp(password, employee[0].password) != 0 )) {
		do{
			system("cls");
		
			printf("\nUser or password incorrect - Try again!");
			printf("\nlogin: ");
			fflush(stdin);
			gets(username);
			
			printf("\nPassword: ");
			fflush(stdin);
			gets(password);
			
			//strcpy(employee[0].name, username);
			//strcpy(employee[0].password, password);
		}while( (strcmp(username, employee[0].name) != 0) || (strcmp(password, employee[0].password) != 0 ) );
	}
	
	printf("\nSuccess!");
	await();				
}

void salesmanLogin() {
	char username[20];
	char registration[20];
	int i = 0;
	
	printf("\nSign in (*---*)/)");
	printf("\nlogin: ");
	fflush(stdin);
	gets(username);
	
	printf("\nRegistration: ");
	fflush(stdin);
	gets(registration);
	
	while( i < 2 ) {
		if ( (strcmp(username, salesman[i].name) == 0) && (strcmp(registration, salesman[i].registration) == 0 ) ) {
			printf("\nWelcome: %s", salesman[i].name);
			await();
			break;
		}
		i++;
	}
	
	do{
		system("cls");
		if ( (strcmp(username, salesman[i].name) != 0) || (strcmp(registration, salesman[i].registration) != 0 ) ) {
			printf("\nUser or registration incorrect - Try again!");
			printf("\nlogin: ");
			fflush(stdin);
			gets(username);
				
			printf("\nPassword: ");
			fflush(stdin);
			gets(registration);
			i=0;
			while( i < 2 ) {
				if ( (strcmp(username, salesman[i].name) == 0) && (strcmp(registration, salesman[i].registration) == 0 ) ) {
					printf("\nWelcome: %s", salesman[i].name);
					break;
				}
				i++;
			}	
		}	
			
	}while( (strcmp(username, salesman[i].name) != 0) || (strcmp(registration, salesman[i].registration) != 0 ) );
	
	printf("\nSuccess!");
	await();
}

void menuRoot() {
	do{
		system("cls");
		printf("\nWelcome: Admin %s!", employee[0].name);
		printf("\n1 - Create new Salesman.");
		printf("\n2 - Create new product. ");
		printf("\n3 - Show product's reports. ");
		printf("\n4 - Logout\n-->");
		scanf("%d", &menuOptionRoot);
		
		printf("\n LOADING...");
		await();
		switch(menuOptionRoot) {
			case 1:
				createEmployee();
				break;
			case 2:
				createProduct();
				break;
			case 3:
				showReport();
				await();
				break;
			case 4:
				printf("\nLogout: (sair)");
				fflush(stdin);
				gets(logoutRoot);
				break;
			default:
				printf("\nInvalid Option, try again!");
		}				
	}while(strcmp(logoutRoot, "sair") != 0 );
	printf("\nfinishing...");
	await();
}

void createProduct() {
	int c = 0;
	do{
		system("cls");
		printf("\nREGISTER PRODUCTS");
		printf("\nProduct name: ");
		fflush(stdin);
		gets(product[c].name);
		printf("\nQuantity: ");
		scanf("%d", &product[c].quantity);
		printf("\nValue: $");
		scanf("%f",&product[c].price);
		c++;
		printf("Save another product (y)? to exit (sair): ");
		fflush(stdin);
		gets(sair);		
	}while( strcmp(sair, "sair") != 0 );
	printf("Product %s", product[1].name);
	printf("\nSuccess!");
	printf("\nfinishing...");
	await();
}

void sale() {
	int i, y, choice, quantity;
	int idReport = 0;
	int remainQuantity;
	char name[20];
	
	do{
		system("cls");
		printf("\nMENU PRODUCTS\n");
		printf("\nID -- Name -- Price -- Quantity");
		for( i=0; i<5; i++ ){
			printf("\n%d -- %s   -- $%.2f -- %d", i, product[i].name, product[i].price, product[i].quantity);
		}
		
		printf("\nChoice your product!\n-->");
		scanf("%d",&choice);
		
		for(y=0; y<5; y++){
			if(y == choice){
				//char newName[10] = product[y].name;
				do{
					printf("\nQuantity: ");
					scanf("%d",&quantity);
					remainQuantity = product[y].quantity - quantity;
					if(remainQuantity < 0) {
						printf("\nQuantity unavailable, try again!");
						await();	
					}
				}while( remainQuantity < 0);
				float valueIten = product[y].price * quantity;
				
				product[y].quantity = remainQuantity;
				
				report[idReport].name[20] = product[y].name ;
				report[idReport].quantity = quantity;
				report[idReport].total = valueIten;
			}
		}
		
		idReport++;
		
		printf("Sale another (y)? to exit (sair): ");
		fflush(stdin);
		gets(sair);
	}while(strcmp(sair, "sair") != 0 );
	
	//printf("Thank you! %s", report[1].name);
	printf("\nSuccess!");
	printf("\nfinishing...");
	await();
	
}

void showReport() {
	int i;
	float sumTotal = 0;
	
	do{
		system("cls");
		printf("\nREPORT\n");
		printf("\nID -- Name -- Quantity -- Total ");
		for( i=0; i<5; i++ ){
			printf("\n%d -- %s   -- %d  --  $%.2f", i, report[i].name, report[i].quantity, report[i].total);
			sumTotal = sumTotal + report[i].total;
		}
		printf("\n------------------------- Total $%.2f", sumTotal);
		
		printf("to exit (sair): ");
		fflush(stdin);
		gets(sair);
	}while(strcmp(sair, "sair") != 0 );
}





