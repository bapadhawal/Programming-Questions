#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node *next;
};
struct node *newnode(int k){
struct node * temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=k;
temp->next=NULL;
return temp;
}
struct node *insert(struct node *head,int k){
	struct node * temp;
	if (head==NULL)
	{
	temp=newnode(k);
	head=temp;
	}
	else 
	{
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode(k);
	}
	return head;
}
struct node *rev(struct node *head){
	struct node *temp;
	struct node *curr=head;
	struct node *pre=NULL;
	while (curr!=NULL){
	temp=curr->next;
	curr->next=pre;
	pre=curr;
	curr=temp;
	}
	head=pre;
	return head;
}
void print(struct node *head){
struct node *temp;
temp=head;
	while(temp!=NULL){
	cout<<temp->data<<" ";
	temp=temp->next;
	}
	cout<<"\n";
}
struct node *alternatelist(struct node *a,struct node *b){
struct node *temp=a;
	struct node *temp1=NULL;
	while(temp!=NULL && b!=NULL){
	temp1=b;
	b=b->next;
	temp1->next=temp->next;
	temp->next=temp1;
	temp=temp->next->next;
	}
	return a;
}
int main(){
int n;
cout<<"enter the linked list 1\n";
cin>>n;
int m;
struct node *head1=NULL;
for(int i=0;i<n;i++)
{
	cin>>m;
	head1=insert(head1,m);
}
print(head1);
cout<<"enter the linked list 2:\n";
cin>>n;
struct node *head2=NULL;
for(int i=0;i<n;i++)
{
	cin>>m;
	head2=insert(head2,m);
}
print(head2);
struct node *head3;
head3=alternatelist(head1,head2);
print(head3);
return 0;
}
