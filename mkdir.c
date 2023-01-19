#include<stdio.h>
#include<sys/stat.h>

void main(int ttt,char *t[],char*a[]){
	int  status;
	status=mkdir(t[0],0777);
	if(status==-1){


		printf("Directory not created!!");
		}


}

