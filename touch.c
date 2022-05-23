#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int Validate_inputs(char *array, int size)
{
	int value = 0;

	for(int i=0; array[i] != '\0'; i++)
	{ 
		if(isdigit(array[i])) {
			value =(value*10) + (array[i]-'0');
		}
	}
	printf("Value: %d\n", value);
	return value;
}

void main(int argc, char **argv)
{
	int fd, result;
	char *file_name = argv[1];
	size_t size;
	ssize_t ret;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if(argc != 3)
	{
		printf("Give full arguments to the command\nEG: guru_create <path+file_name> <size> \n");
		exit(0);
	}
	size = Validate_inputs(argv[2], sizeof(argv[2]));
	printf("Size: %d\n",size);
	fd = open(file_name, O_WRONLY | O_EXCL | O_CREAT, mode);
	result = lseek(fd, size-1, SEEK_SET);
	result = write(fd, "a", 1);
}
