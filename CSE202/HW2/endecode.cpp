#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Code
{
   public:
    Code();
    string decode(vector<string> message);
    string encode(vector<char> message);
 
   private:
    vector<string> codewords;
    vector<char> alpha;
    vector<char> alphacode();
    vector<string> morsecode();
    char decode(string c);
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

string Code::encode(char x)
{


   for(int i=0;i<morsecode().size();i++)
    {
         if(alphacode()[i]==x)
           return morsecode()[i];
    }

           return 0;
    
 
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
   
   int num;
   string result;
   Code c=Code();
   cout<<"Enter the number 0 for endcoding, 1 for decording:";
   cin>>num;
   cin.ignore();
  
  if(num==0)
   {
     vector<char> cmessage;
     char a[50];
 
     cout<<"Put the code for encording:";
   
     cin.getline(a,50);
     
       
     for(int i=0;a[i-1]!='.';i++)
      {
        cmessage.push_back(a[i]);
      }  


     result=c.encode(cmessage);

   } 

  
  if(num==1)
   { 
     int i=0;
     vector<string> smessage;
     string code;
   
     cout<<"Put the code for decording:";
   
     while(1)
     {
       cin>>code;
  
       smessage.push_back(code);
    
       if(smessage[i]=="x")
        break;
       i++;
     }
    result=c.decode(smessage);
   }
  
   
   cout<<result<<endl;
}
