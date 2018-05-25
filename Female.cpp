#include "Female.h"
#include"Man.h"
#include"Person.h"
#include"fstream"
#include"iostream"
#include"locale.h"
#include"PersFunc.h"
#include<string>

using namespace std;
static string error = "ERROR";
Female::Female():Person(){

gfamilyname="NULL" ;

}
Female::Female(string name,string familyname,string gfamilyname,int id,int age,int birth,bool alive,int idmom,int iddad,int Pol,int gen):Person(name,familyname,id,age,birth,alive,idmom,iddad,Pol,gen){
this->gfamilyname=gfamilyname;
}

string Female::getGfamilyname(){

	return this->gfamilyname;

	}
	void Female::setGfamilyname(string gfamilyname){
	   this->gfamilyname=gfamilyname;
	}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////

Female* Female::findPerson(Female*p,string name,int n ){//поиск нужного человека
int count = 0;
int birth = 0;
string name_1;
Female*	k;
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
        cout<<"Set female's year of birth \n";
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
      k=findPerson(p,name_1,n);
       return k;
}

}
///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////


///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
