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
struct node *mnnodes(struct node *head,int m,int n){
struct node *temp=head;
for (int i=1;i<m&&temp!=NULL;i++)
{
	temp=temp->next;
}
	if (temp==NULL)
	return head;
	struct node *pre=temp;
	temp=temp->next;
	for(int i=0;i<n&&temp!=NULL;i++){
		temp=temp->next;
	}
	pre->next=temp;
	return head;
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
cout<<"enter m and n nodes\n";
int a,b;
cin>>a>>b;
head1=mnnodes(head1,a,b);
print(head1);
return 0;
}
