#include<stdio.h>
#include<time.h>
#include<string.h>

void main(int argc,char *y[]){
	if(strcmp(y[0],"-R")==0){
	time_t Time;
	char array[1000];
	time(&Time);	
	struct tm *ptr=localtime(&Time);
	strftime(array,1000,"%a, %d %b %Y %H:%M:%S %z",ptr);
	printf("%s",array);
		printf("\n");
	}
	else{
	time_t k;
	time(&k);
	char l[1000];
	struct tm *ptr=localtime(&k);
	strftime(l,1000,"%a %d %b %Y %H:%M:%S %p %Z ",ptr);
	printf("%s",l);	
	printf("\n");
		}	
}
