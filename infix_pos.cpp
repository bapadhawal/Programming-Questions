#include <bits/stdc++.h>
using namespace std;
int priority(char ch){
switch(ch){
case '+':
case '-':
return 1;
case '*':
case '/':
return 2;
case '^':
return 3;
}
return -1;
}
int main(){
string str;
cin>>str;
int n=str.size();
char pos[10000];
int k=0;
stack <char> v;
v.push('@');
for (int i=0;i<n;i++){
	if (isalpha(str[i]))
	{
	pos[k++]=str[i];
	}
	else if (str[i]=='(')
	{
	v.push(str[i]);
	}
	else if (str[i]==')')
	{
		while (v.top()!='(')
		{
		pos[k++]=v.top();
		v.pop();
		}
		v.pop();
	}
	else
	{
		while ( (priority(str[i])<=priority(v.top())))
		{
		pos[k++]=v.top();
		v.pop();
		}
		v.push(str[i]);
	}
	//cout<<pos[k]<<" ";
}
while (v.top()!='@')
{
pos[k++]=v.top();
v.pop();
}
pos[k]='\0';
cout<<pos<<"\n";
return 0;
}
