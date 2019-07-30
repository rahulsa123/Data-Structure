/*
 * DynamicStack.cpp
 *
 *  Created on: 24-Jul-2019
 *      Author: rahul
 */

#include <iostream>
using namespace std;
#include "headerFile.h"
struct Node{
	int data;
	Node *next=NULL;
};
Node *LINKED_LIST=NULL;

int linkedList_isEmpty(){
	if(LINKED_LIST==NULL)
		return 1;
	else
		return 0;
}
int linkedList_Create(){
	Node *ref=LINKED_LIST,*temp;
	while(ref!=NULL){
		temp=ref;
		ref=ref->next;
		free(temp);
	}
	LINKED_LIST=NULL;
	cout<<"New Linked List is created. \n";
	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int linkedList_append(){
	Node *temp = new Node;
	temp->next=NULL;
	cout<<"Enter Data :-";
	cin>>temp->data;
	if(LINKED_LIST == NULL){
		LINKED_LIST=temp;
	}
	else{
	Node *ref=LINKED_LIST;
	while(ref->next!=NULL)
		ref=ref->next;
	ref->next=temp;
	}
	cout<<"Data is added at the end of Linked List\n";
	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int linkedList_length(){
	int count=0;
	Node *ref=LINKED_LIST;
	while(ref!=NULL){
		ref=ref->next;
		count++;
	}
	cout<<"Length of Linked List is "<<count<<" \n";
	//cout<<"Press enter ";
	//getchar();getchar();
	return count;
}
int linkedList_delete(){
	if(linkedList_isEmpty()){
		cout<<"please first add some element\n";
	}else{
		int data;
		cout<<"Enter Data For Deletion :-";
		cin>>data;
		Node *ref=LINKED_LIST;
		while(ref!=NULL && ref->next->data!=data)
			ref=ref->next;
		if(ref==NULL)
			cout<<"Data not Found";
		else{
			Node * temp = ref->next;
			ref->next=temp->next;
			free(temp);
		}
	}
	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int linkedList_add_at_begin(){
	Node *ref=new Node;
	cout<<"Enter Data :-";
	cin>>ref->data;
	ref->next=NULL;
	if(! linkedList_isEmpty())
		ref->next=LINKED_LIST;
	LINKED_LIST=ref;
	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int linkedList_add_after(){
	if(linkedList_isEmpty()){
			cout<<"please first add some element\n";
	}else{
		int data,adata;
		cout<<"Enter data (adding new data after it) :-";
		cin>>data;
		Node *ref=LINKED_LIST;
		cout<<"Enter data (you want to add) :-";
		cin>>adata;
		while(ref!=NULL && ref->data!=data){
			ref=ref->next;
		}
		if(ref==NULL){
			cout<<"Invalid Entry \n";
		}else{
			Node *temp=new Node;
			temp->data=adata;
			temp->next=ref->next;
			ref->next=temp;
			cout<<"Data is added \n";
		}
	}
		cout<<"\nPress enter ";
		getchar();getchar();
		return 0;

}
int linkedList_display(){
	if(linkedList_isEmpty()){
		cout<<"please first add some element\n";
	}else{
		cout<<"LINKED_LIST is \n";
		for(Node *i=LINKED_LIST;i!=NULL;i=i->next)
			cout<<i->data<<" -> ";
		cout<<"NULL";
	}
	cout<<"\nPress enter ";
	getchar();getchar();
	return 0;
}
int linkedList_swap(){
	if(linkedList_isEmpty()){
			cout<<"please first add some element\n";
	}else{
		int first,second;
	cout<<"Enter first location(1 based indexing) \n";
	cin>>first;
	cout<<"Enter second location(1 based indexing) \n";
		cin>>second;
	int length= linkedList_length();
	if(first >length || second > length){
		cout<< "invalid Entry";
	}else{
		Node *fnode=LINKED_LIST,*snode=LINKED_LIST;
		while(--first && fnode!=NULL){
			fnode=fnode->next;
		}
		while(--second && snode!=NULL)
			snode=snode->next;
		cout<<endl<<fnode->data<<" "<<snode->data;
		fnode->data = (fnode->data+snode->data)-(snode->data=fnode->data);
	}
}
	cout<<"\nPress enter ";
	getchar();getchar();
	return 0;
}
int linkedList_reverse(){
	if(linkedList_isEmpty()){
				cout<<"please first add some element\n";
		}else{
			Node *cur,*pre,*nxt;
			cur=LINKED_LIST;
			pre=LINKED_LIST;
			nxt=cur->next;
			cur->next=NULL;
			while(nxt!=NULL){
				cur=nxt;
				nxt=cur->next;
				cur->next=pre;
				pre=cur;
			}
			LINKED_LIST=cur;
	}
	cout<<"Reversed Linked List ";
	linkedList_display();
	return 0;
}
int linkedList_sort(){
	if(linkedList_isEmpty()){
			cout<<"please first add some element\n";
	}else{
		cout<<"In reverse Order [Y/N] :-";
		char a;
		cin>>a;
		for(Node *ref1=LINKED_LIST;ref1->next!=NULL;ref1=ref1->next){
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
	cout<<"Linked Sorted";
	cout<<"\nPress enter ";
	getchar();getchar();
	return 0;
}
int linkedList(char * clear){
	while(1){
		system(clear);
			cout<<"-*--*--*--*-Welcome in Single Linked List-*--*--*--*-\n";
			cout<<"1. Create \n";
			cout<<"2. Append \n";
			cout<<"3. Delete \n";
			cout<<"4. Add after \n";
			cout<<"5. Add at begin \n";
			cout<<"6. Display \n";
			cout<<"7. Swap \n";
			cout<<"8. Reverse \n";
			cout<<"9. Sort \n";
			cout<<"10. stop \n";
			cout<<"Enter your choice \n";
			int choice;
			int stop=0;
			cin>>choice;
			switch(choice){
			case 1 : linkedList_Create();
					break;
			case 2 :linkedList_append();
					break;
			case 3 :linkedList_delete();
					break;
			case 4 :linkedList_add_after();
					break;
			case 5 :linkedList_add_at_begin();
					break;
			case 6 :linkedList_display();
					break;
			case 7 :linkedList_swap();
					break;
			case 8 :linkedList_reverse();
					break;
			case 9 :linkedList_sort();
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
