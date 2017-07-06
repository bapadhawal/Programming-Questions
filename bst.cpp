#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node *left,*right;
};
struct node *newnode(int k){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=k;
temp->left=temp->right=NULL;
return temp;
}
struct node *search(struct node *head,int k){
	if (head==NULL||head->data==k) //this does not shows the if it is not present in it or not.
	return head;
	if (head->data<k)
	return search(head->right,k);
	else 
	return search(head->left,k);
}
struct node * insert(struct node *head,int k){
	if (head==NULL)
	return newnode(k);
	if (head->data>k) 
	head->left=insert(head->left,k);
	else if  (head->data<k)
	head->right=insert(head->right,k); 
	return head;
}
void inorder(struct node *head){
	if (head==NULL)
	return;
	inorder(head->left);
	printf("%d ",head->data);
	inorder(head->right);
}
int main(){
int n;
cin>>n;
int k;
struct node *head=NULL;
for (int i=0;i<n;i++){
	cin>>k;
	head=insert(head,k);
}
inorder(head);
int m;
cin>>m;
struct node *temp=search(head,m);
cout<<temp->data;
return 0;
}
