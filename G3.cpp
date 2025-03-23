#include <bits/stdc++.h>
using namespace std;

void change(int c[], int want, int n){
	int count = 0;
	vector<int> result;
	
	sort(c, c+n, greater<int>());
	
	for(int i=0; i<n; i++){
		while(want >= c[i]){
			want -= c[i];
			result.push_back(c[i]);
			count++;
		}
	}
	
	cout<<count<<endl;
	for(int i=0; i<result.size(); i++){
		cout<<result[i]<<" ";
	}
}

int main(){
	int n;
	cin >> n;
	
	int coin[n];
	for(int i=0; i<n; i++){
		cin>>coin[i];
	}
	
	int want;
	cin>>want;
	
	change(coin, want, n);
	
	return 0;
}
