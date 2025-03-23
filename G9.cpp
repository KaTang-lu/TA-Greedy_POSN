#include <bits/stdc++.h>
using namespace std;

struct Task {
	int start;
	int finish;
	int index;
};

bool compare(Task a, Task b){
	int A = a.finish - a.start;
	int B = b.finish - b.start;
	if(A == B){
		return a.start < b.start; 
	}
	return A > B;
}

int main(){
	int n;
	cin>>n;
	
	vector<Task> task(n);
	for(int i=0; i<n; i++){
		cin>> task[i].start >> task[i].finish;
		task[i].index = i + 1;
	}
	sort(task.begin(), task.end(), compare);
//	cout<<"---"<<endl;
//	for(int i=0; i<n; i++){
//		cout<< task[i].start << " " << task[i].finish <<endl;
//	}
	
	
	
	return 0;
}
