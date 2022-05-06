/* --------------------------------------------------------------
   Name      : Hyeongjun Yang
   Cotent    : Shell
   Student ID: 005897537
   Term      : Fall 2021
   ----------------------------------------------------------------*/

#include "shell.h"

#include <iostream>
#include <string>
#include <vector>

//empty function to intialize shell.
Shell::Shell(string filename, int numberofblocks, int blocksize): Filesys(filename, numberofblocks, blocksize)
{
}

//It is function shows lists of file
int Shell::dir()
{
    vector<string> flist = ls();
    
    for( int i=0; i< flist.size(); i++)
    {
          cout<<flist[i]<<endl;;
    }
    return 1;

}

//It is a function that helps adding file and data.
int Shell::add(string file, string buffer)
{
        if (!newfile(file))     
	{
		cout << "Cannot add file" << endl;
		return 0;
	}
	if (buffer != "")
	{       
		vector<string> blocks = block(buffer, getblocksize()); 
                
		for (int i = 0; i < blocks.size(); ++i)
		{
                       
			if (!addblock(file, blocks[i]))
			{
				cout << "Error! Cannot add data!" << endl;
				return 0;
			}
		}
	}
	return 1;
}

//It is a function that delete file.
int Shell::del(string file)
{

    int block = getfirstblock(file);
 
    while(block >0)
    {
      delblock(file,block); 
      block =getfirstblock(file);     
     
    }
    rmfile(file);

    return 1;

}

//It is a function that shows the file inside.
int Shell::type(string file)
{
    int block = getfirstblock(file);
    string buffer;
    while(block >0)
    {
         string t;
         readblock(file, block, t);
         buffer += t;
         block = nextblock(file,block);
    }
    
    cout <<"<---------------------- This is content of "<<file<<" ---------------------->"<<endl;
    for(int i=0; i<buffer.size();i++)
    {
         if(buffer[i] !='#')
         {
               cout <<buffer[i];
         }
    }
    cout <<endl;
    cout <<endl;
    cout <<"The length of " <<file<<"is "<<buffer.length()<<endl;
    cout <<"<----------------------   End of type for   "<<file<<" ---------------------->"<<endl;
    return 1;
}

//It is a function that copies file to other file.
int Shell::copy(string file1, string file2)
{
     int block = getfirstblock(file1);
     if(block == -1)
     {
          cout<<"No such file"<<endl;
          return 0;
     }
     
     block=getfirstblock(file2);
     if(block>=0)
     {
           cout<<"Destination File Exists"<<endl;
           return 0;
     }

     newfile(file2);
     block=getfirstblock(file1);
     while(block!=0)
     {
         string buffer;
         readblock(file1, block, buffer);
         addblock(file2, buffer);
         block=nextblock(file1,block);
     }
  
     return 1;
}

