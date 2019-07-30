/*
 * Binary_Search_Tree.cpp
 *
 *  Created on: 31-Jul-2019
 *      Author: rahul
 */
#include <iostream>
using namespace std;
#include "headerFile.h"

#define enter cout<<"Press Enter \n";\
getchar();getchar();

struct Node {
	int data;
	Node *left,*right;
};
Node *BST_ROOT=NULL;
int bst_isEmpty(){
	if(BST_ROOT==NULL)
		return 1;
	else
		return 0;
}
int bst_insert(){
	Node *ref= new Node;
	ref->left=NULL;
	ref->right=NULL;
	cout<<"Enter data :- ";
	cin>>ref->data;
	if(bst_isEmpty())
		BST_ROOT=ref;
	else{
		Node *parent,*curr;
		curr=BST_ROOT;
		while(curr!=NULL){
			parent=curr;
			if(ref->data>curr->data)
				curr=curr->right;
			else
				curr=curr->left;
		}
		if(ref->data<parent->data)
			parent->left=ref;
		else
			parent->right=ref;
	}
	cout<<"Data is inserted in BST \n";
	enter;
	return 1;
}
int bst_delete(){
	if(bst_isEmpty())
		cout<<"first enter some element";
	else{
		int data;
		cout<<"Enter Data you want to delete ";
		cin>>data;
		Node *parent,*curr;
		int found=0;
		curr=BST_ROOT;
		parent=curr;
		while(curr!=NULL){
			if(curr->data==data){
				found=1;
				break;
			}else{
				parent=curr;
				if(curr->data > data)
					curr=curr->left;
				else
					curr=curr->right;
			}
		}
		if(!found){ // data in not in tree
			cout<<"Data in not present in BS Tree\n";
		}else{
		// here we have Some cases
		// case 1 not child
		if(curr->right==NULL && curr->left==NULL){
				// checking if curr is root or not
				if(curr==BST_ROOT){
					BST_ROOT=NULL;
					free(curr);
				}else{
					if(curr==parent->left)
						parent->left=NULL;
					else
						parent->right=NULL;
					free(curr);
					}
		}
		// case 2 having only one child
		else if((curr->left!=NULL && curr->right==NULL) || (curr->left==NULL && curr->right!=NULL)){
			// checking if curr is root or not
			if(curr==BST_ROOT){
				if(curr->left!=NULL)
					BST_ROOT=curr->left;
				else
					BST_ROOT=curr->right;
				free(curr);
			}else{
				// first checking curr is in right node or in left node
				if(curr==parent->left){
					parent->left= curr->left!=NULL ? curr->left:curr->right;
				}else{
					parent->right= curr->left!=NULL ? curr->left:curr->right;
				}
				free(curr);
				}
		}
	// case 3 having 2 children
		else if(curr->left!=NULL && curr->right!=NULL){





		}
	}
	enter;
	return 1;
	}
}
int binary_search_tree(char * clear){
	while(1){
			system(clear);
				cout<<"-*--*--*--*-Welcome in Binary Search Tree-*--*--*--*-\n";
				cout<<"1. Insert \n";
				cout<<"2. Delete \n";
				cout<<"3. Traverse \n";
//				cout<<"4. Add after \n";
//				cout<<"5. Add at begin \n";
//				cout<<"6. Display \n";
//				cout<<"7. Swap \n";
//				cout<<"8. Reverse \n";
//				cout<<"9. Sort \n";
				cout<<"10. stop \n";
				cout<<"Enter your choice \n";
				int choice;
				int stop=0;
				cin>>choice;
				switch(choice){
				case 1 : bst_insert();
						break;
				case 2 :bst_delete();
						break;
//				case 3 :bst_traverse();
//						break;
//				case 4 :linkedList_add_after();
//						break;
//				case 5 :linkedList_add_at_begin();
//						break;
//				case 6 :linkedList_display();
//						break;
//				case 7 :linkedList_swap();
//						break;
//				case 8 :linkedList_reverse();
//						break;
//				case 9 :linkedList_sort();
//						break;
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

