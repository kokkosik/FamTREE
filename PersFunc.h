#ifndef PERSFUNC_H
#define PERSFUNC_H
#include<string>
#include "Person.h"
#include"Female.h"
using namespace std;

Person* add(Person *p,int &n,string fileName);
Person* findPerson(Person *p,string name,int n);
void save(Person *p,int n,string fileName);
void Parents(Person *p,int n,string filename);

void infoParents(Person* p,int n);

//==============================================================

void menu();
int Perssize(string fileName);
#endif // PERSFUNC_H
