#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <sys/wait.h>

using namespace std;

int main (int argc, char *argv[] )
{
  if (argc != 2)
  {
    cout<<"Argument is not enough.\n";
    return 1;
  }	  
  pid_t pid = fork();

  if(pid < 0)
  {
    cout<<"Fork() fails.\n";
    return 1;
  }
  else if (pid == 0)
  {
    int fd;
    fd = open(argv[1], O_CREAT | O_WRONLY, S_IREAD | S_IWRITE);
    if (fd == -1)
    {
      perror(argv[0]);
      return 1;
    }
    int n_char;
    char buf[100];    
    n_char = read(0, buf, sizeof(buf));
    if (n_char == -1)
    {
      perror(argv[0]);
      return 1;
    }	    
    n_char = write(fd, buf, n_char);
    if (n_char == -1)
    {
      perror(argv[0]);
      return 1;
    }
    close(fd);    
  }  
  else
  {
    wait(NULL);
    int fd;
    fd = open(argv[1], O_RDONLY, S_IREAD | S_IWRITE);
    if (fd == -1)
    {
      perror(argv[0]);
      return 1;
    }
    cout<<"This is parent process.\n";
    int n_char;
    char buf[100];
    n_char = read(fd, buf, sizeof(buf));    
    if (n_char == -1)
    {
      perror(argv[0]);
      return 1;
    }
    n_char = write(1, buf, n_char);
    if (n_char == -1)
    {
      perror(argv[0]);
      return 1;
    }
    close(fd);    
  }

  return 0;  
  	  
}	
