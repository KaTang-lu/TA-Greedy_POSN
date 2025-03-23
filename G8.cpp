#include <bits/stdc++.h>
using namespace std;

struct Task {
	int start;
	int finish;
};

bool compare(Task a, Task b){
	return a.start < b.start;
}

int main(){
	int n;
	cin>>n;
	
	vector<Task> task(n);
	for(int i=0; i<n; i++){
		cin>>task[i].start>>task[i].finish;
	}
	
	sort(task.begin(), task.end(), compare);
	priority_queue<int, vector<int>, greater<int> > minHeap;
    
    int time = 0;
    for (int i = 0; i < n; i++) {
    	time += (task[i].finish - task[i].start);
        if (!minHeap.empty() && minHeap.top() <= task[i].start) {
            minHeap.pop();
        }
        minHeap.push(task[i].finish);
    }
    
    int mincpu = minHeap.size();
    int cost = (time*1) + (mincpu*100);
	
    cout<<mincpu<< "\n";
    cout<<cost;

	return 0;
}
