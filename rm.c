#include<stdio.h>

void main(int f,char*q[]){
	int status=remove(q[0]);
	if(status!=0){
		printf("Not removed!!");
		

		}
	else if(status==0){
		printf("Removed!!");
	
	}

	
	

	
}
