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
void n1(int n){
	struct node * temp,* temp1;
	temp=head;
	temp1=head;
	int cnt=1;
	while(cnt!=n)
	{
		cnt++;
		temp=temp->next;
	}
	while(temp->next!=NULL){
		temp1=temp1->next;
		temp=temp->next;		
	}
	cout<<(temp1->data)<<" "; 
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
int m;
print();
cin>>m;
n1(m);
return 0;
}
