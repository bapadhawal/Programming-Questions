#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node *next;
};
struct node *newnode(int k){
struct node *temp;
temp=(struct node * )malloc(sizeof(struct node));
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
		while(temp->next!=NULL){
		temp=temp->next;
		}
		temp->next=newnode(k);
	}
	return head;
}
void print(struct node *head){
struct node * temp;
temp=head;
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;
}
}
struct node *intersection(struct node *a,struct node *b){
	if (a==NULL||b==NULL)
	return NULL;
	if (a->data <  b->data)
	return intersection(a->next,b);
	if (a->data>b->data)
	return intersection(a,b->next);
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=a->data;
	temp->next=intersection(a->next,b->next);
	return temp;
}
int main(){
int k;
cin>>k;
int m;
struct node * head=NULL;
//head=(struct node *)malloc(sizeof(struct node));
for (int i=0;i<k;i++)
{
cin>>m;
head=insert(head,m);
}
print(head);
cout<<"\n";
struct node * head1=NULL;
cin>>k;
for (int i=0;i<k;i++)
{
cin>>m;
head1=insert(head1,m);
}
print(head1);
cout<<"\n";
struct node * temp;
temp=intersection(head,head1);
print(temp);
return 0;
}
