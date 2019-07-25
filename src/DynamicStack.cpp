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
Node *dynamic_top=NULL;
Node *dynamic_STACK=NULL;
int dynamicStack_isEmpty(){
	if(dynamic_top==NULL)
		return 1;
	else
		return 0;
}
int dynamicStack_push(){
	Node *temp = new Node;
	temp->next=NULL;
	cout<<"Enter Data :-";
	cin>>temp->data;
	if(dynamic_STACK == NULL){
		dynamic_STACK=temp;
		dynamic_top=dynamic_STACK;
	}
	else{
	Node *ref=dynamic_STACK;
	while(ref->next!=NULL)
		ref=ref->next;
	ref->next=temp;
	dynamic_top=temp;
	}
	cout<<"Data is pushed in Stack\n";
	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int dynamicStack_pop(){
	if(dynamicStack_isEmpty()){
		cout<<"please first push some element\n";
	}else{
		cout<<"Data is pop out from  Stack "<<dynamic_top->data<<"\n";
		Node *ref=dynamic_STACK;
		if(dynamic_top==dynamic_STACK)
		{	free(dynamic_top);
			dynamic_top=NULL;
			dynamic_STACK=NULL;
		}else{
		while(ref->next!=dynamic_top)
			ref=ref->next;
		ref->next=NULL;
		free(dynamic_top);
		dynamic_top=ref;
		}

	}

	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int dynamicStack_peek(){
	if(dynamicStack_isEmpty()){
		cout<<"please first push some element\n";
	}else{
		cout<<"Peek is "<<dynamic_top->data<<"\n";
	}

	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int dynamicStack_traverse(){
	if(dynamicStack_isEmpty()){
		cout<<"please first push some element\n";
	}else{
		cout<<"dynamic_STACK is \n";
		for(Node *i=dynamic_STACK;i!=NULL;i=i->next)
			cout<<i->data<<" ";
	}

	cout<<"\nPress enter ";
	getchar();getchar();
	return 0;
}

int dynamicStack(char * clear){
	while(1){
		system(clear);
			cout<<"-*--*--*--*-Welcome in Stack(Dynamic)-*--*--*--*-\n";
			cout<<"1. push \n";
			cout<<"2. pop \n";
			cout<<"3. traverse \n";
			cout<<"4. peek \n";
			cout<<"10. stop \n";
			int choice;
			int stop=0;
			cin>>choice;
			switch(choice){
			case 1 :dynamicStack_push();

			break;
			case 2 :dynamicStack_pop();
					break;
			case 3 :dynamicStack_traverse();
					break;
			case 4 :dynamicStack_peek();
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




