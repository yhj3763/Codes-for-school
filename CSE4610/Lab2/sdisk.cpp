#include "sdisk.h"

#include <sstream>
#include <fstream>


// initialize the values
Sdisk::Sdisk(string diskname, int numberofblocks, int blocksize)
{
   this->diskname = diskname;
   this->numberofblocks = numberofblocks;
   this->blocksize=blocksize;
 
   fstream iofile;
   iofile.open(diskname.c_str(), ios::in);
   if(iofile.fail()) //close if there are problems
   {
      iofile.close();
      return;
   }
   else //open file and put #s
   {
      iofile.close();
      ofstream outfile;
      outfile.open(diskname.c_str());
      for(int i=0; i<numberofblocks*blocksize; i++)
      {
          outfile.put('#');
      }
      outfile.close();
      return;
   }

}


int Sdisk::getblock(int blocknumber, string& buffer)
{
    buffer.clear();
    if(blocknumber >=0 and blocknumber < numberofblocks-1) // check the condition for block number
    {
       fstream iofile;
       iofile.open(diskname.c_str(),ios::in);
       iofile.seekg(blocknumber*blocksize); // set the position
       
       for(int i=0; i<blocksize; i++)
       {
             buffer +=iofile.get();    // add values to buffer
             
       }
       iofile.close();
       return 1;
       

    }   
    else
    {
         return 0;
     }
    
}


int Sdisk::putblock(int blocknumber, string buffer)
{
     
     if(blocknumber >=0 and  blocknumber < this->numberofblocks-1) // check the condition for block number
     {
       fstream iofile;
       iofile.open(diskname.c_str(), ios::in|ios::out);
       iofile.seekp(blocknumber*blocksize);    // set the position
       for(int i=0; i<buffer.length() and i<blocksize; i++)
       {
           iofile.put(buffer[i]); // put value in buffer[i] to file
       }
       iofile.close();
       return 1;
     } 
     else
     {
        return 0;
     }
     
     
}  

int Sdisk::getnumberofblocks()
{
    return this->numberofblocks; //get value for number of blocks
}


int Sdisk::getblocksize()
{
    return this->blocksize;      //get value for blocksize
}

