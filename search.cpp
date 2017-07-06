#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node * next;
};
struct node * head;
struct node *newnode(int x){
struct node * temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=x;
temp->next=NULL;
return temp;
}
void insert(int x){
	struct node * temp;
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
int len(int x){// ierative method for the search of the linked list
struct node * temp;
temp=head;
int cnt=0;
while(temp!=NULL){
	if (temp->data==x)
	return 1;
temp=temp->next;
}
return 0;
}
int len1(struct node * temp,int x){// recursive method for the search of the linked list 
	static int cnt=0;
	if (temp==NULL)
	return 0;
	if (temp->data==x)
	return 1;
	else 
	return len1(temp->next,x);
		
}
void print(){
struct node * temp;
temp=head;
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}
int main(){
int n;
cin>>n;
int k;
for(int i=0;i<n;i++)
{
	cin>>k;
	insert(k);
}
print();
int m;
cin>>m;
cout<<len(m)<<"\n";
cout<<len1(head,m)<<"\n";
return 0;
}
