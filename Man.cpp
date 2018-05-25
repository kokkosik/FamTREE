#include "Man.h"
#include "Person.h"
#include"Female.h"
#include"PersFunc.h"
#include<string>
#include "iostream"
#include"fstream"

using namespace std;
static string error = "ERROR";
Man::Man():Person(){

}
Man::Man(string name,string familyname,int id,int age,int birth,bool alive,int idmom,int iddad,int Pol,int gen):Person(name,familyname,id,age,birth,alive,idmom,iddad,Pol,gen){
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
Man* Man::findPerson(Man *p,string name,int n ){//поиск нужного человека
int count = 0;
int birth = 0;
string name_1;
Man*	k;
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
      k=findPerson(p,name_1,n);
       return k;
}

}
