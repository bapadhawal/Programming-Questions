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
void split(struct node *a,struct node **b,struct node **c){
	struct node *slow=NULL;
	struct node *fast=NULL;	
	struct node *temp=NULL,*pre=NULL;
	if (a==NULL||a->next==NULL){
		*b=a;
		*c=NULL;
	}
	else
	{
	slow=a;
	fast=a;
	while (fast!=NULL&& fast->next!=NULL){// try to always make the case before doing it ok.
		pre=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	if (fast!=NULL){
	temp=slow->next;
	slow->next=NULL;
 	*b=a;
	*c=temp;
	}
	else 
	{
	pre->next=NULL;
	*b=a;
	*c=slow;
	}
	}
}
struct node *sortedmerge(struct node *a,struct node *b){
	struct node *result=NULL;
	if (a==NULL)
	return b;
	if (b==NULL)
	return a;
	if (a->data<= b->data){
	result=a;
	result->next=sortedmerge(a->next,b);
	}
	else 
	{
	result=b;
	result->next=sortedmerge(a,b->next);
	}
	return (result);
}
void mergesort(struct node **headref){
	struct node *head= *headref;
	struct node *a;
	struct node *b;
	
	if (head==NULL||head->next==NULL)
	{
		return;
	}
	//cout<<"jfnhweofh";
	split(head,&a,&b);
	//cout<<"wwf";
	mergesort(&a);
	mergesort(&b);
	
	*headref=sortedmerge(a,b);
	//print(*headref);
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
mergesort(&head);
print(head);
return 0;
}
