#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
class Patient{   // a patient

public :
	
string name;
string surname;
int id;
string gender;
string date;
string status;

Patient(){
}

Patient(string n,string s,int i,string g,string d,string stat){

name = n;
surname= s;
id = i;
gender = g;
date = d;
status = stat;

}

Patient(const Patient &p){  // copy constructer
name = p.name;
surname= p.surname;
id = p.id;
gender = p.gender;
date = p.date;
status = p.status;	
	
}


displayPatient(){
	cout<<"\nName    : "<< name <<endl;
	cout<<"Surname : "<< surname <<endl;
	cout<<"id      : "<< id <<endl;
	cout<<"Gender  : "<< gender <<endl;
	cout<<"date    : " << date<<endl;
	cout<<"status  : "<<status<<"\n\n"<<endl;
}



};


