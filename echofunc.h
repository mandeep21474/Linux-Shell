void echofunc(int numofarguments,char *a[]){
	for(int i=1;i<numofarguments;i++){
		printf("%s ",strtok(a[i],"\n"));
	}
		printf("\n");	
	}
void echofunc1(int numofarguments,char* aa[]){
	for(int i=2;i<numofarguments;i++){

		printf("%s ",strtok(aa[i],"\n"));
		}


}
