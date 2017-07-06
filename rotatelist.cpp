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
struct node * rotate(struct node * head,int B){
struct node *temp,*temp1;
temp=head;
int cnt=1;
int n=1;
while(temp!=NULL){   //this step is to get the number of rotation can be more than the required and and for the first be noticed 
    temp!=NULL;
    temp=temp->next;
    n++;
} 
B=B%n;
if (B==0)
return head;
B=B+1;
temp=head;
while(cnt!=B){
	temp=temp->next;
	cnt++;
}
struct node *pre=NULL;
while (temp->next!=NULL)
{
	temp=temp->next;
	pre=temp1;
	temp1=temp1->next;
}
cout<<temp1->data<<" ";
pre->next=NULL;
temp->next=head;
head=temp1;
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
struct node * temp=rotate(head,n);
print(temp);
return 0;
}
