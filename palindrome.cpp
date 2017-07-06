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
struct node *reverse(struct node *head){
struct node * curr,*temp,*pre;
temp=pre=NULL;
curr=head;
while(curr!=NULL)
{
	temp=curr->next;
	curr->next=pre;
	pre=curr;
	curr=temp;
}
head=pre;
return head;
}
bool palindrome(struct node * head){
	struct node  * slow,*fast,*pre;
	slow=head;
	fast=head;
	struct node *mid=NULL;
	while(fast!=NULL&&fast->next!=NULL)
	{
		pre=slow;
		slow=slow->next;
		fast=fast->next->next;
	}
	if (fast!=NULL)
	{
	mid=slow;
	slow=slow->next;		
	}
	struct node *second=slow;
	pre->next=NULL;
	struct node * rev= reverse(second);
	while (head!=NULL && rev!=NULL){
		if(head->data==rev->data)
		{
			head=head->next;
			rev=rev->next;
		}
		else 
		{
		return 0;
		}
	}
	return 1;
	
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
cout<<palindrome(head)<<"\n";
return 0;
}
