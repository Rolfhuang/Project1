#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1000

void replaceCh(char *str, const char *oldCh, const char *newCh);

int main(){
	FILE *fptr;
	FILE *ftemp;
	char path[100];
	char buffer[BUFFER_SIZE];
	char oldCh[100], newCh[100];
	printf("Enter source: ");
	scanf("%s", path);
	printf("replace: ");
	scanf("%s", oldCh);
	printf("new: ");
	scanf("%s", newCh);
	
	fptr = fopen(path, "r");
	ftemp = fopen("destination.txt","w");
	
	while((fgets(buffer, BUFFER_SIZE, fptr)) != NULL){
		replaceCh(buffer, oldCh, newCh);
		fputs(buffer,ftemp);
	}
	fclose(fptr);
	fclose(ftemp);
	//remove(path);
	//rename("destination.txt",path);
	printf("\nSuccessfully");
	return 0;
}
void replaceCh(char *str, const char *oldCh, const char *newCh){
	char *pos, temp[BUFFER_SIZE];
	int index = 0;
	int owlen;
	owlen = strlen(oldCh);
	while ((pos = strstr(str, oldCh)) != NULL){
		strcpy(temp, str);
		index = pos - str;
		str[index] = '\0';
		strcat(str,newCh);
		strcat(str, temp + index + owlen);
	}
}
