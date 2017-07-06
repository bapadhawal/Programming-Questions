#include <bits/stdc++.h>
using namespace std;
int main(){
long long  int a,b,c;
cin>>a>>b>>c;
long long int res=1;
while (b>0){
	if (b%2==1)
	res=(((res%c)*(a%c))%c);
	a=(((a%c)*(a%c))%c);
	b/=2;
}
cout<<(res+c)%c<<"\n";
}
