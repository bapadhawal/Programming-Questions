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

struct node *reverse1(struct node *head){
	struct node *curr=head;
	struct node *pre=NULL;
	struct node *temp;
	while(curr!=NULL){
	temp=curr->next;
	curr->next=pre;
	pre=curr;
	curr=temp;
	}
	head=pre;
	return head;
}
struct node *greater1(struct node *head){
	struct node * temp=NULL,*temp1=NULL,*temp2=NULL;
	temp=reverse1(head);
	temp1=temp;
	while(temp1->next!=NULL){
		if (temp1->data > temp1->next->data){
			temp2=temp1->next->next;
			free(temp1->next);
			temp1->next=temp2;
		}
		else
		{
			temp1=temp1->next;
		}
	}
	temp=reverse1(temp);
	return temp;
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
head=greater1(head);
print(head);
return 0;
}
