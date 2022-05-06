#include <iostream>

#include <vector>

#include <string>



using namespace std;



template<typename T>

class Stack

{

public:

    Stack();//creates the stack

    bool isempty(); // returns true if the stack is empty

    T gettop();//returns the front of the list

    void push(T entry);//add entry to the top of the stack

    void pop();//remove the top of the stack

private:

    vector<T> stack;

}; // Stack



template<typename T>

Stack<T>::Stack()

{

}



template<typename T>

bool Stack<T>::isempty()

{ if (stack.size() == 0)

    return true;

else

    return false;

}



template<typename T>

T Stack<T>::gettop()

{ return stack[stack.size()-1];

}



template<typename T>

void Stack<T>::push(T entry)

{

    stack.push_back(entry);

}



template<typename T>

void Stack<T>::pop()

{

    stack.pop_back();

}





int main()

{

    Stack<char> s=Stack<char>();

    vector<char> X;

    vector<char> Y;

    int i=0;

    char c;

    c=cin.get();

    while(c!=';')

    {

        X.push_back(c);

        c=cin.get();

    }

    

    s.push('[');

    X.push_back(']');

    

    while(s.isempty()!=true)

    {

        

        if(X[i]=='(')

        {

             s.push(X[i]);

        }

        else if(X[i]=='+'||X[i]=='-'||X[i]=='*'||X[i]=='/')

        {

            if((X[i]=='+' or X[i]=='-') and (s.gettop()=='+' or s.gettop()=='-' or s.gettop()=='*' or s.gettop()=='/'))

            {

                Y.push_back(s.gettop());

                s.pop();

                s.push(X[i]);

                

            }

            else if((X[i]=='*' or X[i]=='/') and (s.gettop()=='*' or s.gettop()=='/'))

            {

                Y.push_back(s.gettop());

                s.pop();

                s.push(X[i]);

            }

            else

            {

                s.push(X[i]);

                

            }

        

        }

        else if(X[i]==')' or X[i]==']')

        {

             if(X[i]==')')

             {

                 while(s.gettop()!='(')

                 {

                     Y.push_back(s.gettop());

                     s.pop();

                 }

                 s.pop();

                 

             }

            else

            {

                while(s.gettop()!='[')

                {

                   Y.push_back(s.gettop());

                    s.pop();

                    

                }

                s.pop();

            }

            

            

        }

        else

        {

            Y.push_back(X[i]);

            

        }

        

        i++;

    }

    

    for(int i=0;i<Y.size();i++)

        cout<<Y[i];

    

    cout<<endl;

    

    

}
