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
struct node *remove(struct node *head,int n){
struct node * temp;
temp=head;
int cnt=1;
int n1=1;
while(temp->next!=NULL){
	temp=temp->next;
	n1++;
}
if (n1==n)
return head->next;
temp=head;
while(cnt!=n){
	temp=temp->next;
	cnt++;
}
struct node *temp1=head,*pre=NULL;
while(temp->next!=NULL){
	temp=temp->next;
	pre=temp1;
	temp1=temp1->next;	
}
pre->next=temp1->next;
free(temp1);
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
struct node * temp=remove(head,n);
print(temp);
return 0;
}
