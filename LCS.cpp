#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
const int N = 1e6 + 7;
const int M = 1e9 + 7;

int dp[1000][1000];

int lcs(string a, string b, int n, int m){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][0] = 0;
			dp[0][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n][m];
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int tt;
  	cin >> tt;
  	for(int tc = 1; tc <= tt; tc++){
  		//cout << "Case " << tc << ": ";
  		string a, b;
  		cin >> a >> b;
  		int n = a.size();
  		int m = b.size();
  		cout << lcs(a, b, n, m) << "\n";
  	}
  	return 0;
}
