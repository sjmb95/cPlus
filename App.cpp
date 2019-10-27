#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Patients.cpp"
#include <cstdlib>
#include<stdio.h>
using namespace std;



class App{

public:

string line;
int size, id;
string name, surname,gender,date,status;
Patients* patientList;
string strId;   // input id string to be converted to int


bool begining;
int tempId;    //  input id not incremented id;

App(){
	

id = 0;

 begining = false; 
 size = getSize();
 

if(size == 0) //checking if empty hen would request for size;
{
 begining = true;
cout<<"input size of list"<<endl;
cin>>size;


}


patientList = new Patients(size);	
}

void run(){
	
	ifstream data("patients.txt");

while(getline(data,line)){ // getting patient data from textfile and storing them in array using rows and cols
   
   
    
     
     
     
 	 name= line.substr(10,line.length());
 	 
	  getline(data,line);
 	 surname= line.substr(10,line.length());
 	  
 	 getline(data,line);
 	istringstream temp(line.substr(10,line.length()));
 	 temp>>id;
 	 
 	 getline(data,line);
 	 gender= line.substr(10,line.length());
 	 
	 getline(data,line);
	 date= line.substr(10,line.length());
 	 
 	 getline(data,line);
 	 status= line.substr(10,line.length());
 	 
 	 patientList->addPatient(name,surname,id,gender,date,status);
 	 getline(data,line);
 	 
 	
 	 
 }
 data.close();
 
  
if(begining == false){  // check if beginning to prevent double menu display
 
cout<<"  ****************************************************************************"<<endl;
cout<<"  * (a) add Patient  (b)search by name  (c) search by id  (d)discharge       *\n  * (e) display gender list (f) display ALL  (g) delete  (s) save  (q) quit  *"  <<endl;
cout<<"  ****************************************************************************"<<endl;
cout<<"enter option"<<endl;
} 

string input ;



while(input!= "q"){
// options to choose

 getline(cin,input);
 if(input.compare("a") == 0){
    id++;       // next id is always incremented by 1
 	cout<<"enter name"<<endl;
 	getline(cin,name);
 	cout<<"enter surname"<<endl;
 	getline(cin,surname);
 	cout<<"enter gender"<<endl;
 	getline(cin,gender);
 	cout<<"enter date"<<endl;
 	getline(cin,date);
 	cout<<"enter status"<<endl;
 	getline(cin,status);
 	
 	patientList->addPatient (name,surname,id,gender,date,status);
    patientList->displayAll();

    
    
 }else if(input.compare("b")== 0){
 	cout<<"enter name of patient :"<<endl;
 	getline(cin,name);
 	patientList->search(name,surname);
 }else if(input.compare("c") == 0){
 
   cout<<"enter ID of patient :"<<endl;
 	getline(cin,strId);
 	istringstream iss(strId);
 	iss>> tempId;
 	patientList->search(tempId);

}else if(input.compare("d")== 0){
 	cout<<"enter patient id :"<<endl;
 	getline(cin,strId);
 	istringstream iss(strId);
 	iss>> tempId;
 	
 	patientList->discharging(patientList->search(tempId));
 	
 }else if(input.compare("e") == 0){
     
     patientList->genderList();
  

}else if(input.compare("f")== 0){
 	
 	patientList->displayAll();
} else if(input.compare("g")== 0){
 	cout<<"enter patient id :"<<endl;
   	getline(cin,strId);
 	istringstream iss(strId);
 	iss>> tempId;
 	patientList->search(tempId);
	 
	 patientList->deletePatient(patientList->search(tempId));
 	
 }else if(input.compare("s")== 0){
 	patientList->save();
 	
 }else if(input.compare("q")==0){
 
  cout<<"****************** PROGRAM TERMINATED *******************"<<endl;
  
 	break;
 }else{
 
 	if(input.compare("")== 1){
	 
 	 cout<<" \n YOU HAVE ENTERED AN INCORRECT OPTION  "<<endl;
 }
 }
 
 
 
cout<<"  ****************************************************************************"<<endl;
cout<<"  * (a) add Patient  (b)search by name  (c) search by id  (d)discharge       *\n  * (e) display gender list (f) display ALL  (g) delete  (s) save  (q) quit  *"  <<endl;
cout<<"  ****************************************************************************"<<endl;
cout<<"enter option"<<endl;

}




	
	
}

int  getSize(){   //getting size of array through textfile 
	int count = 0;
	
	ifstream file("patients.txt");
	while(getline(file,line)){
	   if(line.compare(" ")== 1){
	   
	   	count++;
	}
	 
	}
	file.close();
      return count/6;
	
}
	
	
};
