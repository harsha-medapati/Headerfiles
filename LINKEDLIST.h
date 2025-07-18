#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
struct LINKEDLIST
{
	Node* head = NULL;
	
	void insert(int val)
	{
		Node* newNode = new Node{val,NULL};
		if(!head)
		{
			head = newNode;
			return;
		}
		Node* temp = head;
		while(temp!=NULL)
		{
			temp = temp->next;
			temp->next = newNode;
		}
	}
	void insertAtbegin(int val)
	{
		Node* newNode = new Node{val,head};
		head = newNode;
	}
	void remove(int val)
	{
		if(!head)
		{
			cout<<"List is empty\n";
			return;
		}
		if(head->data == val)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node* cur = head;
		while(cur->next && cur->next->data!=val)
		{
			cur=cur->next;
		}
		if(cur->next)
		{
			Node* temp=cur->next;
			cur->next=temp->next;
			delete temp;
		} 
		else
		{
			cout<<"Value not found\n";
		}
	}
	void display()
	{
		if (!head)
		{
			cout<<"List is empty\n";
			return;
		}
		Node* temp=head;
		while (temp)
		{
			cout<<temp->data <<" ";
			temp=temp->next;
		}
		cout<<"\n";
	}
};
#endif
