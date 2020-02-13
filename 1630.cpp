#include<bits/stdc++.h>
using namespace std;

vector<pair<long long,long long> > vt;
int main() {
    long long n,x,y,sum=0,ans=0;
    scanf("%lld",&n);
    for(int i=1; i<=n; i++) {
        scanf("%lld %lld",&x,&y);
        vt.push_back({x,y});
    }
    sort(vt.begin(),vt.end());
    for(int i=0; i<vt.size(); i++) {
        sum+=vt[i].first;
        ans+=(vt[i].second-sum);
    }
    printf("%lld\n",ans);
    return 0;
}
