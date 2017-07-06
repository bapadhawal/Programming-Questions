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
int arr[100000];
void dup(){
struct node * temp,*pre;
temp=head;
pre=NULL;
while(temp!=NULL){
	if (arr[temp->data]==0){
		arr[temp->data]=1;
		pre=temp;
	}
	else 
	{
		struct node * temp2;
		temp2=temp;
		pre->next=temp->next;
		free(temp);
	}
	temp=	
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
