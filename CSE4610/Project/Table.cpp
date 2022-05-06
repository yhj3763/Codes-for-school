#include "Sdisk.h"
#include "Filesys.h"
#include "Shell.h"
#include "Table.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Table::Table(string diskname, int numberofblocks, int blocksize, string flatfile, string indexfile) : Filesys(diskname, numberofblocks, blocksize)
{
	this -> indexfile = indexfile;
	this -> flatfile = flatfile;
	newfile(flatfile);
	newfile(indexfile);
}

int Table::Build_Table(string input_file)
{
	stringstream indexstream;
	ifstream infile;
	infile.open(input_file);
	if(!infile.is_open())
	{
		return 0;
	}
	string s;
	indexstream << ".";
	while(getline(infile, s))
	{
		string key = s.substr(0,6);//was 5
		vector<string> blocks = block(s, getblocksize());
		int b = addblock(flatfile, blocks[0]);
		indexstream << key << " " << b << ".";
	}
	string buffer = indexstream.str();
	vector<string> blocks = block(buffer, getblocksize());
	for(int i = 0; i < blocks.size(); i++)
	{
		addblock(indexfile, blocks[i]);
	}
	return 0;
}

int Table::IndexSearch(string value)
{	
	istringstream instream;
	string buffer2;
	int b = getfirstblock(indexfile);
	if(b <= 0)
	{
		return 0;
	}
	while( b != 0)
	{
		string buffer;
		int error = readblock(indexfile, b, buffer);
		buffer2 += buffer;
		b = nextblock(indexfile,b);
	}
	//indexfile is a string in buffer2
	instream.str(buffer2);
	for(int i = 0; i < numberofrecords; i++)
	{
		string key;
		int block;
		instream >> key >> block;
		if(value == key)
		{
			return block;
		}
	}
	return -1;
//end indexsearch
}

int Table::Search(string value)
{
	int b = IndexSearch(value);
	if(b <= 0)
	{
		return -1;
	}
	string buffer;
	b = readblock(flatfile,b,buffer);
	cout << buffer;
	return b;
}


