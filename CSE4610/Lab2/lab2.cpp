#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Sdisk
{
public :
Sdisk(string diskname, int numberofblocks, int blocksize);
int getblock(int blocknumber, string& buffer);
int putblock(int blocknumber, string buffer);
int getnumberofblocks(); // accessor function
int getblocksize(); // accessor function

private :
string diskname;        // file name of software-disk
int numberofblocks;     // number of blocks on disk
int blocksize;          // block size in bytes
};

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

int main()
{
  Sdisk disk1("test1",16,32);
  string block1, block2, block3, block4;
  for (int i=1; i<=32; i++) block1=block1+"1";
  for (int i=1; i<=32; i++) block2=block2+"2";
  disk1.putblock(4,block1);
  disk1.getblock(4,block3);
  cout << "Should be 32 1s : ";
  cout << block3 << endl;
  disk1.putblock(8,block2);
  disk1.getblock(8,block4);
  cout << "Should be 32 2s : ";
  cout << block4 << endl;;
}


