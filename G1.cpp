#include <bits/stdc++.h>
using namespace std;

struct Item {
	int weight, value;
	double best;
};

bool compare(Item a, Item b){
	return a.best > b.best;
}

int knapsack(int n, int cap, Item it[]) {
	int total = 0, now = 0;
	
	for(int i=0; i<n; i++){
		if(now + it[i].weight <= cap){
			total += it[i].value;
			now += it[i].weight;
		}
	}
	
	return total;
}

int main(){
	int n, cap;
	cin>>n>>cap;
	
	Item item[n];
	for(int i=0; i<n; i++){
		cin >>item[i].weight>>item[i].value;
		item[i].best = (double)item[i].value/item[i].weight;
	}
	sort(item, item+n, compare);
	cout<<knapsack(n, cap, item);
	
	return 0;
}
