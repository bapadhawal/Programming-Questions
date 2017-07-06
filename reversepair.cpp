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
struct node *reverse(struct node * a,int m,int n){
	struct node *temp,*temp1,*temp2,*pre=NULL,*pre1=NULL,*pre2=NULL;
	temp=a;
	int cnt=1;
	
	while (temp!=NULL){
			
		if (cnt==m)
		{
			pre1=pre;
			temp1=temp;
		}
		if (cnt==n)
		{
			pre2=pre;
			temp2=temp;
		}
		cnt++;
		pre=temp;
		temp=temp->next;
	}
	struct node * curr;
	curr=temp1;
	struct node * temp;
	while (curr!=temp2->next){
	
	}
	
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
struct node * temp;
temp=alternatenodes(head);
print(temp); 
return 0;
}
