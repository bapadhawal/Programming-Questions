#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node * next;
};
struct node *newnode(int k){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=k;
temp->next=NULL;
return temp;
}

void print(struct node *head){
struct node * temp;
temp=head;
	while(temp!=NULL){
	cout<<temp->data<<" ";
	temp=temp->next;
	}
}
struct node *insert(struct node *head,int k){
	struct node *temp;
	if (head==NULL)
	{
		temp=newnode(k);
		head=temp;
	}
	else 
	{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode(k);
	}
	return head;
}
struct node *kreverse(struct node *head,int k){
	struct node *curr=head;
	struct node *pre=NULL;
	struct node *temp;
	int count=0;
	while(curr!=NULL && count <k){
	temp=curr->next;
	curr->next=pre;
	pre=curr;
	curr=temp;
	count++;
	}
	if (head!=NULL)//This is the  most important step and you must think about it twice.
	head->next=curr;
	count=0;
	while(count<k-1 && curr!=NULL)
	{
		curr=curr->next;
		count++;
	}
	
	if(curr!=NULL)
	curr->next=kreverse(curr->next,k);
	
	return pre;
}
int main(){
int n;
cin>>n;
int k;
struct node *head=NULL;
for(int i=0;i<n;i++)
{
	cin>>k;
	head=insert(head,k);
}
print(head);
cout<<"\n";
//mergesort(&head);
head=kreverse(head,3);
print(head);
return 0;
}
