
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ar[N];

long long divide(int l,int r) {
    if(l==r) {
        if(ar[l]%n==0)return 1;
        return 0;
    }
    int mid=(l+r)>>1;
    long long sum=0,ans=0,ck;
    vector<long long>vt;
    for(int i=mid+1; i<=r; i++) {
        sum+=ar[i];
        sum%=n;
        if(sum<0)sum+=n;
        vt.push_back(sum);
    }
    sum=0;
    sort(vt.begin(),vt.end());
    for(int i=mid; i>=l; i--) {
        sum+=ar[i];
        sum%=n;
        if(sum<0)sum+=n;
        if(sum==0)ck=0;
        else ck=n-sum;
        ans+=(upper_bound(vt.begin(),vt.end(),ck)-lower_bound(vt.begin(),vt.end(),ck));
        //cout<<ans<<" ";
    }
    return ans+divide(l,mid)+divide(mid+1,r);
}
int main() {
    scanf("%lld",&n);
    for(int i=1; i<=n; i++) {
        scanf("%lld",&ar[i]);
    }
    printf("%lld\n",divide(1,n));
    return 0;
}
