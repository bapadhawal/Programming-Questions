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
struct node *add(struct node *a,struct node *b){
	struct node *res=NULL,*pre=NULL;
	int sum=0;
	int carry=0;
	struct node *temp;
	while(a!=NULL || b!=NULL){
	
	sum=(carry + (a?(a->data):0) + (b?(b->data):0));
	carry=sum/10;
	sum%=10;
	
	temp=newnode(sum);
	if (res==NULL)
	{
	res=temp;
	}
	else 
	{
		pre->next=temp; // this is the most important part of it as the new way to recognise it.
	}
	pre=temp;
	if(a) // always try to mention  this part because of this it is caursing the segamantation fault.
	a=a->next;
	if (b)
	b=b->next;
	}
	if (carry==1)
	temp->next=newnode(carry);
	return res;
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
//print(head1);
cout<<"enter the linked list 2:\n";
cin>>n;
struct node *head2=NULL;
for(int i=0;i<n;i++)
{
	cin>>m;
	head2=insert(head2,m);
}
//print(head2);
head1=rev(head1);
head2=rev(head2);
//print(head1);
//print(head2);
struct node *res=add(head1,head2);
res=rev(res);
print(res);
return 0;
}
