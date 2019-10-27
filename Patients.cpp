#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Patient.cpp"

class Patients{

public :

int filled ; // how much space is filled in array
int size;
Patient* pat;  // dynamicaly alocated array of object Patient 


Patients(int s) {
size = s;
filled = 0;


 pat = new Patient[size];
 
 
 }
	




void addPatient(string n,string s,int i,string g,string d,string stat){  // adding patient
Patient p(n,s,i,g,d,stat);

Patient* temp;



if(filled == 0){
	pat[0] = p;
	filled++;
}else if(filled>= size  ){   // if its full create bigger array and copy
	
	size = size *2;
     temp= new Patient[size];
	 for(int i = 0; i < filled;i++){
	 	    temp[i] = Patient(pat[i]);
	    
	 }
	 
	 
	  delete [] pat;
	 
	 pat = temp;
     pat[filled] = p;
	 
	 filled++;
		 
	
}else{
	pat[filled]= p;
	filled++;
}	 
	 
	
	
	
	
}

void discharging(Patient* p){
	p->status = "discharged";
	p->displayPatient();
	cout<<"patient discharged"<<endl;
}


void displayAll()
{
   	for(int i =0; i < filled;i++){ //showing all patients in array
   	
   		pat[i].displayPatient();
	   }
	   	
}

void save(){         // save everything to textfile
	ofstream hospfile;
	hospfile.open("patients.txt");
 	
	
for(int i = 0;i < filled;i++){

	hospfile<<
     "Name    : "<< pat[i].name <<"\n"
	<<"Surname : "<< pat[i].surname <<"\n"
	<<"id      : "<< pat[i].id <<"\n"
	<<"Gender  : "<< pat[i].gender <<"\n"
	<<"date    : " << pat[i].date<<"\n"
	<<"status  : "<<pat[i].status<<"\n\n";
}
     hospfile.close();
     
     cout<<"save complete "<<endl;
   
}

Patient* search(int n){  //searching by id
	 
	for(int i = 0; i < filled;i++){
		
		if(pat[i].id == n){
		   cout<<"found :"<<endl;
		  pat[i].displayPatient();
		  
          return &(pat[i]);    	
	}	
}
    cout<< "\nPatient not found" << endl;
	return NULL;
}

Patient* search(string n,string s){   // searh with name
	 bool found = false;
	for(int i = 0; i < filled;i++){
		
		if(pat[i].name == n){
         if(pat[i].surname== s){
		 
		  found = true;
		  cout<<"found :"<<endl;
		  pat[i].displayPatient();
          
		  return &(pat[i]);
		 }
		} 
	
	}
	cout<< "\nPatient not found" << endl;
	 return NULL;	
}

void genderList(){
	ofstream hospfile;
	hospfile.open("patients-genderlist.txt");
	
	for(int i = 0; i < filled;i++){ //printing out and saving all females
	  if(pat[i].gender.compare("female")==0){  
	  	 pat[i].displayPatient();
	  	hospfile<<
    	 "Name :"<< pat[i].name <<"\n"
		<<"Surname :"<< pat[i].surname <<"\n"
		<<"id :"<< pat[i].id <<"\n"
		<<"Gender :"<< pat[i].gender <<"\n"
		<<"date : " << pat[i].date<<"\n"
		<<"status : "<<pat[i].status<<"\n\n";
	  	 	 
	  }
		
	}
	
	for(int i = 0; i < filled;i++){  // printing out and saving all males
	  if(pat[i].gender.compare("male")==0){
	  	 pat[i].displayPatient();
	  	hospfile<<
    	 "Name :"<< pat[i].name <<"\n"
		<<"Surname :"<< pat[i].surname <<"\n"
		<<"id :"<< pat[i].id <<"\n"
		<<"Gender :"<< pat[i].gender <<"\n"
		<<"date : " << pat[i].date<<"\n"
		<<"status : "<<pat[i].status<<"\n\n";
	  	 	 
	  }
		
	}
}

void deletePatient(Patient* p){    // deletion of patient
  bool found = false;
	for(int i = 0; i < filled;i++){
		
		if(pat[i].id == p->id){
		  found = true;
		
		  
		  for(int j = i;j <filled - 1;j++){ // shifting all elements down by 1
		      
		      pat[j] = pat[j+1];
		    }
		  
		  
		}
		
	}
	
	
	  if(found = true){
	  	cout<<"deletion complete"<<endl;
	  	
		filled--;
	  }else{
	  
	  cout<<"incomplete not found"<<endl;
     }
	   
}


};
