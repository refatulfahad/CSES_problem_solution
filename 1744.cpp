/**Bismillahir Rahmanir Raheem
    Author:Refatul Fahad**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define grv(v) sort(v.begin(),v.end(),greater<int>())
#define sz(s)  (int)s.size()
#define all(s)  s.begin(),s.end()
#define fill(a,b) memset(a,b,sizeof(a))
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) count(v.begin(),v.end(),a)
#define el "\n"
#define IOS  ios_base::sync_with_stdio(false),cin.tie(NULL)

const int N = 1e5 + 5;
const ll M = (ll)1e9 + 7;
const ll inf = (ll)1e18;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
int Set(int N, int pos) {
	return N = N | (1 << pos);
}
int reset(int N, int pos) {
	return N = N & ~(1 << pos);
}
bool check(int N, int pos) {
	return (bool)(N & (1 << pos));
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dp[505][505];
int fun(int n, int m) {
	if (n == m)return 0;
	int r1 = N, r2 = N;

	if (dp[n][m])return dp[n][m];
	//cutting vertically
	/*you have to multiply by 2,otherwise you will get TLE.Because after half iteration
	it will repeat.if we assume n=3,m=6 then all iterations are without multiplied by 2
	1.{(3,1),(3,5)}
	2.{(3,2),(3,4)}
	3.{(3,3),(3,3)}
	4.{(3,4),(3,2)}
	5.{(3,5),(3,1)}
	in the above you can see that 1==5 and 2==4.So you have to multiply by 2
	for optimizing this  code
	*/
	for (int i = 1; i * 2 <= m; ++i) {
		r1 = min(r1, 1 + fun(n, i) + fun(n, m - i));
	}
	//cutting horizontally
	for (int i = 1; i * 2 <= n; ++i) {
		r2 = min(r2, 1 + fun(i, m) + fun(n - i, m));
	}
	return dp[n][m] = min(r1, r2);
}
int main() {
#ifndef ONLINE_JUDGE
	//read input from input.txt
	freopen("input.txt", "r", stdin);
	//write output from output.txt
	freopen("output.txt", "w", stdout);
#endif
	IOS;
	/// freopen("input.txt","r",stdin);
	/// freopen("output.txt","w",stdout);

	int test = 1;
	//cin >> test;
	for (int cs = 1; cs <= test; ++cs) {
		int n, m, ans = 0;
		cin >> n >> m;

		printf("%d\n", fun(n, m));
	}
	return 0;
}