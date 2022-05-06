#include "Person.h"
#include <string>
using namespace std; 

Person::Person()
{
   firstname = "";
   lastname = "";
   company = "";
} // constructor

Person::Person(string fname,string lname, string cname)
{
  firstname=fname;
  lastname=lname;
  company=cname;
}

string Person::getFirstName()
{
  return firstname;
}

string Person::getName()
{
  return firstname+lastname;
}

string Person::getLastName()
{
  return lastname;
}

string Person::getCompany()
{
  return company;
}
