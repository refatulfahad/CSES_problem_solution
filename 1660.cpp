#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
long long ar[N],k;
bool binarysearch(int l,int r,int in) {
    while(l<=r) {
        int mid=(l+r)>>1;
        long long sub=ar[in]-ar[mid];
        if(sub>k) {
            l=mid+1;
        } else if(sub<k) {
            r=mid-1;
        } else {
            return true;
        }
    }
    return false;
}
int main() {
    int n,ans=0;
    scanf("%d %lld",&n,&k);
    for(int i=1; i<=n; i++) {
        scanf("%lld",&ar[i]);
        ar[i]=ar[i]+ar[i-1];
        //cout<<ar[i]<<" ";
    }
    for(int i=1; i<=n; i++) {
        bool ck=binarysearch(0,i,i);
        if(ck) {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
