#include <bits/stdc++.h>
using namespace std;

void shortest(char start, int (*dist)[5], char town[], int n){
	bool visited[n] = {false};
	int total = 0;
	char path[n+1];
	
	int start_i = find(town, town+n, start) - town;
	int current = start_i;
	path[0] = town[start_i];
	visited[start_i] = true;
	
	for(int i=1; i<n; i++){
		int near = -1, min_d = INT_MAX;
		
		for(int j=0; j<n; j++){
			if(!visited[j] && dist[current][j] > 0 && dist[current][j] < min_d) {
				near = j;
				min_d = dist[current][j];
			}
		}
		
		if(near != -1){
			visited[near] = true;
			total += min_d;
			path[i] = town[near];
			current = near;
		}
	}
	
	total += dist[current][start_i];
	path[n] = town[start_i];
	
	cout<<total<<endl;
	for(int i=0; i<n; i++){
		cout<<path[i]<<" ";
	}
	cout<<path[0];
}

int main(){
	int dist[5][5] = { 
        { 0, 20, 42, 35, 40 },
        { 20, 0, 30, 34, 25 },
        { 42, 30, 0, 12, 70 },
        { 35, 34, 12, 0, 21 },
        { 40, 25, 70, 21, 0 }
    };				
	char town[5] = {'A', 'B', 'C', 'D', 'E'};
								
	char start;
	cin>>start;

	shortest(start, dist, town, 5);
			
	return 0;
}
