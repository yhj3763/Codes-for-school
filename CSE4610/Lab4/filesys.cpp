#include "filesys.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>

//It is a constructor for the filesystem. Therefore, values are initialized here.
Filesys::Filesys(string diskname, int numberofblocks, int blocksize):Sdisk(diskname,numberofblocks,blocksize)
{
   this->rootsize = getblocksize()/10;
   this->fatsize = (getnumberofblocks()*5)/getblocksize()+1;
  
 
   string buffer;
     
   getblock(1, buffer);
    
    
   if(buffer[0] == '#')
   {
      
      for(int i = 0; i<rootsize; i++)
      {
         filename.push_back("xxxxxx");
   	 firstblock.push_back(0);
      }
 
      fat.push_back(fatsize+2);
      fat.push_back(-1);
     
   
      for(int i=0;i<fatsize; i++)
      {
          fat.push_back(-1);
      }
      
   
      for(int i=fatsize+2;i<getnumberofblocks(); i++)
      {
          fat.push_back(i+1);
      }
        
     
      fat[fat.size()-1] =0;

      fssynch();
   }
   else
   {  

      readfs();
   }
   

}

//It is a function to close the filesystem.
int Filesys::fsclose()
{
     fssynch();
     cout<<"Filesystem is closed."<<endl;
     return 1;

}

//It is a function to synch the filesystem when it is updated.
int Filesys::fssynch()
{
   
    ostringstream ostream1;
    ostream1 <<endl;
   
    for(int i=0; i<rootsize; i++)
    {
       ostream1 << filename[i]<<" "<<firstblock[i]<<" ";
    }
    
    ostringstream ostream2;
    
    for(int i=0; i<getnumberofblocks(); i++)
    {
       ostream2<<fat[i]<<" ";
    }
 

    string buffer1 = ostream1.str();
    string buffer2 = ostream2.str();
    
    vector<string> blocks1 = block(buffer1,getblocksize());
    vector<string> blocks2 = block(buffer2,getblocksize());
     


    putblock(1,blocks1[0]);
    for(int i =0; i<blocks2.size(); i++)
    {
         putblock(2+i, blocks2[i]);
    }
   
    cout<<"Synch is complete."<<endl; 
    return 0;
}

//It is a function to read filesystem.
int Filesys::readfs()
{
    string buffer;
    getblock(1, buffer);
   
    istringstream istream;
    istream.str(buffer);

    for(int i=0; i<rootsize; i++)
    {
       string fn;
       int fb;
       istream>>fn>>fb;
       filename.push_back(fn);
       firstblock.push_back(fb);
    }

    string buffer2, buffer3;
    
    for(int i=0; i<fatsize; i++)
    {
       getblock(i+2, buffer2);
       buffer3+=buffer2;
       buffer2.clear();
    }

    istringstream istream2;
    istream2.str(buffer3);

    for(int i=0; i<getblocksize(); i++)
    {
       
       istream2>>i;
       fat.push_back(i);
    }
   
    return 0;
}

//It is a function to make new file.
int Filesys::newfile(string file)
{
    

    for(int i=0; i<filename.size(); i++)
    {
        
        if(filename[i] == file)
        {
           cout<<"File exists"<<endl;
           return 0;
        }
    }

    for(int i=0; i<filename.size(); i++)
    {
         
        if(filename[i] == "xxxxxx")
        {
            filename[i] =file;
            firstblock[i] = 0;
            fssynch();
            return 1;
        }
    }
    cout<<"No space for newfile"<<endl;
    return 0;
}

//It is a function to remove the file.
int Filesys::rmfile(string file)
{
   	for (int i = 0; i < rootsize; i++) {
		if (filename[i] == file) {
			if (firstblock[i] != 0) {
				cout << "File is not empty" << endl;
				return 0;
			} else {
				filename[i] == "xxxxxx";
				fssynch();
				return 1;
			}
		}
	}
    return 0;

}

//It is a function to get first block.
int Filesys::getfirstblock(string file)
{
   for(int i=0; i<filename.size(); i++)
   {
       if(filename[i]==file)
       {
           return firstblock[i];
       }
   }
   return -1;
}

//It is a function to add blocks to the disk.
int Filesys::addblock(string file, string block)
{
   
   int allocate=fat[0];
   if(allocate==0)
   {
       cout<<"No sapce on disk"<<endl;
       return 0;
   }
   
   fat[0]=fat[fat[0]];
   fat[allocate]=0;
   
   int block1 = getfirstblock(file);
   
   if(block1==0)
   {
      for(int i=0; i<rootsize;i++)
      {
         if(filename[i]==file)
         {
            firstblock[i]=allocate;
            fssynch();
            putblock(allocate, block);
            return allocate;
         }
      }
   }
   else
   {
      int first = block1;
      while(fat[first]!=0)
      { 
             first=fat[first];   
           
       }
      fat[first]=allocate;
      
   }
   
   fssynch();
   putblock(allocate, block);
   cout<<"Adding the block is complete."<<endl;
   return allocate;
}

//It is a function to check the block.
bool Filesys::checkblock(string file, int blocknumber)
{
  int block = getfirstblock(file);
  if(block == -1)
  {
     cout<<"No such file"<<endl;
     return false;
  }
  
  while(block!=0)
  {
     if(block == blocknumber)
     {
        return true;
     } 
     block=fat[block];
  }

  return false;
}

//It is a function to read a block.
int Filesys::readblock(string file, int blocknumber, string& buffer)
{
   if(checkblock(file,blocknumber))
   {
      getblock(blocknumber, buffer);
      return 1;
   }
   else
   {
      cout<<"No can do"<<endl;
      return 0;
   }
}

//It is a function to write the block.
int Filesys::writeblock(string file, int blocknumber, string buffer)
{
   if(checkblock(file,blocknumber))
   {
      putblock(blocknumber, buffer);
      return 1;
   }
   else
   {
      cout<<"No can do"<<endl;
      return 0;
   }
}

//It is a function for the next block.
int Filesys::nextblock(string file, int blocknumber)
{
   if(checkblock(file,blocknumber))
   {
     
      return fat[blocknumber];
   }
   else
   {
      cout<<"No can do"<<endl;
      return 0;
   }
}

//It is a function to delete the block from the disk.
int Filesys::delblock(string file, int blocknumber)
{
  
   if(not checkblock(file,blocknumber))
   {
      cout<<"No can do"<<endl;
      return 0;
   }

   int block =getfirstblock(file);
   if(block == blocknumber)
   {
      for(int i=0; i<filename.size(); i++)
      {
         if(filename[i] ==file)
         {
            firstblock[i]=fat[blocknumber];
         }
      }
   }
   else
   {
      while(fat[block]!=0 and fat[block] != blocknumber)
      {
         block=fat[block];
      }
      fat[block] = fat[blocknumber];
   }
   fat[blocknumber] = fat[0];
   fat[0]=blocknumber;
   fssynch();
   cout<<"Deleting the block is complete."<<endl;
   return 0;
}

vector<string> Filesys::block(string buffer, int b)
{
	vector<string> blocks;
	int numberofblocks = 0;

	if (buffer.length() % b == 0)
	{
		numberofblocks = buffer.length()/b;
	} else {
		numberofblocks = buffer.length()/b +1;
	}

	string tempblock;
	for (int i = 0; i < numberofblocks; i++)
	{
		tempblock = buffer.substr(b*i, b);
		blocks.push_back(tempblock);
	}

	int lastblock = blocks.size() - 1;

	for (int i = blocks[lastblock].length(); i < b; i++)
	{
		blocks[lastblock] += "#";
                
	}

	return blocks;
}

vector<string> filesys::ls()
{ 
    vector<string> flist;
    for (int i=0; i<filename.size(); i++)
    {
        if (filename[i] != "xxxxxx")
        {
            flist.push_back(filename[i]);
        }
    }
    return flist;
}

 



