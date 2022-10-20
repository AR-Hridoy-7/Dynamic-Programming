#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
const int N = 1e6 + 7;
const int M = 1e9 + 7;

bool subSetSum(int set[], int n, int sum){
	bool subset[n + 1][sum + 1];
	for(int i = 0; i <= n; i++){
		subset[i][0] = 1;
	}
	for(int i = 1; i <= sum; i++){
		subset[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= sum; j++){
			if(j < set[i - 1]){
				subset[i][j] = subset[i - 1][j];
			}
			if(j >= set[i - 1]){
				subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
			}
		}
	}
	return subset[n][sum];
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	int tt;
  	cin >> tt;
  	for(int tc = 1; tc <= tt; tc++){
  		//cout << "Case " << tc << ": ";
  		int n, sum;
  		cin >> n >> sum;
  		int set[n];
  		for(int i = 0; i < n; i++){
  			cin >> set[i]; 
  		}
  		cout << subSetSum(set, n, sum);
  	}
  	return 0;
}
