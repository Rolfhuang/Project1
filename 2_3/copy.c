#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fptr1, *fptr2;
	char filename[100], c;
	printf("Enter for read\n");
	scanf("%s", filename);
	fptr1 = fopen(filename, "r");
	if(fptr1 == NULL){
		printf("Can't open file %s \n", filename);
		exit(0);
	}
	printf("Enter for write\n");
	scanf("%s", filename);
	fptr2 = fopen(filename,"w");
	if(fptr2 == NULL){
		printf("Can't open file %s \n", filename);
		exit(0);
	}
	c = fgetc(fptr1);
	while(c != EOF){
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}
	printf("\nCopy Successful\n");
	fclose(fptr1);
	fclose(fptr2);
	return 0;
	
	
}
