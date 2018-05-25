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
static string error = "ERROR";//статическая переменная




Person* add(Person *p,int &n,string fileName){//Добавление ЛЮДЕЙ в общий файл
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
	cout<<"Имя нового Человека : ";
	cin>>name;
	temp[n].setName(name);
	cout<<"Год его рождения : ";
	cin>>birth;
	temp[n].setBirth(birth);
	temp[n].setAge();
	cout<<"напишите 'alive' или 'dead': ";
	cin>>alive;
	if(alive=="alive")temp[n].setAlive(alive);
	else if(alive=="dead")

		temp[n].setAlive(alive);
	else
		temp[n].setAlive("Null");
    cout<<"Укажите его мать:";
    cin>>mama;
    Person* m =p->findPerson(p,mama,n);
    temp[n].setMama(m->getId());
    cout<<"Укажите его отца:";
    cin>>papa;
    Person* pa =p->findPerson(p,papa,n);
    temp[n].setPapa(pa->getId());
    cout<<"Укажите его фамилию:";
    cin>>family;
    temp[n].setFamily(family);
    cout<<"Укажите его супруга/супругу:";
    cin>>gen;
    Person* sup =p->findPerson(p,gen,n);
    temp[n].setGen(sup->getId());
    cout<<"Укажите его ПОЛ(0-женщина;1-мужчина):";
    cin>>pol;
    temp[n].setPol(pol);
    p=nullptr;
	n=n+1;
	cout<<"Добавлен.\n";
	return temp;
}
void save(Person *p,int n,string fileName){
	ofstream ofile;
	ofile.open(fileName);

	for(int i=0;i<n;i++)
		ofile<<p[i].getId()<<" "<<p[i].getName()<<" "<<p[i].getBirth()<< " "<<p[i].getAlive()<<" "<<p[i].getMama()<<" "<<p[i].getPapa()<<" "<<p[i].getFamily()<<" "<<p[i].getPol()<<" "<<p[i].getGen()<<"\n";

    ofile.close();
	cout<<"Сохранено.\n";

}





//=====================================================================================================
void menu(){
   cout<<"Выберите позицию : \n";
	cout<<"1-Добавить Человека.\n";
	cout<<"2-Женить\n";
	cout<<"3-БлокИНФО\n";
	cout<<"4-\n";
	cout<<"5-\n";
	cout<<"6-\n";
	cout<<"7-\n";
    cout<<"-1 - Выход из программы\n";



}





//============================================================================================================


/////////////////////////////////////////////////////////////////////////

//////////////////
Perssize(string fileName){//Количество людей в общей файле
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

