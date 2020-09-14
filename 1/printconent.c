#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char* argv[]){
	FILE *fd;
	int returnval;
	char* filepath = argv[1],c;
	returnval = access (filepath, F_OK);
	if(returnval == 0){
		printf("\n %s exists\n", filepath);
	}
	else {
		if (errno == ENOENT){
			printf("%s No such file or directory.\n", filepath);
		}
		else if(errno == EACCES)
			printf("%s Permission denied. \n", filepath);
	}
	returnval =0;
	returnval = access (filepath, R_OK | W_OK);
	if(returnval == 0){
		printf("\n %s has Read permissions.\n", filepath);
		printf("\n %s has Write permissions.\n", filepath);

	}	
	else {
		if(errno == ENOENT)
			printf("%s No such file or directory.\n", filepath);
		else if(errno == EACCES)
			printf("%s Read permission denied.\n", filepath);
			printf("%s Write permission denied.\n", filepath);
	}
	fd = fopen(filepath, "r");
	if(fd == NULL){
		printf("Cannot open file\n");
		exit(0);
	}
	c = fgetc(fd);
	while(c != EOF){
		printf("%c", c);
		c = fgetc(fd);
	}
	fclose(fd);
	return 0;
}
