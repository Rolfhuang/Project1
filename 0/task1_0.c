#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main(int argc, char* argv[]){
	char* filepath = argv[1];
	int returnval;
	returnval = access(filepath,F_OK);
	if(returnval == 0)
		printf("\n %s exist\n", filepath);
	else{
		if(errno == ENOENT)
			printf("%s does not exist\n", filepath);
		else if(errno == EACCES)
			printf("%s is not accessible\n", filepath);
			return 0;
	}
	returnval = access(filepath, R_OK);
	if (returnval == 0)
		printf("\n %s has Read permissions.\n", filepath);
	else{
		if(errno == ENOENT)
			printf("%s No such file or directory.\n", filepath);
		else if(errno == EACCES)
			printf("%s Write Permission denied.\n", filepath);
	}
	returnval = access(filepath, W_OK);
	if(returnval == 0)
		printf("\n %s has Write permissions.\n", filepath);
	else{
		if(errno == ENOENT)
			printf("%s No such file or directory.\n", filepath);
		else if(errno == EACCES)
			printf("%s Write permission denied.\n",filepath);
	}
	return 0;
	
}
