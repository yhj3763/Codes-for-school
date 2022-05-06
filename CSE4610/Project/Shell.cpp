//Shell.cpp file
#include "Sdisk.h"
#include "Shell.h"
#include "Filesys.h"
#include <string>
#include <vector>
#include <iostream>


Shell::Shell(string diskname, int numberofblocks, int blocksize):Filesys(diskname, numberofblocks, blocksize)
{
}

int Shell::dir()
{
	vector<string> flist = ls();
	for(int i = 0; i < flist.size(); i++)
	{
		cout << flist[i] << endl;
	}
	return 1;
}

int Shell::add(string file, string buffer)
{	
	int error = newfile(file);
	if(error != 1) //was <
	{
		cout << "No can do" << endl;
		return 0;
	}
	vector<string> blocks = block(buffer, getblocksize());
	for(int i = 0; i < blocks.size(); i++)
	{
		addblock(file,blocks[i]);
	}
	return 1;
}

int Shell::del(string file)
{
	int code = getfirstblock(file);
	if(code == 1)
	{
		cout << "file doesn't exist" << endl;
		return 0;
	}
	while(getfirstblock(file) != 0)
		{
			delblock(file,getfirstblock(file));
		}
	cout << file << " will be deleted." << endl;
	rmfile(file);
	return 1;
}

int Shell::type(string file)
{
	string buffer;
	int block = getfirstblock(file);
	if(block < 0)
	{
	cout << "no such file " << endl;
	return 0;
	}
	if(block == 0)
	{
	cout << "empty file " << endl;
	return 0; //was 1 
	}
	while(block > 0) //changed != to >
	{
		string b; 
		readblock(file,block,b);
		buffer += b;
		block = nextblock(file, block);
	}
	for(int i = 0; i < buffer.size(); i++)
	{
		if(buffer[i] != '#')
		{
			cout << buffer[i];
		}
	}
	cout << endl;
	return 1;
}

int Shell::copy(string file1, string file2)
{
	if(newfile(file2) == 0)
	{
		return 0;
	}
	int block = getfirstblock(file1);
	if(block < 0)
		{
			cout << "No such file" << endl;
			return 0;
		}
	if(block == 0)
	{
		cout << "empty file" << endl;
		return 1;
	}
	while( block != 0)
	{
		string b;
		readblock(file1, block, b);
		addblock(file2, b);
		block = nextblock(file1, block);
	}
	return 1;
}

