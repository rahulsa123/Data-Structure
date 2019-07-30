/*
 * Double_Linked_List.cpp
 *
 *  Created on: 30-Jul-2019
 *      Author: rahul
 */

#include <iostream>
using namespace std;
#include "headerFile.h"
struct Node{
	int data;
	Node *prev,*next;
};
Node * DOUBLE_LINKED_LIST=NULL;
int double_linked_list_isEmpty(){
	if(DOUBLE_LINKED_LIST==NULL)
		return 1;
	else
		return 0;
}
int double_linked_list_insert(){
	Node *ref = new Node;
	ref->prev=NULL;
	ref->next=NULL;
	cout<<"Enter data :-";
	cin>>ref->data;
	if(double_linked_list_isEmpty())
		DOUBLE_LINKED_LIST=ref;
	else{
		Node *temp=DOUBLE_LINKED_LIST;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ref;
		ref->prev=temp;
	}
	cout<<"Data is inserted \n";
	cout<<"Press enter ";
	getchar(); getchar();
	return 1;
}
int double_linked_list_display(){
	if(double_linked_list_isEmpty())
		cout<<"firstly enter some element";
	else{
		Node *ref= DOUBLE_LINKED_LIST;
		cout<<"NULL <==> ";
		while(ref!=NULL){
			cout<<ref->data<<" <==> ";
			ref=ref->next;
		}
		cout<<"NULL";
	}
	cout<<"\n Press enter ";
	getchar();getchar();
	return 1;
}
int double_linked_list_add_first(){
	Node *ref = new Node;
		ref->prev=NULL;
		ref->next=NULL;
		cout<<"Enter data :-";
		cin>>ref->data;
		if(double_linked_list_isEmpty())
			DOUBLE_LINKED_LIST=ref;
		else{
			DOUBLE_LINKED_LIST->prev=ref;
			ref->next=DOUBLE_LINKED_LIST;
			DOUBLE_LINKED_LIST=ref;
		}
	cout<<"Data is inserted \n";
	cout<<"\n Press enter ";
	getchar();getchar();
	return 1;
}
int double_linked_list_length(){
	int count=0;
	for(Node *ref=DOUBLE_LINKED_LIST;ref!=NULL;ref=ref->next)
		count++;
	return count;
}
int double_linked_list_add_after(){
	if(double_linked_list_isEmpty())
			cout<<"firstly enter some element";
	else{
		int length = double_linked_list_length(), position;
		cout<<"Enter position  you wanted to insert data from 2 to "<< length+1<<":- ";
		cin>>position;
		if(position<2 || position>length+1)
			cout<<"Enter valid position";
		else{
			position--;
			Node *ref = new Node;
			ref->prev=NULL;
			ref->next=NULL;
			cout<<"Enter data :-";
			cin>>ref->data;
			Node *temp= DOUBLE_LINKED_LIST;
			while(--position){
				temp=temp->next;
			}
			ref->next=temp->next;
			ref->prev=temp;
			if(temp->next!=NULL)
				temp->next->prev=ref;
			temp->next=ref;
			cout<<"Data in inserted\n";
		}
	}
	cout<<"\n Press enter ";
		getchar();getchar();
		return 1;
}
int double_linked_list_delete(){
	if(double_linked_list_isEmpty())
				cout<<"firstly enter some element";
		else{
			int length = double_linked_list_length(), position;
			cout<<"Enter position  you wanted to Delete, from 1 to "<< length<< ":- ";
			cin>>position;
			if(position<1 || position>length)
				cout<<"Enter valid position";
			else{
				Node *temp = DOUBLE_LINKED_LIST;
				if(position==1){
					DOUBLE_LINKED_LIST=temp->next;
					if(DOUBLE_LINKED_LIST!=NULL) // for checkin only element in list
						DOUBLE_LINKED_LIST->prev=NULL;
					free(temp);

				}
				else{
					while(--position)
						temp=temp->next;
					temp->prev->next=temp->next;
					if(temp->next!=NULL)//checking last element
						temp->next->prev=temp->prev;
					free(temp);
				}
				cout<<"Data is deleted from list";
			}
		}
		cout<<"\n Press enter ";
		getchar();getchar();
		return 1;
}
int double_linked_list_sort(){
	if(double_linked_list_isEmpty()){
				cout<<"please first add some element\n";
		}else{
			cout<<"In reverse Order [Y/N] :-";
			char a;
			cin>>a;
			for(Node *ref1=DOUBLE_LINKED_LIST;ref1->next!=NULL;ref1=ref1->next){
				Node *temp=ref1;
				for(Node *ref2=ref1->next;ref2!=NULL;ref2=ref2->next){
					// for reverse order
					if(a=='Y'||a=='y'){
						if(temp->data<ref2->data){
							temp=ref2;
						}
					}else{
						if(temp->data>ref2->data){
							temp=ref2;
						}
					}
				}
				ref1->data=(ref1->data+temp->data)-(temp->data=ref1->data);
			}
		}
		cout<<"Double Linked Sorted";
		cout<<"\nPress enter ";
		getchar();getchar();
		return 0;
}
int double_linked_list(char *clear){
	while(1){
				system(clear);
					cout<<"-*--*--*--*-Welcome in Double Linked List-*--*--*--*-\n";
					cout<<"1. Append \n";
					cout<<"2. Add first \n";
					cout<<"3. Add after  \n";
					cout<<"4. Traverse \n";
					cout<<"5. Delete \n";
					cout<<"6. sort \n";
					cout<<"10. stop \n";
					cout<<"Enter your choice \n";
					int choice;
					int stop=0;
					cin>>choice;
					switch(choice){
					case 1 : double_linked_list_insert();
							break;
					case 2 :double_linked_list_add_first();
							break;
					case 3 :double_linked_list_add_after();
							break;
					case 4 :double_linked_list_display();
							break;
					case 5 :double_linked_list_delete();
							break;
					case 6 :double_linked_list_sort();
							break;
					case 10 :stop=1;
							break;
					default : cout<<" Enter valid choice(press Enter)\n";
						getchar();getchar();
							break;
					}
					if(stop){
						cout<<"Bye!!!!!! press enter";
						getchar();getchar();
						break;
					}

				}
	return 0;
}

