#include<stdio.h>
#include<stdlib.h>

void main(int argc, char **argv)
{
	char *filename;
	FILE* fptr;
	int size=1024, linecount = 0,ret,line,position;
	char buffer[size];

	if(argc != 2)
	{
		printf("Give full arguments to the command\nEG: tail <filename> ");
		exit(0);
	}
	filename = argv[1];
	fptr = fopen(filename , "r");
	while(ret != 0){
		//fseek(fptr, 0, ftell(fptr)-1);
		ret = fgets(buffer,size, fptr);
		//puts(buffer);
		linecount++;
	}

	fseek(fptr, 0,SEEK_SET);
  
	while (fgets(buffer,size,fptr) != 0) {
		line++;
		if (line == linecount-10)
			position = ftell(fptr);
	}
  
	fseek(fptr,position,SEEK_SET);
	ret = 1;
	while(ret != 0){
		//fseek(fptr, 0, ftell(fptr)-1);
		ret = fgets(buffer,size, fptr);
		puts(buffer);
		linecount++;
	}
   
	printf("%d",linecount);
}
