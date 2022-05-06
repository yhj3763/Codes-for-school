#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


using namespace std;

int main(int argc, char* argv[] )
{
if(argv[1]==NULL or argv[2]==NULL)
{
  cout<<"Not enough arguments"<<endl;
  return 0;
}


int pid=fork(); 

if(pid==0)
{	
  cout<<"In the CHILD process"<<endl;	 
  cout<<"Process ID:"<<getpid()<<endl; 
  cout<<"Parent Process ID:"<<getppid()<<endl; 
  cout<<"Process group ID:"<<getpgrp()<<endl;
  execl("/bin/cat","cat", "-n",argv[1],"-",argv[2],NULL);
  cout<<"Error"<<endl;
  return -1;
  
}
else if(pid>0)
{
  wait(NULL);
  cout<<"In the PARENT process"<<endl;  
  cout<<"Process ID:"<<getpid()<<endl;
  cout<<"Parent Process ID:"<<getppid()<<endl;
  cout<<"Process group ID:"<<getpgrp()<<endl;

}

}
