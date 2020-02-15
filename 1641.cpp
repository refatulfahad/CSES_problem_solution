#include<bits/stdc++.h>
using namespace std;

const int N=5005;
int ar[N];
pair<int,int>a[N];
int n;
int binarysearch(int l,int r,int val,int i,int j) {

    while(l<=r) {
        int mid=(l+r)>>1;
        if(a[mid].first==val) {
            int in1=mid+1,in2=mid-1;
            if(a[mid].second!=i&&a[mid].second!=j) {
                return a[mid].second;
            }
            while(a[in1].first==val&&in1<=n) {
                if(a[in1].second!=i&&a[in1].second!=j)
                    return a[in1].second;
                in1++;
            }
            while(a[in2].first==val&&in2>=1) {
                if(a[in2].second!=i&&a[in2].second!=j)
                    return a[in2].second;
                in2--;
            }
            return 0;

        } else if(a[mid].first>val) {
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    return 0;
}
int main() {

    int x;
    scanf("%d %d",&n,&x);
    a[0]= {-1,-1};
    a[n+1]= {-1,-1};
    for(int i=1; i<=n; i++) {
        scanf("%d",&ar[i]);
        a[i]= {ar[i],i};
    }
    sort(a+1,a+n+1);
    int half=ceil((double)n/(double)2.0);
    int ck=0;
    for(int i=1; i<=half; i++) {
        for(int j=i+1; j<=half; j++) {

            if(x>=ar[i]+ar[j])
                ck=binarysearch(1,n,x-ar[i]-ar[j],i,j);
            if(ck) {
                printf("%d %d %d",i,j,ck);
                return 0;
            }
        }
    }
    for(int i=half+1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {

            if(x>=ar[i]+ar[j])
                ck=binarysearch(1,n,x-ar[i]-ar[j],i,j);
            if(ck) {
                printf("%d %d %d",i,j,ck);
                return 0;
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
