#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int n;

string solve(int k){
    if(k==1) return "1";
    string str=solve(k-1);
    string ret="";

    int i=0;
    while(i<str.length()){
        char lead=str[i];int len=1;
        while(i+1<str.length()&&str[i+1]==str[i]) len++,i++;
        ret+=to_string(len)+lead;
        i++;
    }

    return ret;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    cout<<solve(n);

    return 0;
}