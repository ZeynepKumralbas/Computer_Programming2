/*       HW1
   Zeynep Kumralbaþ 
      150115051      */

#include<stdio.h>
#include<math.h>
#include<string.h>

/* Function prototypes */
void Line1(double a,double b);
void Line2(double b);

main(){

    char string1[100];
	int chosen;
	
	char ch;
	char ch1;
	char ch2;
	
	int number1;
	int number2;
	int number3;
	
	double a,b,c,x,xd,bd;
    int row,column,xi,bi;
	
	double x1,x2,x1d,x2d;
	int x1i,x2i;
	
	double r;
	
	printf("Which shape would you like to draw?\n1.Line\n2.Parabola\n3.Circle\n4.Exit\n");
	scanf("%s",&string1); //scans the input as a string
	//controls the input, it should be 1, 2, 3 or 4
	while((strcmp(string1,"1"))!=0 && (strcmp(string1,"2"))!=0 && (strcmp(string1,"3"))!=0 && (strcmp(string1,"4"))!=0){ //checks the input
		printf("Invalid choice. Please enter a number 1,2,3 or 4.\n");
		scanf("%s",&string1);
	}
	chosen=atoi(string1); //changes the string to integer
	
	switch(chosen){
		
		case 1: //Line
			printf("Line formula: y=ax+b\nPlease enter a and b\n");
			printf("a: ");
			if(scanf("%lf%c",&a,&ch)&&(ch=='\n'||ch=='\0')){ //scans a, it can be double
				number1=1;
			}
			else{
				number1=0;
				printf("Invalid input.");
				break;
			}

			printf("b: ");
			if(scanf("%lf%c",&b,&ch1)&&(ch1=='\n'||ch1=='\0')){ //scans b, it can be double
				number2=1;
			}
			else{
				number2=0;
				printf("Invalid input.");
				break;
			}
			if(number1==1 && number2==1){
				if(a!=0){
					Line1(a,b); 
				}
				if(a==0){ 
					Line2(b);
				}
			}
			break;
			
		case 2: //Parabola
			printf("Parabola formula is y=ax^2+bx+c\nPlease enter coefficients a, b and c\n");
			printf("a: ");
			if(scanf("%lf%c",&a,&ch)&&(ch=='\n'||ch=='\0')){ //scans a, it can be double
				number1=1;
			}
			else{
				number1=0;
				printf("Invalid input.");
				break;
			}
			
			printf("b: ");
			if(scanf("%lf%c",&b,&ch1)&&(ch1=='\n'||ch1=='\0')){ //scans b, it can be double
				number2=1;
			}
			else{
				number2=0;
				printf("Invalid input.");
				break;
			}
			
			printf("c: "); //scans c
			if(scanf("%lf%c",&c,&ch2)&&(ch2=='\n'||ch2=='\0')){
				number3=1;
			}
			else{
				number3=0;
				printf("Invalid input.");
				break;
			}
			if(number1==1 && number2==1 && number3==1){
			    if(a!=0){
				    for(row=11; row>=-10; row--){ //for loop to control the rows
				        x1=(-b+pow((pow(b,2)-4*a*(c-row)),1.0/2))/(2*a); //first root of the equation
				        x2=(-b-pow(pow(b,2)-4*a*(c-row),1.0/2))/(2*a); //second root of the equation
				        x1i=(int)x1;
				        x1d=(double)x1i;
				        x2i=(int)x2;
				        x2d=(double)x2i;
			            for(column=-10; column<=11; column++){ //for loop to control the columns
			                //all possibilities
			              	if(row==11 && column==0){ 
			    	         	printf("y");
				        	}
				        	if(row==0 && column==11){
					    		printf("x");
				    		}
			        		if((pow(b,2)-4*a*(c-row))>=0){ //if delta>=0
			    	    		if(row!=0 && column!=0 && column==x1i && column!=x2i){
			    		    		if(x1==x1d){ //checks the statement to show only integer values
			    			    		printf("*");
						    		}
			    		    		if(x1!=x1d){
			    		    			printf(" ");
						    		}
					    		}
				        		if(row!=0 && column!=0 && column!=x1i && column==x2i){
						       	    if(x2==x2d){ //checks the statement to show only integer values
						        	 	printf("*");
						       	    	}
					         		if(x2!=x2d){
						         	   printf(" ");
					         		}
					       	    }
					       	    if(row!=0 && column!=0 && column==x1i && column==x2i){
						    	    if(x1!=x1d && x2!=x2d){ //checks the statement to show only integer values
						    		   printf(" ");
						       	    }
						       	    else{
							       	    printf("*");
						        	}
					      	    }
					        	if(row!=0 && column!=0 && column!=x1i && column!=x2i){
						       	    printf(" ");
				        		}
				    	    	if(row!=0 && column==0 && column==x1i && column!=x2i && row!=11){
						        	if(x1==x1d){ //checks the statement to show only integer values
						    	    	printf("*");
					    	    	}
						      	    if(x1!=x1d){
							       	    printf("|");
						       	    }
					        	}
					       	    if(row!=0 && column==0 && column!=x1i && column==x2i && row!=11){
						       	    if(x2==x2d){ //checks the statement to show only integer values
							        	printf("*");
						        	}
						        	if(x2!=x2d){
						          		printf("|");
						       	    }
					        	}
					       	    if(row!=0 && column==0 && column==x1i && column==x2i && row!=11){
						       	    if(x1!=x1d && x2!=x2d){ //checks the statement to show only integer values
						    	    	printf("|");
					     	    	}
						        	else{
						     	    	printf("*");
						        	}
					        	}
					        	if(row!=0 && column==0 && column!=x1i && column!=x2i && row!=11){
						        	printf("|");
					       	    }
					       	    if(row==0 && column!=0 && column==x1i && column!=x2i && column!=11){
					     	    	if(x1==x1d){ //checks the statement to show only integer values
						   	        	printf("*");
						       	    }    	
						        	if(x1!=x1d){
					             		printf("-");
					    	    	}							
					        	}
					        	if(row==0 && column!=0 && column!=x1i && column==x2i && column!=11){
						        	if(x2==x2d){ //checks the statement to show only integer values
							       	    printf("*");
						        	}
						       	    if(x2!=x2d){
							        	printf("-");
						        	}
					        	}
					        	if(row==0 && column!=0 && column!=x1i && column!=x2i && column!=11){
						       	    printf("-");
					        	}
					        	if(row==0 && column!=0 && column==x1i && column==x2i && column!=11){
						     	    if(x1!=x1d && x2!=x2d){ //checks the statement to show only integer values
							        	printf("-");
						    	    }
						        	else{
							        	printf("*");
						        	}
					        	}
				 	        	if(row==0 && column==0 && column==x1i && column!=x2i){
						        	if(x1==x1d){ //checks the statement to show only integer values
							        	printf("*");
						        	}
						        	if(x1!=x1d){
							       	    printf("|");
						        	}
					        	}
					        	if(row==0 && column==0 && column!=x1i && column==x2i){
						        	if(x2==x2d){ //checks the statement to show only integer values
						      	    	printf("*");
						        	}
						        	if(x2!=x2d){
							        	printf("|");
						        	}
					       	    }
					        	if(row==0 && column==0 && column!=x1i && column!=x2i){
						        	printf("|");
					        	}
					        	if(row==0 && column==0 && column==x1i && column==x2i){
						       	    if(x1!=x1d && x2!=x2d){ //checks the statement to show only integer values
							       	    printf("|");
						        	}
						            else{
							        	printf("*");
						        	}
					        	}
					        	if(column==11){
						        	printf("\n");
					        	}
				        	}
				        	if((pow(b,2)-4*a*(c-row))<0){ //if delta<0
					        	if(row==0 && column!=0 && column!=11){
						        	printf("-");
					        	}
				    	    	if(row==0 && column==0){
						        	printf("|");
					        	}
				        		if(row!=0 && column==0 && row!=11){
						        	printf("|");
					        	}
					        	if(row!=0 && column!=0){
						        	printf(" ");
					        	}
					        	if(column==11){
						        	printf("\n");
					        	}
				        	}
				    	}
			    	}
		    	}
			    if(a==0 && b!=0){
				    printf("This is a line, not a parabola.\n");
				    Line1(b,c);
			    }
			    if(a==0 && b==0){
				    printf("This is a line, not a parabola.\n");
				    Line2(c);
			    }
		    }
		    else{
			    printf("Invalid input.");
	        }
			break;
			
	    case 3:	//Circle
	        printf("Circle formula is (x-a)^2 + (y-b)^2 = r^2\nPlease enter center's coordinates (a,b) and radius: \n");
	        printf("a: ");
			if(scanf("%lf%c",&a,&ch)&&(ch=='\n'||ch=='\0')){ //scans a, it can be double
				number1=1;
			}
			else{
				number1=0;
				printf("Invalid input.");
				break;
			}
			
			printf("b: ");
			if(scanf("%lf%c",&b,&ch1)&&(ch1=='\n'||ch1=='\0')){ //scans b, it can be double
				number2=1;
			}
			else{
				number2=0;
				printf("Invalid input.");
				break;
			}
			
			printf("r: ");
			if(scanf("%lf%c",&r,&ch2)&&(ch2=='\n'||ch2=='\0')){ //scans r
				number3=1;
			}
			else{
				number3=0;
				printf("Invalid input.");
				break;
			}
			if(number1==1 && number2==1 && number3==1){ //scans the inputs a, b and r
				if(r>0){ //r>0
				    for(row=11; row>=-10; row--){ //for loop to control the rows
					    for(column=-10; column<=11; column++){ //for loop to control the columns
						    x1=pow(pow(r,2)-pow((row-b),2),(1.0/2))+a; //first root of the equation
						    x2=-pow(pow(r,2)-pow((row-b),2),(1.0/2))+a; //second root of the equation
						    x1i=(int)x1;
					    	x1d=(double)x1i;
					    	x2i=(int)x2;
					    	x2d=(double)x2i;
					     	//all possibilities
					        if(row==11 && column==0){
			    			    printf("y");
						    }
						    if(row==0 && column==11){
						    	printf("x");
						    }
			    		    if(row!=0 && column!=0 && column==x1i && column!=x2i){
			    			    if(x1==x1d){ //checks the statement to show only integer values
			    			    	printf("*");
						    	}
			    		    	if(x1!=x1d){
			    			    	printf(" ");
						    	}
					    	}
					    	if(row!=0 && column!=0 && column!=x1i && column==x2i){
						    	if(x2==x2d){ //checks the statement to show only integer values
							    	printf("*");
							    }
						    	if(x2!=x2d){
							    	printf(" ");
						    	}
						    }
					    	if(row!=0 && column!=0 && column==x1i && column==x2i){
							    if(x1!=x1d && x2!=x2d){ //checks the statement to show only integer values
							    	printf(" ");
						    	}
						    	else{
							    	printf("*");
						    	}
					    	}
						    if(row!=0 && column!=0 && column!=x1i && column!=x2i){
						    	printf(" ");
					    	}
					    	if(row!=0 && column==0 && column==x1i && column!=x2i && row!=11){
						    	if(x1==x1d){ //checks the statement to show only integer values
							    	printf("*");
						    	}
						    	if(x1!=x1d){
								    printf("|");
						    	}
						    }
						    if(row!=0 && column==0 && column!=x1i && column==x2i && row!=11){
							    if(x2==x2d){ //checks the statement to show only integer values
							    	printf("*");
							    }
							    if(x2!=x2d){
							    	printf("|");
							    }
						    }
					    	if(row!=0 && column==0 && column==x1i && column==x2i && row!=11){
						    	if(x1!=x1d && x2!=x2d){ //checks the statement to show only integer values
							    	printf("|");
							    }
						    	else{
								    printf("*");
							    }
					        }    
						    if(row!=0 && column==0 && column!=x1i && column!=x2i && row!=11){
							    printf("|");
						    }
						    if(row==0 && column!=0 && column==x1i && column!=x2i && column!=11){
						        if(x1==x1d){ //checks the statement to show only integer values
						        	printf("*");
						    	}
						    	if(x1!=x1d){
							    	printf("-");
							    }							
						    }
					    	if(row==0 && column!=0 && column!=x1i && column==x2i && column!=11){
							    if(x2==x2d){ //checks the statement to show only integer values
							        printf("*");
							    }
							    if(x2!=x2d){
								    printf("-");
							    }
						    }
						    if(row==0 && column!=0 && column!=x1i && column!=x2i && column!=11){
							    printf("-");
						    }
						    if(row==0 && column!=0 && column==x1i && column==x2i && column!=11){
						    	if(x1!=x1d && x2!=x2d){ //checks the statement to show only integer values
								    printf("-");
						    	}
							    else{
								    printf("*");
							    }
						    }
						    if(row==0 && column==0 && column==x1i && column!=x2i){
						    	if(x1==x1d){ //checks the statement to show only integer values
							    	printf("*");
						    	}
						    	if(x1!=x1d){
							    	printf("|");
						    	}
						    }
						    if(row==0 && column==0 && column!=x1i && column==x2i){
						    	if(x2==x2d){ //checks the statement to show only integer values
							    	printf("*");
						    	}
						    	if(x2!=x2d){
							    	printf("|");
						    	}
					    	}
					    	if(row==0 && column==0 && column!=x1i && column!=x2i){
						    	printf("|");
					    	}
						    if(row==0 && column==0 && column==x1i && column==x2i){
						    	if(x1!=x1d && x2!=x2d){ //checks the statement to show only integer values
							    	printf("|");
							    }
						    	else{
							    	printf("*");
						    	}
						    }
					    	if(column==11){
						    	printf("\n");
						    }						
					    }
				    }    
			    }
			    if(r<0){ //r cannot be negative
				    printf("The radius cannot be negative.");
			    }
		    	if(r==0){ //r cannot be zero
				    printf("The radius cannot be zero.");
			    }
		    }
		    else{
			    printf("Invalid input.");
		    }
			break;	
			
		case 4: //exit the program
			printf("Program ends. Bye...");
	}
}
//Function for drawing a line (when a!=0)
void Line1(double a, double b){ //a and b can be double
	double bd,row,column,x,xd;
	int xi;
	bd=(double)b;
	
	for(row=11; row>=-10; row--){ //for loop to control the rows
		x=(row-bd)/a;  //finds the x value in the equation
		xi=(int)x;     //if a and b are double, show only integer points
		xd=(double)xi;
		for(column=-10; column<=11; column++){ //for loop to control the columns
		    //all possibilities
			if(row==11 && column==0){
				printf("y");
			}
			if(row==0 && column==11){
				printf("x");
			}
			if(row!=0 && column!=0 && column==xi){
				if(x==xd){ //checks the statement to show only integer values
					printf("*");
				}
				if(x!=xd){
					printf(" ");
				}
			}
			if(row!=0 &&column!=0 && column!=xi){
				printf(" ");
			}
			if(row!=0 && column==0 && column!=xi && row!=11){
				printf("|");
			}
			if(row!=0 && column==0 && column==xi && row!=11){
				if(x==xd){ //checks the statement to show only integer values
					printf("*");
				}
				if(x!=xd){
					printf("|");
				}
			}
			if(row==0 && column!=0 && column==xi && column!=11){
				if(x==xd){ //checks the statement to show only integer values
					printf("*");
				}
				if(x!=xd){
					printf("-");
				}
			}
			if(row==0 && column!=0 && column!=xi && column!=11){
				printf("-");
			}
			if(row==0 && column==0 && column!=xi){
				printf("|");
			}
			if(row==0 && column==0 && column==xi){
				if(x==xd){ //checks the statement to show only integer values
					printf("*");
				}
				if(x!=xd){
					printf("|");
				}
			}
			if(column==11){
				printf("\n");
			}
		}
	}
}
//Function for drawing a line (when a=0)
void Line2(double b){
	int bi;
	double bd;
	double row,column;
	bi=(int)b;    //if b is double, show only integer points
	bd=(double)bi;
	
	for(row=11; row>=-10; row--){ //for loop to control the rows
		for(column=-10; column<=11; column++){ //for loop to control the columns
		    //all possibilities
		    if(row==11 && column==0){
			    printf("y");
			}
			if(row==0 && column==11){
				printf("x");
			}
			if(row!=0 && column!=0 && row==bi){
				if(b==bd){ //checks the statement to show only integer values
					printf("*");
				}
				if(b!=bd){
					printf(" ");
				}
			}
			if(row!=0 && column!=0 && row!=bi){
				printf(" ");
			}
			if(row!=0 && column==0 && row!=bi && row!=11){
				printf("|");
			}
			if(row!=0 && column==0 && row==bi && row!=11){
				if(b==bd){ //checks the statement to show only integer values
					printf("*");
				}
				if(b!=bd){
					printf("|");
				}
			}
			if(row==0 && column!=0 && row==bi && column!=11){
				if(b==bd){ //checks the statement to show only integer values
					printf("*");
				}
				if(b!=bd){
					printf("-");
				}
			}
			if(row==0 && column!=0 && row!=bi && column!=11){
				printf("-");
			}
			if(row==0 && column==0 && row!=bi){
				printf("|");
			}
			if(row==0 && column==0 && row==bi){
				if(b==bd){ //checks the statement to show only integer values
					printf("*");
				}
				if(b!=bd){
					printf("|");
				}
			}
			if(column==11){
				printf("\n");
			}
		}			
	}
}
