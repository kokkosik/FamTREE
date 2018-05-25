#ifndef MAN_H
#define MAN_H
#include"Person.h"
#include"Female.h"
using namespace std;

class Man : public  Person
{
    public:
       Man();
    Man(string name,string familyname,int id,int age,int birth,bool alive,int idmom,int iddad,int Pol,int gen);
  int initMan(Man* p,string fileName);
  Man* findPerson(Man *p,string name,int n);
  friend void displayMan(int n,Man*p);
    protected:

    private:
};

#endif // MAN_H
