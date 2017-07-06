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
struct node * b=NULL,*a1=NULL;
struct node *alternatesplit(struct node * a,struct node **temp2,struct node ** temp3){
	struct node * temp;
	temp=a;
	struct node * temp1;
	while(temp!=NULL){
	temp1=temp;
	temp=temp->next;
	temp1->next=NULL;
	temp2->next=temp1;
	temp2=temp2->next;
	temp1=temp;
	temp=temp->next;
	temp1->next=NULL;
	temp3->next=temp1;
	temp3=temp3->next;
	}
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
struct node * temp;
struct node *a,*b;
temp=alternatesplit(head);
print(temp);
cout<<"\n";
print(b); 
return 0;
}
