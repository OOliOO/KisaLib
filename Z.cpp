#include <iostream>
#include <set>

using namespace std;

int Z[1000000];

void z(string s){
    int n=s.size();
    Z[0]=n;
    int l=0,r=0;
    for(int i=1; i<n; i++){
        if(r<i){
            l=i;r=i-1;
            while(r+1<n&&s[r+1]==s[r+1-l])
                r++;
            Z[i]=r+1-i;
            continue;
        }
        if(Z[i-l]>=r-i){
            l=i;r=i-1;
            while(r+1<n&&s[r+1]==s[r+1-l])
                r++;
            Z[i]=r+1-i;
            continue;
        }
        Z[i]=min(Z[i-l],r+1-i);
    }
}

int main(){
    string s;
    cin>>s;
    z(s);
    return 0;
}
