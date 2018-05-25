#include "PersFunc.h"
#include"familyName.h"
#include"Person.h"
#include <iostream>
#include"Female.h"
#include <cstring>
#include <string>
#include <stddef.h>
#include <fstream>
#include<math.h>
using namespace std;
static string error = "ERROR";//����������� ����������




Person* add(Person *p,int &n,string fileName){//���������� ����� � ����� ����
	Person *temp=new Person[n+1];
	for(int i=0;i<n;i++){
        temp[i].setId(p[i].getId());
		temp[i].setName(p[i].getName());
		temp[i].setBirth(p[i].getBirth());
		temp[i].setAge();
		temp[i].setAlive(p[i].getAlive());
		temp[i].setMama(p[i].getMama());
		temp[i].setPapa(p[i].getPapa());
		temp[i].setFamily(p[i].getFamily());
		temp[i].setPol(p[i].getPol());
		temp[i].setGen(p[i].getGen());
	}

	string name,alive,family,gen;
	string mama,papa;
	int birth,pol;
	temp[n].setId(n+1);
	cout<<"��� ������ �������� : ";
	cin>>name;
	temp[n].setName(name);
	cout<<"��� ��� �������� : ";
	cin>>birth;
	temp[n].setBirth(birth);
	temp[n].setAge();
	cout<<"�������� 'alive' ��� 'dead': ";
	cin>>alive;
	if(alive=="alive")temp[n].setAlive(alive);
	else if(alive=="dead")

		temp[n].setAlive(alive);
	else
		temp[n].setAlive("Null");
    cout<<"������� ��� ����:";
    cin>>mama;
    Person* m =p->findPerson(p,mama,n);
    temp[n].setMama(m->getId());
    cout<<"������� ��� ����:";
    cin>>papa;
    Person* pa =p->findPerson(p,papa,n);
    temp[n].setPapa(pa->getId());
    cout<<"������� ��� �������:";
    cin>>family;
    temp[n].setFamily(family);
    cout<<"������� ��� �������/�������:";
    cin>>gen;
    Person* sup =p->findPerson(p,gen,n);
    temp[n].setGen(sup->getId());
    cout<<"������� ��� ���(0-�������;1-�������):";
    cin>>pol;
    temp[n].setPol(pol);
    p=nullptr;
	n=n+1;
	cout<<"��������.\n";
	return temp;
}
void save(Person *p,int n,string fileName){
	ofstream ofile;
	ofile.open(fileName);

	for(int i=0;i<n;i++)
		ofile<<p[i].getId()<<" "<<p[i].getName()<<" "<<p[i].getBirth()<< " "<<p[i].getAlive()<<" "<<p[i].getMama()<<" "<<p[i].getPapa()<<" "<<p[i].getFamily()<<" "<<p[i].getPol()<<" "<<p[i].getGen()<<"\n";

    ofile.close();
	cout<<"���������.\n";

}





//=====================================================================================================
void menu(){
   cout<<"�������� ������� : \n";
	cout<<"1-�������� ��������.\n";
	cout<<"2-������\n";
	cout<<"3-��������\n";
	cout<<"4-\n";
	cout<<"5-\n";
	cout<<"6-\n";
	cout<<"7-\n";
    cout<<"-1 - ����� �� ���������\n";



}





//============================================================================================================


/////////////////////////////////////////////////////////////////////////

//////////////////
Perssize(string fileName){//���������� ����� � ����� �����
	ifstream ifile;
	ifile.open(fileName);
	if(!ifile)
		return -1;
	int size=0;
	string temp;
	int t;

    while(ifile>>t>>temp>>t>>temp>>t>>t>>temp>>t>>t){
        size++;

	}

	cout<<size<<" people documented.\n";
	return size;
     ifile.close();

}
//////////////////////////////////////////////////////////////////////////////////

