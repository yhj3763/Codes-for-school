#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:
        Person(string n,string a,string t,string e);
        string getname();
        string getaddress();
        string gettele();
        string getemail();
        string get();
    
    private:
        string name;
        string address;
        string tele;
        string email;
    
    
};

Person::Person(string n,string a,string t,string e)
{
    name=n;
    address=a;
    tele=t;
    email=e;
}

string Person::getname()
{
    return name;
}

string Person::getaddress()
{
    return address;
}

string Person::gettele()
{
    return tele;
}

string Person::getemail()
{
    return email;
}

string Person::get()
{
    return "Person";
}

class Student:public Person
{
    public:
        Student(string n,string a,string t,string e,string cl);
        string getclass();
        virtual string whatami();
    
    private:
        string c;
};

Student::Student(string n,string a,string t,string e,string cl):Person(n,a,t,e)
{
    c=cl;
}

string Student::getclass()
{
    return c;
}

virtual string Student::get()
{
    return "Student";
}

class Employee:public Person
{
    public:
        Employee(string n,string a,string t,string e,string o,int s,string d);
        string getoffice();
        int getsalay();
        string getdh();
        virtual string whatami();
    
    private:
        string office;
        int salay;
        string dh;
};

Employee::Employee(string n, string a,string t,string e,string o,int s,string d):Person(n,a,t,e)
{
    office=o;
    salay=s;
    dh=d;
}
string Employee::getoffice()
{
    return office;
}

int Employee::getsalay()
{
    return salay;
}

string Employee::getdh()
{
    return dh;
}

virtual string Employee::whatami();
{
    return "Employee";
}

class Faculty:public Employee
{
    public:
        Faculty(string n,string a,string t,string e,string o,int s,string d,string r,string u);
        string getrank();
        string getstatus();
        virtual string whatami();
    
    private:
        string rank;
        string status;
};

Faculty::Faculty(string n,string a,string t,string e,string o, int s, string d,string r, string u):Employee(n,a,t,e,o,s,d)
{
    rank=r;
    status=u;
}

string Faculty::getrank()
{
    return rank;
}

string Faculty::getstatus()
{
    return status;
}

virtual string Faculty::whatami();
{
    return "Faculty";
}

class Staff:public Employee
{
    public:
        Staff(string n,string a,string t,string e,string o,int s,string d,string so);
        string getss();
        virtual string whatami();
    
    private:
        string ss;
};

Staff::Staff(string n,string a,string t,string e,string o,int s,string d,string so):Employee(n,a,t,e,o,s,d)
{
    ss=so;
}

string Staff::getss()
{
    return ss;
}

virtual string Staff::whatami();
{
    return "Staff";
}

class StaffST:public Staff,public Student
{
    public:
      StaffST();
      virtual string whatami();
	 

    private:
      int credithours; 
};

int main()
{
    Staff s=Staff("name","address","tele","email","jack",100,"9-15","cleaner");
    cout<<s.getname()<<endl;
    cout<<s.getaddress()<<endl;
    cout<<s.gettele()<<endl;
    cout<<s.getemail()<<endl;
    cout<<s.getoffice()<<endl;
    cout<<s.getsalay()<<endl;
    cout<<s.getdh()<<endl;
    cout<<s.getss()<<endl;
    cout<<s.get()<<endl;
    Faculty f=Faculty("hy","address","tele","email","jack",100,"9-15","ed","ea");
    cout<<f.get()<<endl;
    cout<<f.getname()<<endl;
    cout<<s.getname()<<endl;
}
