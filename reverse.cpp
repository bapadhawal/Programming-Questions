#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node * next;
};
struct node * head;
struct node * newnode(int k){
struct node * temp;
temp= (struct node *)malloc(sizeof(struct node));
temp->data=k;
temp->next=NULL;
return temp;
}
void insert(int k){
	struct node * temp;
	if (head==NULL){
		temp=newnode(k);
		head=temp;
	}
	else
	{
		temp=head;
		while (head->next!=NULL)
		{
			head=head->next;
		}
		head->next=newnode(k);
		head=temp;
	}
}
void print(){
struct node * temp;
temp=head;
while(temp!=NULL){
	cout<<(temp->data)<<" ";
	temp=temp->next;
}
}
void reverse(){
	struct node * temp,*curr,*pre;
	pre=NULL;
	curr=head;
	temp=NULL;
	while(curr!=NULL){//importat to rememberthe second part of it its the most important
	temp=curr->next;
	curr->next=pre;
	pre=curr;
	curr=temp;
	}
	head=pre;
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
int m;
print();
reverse();
print();
return 0;
}
