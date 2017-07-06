#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node *next;
};
struct node *head=NULL;
struct node *newnode(int k ){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=k;
temp->next=NULL;
return temp;
}
void insert(int k){
	struct node *temp;
	if (head==NULL)
	{
		temp=newnode(k);
		head=temp;
	}
	else 
	{
		temp=head;
		while(head->next!=NULL)
		{
			head=head->next;
		}
		head->next=newnode(k);
		head=temp;		
	}
}
void del(int k){
	struct node *temp;
	temp=head;
	struct node * pre=NULL;
	while((temp->data)!=k){
		pre=temp;
		temp=temp->next;
	}
	struct node *temp2;
	if (pre==NULL)
	head=head->next;
	else
	{
		temp2=pre->next;
		pre->next=temp->next;
		free(temp2);
	}
}
void del1(int k){
	struct node *temp;
	temp=head;
	struct node * pre=NULL;
	int cnt=1;
	while(cnt!=(k)){
		cnt++;
		pre=temp;
		temp=temp->next;
	}
	struct node *temp2;
	if (k==1)
	head=head->next;
	else
	{
		temp2=pre->next;
		pre->next=temp->next;
		free(temp2);
	}
}
void swap1(int a,int b){
	struct node *temp,*temp1,*pre,*pre1;
	pre=NULL;
	pre1=NULL;
	temp=head;
	temp1=head;
	 while((temp->data)!=a){
	 	pre=temp;
	 	temp=temp->next;		
	 }
	 while((temp1->data)!=b){
	 	pre1=temp1;
	 	temp1=temp1->next;		
	 }
	 	if(pre!=NULL)
	 	pre->next=temp1;
	 	else 
	 	head=temp1;
	 	if (pre1!=NULL)
	 	pre1->next=temp;
	 	else 
	 	head=temp;
	 	
	 	struct node * temp2;
	 	temp2=temp1->next;
	 	temp1->next=temp->next;
	 	temp->next=temp2;
}
void print(){
struct node *temp;
temp=head;
while(temp!=NULL)
{
	cout<<(temp->data)<<" ";
	temp=temp->next;
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
print();
int a,b;
cin>>a>>b;
swap1(a,b);
print();
return 0;
}
