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
    
private:
    string filename;
    vector<string> user;
    vector<string> password;
};

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

void PasswordFile::addpw(string u, string p)
{   
    for(int i=0;i<user.size();i++)
     {
         if(user[i]==u)
           {
              cout<<"User is already in Database"<<endl;
              return;
           }

     }
   
    user.push_back(u);
    password.push_back(p);
}

void PasswordFile::delpw(string u)
{
    for(int i=0;i<user.size();i++)
    {
        swap(user[i],user[user.size()-1]);
        swap(password[i],password[password.size()-1]);
        user.pop_back();
        password.pop_back();
        
        
    }
}

bool PasswordFile::checkpw(string u, string p)
{
    for(int i=0;i<user.size();i++)
    {
        if(u==user[i])
        {
            if(p==password[i])
                return true;
        }
    }
    return false;
}


int main()
{
    PasswordFile passfile("password.txt");
    passfile.addpw("dbotting","123qwe");
    passfile.addpw("egomez","qwerty");
    passfile.addpw("tongyu","liberty");
    passfile.addpw("egomez","qwerty");
    cout<<passfile.checkpw("jsmith","turtle")<<endl;
    // write some lines to see if passwords match users
    
    

}

