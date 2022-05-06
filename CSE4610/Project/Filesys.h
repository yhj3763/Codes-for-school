//FileSys.h file

#ifndef FILESYS_H
#define FILESYS_H

#include "Sdisk.h"
#include <string>
#include <vector>

using namespace std;

class Filesys : public Sdisk
{
	public:
		Filesys(string diskname, int numberofblocks, int blocksize);
		int fsclose();
		int fssynch();
		int newfile(string file);
		int rmfile(string file);
		int getfirstblock(string file);
		int addblock(string file, string block);
		int delblock(string file, int blocknumber);
		int readblock(string file, int blocknumber, string& buffer);
		int writeblock(string file, int blocknumber, string buffer);
		int nextblock(string file, int blocknumber);
		vector<string> block(string buffer, int b);
		vector<string> ls();
		vector<int> firstblock;

	private:
		int rootsize;
		int fatsize;
		vector<string> filename;	
		vector<int> fat;	
 		int buildfs();
		void readfs();		
		bool checkblock(string filename, int blocknumber);
};
#endif
