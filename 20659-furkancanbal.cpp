#include <iostream>
#include <string>
#include <fstream>
#include "linkedlist.h"
#include <vector>

using namespace std;

int main(){




	ifstream inFile;

	inFile.open("docdb.txt");

	LinkedList<string,int> listone; //creating list

	string y;
	int x;

	while(!inFile.eof()){


		inFile>>y>>x;


		listone.addToBeginning(y,x); //sending y and x values to the list


	}
	

	string  input;
	string input1;
	string inputnumber;
	string temp;
	string allstring;
	int rakam;
	int rakam2;
	int finder;
	
	string quit="";
	
	cout<<"Search words.If you want to quit type quit"<<endl;
	getline(cin,input);
	quit=input;
	while(quit!="quit") //ending condition
	
	{
	
	vector<int> numberholder;

	
	rakam= input.find(" ");
	inputnumber=input.substr(0,rakam);                  //  These part divides string to smaller strings 
	rakam2=atoi(inputnumber.c_str());
	allstring=input.substr(rakam+1,input.length()-rakam);
	input=input.substr(rakam+1,input.length()-rakam)+" ";
	temp=input;
	
	
	if(rakam2>1) {  //if there are more than one word
	
		
	
	

	
	int controller2=0;
	for(int	recorder=0;recorder<rakam2;recorder++)
	{

		finder=input.find(" ");										//send suitable words to functions and keep the rest of the strings
		temp=input.substr(0,finder);
		listone.intersect(numberholder,temp,controller2);    
		input=input.substr(finder+1,input.length()-finder);
		
			controller2++;
	}

		
	cout<<allstring<<" "<<numberholder.size()<<" ";

	for(int y=0;y<numberholder.size();y++){
	
	
		cout<<numberholder[y]<<" ";   //print all of them
	
	
	
	}
	 cout<<endl;
	}

	else if(rakam==1) {  //if there is only one word to search
		input=input.substr(0,input.length()-1);
	listone.print(input);   
	cout<<""<<endl;
	}

	 
	cout<<"Search words.If you want to quit type quit"<<endl;
	getline(cin,input);
	quit=input;




	}
	







	
	return 0;
}



