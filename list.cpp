#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node *next;
};
//head element
struct node *head=NULL;
//newnode of the linked list
struct node *newnode(int x){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=x;
temp->next=NULL;
return temp;
}
// insert the element in the linked list
void insert(int x){
	struct node *temp;
	if (head==NULL)
	{
		temp=newnode(x);
		head=temp;
	}
	else
	{
		temp=head;
		while(head->next!=NULL){
		head=head->next;
		}
		head->next=newnode(x);
		head=temp;
	}
}
//to insert the element at the first position
void first(int x)
{
	struct node *temp;
	temp=newnode(x);
	temp->next=head;
	head=temp;
}
//to insert the element in the middle of the linked list
void middle(int x, int a){
	if (a==1)
	first(x);
	else
	{
		struct node *temp;
		struct node * temp1;
		temp=head;
		int cnt=0;
		while (head->next!=NULL && cnt!=(a-1)){
		cnt++;
			head=head->next;
		}
		temp1=newnode(x);
		temp1->next=head->next;
		head->next=temp1;
		head=temp;
	}
}
// to print the number
void print(){
struct node * temp;
temp=head;
	while (temp!=NULL){
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
first(7);
cout<<"\n";
print();
cout<<"\n";
middle(9,6);
print();
return 0;
}
