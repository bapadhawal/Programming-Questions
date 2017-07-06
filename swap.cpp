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
void swap(int x,int y){
	struct node *temp,*temp1,*pre,*pre1;
	temp=head;
	pre=NULL;
	while (temp!=NULL&& temp->data!=x){
		pre=temp;
		temp=temp->next;
	}
	temp1=head;
	pre1=NULL;
	while (temp1!=NULL&& temp1->data!=y){
		pre1=temp1;
		temp1=temp1->next;
	}
	if (pre!=NULL)
	pre->next=temp1;
	else
	head=temp1;
	if (pre1!=NULL)
	pre1->next=temp;
	else
	head->next=temp;
	
	struct node *temp2;
	temp2=temp->next;
	temp->next=temp1->next;
	temp1->next=temp2;
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
int a,b;
cin>>a>>b;
swap(a,b);
print();
return 0;
}
