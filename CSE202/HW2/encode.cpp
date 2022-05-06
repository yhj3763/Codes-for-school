//Hyeongjun Yang
//Homework 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Code
{
   public:
    Code();
    string encode(vector<char> message);
    
 
   private:
    vector<string> codewords;
    vector<char> alpha;
    vector<char> alphacode();
    vector<string> morsecode();
    string encode(char x);

};

Code::Code()
{
}

string Code::encode(vector<char> message)
{
   
    alpha=message;
    string a;
    
   for(int i=0;i<alpha.size();i++)
    {
        codewords.push_back(encode(alpha[i]));
        if(i>0)
         a+=" ";
        a+=codewords[i];
        
    }
       
   
   return a;
}

vector<char> Code::alphacode()
{
 vector<char> temp;
 for (char c='A'; c<='Z'; c++)
      temp.push_back(c);
 temp.push_back(' ');
 temp.push_back('.');
 return temp;

}

vector<string> Code::morsecode()
{
 vector<string> temp(28);
    
 temp[0] =".-";
 temp[1] ="-...";
 temp[2] ="-.-.";
 temp[3] ="-.."; 
 temp[4] =".";
 temp[5] ="..-.";
 temp[6] ="--.";
 temp[7] ="....";
 temp[8] ="..";
 temp[9] =".---";
 temp[10] ="-.-";
 temp[11] =".-..";
 temp[12] ="--";
 temp[13] ="-.";
 temp[14] ="---";
 temp[15] =".--.";
 temp[16] ="--.--";
 temp[17] =".-.";
 temp[18] ="...";
 temp[19] ="-";
 temp[20] ="..-";
 temp[21] ="...-";
 temp[22] =".--";
 temp[23] ="-..-";
 temp[24] ="-.--";
 temp[25] ="--..";
 temp[26] =".......";
 temp[27] ="x";
 return temp;
}	

string Code::encode(char x)
{
    
   
    for(int i=0;i<morsecode().size();i++)
     {
         if(alphacode()[i]==x)
           return morsecode()[i];
     }

           return 0;

   
}


int main()
{
   vector<char> message;
   char alpha;
   char a[50];
   string result;
   Code c=Code();
 
   
   cin.getline(a,50);
     
       
   for(int i=0;a[i-1]!='.';i++)
     message.push_back(a[i]);
        


  result=c.encode(message);
   
   cout<<result<<endl;
}
