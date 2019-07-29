/*
 * Queue.cpp
 *
 *  Created on: 29-Jul-2019
 *      Author: rahul
 */

#include <iostream>
using namespace std;
#include "headerFile.h"
struct Node{
	int data;
	Node *next=NULL;
};
Node *QUEUE=NULL;

int queue_isEmpty(){
	if(QUEUE==NULL){
		cout<<"Queue is empty.\n";
	}
	else{
		cout<<"Queue is NOT empty.\n";
	}
	cout<<"Press enter.\n";
	getchar();getchar();
	return 0;
}
int queue_insert(){
	Node *ref = new Node();
	ref->next=NULL;
	cout<<"Enter data :- ";
	cin>>ref->data;
	if(QUEUE==NULL)
		QUEUE=ref;
	else{
		Node *temp = QUEUE;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ref;
	}
	cout<<"\nData in inserted in queue\n";
	cout<<"Press enter.\n";
	getchar();getchar();
	return 0;
}
int queue_display(){
	if(QUEUE==NULL){
			cout<<"please first add some element\n";
		}else{
			cout<<"Queue is \n";
			for(Node *i=QUEUE;i!=NULL;i=i->next)
				cout<<i->data<<" -> ";
			cout<<"NULL";
		}
		cout<<"\nPress enter ";
		getchar();getchar();
		return 0;
}
int queue_delete(){
	if(QUEUE==NULL){
				cout<<"please first add some element\n";
		}else{
				Node *ref=QUEUE;
				QUEUE=QUEUE->next;
				free(ref);
				cout<<"\n Data is Deleted";
			}

			cout<<"\nPress enter ";
			getchar();getchar();
			return 0;
	return 0;
}
int queue(char *clear ){
	while(1){
			system(clear);
				cout<<"-*--*--*--*-Welcome in Queue-*--*--*--*-\n";
				cout<<"1. Insert \n";
				cout<<"2. Delete \n";
				cout<<"3. Traverse \n";
				cout<<"4. Empty \n";
				cout<<"10. stop \n";
				cout<<"Enter your choice \n";
				int choice;
				int stop=0;
				cin>>choice;
				switch(choice){
				case 1 : queue_insert();
						break;
				case 2 :queue_delete();
						break;
				case 3 :queue_display();
						break;
				case 4 :queue_isEmpty();
						break;
				case 10 :stop=1;
						break;
				default : cout<<" Enter valid choice\n";
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


