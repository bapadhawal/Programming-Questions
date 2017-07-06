#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node * next;
};
struct node * head;
struct node *newnode(int k){
struct node * temp;
temp= (struct node *)malloc(sizeof(struct node));
temp->data=k;
temp->next=NULL;
return temp;
}
void insert(int k){
	struct node * temp;
	if (head==NULL)
	{
	temp=newnode(k);
	head=temp;
	}
	else 
	{
	temp=head;
	while(head->next!=NULL){
	head=head->next;
	}
	head->next=newnode(k);
	head=temp;
	}
}
void sortedinsert(int k){
	struct node * temp,* temp1,*pre;
	temp=head;
	pre=NULL;
	if (temp->data>k){
		temp1=newnode(k);
		temp1->next=head;
		head=temp1;
	}
	else 
	{
		while(temp->data<k){
			pre=temp;
			temp=temp->next;
		}
		temp1=newnode(k);
		pre->next=temp1;
		temp1->next=temp;
	}
}
void print(){
	struct node * temp;
	temp=head;
	while (temp!=NULL)
	{
	cout<<temp->data<<" ";
	temp=temp->next;
	}
}
int main(){
int n;
cin>>n;
int k;
for (int i=0;i<n;i++)
{
	cin>>k;
	insert(k);
}
print();
int m;
cin>>m;
sortedinsert(m);
print();
return 0;
}
