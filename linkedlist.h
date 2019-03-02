#include<iostream>
#include <string>
#include <vector>

using namespace std;





template <class itemType,class itemKind>
class LinkedList 
{
private:
	struct node {
	itemType info;
	itemKind number;  //struct consist of 4 parts
	node *docnumb;
	node* next; 

	node ()
	{ }

	node (itemType  s, node* d, node * link,itemKind z)
		: info(s), docnumb(d), next (link), number(z)
	{ }

};
	node<itemType,itemKind> * head;


public:
	LinkedList ();


	void addToBeginning(itemType n,itemKind m);
	void print(itemType a);
	void sort();
	void intersect(vector<itemKind> &s,itemType a, itemKind checker);

};


template <class itemType,class itemKind>
LinkedList<itemType,itemKind>::LinkedList ()
{
	head = NULL;

}



template <class itemType,class itemKind>
void LinkedList<itemType,itemKind>::addToBeginning (itemType word,itemKind page)
{
	string sslot="string";
	int integers=0;
	node<itemType,itemKind> *ptr =head;
	int flag=0;
	int controller=0;

	if(ptr==NULL){

		node<itemType,itemKind> *ptr2=new node<itemType,itemKind>(sslot,NULL,NULL,page); //if this the first word add the the linklist first create integer side of linklist 

		node<itemType,itemKind> *ptr3=new node<itemType,itemKind>(word,ptr2,head,integers); //then create string side of link list and  connect to each other
		head=ptr3;
	}

	else{



		while(ptr!=NULL){
			if(ptr->info==word){
				flag=1;												//if the word isn't new .Just create a new integer node and connect it to the other pages  
				break;
			} else{ ptr=ptr->next; controller++;}
		}

		if(flag==1){

			node<itemType,itemKind> *ptr2=new node<itemType,itemKind>(sslot,ptr->docnumb,NULL,page);
			ptr->docnumb=ptr2;
		}
		else{

			node<itemType,itemKind> *ptr2=new node<itemType,itemKind>(sslot,NULL,NULL,page);

			node<itemType,itemKind> *ptr3=new node<itemType,itemKind>(word,ptr2,head,integers);
			head=ptr3;






		}
	}

}


template <class itemType,class itemKind>

void LinkedList<itemType,itemKind> :: print(itemType word) //if i search for one word this function print it
{
	int flag=0;
	int size=0;
	node<itemType,itemKind> *ptr=head;
	vector<int> myvector;
	while(ptr!=NULL){

		if(ptr->info==word){
			flag=1;

			while(ptr->docnumb!=NULL){ myvector.push_back(ptr->docnumb->number);  size++; ptr=ptr->docnumb;} //push all the number to the vector

		}
		else{ ptr=ptr->next;}
	}

	if(flag==0){cout<<"0 "<<word<<endl;}

	else{
		cout<<word<<" "<<size<<" ";
		for(int x=0;x<size;x++){ 

			cout<<myvector[x]<<" "; //print all of tem

		}
	}




}




template <class itemType,class itemKind> //find the intersection and print it
void LinkedList<itemType,itemKind>::intersect(vector<itemKind> & numberholder,itemType a,itemKind controller){
	int redflag=0;
	node<itemType,itemKind> *ptr=head; 
	vector<itemKind> numberplacer;
	if(controller==0){                    //because of controller if first part of string process in  there



		while(ptr!=NULL){

			if(ptr->info==a){


				while(ptr->docnumb!=NULL){

					numberholder.push_back(ptr->docnumb->number);	//just push all the number to the vector
					ptr=ptr->docnumb;
				}
				ptr=ptr->next;
			}
			else {ptr=ptr->next;}

		}
	}

	else{
		 while(ptr!=NULL){
		if(ptr->info==a){


			while(ptr->docnumb!=NULL){

				for(int a=0;a<numberholder.size();a++) {

					if(ptr->docnumb->number==numberholder[a])		//other parts of the words are contralling for numbers
					{ redflag=1; numberplacer.push_back(numberholder[a]);	}  //if both of them have same number push another vector
					

			
				}
				ptr=ptr->docnumb;
			}

			numberholder=numberplacer;		//first input vector become equal to second temp vector.Now our first vector consist of intersections
		}
		else {ptr=ptr->next;}

		 }
		 if(redflag==0){ vector<int>trash; numberholder=trash;  }

	}
	
}


template <class itemType,class itemKind>
void LinkedList<itemType,itemKind> ::sort(){

	node<itemType,itemKind> *ptr=head;
		node<itemType,itemKind> *ptr2=ptr->docnumb;
	node<itemType,itemKind> *ptr3=ptr2->docnumb;
	int temp1;

	for(ptr=ptr; ptr==NULL;ptr->next){

		for(ptr2=ptr2;ptr2==NULL;ptr2->docnumb){

			for(ptr3=ptr3;ptr3==NULL;ptr->docnumb) {

				if(ptr3->number > ptr2->number) {    

					temp1=ptr2->number;
					ptr2->number=ptr3->number;
					ptr3->number=temp1;

				}




			}
		}	
	}
}



