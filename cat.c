#include<stdio.h>
#include<stdlib.h>

void main(int w,char *rr[]){
	FILE *p;
	char u[1000];
	char *s=rr[0];
	p=fopen(s,"r");
	if(p==0){
		printf("No such file");
		}
	else{
		while(fgets(u,1000,p)){
			printf("%s",u);
			}
	}



}
