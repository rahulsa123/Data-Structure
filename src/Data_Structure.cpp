//============================================================================
// Name        : Data.cpp
// Author      : rahul
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "headerFile.h"
#include <stdlib.h>
using namespace std;
#define enter cout<<"Press Enter \n";\
getchar();getchar();
int main() {
	char *clear="clear";
	int choice;
	int stop;
	cout<<"Running on windows [y/n]";
	char a;
	cin>>a;
	if(a=='Y' || a=='y')
		clear="cls";
	while(1){
		system(clear);
		cout<<"1. Stack \n";
		cout<<"2. Dynamic Stack \n";
		cout<<"3. Single Linked List \n";
		cout<<"4. Queue \n";

		cout<<"5. Double Linked List \n";
		cout<<"6. Binary Search Tree \n";
		cout<<"10. Stop \n";
		cout<<"Enter your choice \n";
		 stop=0;
		cin>>choice;
		switch(choice){
		case 1 :stack(clear);
			break;
		case 2 : dynamicStack(clear);
				break;
		case 3 : linkedList(clear);
				break;
		case 4: queue(clear);
			break;
		case 5: double_linked_list(clear);
				break;
		case 6: binary_search_tree(clear);
				break;
		case 10 :
			stop=1;
			break;
		default : cout<<" Enter valid choice \n";
		enter;
				break;
		}

		if(stop){
			cout<<"Bye!!!!!!";
			enter;
			break;
		}

	}
}
