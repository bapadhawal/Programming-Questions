#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node *next;
};
struct node *newnode(int k){
struct node *temp;
temp=(struct node * )malloc(sizeof(struct node));
temp->data=k;
temp->next=NULL;
return temp;
}
struct node *insert(struct node *head,int k){
	struct node * temp;
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
void print(struct node *head){
struct node * temp;
temp=head;
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;
}
}
struct node *remove(struct node *head){
	struct node * temp;
	temp=head;
	struct node *pre=NULL,*temp1;
	while(head!=NULL && head->next!=NULL){
		if (head->data==head->next->data)
		{
			temp1=head;
			head=head->next->next;
			pre=temp1;
			free(temp1->next);
			free(temp1);
		}
		else if (pre->data==head->data)
		{
			temp1=head;
			head=head->next;
			free(temp);
		}
		else 
		break;
	}
	return head;
}
int main(){
int k;
cin>>k;
int m;
struct node * head=NULL;
//head=(struct node *)malloc(sizeof(struct node));
for (int i=0;i<k;i++)
{
cin>>m;
head=insert(head,m);
}
print(head);
cout<<"\n"; 
head=remove(head);
print(head);
return 0;
}
