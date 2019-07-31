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
		cout<<"first enter some element\n";
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
			// here we replace node with it in order successor
			Node *r1= curr->right;
			// first it's right node having no children
			if(r1->left==NULL && r1->right==NULL){
				curr->data=r1->data;
				curr->right=NULL;
				free(r1);
			}
			// right node having no left child
			else if(r1->left==NULL && r1->right!=NULL){
				curr->data=r1->data;
				curr->right=r1->right;
				r1->right=NULL;
				free(r1);
			}
			//right node having left child
			else{
				Node *r2=r1->left;
				while(r2->left!=NULL){
					r2=r2->left;
					r1=r1->left;
				}
				curr->data=r2->data;
				r1->left=r2->right;
				r2->right=NULL;
				free(r2);
			}
		}
		cout<<"Data is Deleted\n";
		}
	}
	enter;
	return 1;
}
int bst_in_traversal(Node *root){
	if(root==NULL)
		return 0;
	bst_in_traversal(root->left);
	cout<<root->data<<" ";
	bst_in_traversal(root->right);
	return 0;
}
int bst_pre_traversal(Node *root){
	if(root==NULL)
		return 0;
	cout<<root->data<<" ";
	bst_pre_traversal(root->left);
	bst_pre_traversal(root->right);
	return 0;
}
int bst_post_traversal(Node *root){
	if(root==NULL)
		return 0;

	bst_post_traversal(root->left);
	bst_post_traversal(root->right);
	cout<<root->data<<" ";
	return 0;
}
int binary_search_tree(char * clear){
	while(1){
			system(clear);
				cout<<"-*--*--*--*-Welcome in Binary Search Tree-*--*--*--*-\n";
				cout<<"1. Insert \n";
				cout<<"2. Delete \n";
				cout<<"3. In order Traversal \n";
				cout<<"4. Pre order Traversal \n";
				cout<<"5. Post order Traversal \n";
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
				case 3 : cout<<"Data in in order traversal \n";
						bst_in_traversal(BST_ROOT);
						cout<<endl;
						enter;
						break;
				case 4 :cout<<"Data in pre order traversal \n";
					bst_pre_traversal(BST_ROOT);
					cout<<endl;
					enter;
						break;
				case 5 :cout<<"Data in in order traversal \n";
					bst_post_traversal(BST_ROOT);
					cout<<endl;
					enter;
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

