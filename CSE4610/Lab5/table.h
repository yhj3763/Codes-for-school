/* --------------------------------------------------------------
   Name      : Hyeongjun Yang
   Cotent    : Table
   Student ID: 005897537
   Term      : Fall 2021
   ----------------------------------------------------------------*/

#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include "shell.h"

class Table : public Shell
{
	public :
	Table(string diskname,int blocksize,int numberofblocks, string flatfile, string indexfile);
	int Build_Table(string input_file);
	int Search(string value);

	private :
	string flatfile;
	string indexfile;
	int IndexSearch(string value);
};

#endif

