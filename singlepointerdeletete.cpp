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
void del1(struct node * del){//remember only the address of the del has to be deleted okkk

	struct node *temp;
	temp=del->next;
	del->data=temp->data;
	del->next=temp->next;
	free(temp); 
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
del1(head);
print();
return 0;
}
