#include "Person.h"
#include "iostream"
#include "PersFunc.h"
#include <string.h>
#include<fstream>
#include<string>
using namespace std;
static string error = "ERROR";

	Person::Person(){
	    Pol=-1;
	    gen=0;
	    id=0;
        name="NULL";
        iddad=0;
        idmom=0;
		age=0;
		birth=0;
		alive="NULL";
		familyname = "NULL";
		for(int i = 0; i < 256; i++)  str[i] = '\0';
	}

	Person::Person(string names,string familyname,int id,int age,int birth,bool alive,int idmom,int iddad,int Pol,int gen){
	    this->id=id;
		this->name=name;
		this->age=age;
	    this->birth=birth;
		this->alive=alive;
		this->idmom=idmom;
        this->familyname=familyname;
        this->iddad=iddad;
        this->Pol=Pol;
        this->gen=gen;

	}
Person::~Person(){

}
//+++++++++++++++++++++++++++ПЕРЕГРУЗКА++++++++++++++++++++++++++++++++++++++++++++++

void Person::operator +(char *s) //что должен выполнить оператор +
{
    strcat(str,s); //сложение строк
}

    void Person::getSTR()
{
    cout << str << endl << endl;//вывод символьного массива класса на экран
}

int &Person::operator[](int index){

 int n=Perssize("Person.txt");
if(index>=0||index<n-1){
        return this->p[index];

}
}
/////

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++СЕТТЕРЫ+++++++++++++++++++++++++++++++++++++++++++++
void Person::setGen(int gen){
this->gen=gen;
}
void Person::setPol(int Pol){
this->Pol=Pol;
}
void Person::setId(int id){
this->id=id;
}
	void Person::setName(string name){
		this->name=name;
	}

    void Person::setAge(){
		this->age=2018-getBirth();
	}

	void Person::setBirth(int birth){
		this->birth=birth;
	}

	void Person::setAlive(string alive){
		this->alive=alive;
	}
	void Person::setMama(int idmom){

      this->idmom=idmom;

	}
	void Person::setPapa(int iddad){
	 this->iddad=iddad;
	}
	void Person::setFamily(string familyname){
	this->familyname=familyname;
	}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++GETTER+++++++++++++++++++++++++++++++++++++++++++++++++++
int Person::getGen(){
return this->gen;
}
int Person::getPol(){
return this->Pol;

}
int Person::getId(){
return this->id;
}

int Person ::getMama(){
	return this->idmom;
	}
	int Person::getPapa(){
	return  this->iddad;
	}
	string Person::getFamily(){
	return this->familyname;
	}
	string Person::getName(){
		return this->name;
	}

	int Person::getAge(){
		return this->age;
	}

	int Person::getBirth(){
		return this->birth;
	}

	string Person::getAlive(){
		return this->alive;
	}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++ВЫВОД+НА+ЭКРАН+++++++++++++++++++++++++++++++++++++++++++++++++
	//void Person::displayPers(){
	//		cout<<getName()<<"\t"<<getBirth()<<" "<<"(Age: "<<getAge()<<" )"<<"\t"<<getAlive()<<"\n";
	//}

	void displayPers2(int n,Person *p){
	    cout << "Люди :\n";
		for(int i=0;i<n;i++){
			cout<<p[i].getName()<<" "<<p[i].getBirth()<<" "<<"(Age: "<<p[i].getAge()<<" )"<<" "<<p[i].getAlive()<<" "<<p[i].getPol()<<" "<<p[i].getGen()<<" "<<p[i].getFamily()<<"\n";
		}
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Person* Person::findPerson(Person *p,string name,int n ){//поиск нужного человека
int count = 0;
int birth = 0;
string name_1;
Person*	k;
for(int i=0;i<n;i++){
  if(p[i].getName()==name){
       k = &p[i];
        count--;
      }
}
if(count==-1){
return k;
}
else if (count<-1){
        cout<<"Укажите год рождения человека\n";
        cin>>birth;
        for(int i=0;i<n;i++){
        if(p[i].getName()==name){
        if(p[i].getBirth()==birth){
        k = &p[i];
  }
  }
    }

  return k;

}
else if(count==0){

        cout<<error<<"\n";
        cin>>name_1;
      k=p->findPerson(p,name_1,n);
       return k;
}

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Person::setParents(Person* p,int n){
    Person* s;
    Person* m;
    Person* f;
    string son,mom,dad;
    cout<<"Напшите имя человека для которого хотите установить родителей";
    cin>>son;
    s=p->findPerson(p,son,n);
    cout<<"Укажите его мать";
    cin>>mom;
    m=p->findPerson(p,mom,n);
     cout<<"Укажите его отца";
    cin>>dad;
    f=findPerson(p,dad,n);
    s->setMama(m->getId());
    s->setPapa(f->getId());

}
///////////////////////////////////////////////////////////////////////////////////////
Person* Person::findID(Person *p,int id,int n ){
int count = 0;

int j=n;
string namePers;

Person* k;
for(int i=0;i<n;i++){
  if(p[i].getId()==id){
		k = &p[i];
      count--;
      }

}
if(count==-1){
return k ;
}
else
    return nullptr;


}
/////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
int Person::initPers(Person *p,string fileName){//Инициализация людей в общем файле
     ofstream gfile;
	ifstream ifile;
	ofstream mfile;
     gfile.open("Female.txt");
     mfile.open("Man.txt");
	ifile.open(fileName);
	//string gfamilyname ="None";

	if(!ifile)
		return -1;
	int i=0;
	string name,alive,familyname;

	int birth,idmom,iddad,id,Pol,gen;
while(ifile>>id>>name>>birth>>alive>>idmom>>iddad>>familyname>>Pol>>gen){

        p[i].setId(i+1);
		p[i].setName(name);
		p[i].setBirth(birth);
		p[i].setAge();
		p[i].setAlive(alive);
        p[i].setMama(idmom);
		p[i].setPapa(iddad);
		p[i].setFamily(familyname);
		p[i].setPol(Pol);
		p[i].setGen(gen);

		 if(p[i].getPol()==0){
           gfile<<p[i].getId()<<" "<<p[i].getName()<<" "<<p[i].getBirth()<< " "<<p[i].getAlive()<<" "<<p[i].getMama()<<" "<<p[i].getPapa()<<" "<<p[i].getFamily()<<" "<<p[i].getPol()<<" "<<p[i].getGen()<<"\n";
           gfile.close();
        }
         else if (p[i].getPol()==1){
            mfile<<p[i].getId()<<" "<<p[i].getName()<<" "<<p[i].getBirth()<< " "<<p[i].getAlive()<<" "<<p[i].getMama()<<" "<<p[i].getPapa()<<" "<<p[i].getFamily()<<" "<<p[i].getPol()<<" "<<p[i].getGen()<<"\n";
            mfile.close();
         }


		i++;

}
	ifile.close();
}
////////////////////////////////////////////////////////////////////////////////////////////
int Person::Genit(Person*p,int n){
 string myz,gena;
 Person*t;
 Person*q;
 cout<<"Set Man's name\n";
 cin>>myz;
 t=p->findPerson(p,myz,n);
 while((t->getPol())==0){
    cout<<"Укажите мужчину\n";
    cin>>myz;
    t=t->findPerson(p,myz,n);
 }

 cout<<"Set Female's name\n";
 cin>>gena;
 q=p->findPerson(p,gena,n);
 while((q->getPol())==1){
    cout<<"Укажите женщину\n";
    cin>>gena;
    q=q->findPerson(p,gena,n);
 }
 cout<<"f";
 t->setGen(q->getId());
 q->setGen(t->getId());

  return  t->getId();

}

