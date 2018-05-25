#ifndef PERSON_H
#define PERSON_H
#include <string>


using namespace std;


class Person{
private:
    char str[256];
	int age;
    int  id;
	string alive;
    string name;
    int idmom;
    int iddad;
    string familyname;
    int Pol;
    int gen;
    int*p;
public:
    int birth;
	Person();

    void operator +(char*);
  bool  operator<(Person& x);
friend istream& operator>>(istream& p, Person& a);

    void getSTR();
    ~Person();

	Person(string name,string familyname,int id,int age,int birth,bool alive,int idmom,int iddad,int Pol,int gen);

void setId(int id);
int getId();

 void setPol(int Pol);
 int getPol();

	void setName(string name);

	string getName();

void setPapa(int iddad);

int getPapa();

void setMama(int idmom);

int getMama();

void setFamily(string familyname);
string getFamily();

	void setAge();

	int getAge();

	void setBirth(int birth);

	int getBirth();

	void setAlive(string alive);

	string getAlive();

	void setGen(int gen);
	int getGen();

	void displayPers();

	friend void displayPers2(int n,Person *p);
    virtual int initPers(Person *p,string fileName);
    //////////////////////////////////////////////////////
    int Genit(Person*p,int n);
   int &operator[](int index);

  virtual Person* findPerson(Person *p,string name,int n );
   void setParents(Person* p,int n);
   Person* findID(Person *p,int id,int n );



	void menu();

};
#endif // PERSON_H
