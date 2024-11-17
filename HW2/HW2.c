#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
/* Function prototypes */
void readFile();
void displayRecords();
void updateRecord();
void createRecord();
void deleteRecord();
void writeToFile(int count);

struct recordData{
    int id;
	char firstName[15];
	char lastName[15];   
	double phoneNum;   
	char adress[100]; 
}; struct recordData record;

	int id1[100];
	char firstName1[100][15];
	char lastName1[100][15];
	double phoneNum1[100];
	char address1[100][100];
	char chooseUpdate[50];

void main(){
	char choice[100];
	int chosen;
	int menu=0;
	FILE *file;
	while(menu==0){
		printf("ADDRESS BOOK\n1-List all records\n2-Uptade a record\n3-Create a new record\n4-Delete a record\n5-Exit\nEnter your choice : ");
	    scanf("%s",&choice); //scans the choice as a string
	    //controls the input
    	while(strcmp(choice,"1")!=0 && strcmp(choice,"2")!=0 && strcmp(choice,"3")!=0 && strcmp(choice,"4")!=0 && strcmp(choice,"5")!=0){
		    printf("\nInvalid input. Please enter 1, 2, 3, 4 or 5.\n");
	    	scanf("%s",&choice);
    	}
    	chosen=atoi(choice); //converts string to integer
		//if the file does not exist, creates it 
        if((file = fopen("AddressBook.txt","r"))==NULL){
	    	printf("\nThe file did not exist, now it is created.");
	    	file=fopen("AddressBook.txt","w");
	    	fclose(file);
	    }
	    readFile(); //reads the file
    	
    	switch(chosen){
    		case 1: 
    	    	printf("\n");
    	    	displayRecords();
    	    	break;
    		
    		case 2:
    			printf("\n");
    			updateRecord();
    			break;
    			
    		case 3:
    			printf("\n");
    			createRecord();
    			break;
    			
    		case 4:
    			printf("\n");
    			deleteRecord();
    			break;
    			
    		case 5:	
    		    printf("\nBye..");
    		    menu=1;
    		    break;
		}
    }
}
void readFile(){
	FILE *file;
	int i=0; 
	int j=0;
	file=fopen("AddressBook.txt","r"); //opens the text file for reading
	while(!feof(file)){
		fscanf(file,"%d%s%s%lf%s",&record.id,record.firstName,record.lastName,&record.phoneNum,record.adress);
		//assign the values which are read from the file to arrays
        id1[i]=record.id;
	    strcpy(firstName1[i],record.firstName);
    	strcpy(lastName1[i],record.lastName);
    	phoneNum1[i]=record.phoneNum;
    	strcpy(address1[i],record.adress);
		i++;
		j++;	
	}			
	fclose(file); //closes the text file
}
void displayRecords(){
		FILE *file;
	int i=0; 
	int j=0;
	int k=0;
	int count=0;
	file=fopen("AddressBook.txt","r");
	while(!feof(file)){
		fscanf(file,"%d%s%s%lf%s",&record.id,record.firstName,record.lastName,&record.phoneNum,record.adress);
		if(record.id==0 && record.phoneNum==0){ //if the file is empty
			printf(" ");
		}
		//assign values which are read from the file to arrays
        id1[i]=record.id;
	    strcpy(firstName1[i],record.firstName);
    	strcpy(lastName1[i],record.lastName);
    	phoneNum1[i]=record.phoneNum;
    	strcpy(address1[i],record.adress);
		i++;
		j++;	
	}
	for(i=0; i<=100; i++){ //counts the empty elements in the array
		if(id1[i]==0){
			count++;
		}
	}	
	//sorting alphabetically according to last names
	char array[100][100];
	int temp;
	double temp1;
    for(i=1;i<101;i++){
    	for(j=0;j<100-count;j++){
    		if(strcmp(lastName1[j],lastName1[j+1])==1){
			    strcpy(array[1],lastName1[j]);
		    	strcpy(lastName1[j],lastName1[j+1]);
		    	strcpy(lastName1[j+1],array[1]);
		    	
		    	temp=id1[j];
		    	id1[j]=id1[j+1];
		    	id1[j+1]=temp;
		    	
		    	strcpy(array[2],firstName1[j]);
		    	strcpy(firstName1[j],firstName1[j+1]);
		    	strcpy(firstName1[j+1],array[2]);
		    	
		    	temp1=phoneNum1[j];
		    	phoneNum1[j]=phoneNum1[j+1];
		    	phoneNum1[j+1]=temp1;
		    	
		    	strcpy(array[3],address1[j]);
		    	strcpy(address1[j],address1[j+1]);
		    	strcpy(address1[j+1],array[3]);
	    	}
		}
	}
	if(record.id!=0 && record.phoneNum!=0){ //if the file is not empty
    	printf("%-10s%-15s%-15s%0s%25s\n","No","First Name","Last Name","Phone Num","Address");
    	printf("%-10s%-15s%-15s%0s%25s\n","--","----------","---------","---------","-------");
		for(k=0;k<101-count;k++){
		    printf("%-10d%-15s%-15s%0.0f%30s\n",id1[k],firstName1[k],lastName1[k],phoneNum1[k],address1[k]);
	    }
	}
	printf("\n");			
	fclose(file); //closes the file
}
void updateRecord(){ //update a record
	char *stringPtr; 
	char s_idno[100];
	char s_phoneNum1[100];
	int idno_i=0;
	int idno;
	int count=0;
	int a;
	int chosenUpdate;
	int i;
	printf("Please enter the record number of the person you want to update : ");
	scanf("%s",&s_idno); //scans the record number as a string
	for(i=0; s_idno[i]!='\0'; i++){
		while(!(48<=s_idno[i] && s_idno[i]<=57)){ //if it includes characters other than numbers, it will be an invalid input
	    	printf("\nInvalid input. Enter again: ");
	    	scanf("%s",&s_idno);
	    	i=0;
	    }
	}
	idno=atoi(s_idno); //converts the input to integer
	for(idno_i=0; idno_i<=100; idno_i++){
		if(idno==id1[idno_i]){ //searches if the record number user entered does exist
			a=1;
			break;
		}
		else{
			a=0;
		}
	}
	for(i=0; i<=100; i++){ //counts the empty elements in the array
		if(id1[i]==0){
			count++;
		}
	}	
	if(a==1){ //if the record number exists
    	printf("\n%-10d%-15s%-15s%0.0f%30s\n",idno,firstName1[idno_i],lastName1[idno_i],phoneNum1[idno_i],address1[idno_i]); //prints the record
		printf("\n1 - Update phone number\n2 - Update address\nEnter your choice: "); 
		scanf("%s",&chooseUpdate);
		while(strcmp(chooseUpdate,"1")!=0 && strcmp(chooseUpdate,"2")!=0){ //controls the input, it should be 1 or 2
		    printf("\nInvalid input. Please enter 1 or 2");
	    	scanf("%s",&chooseUpdate);
    	}
    	chosenUpdate=atoi(chooseUpdate); //converts the input to integer
    	if(chosenUpdate==1){ //if user wants to update the phone number 
    		printf("Enter the new phone number : ");
    		scanf("%s",&s_phoneNum1); //scans the new phone number
	    	for(i=0; s_phoneNum1[i]!='\0'; i++){ //controls the input
		     	while(!(48<=s_phoneNum1[i] && s_phoneNum1[i]<=57)){
	    	        printf("\nInvalid input. Enter phone number again: ");
	    	        scanf("%s",&s_phoneNum1);
	    	        i=0;
	            }
	        }
	        phoneNum1[idno_i]=strtod(s_phoneNum1,&stringPtr); //converts string to double
    		printf("%-10d%-15s%-15s%0.0f%30s\n",idno,firstName1[idno_i],lastName1[idno_i],phoneNum1[idno_i],address1[idno_i]); //prints the updated record
		}
		if(chosenUpdate==2){ //if user wants to update the address
			printf("Enter the new address : ");
			scanf("%s",address1[idno_i]); //scans the new address
	    	for(i=0; address1[idno_i][i]!='\0'; i++){ //controls the input
		     	while(!((65<=address1[idno_i][i] && address1[idno_i][i]<=90) || (97<=address1[idno_i][i] && address1[idno_i][i]<=122) || (address1[idno_i][i]=='/'))) {
	        	    printf("\nInvalid input. Enter address again: ");
	        	    scanf("%s",&address1[idno_i]);
	        	    i=0;
	            }
	        }
			printf("%-10d%-15s%-15s%0.0f%30s\n",idno,firstName1[idno_i],lastName1[idno_i],phoneNum1[idno_i],address1[idno_i]); //prints the updated input
		}
		writeToFile(count); //writes the updates to the file
	}
	if(a==0){ //if record number does not exist
		printf("\nNo record to update.\n");
	}
	printf("\n");
}
void createRecord(){ //create a record
	char s_idno[100];
	char s_phoneNum1[100];
	char *stringPtr;
	int idno;
	int a,i;
	int count=0;
	printf("Enter the record number to create a new record : ");
	scanf("%s",&s_idno); //scans the record number as a string
	for(i=0; s_idno[i]!='\0'; i++){ 
		while(!(48<=s_idno[i] && s_idno[i]<=57)){ //if it includes characters other than numbers, it will be an invalid input
	    	printf("\nInvalid input. Enter the record number again: ");
	    	scanf("%s",&s_idno);
	    	i=0;
	    }
	}
	idno=atoi(s_idno); //converts the input to integer
	for(i=0; i<=100; i++){
		if(idno==id1[i]){ //searches if the record number user entered does exist
			a=1;
			break;
		}
		else{
			a=0;
		}
	}
	for(i=0; i<=100; i++){
		if(id1[i]==0){ //counts the empty elements in the array
			count++;
		}
	}
	if(a==1){ //if the record number exists
		printf("\nThe record already exists\n");
	}
	if(a==0){ //if the record number does not exist
		id1[100-count+1]=idno;
		printf("\nPlease use English characters\nEnter the first name: "); 
		scanf("%s",firstName1[100-count+1]); //scans the first name
	    for(i=0; firstName1[100-count+1][i]!='\0'; i++){ //controls the characters of first name
	    	while(!((65<=firstName1[100-count+1][i] && firstName1[100-count+1][i]<=90) || (97<=firstName1[100-count+1][i] && firstName1[100-count+1][i]<=122))) {
	        	printf("\nInvalid input. Enter first name again: ");
	        	scanf("%s",firstName1[100-count+1]);
	        	i=0;
	        }
     	}
		printf("Enter the last name: ");
		scanf("%s",lastName1[100-count+1]); //scans the last name
        for(i=0; lastName1[100-count+1][i]!='\0'; i++){ //controls the characters of last name
		    	while(!((65<=lastName1[100-count+1][i] && lastName1[100-count+1][i]<=90) || (97<=lastName1[100-count+1][i] && lastName1[100-count+1][i]<=122))){
	    	        printf("\nInvalid input. Enter last name again: ");
	    	        scanf("%s",&lastName1[100-count+1]);
	    	        i=0;
	        }
	    }
		printf("Enter the phone number: ");
		scanf("%s",&s_phoneNum1); //scans the phone number as a string
		for(i=0; s_phoneNum1[i]!='\0'; i++){
		  	while(!(48<=s_phoneNum1[i] && s_phoneNum1[i]<=57)){
	    	    printf("\nInvalid input. Enter phone number again: ");
	    	    scanf("%s",&s_phoneNum1);
	    	    i=0;
	        }
	    }
	    phoneNum1[100-count+1]=strtod(s_phoneNum1,&stringPtr); //converts string to double
		printf("Enter the address: ");
		scanf("%s",address1[100-count+1]); //scans the address
		for(i=0; address1[100-count+1][i]!='\0'; i++){ //controls the characters of address
		  	while(!((65<=address1[100-count+1][i] && address1[100-count+1][i]<=90) || (97<=address1[100-count+1][i] && address1[100-count+1][i]<=122) || (address1[100-count+1][i]=='/'))){
	    	    printf("\nInvalid input. Enter address again: ");
	    	    scanf("%s",&address1[100-count+1]);
	    	    i=0;
	        }
	    }
		writeToFile(count-1); //writes the new created record to the file
	}
	printf("\n");
}
void deleteRecord(){ //delete a record
	char s_idno[100];
	int i,idno,idno_i,a;
	int count=0;
	printf("Enter the record number to delete : ");
	scanf("%s",&s_idno); //scans the record number as a string
	for(i=0; s_idno[i]!='\0'; i++){ //controls the input
		while(!(48<=s_idno[i] && s_idno[i]<=57)){
	    	printf("Invalid input. Enter again: ");
	    	scanf("%s",&s_idno);
	    	i=0;
	    }
	}
	idno=atoi(s_idno); //converts the string to integer
    for(idno_i=0; idno_i<=100; idno_i++){
		if(idno==id1[idno_i]){ //searches if the record number exists
			a=1;
			break;
		}
		else{
			a=0;
		}
	}
	for(i=0; i<=100; i++){ //counts the empty elements in the array
		if(id1[i]==0){
			count++;
		}
	}
	if(a==1){ //if the record number exists
		printf("%-10d%-15s%-15s%0.0f%30s\n",id1[idno_i],firstName1[idno_i],lastName1[idno_i],phoneNum1[idno_i],address1[idno_i]); //prints the record
		printf("Deleted.\n");
		//deletes the record 
		for(i=idno_i;i<=100-count;i++){ //changes the values of the array elements
			id1[i]=id1[i+1];
			strcpy(firstName1[i],firstName1[i+1]);
			strcpy(lastName1[i],lastName1[i+1]);
			phoneNum1[i]=phoneNum1[i+1];
			strcpy(address1[i],address1[i+1]);
		}
		id1[100-count]=0;
		strcpy(firstName1[100-count],"");
		strcpy(lastName1[100-count],"");
		phoneNum1[100-count]=0;
		strcpy(address1[100-count],"");
		writeToFile(count+1);
	}
	if(a==0){ //if the record number does not exist
		printf("No record to delete.\n");
	}
	printf("\n");
}
void writeToFile(int count){ //write to file
	int row=0;
	int i;
	FILE *writeFile;
	writeFile=fopen("AddressBook.txt","w"); //opens the file for writing
	for(row=0;row<=(100-count);row++){
		fprintf(writeFile,"\n%d\t%s\t%s\t%.0f\t%s",id1[row],firstName1[row],lastName1[row],phoneNum1[row],address1[row]); //writes the records to the file
	}
	fclose(writeFile); //closes the file
	for(i=0;i<=100;i++){
		id1[i]=0;
		strcpy(firstName1[i],"");
		strcpy(lastName1[i],"");
		phoneNum1[i]=0;
		strcpy(address1[i],"");
	}
	//deletes all contents
	record.id=0;
	strcpy(record.firstName," ");
	strcpy(record.lastName," ");
	record.phoneNum=0;
	strcpy(record.adress," ");
}
