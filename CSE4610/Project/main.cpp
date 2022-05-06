#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Sdisk.h"
#include "Filesys.h"
#include "Shell.h"
#include "Table.h"

using namespace std;

int main()
{
	//Shell shell("empty.txt",256,128);
	Table table("sdisk.txt",256,128,"flatfile","indexfile");
	
	table.Build_Table("data.txt");


	Shell shell("sdisk.txt",256,128);

	string s;
	string command = "go";
	string op1, op2;


	cout << "The disk has various commands to access the disk\n";
	cout << "dir - lists the files on the disk\n";
	cout << "add - add files to the disk\n";
	cout << "del - delete files from the disk\n";
	cout << "type - lists the contents of a file\n";
	cout << "copy - copies contents of one file to another\n";
	cout << "search - find files on disk\n";
	cout << "quit - exit the disk\n \n";


	while(command != "quit")
	{
		command.clear();
		op1.clear();
		op2.clear();
		cout << "$";
		getline(cin,s);
		int firstblank = s.find(' ');
		if(firstblank < s.length()) s[firstblank]= '#';
		int secondblank = s.find(' ');
		command = s.substr(0,firstblank);
		if(firstblank < s.length())
			op1 = s.substr(firstblank + 1,secondblank - firstblank - 1);
		if(secondblank < s.length())            
			op2 = s.substr(secondblank + 1);
		if(command=="dir")
		{
			shell.dir();
		}
		if(command=="add")
		{
			//the variable op1 is the new file and op2 is the file data
           		cout << "Enter new file name" << endl;
           		getline(cin, op1);
        	   	cout << "Enter the file data" << endl;
           		getline(cin, op2);
           		shell.add(op1, op2);
		}
		if(command=="del")
		{
			//the variable op1 is the file
			cout << "enter file you want deleted" << endl;
			getline(cin, op1);
			shell.del(op1);
			cout << op1 << " has been deleted." << endl;
		}
		if(command=="type")
		{
	        	//the variable op1 is the file
	                cout << "Enter file name" << endl;
	                cin >> op1;
        	        shell.type(op1);
		}
		if(command=="copy")
		{
			//the variable op1 is the source file and the variable op2 is the desitination file
			cout << "Enter the file name you want to copy" << endl;
	          	cin >> op1;
        	  	cout << "Enter the destination file" << endl;
          		cin >> op2;
         	  	shell.copy(op1, op2);
			cout << "copy successful!" << endl;
		}

		if(command=="search")
		{
			//command for project4
			//variable op1 is the date
		}
	}

return 0;
}
