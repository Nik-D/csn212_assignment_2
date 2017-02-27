#include<bits/stdc++.h>
using namespace std;

int index(int t[],int r,int key) {
    int m;
    int l=-1;
    while(r-l>1) {
        m=l+(r-l)/2;
        (t[m]>=key?r:l)=m;
    }
    return r;
}
int eligible_per(int person[],int n) {
    int temp[n];
    int max_len=1;
    for(int j=0;j<n;j++) {
        for(int i=0;i<n;i++) {
            temp[i]=0;
        }
        temp[0]=person[j];
        int len=1;
        for(int i=(j+1);i<(j+n);i++) {
            if(person[i]<temp[0]) {
                temp[0]=person[i];
            }
            else if(person[i]>temp[len-1]) {
                temp[len++]=person[i];
            }
            else {
                temp[index(temp,len-1,person[i])]=person[i];
            }
        }
        if(len>max_len) {
            max_len=len;
        }
    }
    return max_len;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int person[2*n];
        for(int i=0;i<n;i++) {
            cin>>person[i];
            person[i+n]=person[i];
        }
        cout<<"\n"<<eligible_per(person,n);
    }
    return 0;
}

