#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
int main(int argc, char *argv[]){
	char *filepath = argv[1];
	int fd =open(filepath, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd == -1){
		printf("\nError in opening\n");
		return 0;
	}
	else
		printf("\nOpen Successful\n");
	
	return 0;
}
