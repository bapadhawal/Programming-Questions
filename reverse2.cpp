#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node *next;
};
struct node *newnode(int k){
struct node * temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=k;
temp->next=NULL;
return temp;
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
struct node *reverse(struct node *head,int n){
	struct node *temp,*pre,*curr;
	curr=head;
	pre=NULL;
	int index=1;
	while(index<n){
	temp=curr->next;
	curr->next=pre;
	pre=curr;
	curr=temp;
	index++;
	}
	struct node * temp2=curr;
	head=curr;
	temp=head;
	while(temp->next!=NULL){
	temp=temp->next;
	}
	temp->next=temp2;
	return head;
	
}
void print(struct node *head){
	struct node *temp;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main(){
int k;
cin>>k;
int m;
struct node *head=NULL;
for(int i=0;i<k;i++){
	cin>>m;
	head=insert(head,m);
}
print(head);
int n;
cin>>n;
//struct node *temp=NULL;
struct node * temp=reverse(head,n);
print(temp);
return 0;
}
