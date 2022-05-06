//Homework 3
//Hyeongjun Yang
//studnet number:005897537
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person();
    Person(string n,string a,string t,string e);
    string getname();
    string getaddress();
    string gettele();
    string getemail();
    void setPerson(string nn,string na,string nt,string ne);
    virtual string whatami();
    
private:
    string name;
    string address;
    string tele;
    string email;
    
    
};

Person::Person()
{
    
}

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

void Person::setPerson(string nn,string na,string nt,string ne)
{
    name=nn;
    address=na;
    tele=nt;
    email=ne;
}

string Person::whatami()
{
    return "Person";
}

class Student:virtual public Person
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

string Student::whatami()
{
    return "Student";
}

class Employee:virtual public Person
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
    setPerson(n,a,t,e);
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

string Employee::whatami()
{
    return "Employee";
}

class Faculty:public Employee
{
public:
    Faculty(string n,string a,string t,string e,string o,int s,string d,string r,string u);
    string getrank();
    string getstatus();
    virtual string
    whatami();
    
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

string Faculty::whatami()
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

string Staff::whatami()
{
    return "Staff";
}

class StaffST:public Staff,public Student
{
public:
    StaffST(string n,string a,string t,string e,string o,int s,string d,string so,string cl,int cre);
    virtual string whatami();
    
private:
    int credithours;
};

StaffST::StaffST(string n,string a,string t,string e,string o,int s,string d,string so,string cl,int cre):Staff(n,a,t,e,o,s,d,so),Student(n,a,t,e,cl)
{
    
    credithours=cre;
}

string StaffST::whatami()
{
    return "StaffST";
}



int main()
{
    vector<Person*> v;
    v.push_back(new Person("John Adams","Boston","617-555-0000","john@adams.com"));
    v.push_back(new Student("John Quincy Adams","Boston","617-555-0000","johnq@adams.com","senior"));
    v.push_back(new Staff("Samuel Adams","Boston","617-555-BEER","sam@adams.com","brewhouse 1",1000,"9-15-1764","Brewer"));
    v.push_back(new StaffST("Samuel Smith","Boston","617-555-BEER","samsmith@adams.com","brewhouse 5",100,"9-15-1774","Taster","junior",50));
    v.push_back(new Faculty("Bob","Boston","617-555-BEER","samsmith@adams.com","brewhouse 5",100,"9-15-1774","Taster","junior"));
    // Hey - no Faculty object ---> add one yourself!
    
    for (int i=0; i<v.size(); i++)
    {
        cout << v[i]->getname() << "  " << v[i]->whatami() << endl;
    }
    
    return 1;
}


