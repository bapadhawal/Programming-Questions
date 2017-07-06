#include <bits/stdc++.h>
using namespace std;
struct node {
int data;
struct node * next;
};
struct node * head;
struct node * newnode(int k){
struct node * temp;
temp= (struct node *)malloc(sizeof(struct node));
temp->data=k;
temp->next=NULL;
return temp;
}
void insert(int k){
	struct node * temp;
	if (head==NULL){
		temp=newnode(k);
		head=temp;
	}
	else
	{
		temp=head;
		while (head->next!=NULL)
		{
			head=head->next;
		}
		head->next=newnode(k);
		head=temp;
	}
}
void print(){
struct node * temp;
temp=head;
while(temp!=NULL){
	cout<<(temp->data)<<" ";
	temp=temp->next;
}
}
void middle(){
	struct node *temp,*temp1;
	temp=head;
	temp1=head;
	while((temp1!=NULL) && (temp1->next!=NULL)){//this is the important part most to remember it as the faster pointer needs to grow the faster
		temp=temp->next;
		temp1=temp1->next->next;
	}
	cout<<temp->data<<"\n";
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
middle();
return 0;
}
