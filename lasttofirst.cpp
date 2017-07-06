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
void print(struct node * head){
	struct node * temp;
	temp=head;
	while (temp!=NULL)
	{
	cout<<temp->data<<" ";
	temp=temp->next;
	}
}
struct node * lasttofirst(struct node * head){
	struct node * temp;
	temp=head;
	while (temp->next->next!=NULL){
	temp=temp->next;
	}
	struct node * temp2;
	temp2=temp->next;
	temp->next=NULL;
	temp2->next=head;
	return temp2;// this is the step where i had encountered the problem due to the head copy please see to it.
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
print(head);
cout<<"\n";
head=lasttofirst(head);
print(head);
return 0;
}
