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
void dup(){
	struct node *temp=head;
	struct node * temp1=NULL;
	while (temp->next!=NULL){
		if (temp->data==temp->next->data){// this step is most important
			temp1=temp->next->next;
			free(temp->next);
			temp->next=temp1;	
		}
		else 
		{
			temp=temp->next;
		}
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
print(head);
cout<<"\n";
dup();
print(head);
return 0;
}
