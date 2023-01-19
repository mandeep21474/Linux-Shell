#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"echofunc.h"
#include"pwd.h"
#include<sys/wait.h>

	char *inputenter;
	char *entered;
	char *initial;
	char* typeofcommand;
	int numofargu;
	char*argumentslist[1000];

void input(){

	inputenter=(char *)malloc(1000);
	entered=fgets(inputenter,1000,stdin);
	initial=strtok(inputenter," ");
	while(initial!=NULL){
	argumentslist[numofargu]=initial;
	numofargu++;
	initial=strtok(0," ");
		
		}
}
void main(){
	input();
	typeofcommand=strtok(argumentslist[0],"\n");
	if(strcmp(typeofcommand,"echo")==0){
		if(numofargu<=1){
			printf("Enter arguments first..\n");
			}
		else{
			if(strcmp(strtok(argumentslist[1],"\n"),"-n")==0){
				echofunc1(numofargu,argumentslist);
				}
			if(strcmp(strtok(argumentslist[1],"\n"),"-N")==0){
				printf("error\n");
				}
			else if(strcmp(strtok(argumentslist[1],"\n"),"-n")!=0){
			echofunc(numofargu,argumentslist);
			}

			}

	}
	else if(strcmp(typeofcommand,"pwd")==0){
		if(numofargu==1){
			
			pwdfunc();
			}
		else if(numofargu==2){


			if(strcmp(strtok(argumentslist[1],"\n"),"-L")==0){

				pwdfunc();
				}
			else{

				printf("Error\n");
				}
		}
		else{
			printf("error\n");
			}

	}
	else if(strcmp(typeofcommand,"cat")==0){
		if(numofargu!=2){
			printf("Enter command correctly\n");
			
			}
		else{
		int id=fork();
		if(id==0){
			char * tosent=strtok(argumentslist[1],"\n");  // to remove new line to get exact word
									
			execl("./cat",tosent,NULL);
	
			}
		else {
			wait(NULL);
			printf("\nparent waited!! \n");
			
			}
		
		}
	
	}
	else if(strcmp(typeofcommand,"mkdir")==0){
		if(numofargu==1){
			printf("Enter command correctly\n");
			}
		else{
			if(numofargu==3){
			if(strcmp(strtok(argumentslist[1],"\n"),"-v")==0){
				int id=fork();
				if(id==0){
						execl("./mkdir",strtok(argumentslist[2],"\n"),NULL);
					}
				else{
					wait(NULL);
					printf("mkdir:created directory \"%s\"",argumentslist[2]);
					printf("\nparent waited!!\n");
					}
			

				}
			}	

			else{
			int id = fork();
			if(id==0){

				char *tosentt=strtok(argumentslist[1],"\n");
				execl("./mkdir",tosentt,NULL);
				}
			else{
				wait(NULL);
				printf("\nparent process waited\n");
				}
			


		
			}
		}
	
	}
	else if(strcmp(typeofcommand,"date")==0){
			if(numofargu==2){
			if(strcmp(strtok(argumentslist[1],"\n"),"-R")==0){
			int id=fork();
				if(id==0){
					execl("./date",strtok(argumentslist[1],"\n"),NULL);
					}		
				else{
				wait(0);
					printf("\nparent waited\n");
						
				}
			}
		}
			

			else if(numofargu>2){
					printf("Error\n");
				}
			else if(numofargu==1){
			int id=fork();
			if(id==0){
				execl("./date",strtok(argumentslist[0],"\n"),NULL);
				}
			else{

				wait(NULL);
				printf("\nparent process waited!!\n");
				}	
	
			}

			}
	else if(strcmp(typeofcommand,"rm")==0){

			if(numofargu==1){
				printf("Enter command properly!!\n");
				}
			else if(numofargu==2){	
				int id=fork();
				if(id==0){
					execl("./rm",strtok(argumentslist[1],"\n"),NULL);
					}
				else{

				wait(NULL);
				printf("\nparent waited!!\n");
					}

				}
			else if(strcmp(strtok(argumentslist[1],"\n"),"-i")==0){
			printf("remove regular file %s?",strtok(argumentslist[2],"\n"));
				char r[10];
				scanf("%c",&r);
				if(r[0]=='y'){
					int id=fork();
					if(id==0){

						execl("./rm",strtok(argumentslist[2],"\n"),NULL);
						}
					else{
						wait(0);
							printf("\nparent waited\n");

							}
					} 

				
				}
			else{
					printf("Error\n");
					}
		

		}

	else{


		printf("Error!!\n");
		}
}
