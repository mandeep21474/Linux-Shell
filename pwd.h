#include<unistd.h>

void pwdfunc(){
	char A[1000];
	printf("Current directory-- >  %s\n",getcwd(A,1000));
	}
