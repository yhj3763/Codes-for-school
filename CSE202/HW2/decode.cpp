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
    string decode(vector<string> message);
    
 
   private:
    vector<string> codewords;
    vector<char> alpha;
    vector<char> alphacode();
    vector<string> morsecode();
    char decode(string c);

};

Code::Code()
{
}

string Code::decode(vector<string> message)
{
   
    codewords=message;
    string a;
    
   for(int i=0;i<codewords.size();i++)
    {
        alpha.push_back(decode(codewords[i]));
        a.push_back(alpha[i]);
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

char Code::decode(string c)
{
    
   
    for(int i=0;i<morsecode().size();i++)
     {
         if(morsecode()[i]==c)
           return alphacode()[i];
     }

           return 0;

   
}


int main()
{
   vector<string> message;
   string code;
   string result;
   int i=0;
   Code c=Code();
 
   cin>>code;
   while(code!="x")
   {
   
     message.push_back(code);
     cin>>code;
   }

  result=c.decode(message);
  result.push_back('.');
   cout<<result<<endl;
}
