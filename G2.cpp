#include <bits/stdc++.h>
using namespace std;

struct Item {
	double weight, value;
	double best;
};

bool compare(Item a, Item b){
	return a.best > b.best;
}

int knapsack(int n, int cap, Item it[]) {
	double total = 0;
	
	for(int i=0; i<n; i++){
		if(cap >= it[i].weight){
			total += it[i].value;
			cap -= it[i].weight;
		}
		else{
			total += (it[i].value / it[i].weight) * cap;
			break; // full
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
		item[i].best = (double)item[i].value/ item[i].weight;
	}
	sort(item, item+n, compare);
	cout<<knapsack(n, cap, item);
	
	return 0;
}
