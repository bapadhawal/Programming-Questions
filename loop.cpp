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
void loop(){
	struct node * temp,*temp1;
	temp=head;
	temp1=head;
	while(temp&&temp1&&temp1->next){
		temp=temp->next;
		temp1=temp1->next->next;
		if (temp==temp1)
		{
		cout<<"loop\n";
		break;
		}
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
head->next->next->next=head;
loop();
return 0;
}
