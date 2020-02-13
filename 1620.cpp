#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=2e5+5;
ull  ar[N];
int main(){
   ull n,k,ans,sum;
   scanf("%llu %llu",&n,&k);

   for(int i=1;i<=n;i++){
    scanf("%llu",&ar[i]);
   }
   ull l=1,r=1e18;

   while(l<=r){
    ull mid=(l+r)>>1ll;
    sum=0;
    for(int i=1;i<=n;i++){
        sum+=(mid/ar[i]);
    }
    if(sum<k){
        l=mid+1;
    }
    else{
        ans=mid;
        r=mid-1;
    }
   }
   printf("%llu",ans);
   return 0;
}
