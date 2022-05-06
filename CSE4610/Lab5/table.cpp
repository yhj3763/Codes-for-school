/* --------------------------------------------------------------
   Name      : Hyeongjun Yang
   Cotent    : Table
   Student ID: 005897537
   Term      : Fall 2021
   ----------------------------------------------------------------*/

#include "table.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

//It is a function to initalize table.
Table::Table(string filename, int numberofblocks, int blocksize, string flatfile, string indexfile):Shell(filename, numberofblocks, blocksize)
{
    this->indexfile = indexfile;
    this->flatfile = flatfile;
    this->newfile(flatfile);
    this->newfile(indexfile);
}

//Simply this function builds table.
int Table::Build_Table(string input_file)
{
 
        stringstream indexstream;
	
	ifstream infile;
	infile.open(input_file);
	
	if (!infile.is_open())
	{
		return 0;
	}

	string s;

	
	indexstream << ".";

	while (getline(infile, s)) 
       {
		
		string key = s.substr(0, 5);
		vector<string> blocks = block(s, getblocksize());
		
		int b = addblock(flatfile, blocks[0]);
		
		indexstream << key << " " << b << ".";
		
	}

	string buffer = indexstream.str();
	
	vector<string> blocks = block(buffer, getblocksize());
	
	for (int i = 0; i < blocks.size(); i++) {
		addblock(indexfile, blocks[i]);

	}
	
	return 0;
}  
 
//It is a function that search based on index.
int Table::IndexSearch(string value)
{
        istringstream instream;
	int b = getfirstblock(indexfile);
	string bigbuffer; 
	value = "." + value + " ";
	if (b < 0) {
		return 0;
	}
	while (b != 0) {
		string buffer;
		readblock(indexfile, b, buffer);
		b = nextblock(indexfile, b);
		bigbuffer += buffer;
	}

        
	int index = bigbuffer.find(value);
	if (index < 0)
	{
		return 0;
	}
	stringstream s(bigbuffer.substr(index + 6, 10));

	int r;
	s >> r;

	return r;
}

//By using index serach function, it search the thing user want.
int Table::Search(string value)
{       
{
	
	int idx = IndexSearch(value);
	if (idx == 0) {
		cout << "not existing." << endl << endl;
		return 0;
	}
	string buffer;
	int error = readblock(flatfile, idx, buffer);
	buffer.erase(buffer.find_last_not_of('#') + 1);
	cout << buffer << endl << endl;
	
	return error;
}
}
