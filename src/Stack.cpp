/*
 * Stack.cpp
 *
 *  Created on: 24-Jul-2019
 *      Author: rahul
 */
#include <iostream>

#include "headerFile.h"
using namespace std;
int STACK[10000],top=-1;
int isFull(){
	if(top==9999)
		return 1;
	else
		return 0;

}
int isEmpty(){
	if(top==-1)
		return 1;
	else
		return 0;
}
int push(){
	if(isFull()){
		cout<<"please first pop some element\n";
	}else{
		cout<<"Enter Data :-";
		cin>>STACK[++top];
		cout<<"Data is pushed in Stack\n";
	}

	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int pop(){
	if(isEmpty()){
		cout<<"please first push some element\n";
	}else{
		cout<<"Data is pop out from  Stack "<<STACK[top]<<"\n";
		top--;

	}

	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int peek(){
	if(isEmpty()){
		cout<<"please first push some element\n";
	}else{
		cout<<"Peek is "<<STACK[top]<<"\n";
	}

	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}
int traverse(){
	if(isEmpty()){
		cout<<"please first push some element\n";
	}else{
		cout<<"STACK is \n";
		for(int i=top;i>=0;i--)
			cout<<STACK[i]<<"\n";
	}

	cout<<"Press enter ";
	getchar();getchar();
	return 0;
}

int stack(char * clear){
	while(1){
		system(clear);
			cout<<"-*--*--*--*-Welcome in Stack(fixed size of 10000)-*--*--*--*-\n";
			cout<<"1. push \n";
			cout<<"2. pop \n";
			cout<<"3. traverse \n";
			cout<<"4. peek \n";
			cout<<"10. stop \n";
			cout<<"Enter your choice \n";
			int choice;
			int stop=0;
			cin>>choice;
			switch(choice){
			case 1 :push();
				cout<<"\n push";
			break;
			case 2 :pop();
					break;
			case 3 :traverse();
					break;
			case 4 :peek();
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

