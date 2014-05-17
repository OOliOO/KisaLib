#include <iostream>

#define N 131072

using namespace std;

int spuu[2*N];

void update(int i, int v){
    i+=N;
    v-=spuu[i];
    while(i>0){
        spuu[i]+=v;
        i/=2;
    }
}

void build(){
    for(int i=N-1; i>0; i--)
        spuu[i]=spuu[2*i]+spuu[2*i+1];
}

int get(int l, int r){
    l+=N;
    r+=N;
    int s=0;
    while(l<r){
        if(l%2==1){
            s+=spuu[l];
            l++;
        }
        if(r%2==0){
            s+=spuu[r];
            r--;
        }
        l/=2;r/=2;
    }
    if(l==r)
        s+=spuu[l];
    return s;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>spuu[i+N];
    build();
    cout<<get(0,100000)<<endl;
    return 0;
}
