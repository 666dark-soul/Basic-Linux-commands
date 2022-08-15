#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t byte;
size_t size;

void copy_status()
{
	printf("\n Number of bytes copied:%d bytes",byte);
	if(size == byte)
	{
		printf("\n The copy process is Sucessfull");
	}else
		printf("\n The copy process is intruppted in middle");
	exit(0);
}

void main(int argc, char** argv)
{
  signal(SIGINT, copy_status);
	size_t size =0;
	char *source_file_name = argv[1];
	char *destination_file_name = argv[2];
	if(argc != 3)
	{
		printf("\n Invalid Arguments\n cp <source> <destination> \n");
	}else{
		struct stat file = {0x00};
		mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
		int f = open(source_file_name, O_RDONLY);
		int fd = open(destination_file_name, (O_CREAT | O_TRUNC | O_WRONLY), mode);
		fstat(f, &file);
	        size = file.st_size;
		byte = 0;
		while (byte < size)
		{
			read(f, &byte, 1);
			write(fd, &byte, 1);
			byte++;
		}
	}
	copy_status();
} 
