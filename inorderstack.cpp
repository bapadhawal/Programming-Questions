#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node *left;
struct node *right;
};
struct node * newnode (int k){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=k;
temp->left=NULL;
temp->right=NULL;
return temp;
}
struct node *minvalue(struct node *head){
	struct node *curr;
	curr=head;
	while(curr->left!=NULL)
	{
	curr=curr->left;
	}
	return curr;
}
struct node *del(struct node *head,int k){
	
	if(head==NULL)
	return head;
	
	if (head->data > k )
	head->left=del(head->left,k);
	else if (head->data <k)
	head->right = del(head->right,k);
	else {
	if (head->left==NULL && head->right==NULL)
	free(head);
	else if (head->left==NULL)
	{
		struct node *temp=head->right;
		free(head);
		return temp;
	}
	else if (head->right==NULL)
	{
	struct node *temp=head->left;
		free(head);
		return temp;
	}
	struct node * temp=minvalue(head); // this is the most important portion to remember the process ok.
	head->data=temp->data;
	head->right=del(head->right,temp->data);
	}
	return head;
}
struct node*  insert(struct node *head,int k){
	if (head==NULL)
	return newnode(k);
	
	if (head->data>k)
	head->left=insert(head->left,k);
	else if (head->data<k)
	head->right=insert(head->right,k);
	
	return head;
}
void inorder(struct node *head)
{
	struct node *temp=head;
	stack <struct node > s;
	s.push(head);
	s.push(head->left);
	temp=s.top();
	s.pop();
	
}
int main(){
int n;
cin>>n;
int m;
struct node *head=NULL;
for(int i=0;i<n;i++)
{
	cin>>m;
	head=insert(head,m);
}
inorder(head);
head=del(head,2);
inorder(head);
return 0;
}
