#include <iostream>
#include<locale.h>
#include <string>
#include <cstring>
#include <fstream>
#include "familyName.h"
#include"Man.h"
#include"Female.h"
#include "Person.h"
#include "PersFunc.h"
#include"famTreeFunc.h"

using namespace std;
int Perssize(string fileName);
void InfoPers(Person *p,string name,int n);

int main()
{   setlocale(LC_ALL,"RUS");
    char *str1 = new char [strlen("FAMILY ")+1];
    char *str2 = new char [strlen("TREE v3.0\n")+1];
    string fileName_1="Person.txt";
    string fileName_2="Famtree.txt";
    string fileName_3="famPers.txt";
    string fileName_5="Female.txt";
    string fileName_6="Man.txt";
    string fileName_7="Female_save.txt";
    string filename_4;
    strcpy(str1,"FAMILY ");
    strcpy(str2,"TREE v3.0\n");


     Person story;
     story + str1;
     story + str2;



	int n,m,t,k,f;

	string kek,fmname,fmname1;
    story.getSTR();




if((m=Perssize(fileName_1))==-1)
		return 0;




Person *q = new Person[m];

q->initPers(q,fileName_1);




  displayPers2(m,q);

	int ch=0;
	while(ch!=-1){
  menu();
		cin>>ch;
		if(ch==-1)
			break;
		else if(ch==1){
		 q=add(q,m,fileName_1);
		 displayPers2(m,q);
		}
		else if(ch==2){

q->Genit(q,m);
displayPers2(m,q);
save(q,m,fileName_1);


		}
		else if(ch==3){

	cout<<"Óêàæèòå èìÿ ÷åëîâåêà \n";
        cin>>kek;
	InfoPers(q,kek,m);
		}
		else if(ch==4){

		}

		else if(ch==5){

	}
	    else if(ch==6){



		}

		else if (ch == -1){

		}




	}
    return 0;
}

/////////////////////////////////////////////////////////
void InfoPers(Person *p,string name,int n){
   Person*dad;
   Person*mam;
   Person*sup;

   string none_name="Íå óêàçàí";
  Person* temp=p->findPerson(p,name,n);

    int info=0;
    cout<<"////////////////////ÈÍÔÎÐÌÀÖÈß Î ×ÅËÎÂÅÊÅ////////////////////\n";
    cout<<"ÈÌß - "<<temp->getName()<<"\n";
    cout<<"ÔÀÌÈËÈß - "<<temp->getFamily()<<"\n";
    cout<<"ÃÎÄ ÐÎÆÄÅÍÈß - "<<temp->getBirth()<<"\n";
    if((dad=p->findID(p,temp->getPapa(),n))==nullptr)
    cout<<"ÎÒÅÖ -"<<none_name<<"\n";
    else
    cout<<"ÎÒÅÖ -"<<dad->getName()<<"\n";
    if((mam=p->findID(p,temp->getMama(),n))==nullptr)
    cout<<"ÌÀÒÜ -"<<none_name<<"\n";
    else
    cout<<"ÌÀÒÜ - "<<mam->getName()<<"\n";
    if((sup=p->findID(p,temp->getGen(),n))==nullptr)
    cout<<"Ñóïðóã/Ñóïðóãà -"<<none_name<<"\n";
    else
    cout<<"Ñóïðóã/Ñóïðóãà - "<<sup->getName()<<"\n";
    cout<<"/////////////////////////////////////////////////////////////\n";
    cout<<"info î ìàòåðè-1\n";
    cout<<"info î ïàïå -2\n";
    cout<<"info î ñóïðóãå-3\n";
    cout<<"Âûõîä èç èíôî-0\n";
    cin>>info;
    while(info!=0){
    if(info==1){
       InfoPers(p,mam->getName(),n);
       }
    if(info==2){
       InfoPers(p,dad->getName(),n);
       }
    if(info==3){
;
    }
    if(info==0)
        ;
}


}
