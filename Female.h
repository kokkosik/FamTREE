#ifndef FEMALE_H
#define FEMALE_H
#include"Man.h"
#include "Person.h"
#include"PersFunc.h"

class Female : public Person
{
    public:
        Female();
    Female(string name,string familyname,string gfamilyname,int id,int age,int birth,bool alive,int idmom,int iddad,int Pol,int gen);
///////////////////////////////////////////

//////////////////////////////////////////
friend void displayFemale(int n,Female *p);

Female* findPerson(Female *p,string name,int n );
int initFemFile(Female *p,string fileName);
Female* initFem(Person*p,int n);


void setGfamilyname(string gfamilyname);
string getGfamilyname();

    private:
        string gfamilyname;



        string suprug;
};

#endif // FEMALE_H
