/* --------------------------------------------------------------
   Name      : Hyeongjun Yang
   Cotent    : Sdisk
   Student ID: 005897537
   Term      : Fall 2021
   ----------------------------------------------------------------*/

#include "sdisk.h"

#include <sstream>
#include <fstream>
#include <iostream>


// initialize the values
Sdisk::Sdisk(string diskname, int numberofblocks, int blocksize)
{
   this->diskname = diskname;
   this->numberofblocks = numberofblocks;
   this->blocksize=blocksize;
 
   fstream fsfile;
   fsfile.open(this->diskname.c_str(), ios::in);
  
  
   if(fsfile.good()) 
   {
       cout<<"Disk Exists" <<endl;
      
   }
   else 
   {
       cout<<"Creating Disk: "<<diskname<<" "<<endl;
       fsfile.open(diskname.c_str(), ios::out);
       for(int i=0; i<this->numberofblocks*this->blocksize; i++)
       {  
            fsfile.put('#');
       }
             
   }
   return;
         
  

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

