#include "Sdisk.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Sdisk::Sdisk(string diskname, int numberofblocks, int blocksize)
{
	this -> diskname = diskname;
	this -> numberofblocks = numberofblocks;
	this -> blocksize = blocksize;

	fstream iofile;
	iofile.open(diskname.c_str(), ios::in);

	if(iofile.good())
	{
		iofile.close();
		return;
	}
	else
	{
		iofile.close();
		ofstream outfile;
		outfile.open(diskname.c_str());
		for(int i = 0; i < numberofblocks * blocksize; i++)
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

	if(blocknumber >=0 && blocknumber < numberofblocks - 1)
	{
		fstream infile;
		infile.open(diskname.c_str(), ios::in | ios::out);
		infile.seekg(blocknumber*blocksize);
		char c;
		for(int i = 0; i < blocksize; i++)
		{
			c = infile.get();
			//buffer.push_back(c);
			 buffer += c;
		}
		infile.close();
		return 1;
	}
	else
	{
		return 0;
	}
}

int Sdisk::putblock(int blocknumber, string buffer)
{
	if(blocknumber >=0 && blocknumber < numberofblocks - 1)
	{
		fstream outfile;
		outfile.open(diskname.c_str(), ios::in | ios::out);
		outfile.seekg(blocknumber*blocksize);
		for(int i = 0; i < blocksize; i++)
		{
			outfile.put(buffer[i]);
		}
		outfile.close();
		return 1;
	}
	else
	{
		return 0;
	}
}

int Sdisk::getblocksize()
{
	return blocksize;
}

int Sdisk::getnumberofblocks()
{
	return numberofblocks;
}

