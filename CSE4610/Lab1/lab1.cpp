#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class PasswordFile
{
public:
    PasswordFile(string filename);
    void addpw(string u, string p);
    void delpw(string u);
    bool checkpw(string u, string p);
    static void newsalt(int ns);
    
private:
    static int salt;
    string filename;
    vector<string> user;
    vector<string> password;
    void synch();
    string encrypt(string s);
};

//The part to encrypt password.
int PasswordFile::salt=1;

void PasswordFile::newsalt(int ns)
{
  salt = ns;
}

string PasswordFile::encrypt(string s)
{
  for(int i=0; i<s.size(); i++)
   {
      s[i]+=salt;
   }
   return s;
}


//initialize passwordfile
PasswordFile::PasswordFile(string filename)
{
    this->filename=filename;
    string u,p;
    ifstream infile;

    infile.open(filename.c_str());
   
    infile>>u>>p;
    while(infile.good())
    {
        user.push_back(u);
        password.push_back(p);
        infile>>u>>p;
        
    }
    
    infile.close();
    
}

// add id and password based on user's input, also check whether it is in database or not.
void PasswordFile::addpw(string u, string p)
{   
    string encryptedPW = encrypt(p);
    for(int i=0;i<user.size();i++)
     {
         if(user[i]==u)
           {
              cout<<"User is already in Database"<<endl;
              return;
           }

     }
   
    user.push_back(u);
    password.push_back(encryptedPW);
    synch();
    
}

// delete users based on user's id
void PasswordFile::delpw(string u)
{
    vector<string>::iterator it1,it2;
    it2=password.begin();
    
    for(it1=user.begin();it1!=user.end();it1++)
    {
        if(*it1==u)
	{
	   user.erase(it1);
	   password.erase(it2);
	   synch();
	   return;   
	}
	it2++;

        
    }
}

// check whether id and password are in database
bool PasswordFile::checkpw(string u, string p)
{
    string encryptedPW = encrypt(p);
    for(int i=0;i<user.size();i++)
    {
        if(u==user[i])
        {
            if(encryptedPW==password[i])
                return true;
        }
    }
    return false;
}

// renew the password file when there is any change
void PasswordFile::synch()
{
    ofstream outstream;
    outstream.open(filename.c_str());
    
    for(int i=0; i<user.size(); i++)
    {
    	outstream << user[i] << " "<<password[i]<<endl;
    }
    outstream.close();
}


int main()
{
    
    PasswordFile passfile("password.txt");  // initialize password file
    
    int n = 0;
    string id ="";    
    string pw ="";

   // loop until user wants to exit the program. There are add, check, delete, and exit based on user's input
   while(1) 
   {
    cout << "Enter 1 to add, 2 to check, 3 to delete or any other key to exit : " ;
    cin >> n;


    if(n == 1)
    {
      cout << "Enter username that you want to add: ";
      cin >> id;
      cout << "Enter password that you want to add: ";
      cin >> pw;
      passfile.addpw(id,pw);
    }
    else if(n == 2)
    {
      cout << "Enter username that you want to check: ";
      cin >> id;
      cout << "Enter password that you want to check: ";
      cin >> pw;
      if(passfile.checkpw(id,pw))
       {
          cout<< "It is already in the Database."<<endl; 
       }
      
    }
    else if(n == 3)
    {
       cout << "Enter username that you want to delete: ";
       cin >> id;
       passfile.delpw(id);
    }
    else
    {
      return 0;
    }
   }
}

