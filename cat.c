#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<sys/stat.h>

int Validate_inputs(char *array, int size)
{
  int value=0;
  for(int i=0; array[i] != '\0'; i++)
    { 
      if(isdigit(array[i])) {
	value =(value*10) +((int)array[i]-48);
      }
    }
  return value;
}
  
void main(int argc, char **argv)
{
  struct stat file;
  stat(argv[1],&file);
  int fd,from,to,position;
  char *filename = argv[1],buffer[file.st_size];
  ssize_t ret =1;
  if(argc != 4)
    {
      printf("Give full arguments to the command\nEG: guru_cat <file_name> <from> <to>\n");
      exit(0);
    }else {
    from = Validate_inputs(argv[2],1);
    to = Validate_inputs(argv[3],2);
  }
  fd = open(filename, O_RDONLY);
  ret = read(fd,buffer,sizeof(buffer));
  for(int i=from; i <= to; i++)
    {
      putchar(buffer[i]);
    }
}
