#include <iostream>
using namespace std;
void permute (string s,int low,int high){
    if(low==high)
    cout<<s<<" ";
    else {
        for (int i=low;i<=high;i++){
            swap(s[low],s[i]);
            permute(s,low+1,high);
            swap(s[low],s[i]);
        }
    }
}
int main() {
	int t;
	cin>>t;
	string s;
	while(t--){
	    cin>>s;
	    int k=s.size()-1;
        permute(s,0,k);
        cout<<"\n";
	}
	return 0;
}
