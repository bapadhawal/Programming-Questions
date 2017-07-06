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
	struct node *even=NULL;
	struct node *odd=NULL;
void segregate(struct node *head){
	struct node *curr=head;
	while(curr!=NULL){
		if (curr->data%2==0)
		{
			even=insert(even,curr->data);
			curr=curr->next;	
		}
		else 
		{
			odd=insert(odd,curr->data);
			curr=curr->next;
		}
	}
	
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
segregate(head);
print(even);
cout<<"\n";
print(odd);
return 0;
}
