#include <bits/stdc++.h>
using namespace std;

struct Sprinkler {
    double left, right;
};

bool compare(Sprinkler a, Sprinkler b) {
    if (a.left == b.left){
    	return a.right > b.right;
	}
    return a.left < b.left;
}

int minSprinklers(int n, int L, int W, vector<pair<int, int> > &sprinkler) {
    vector<Sprinkler> range;

    for (int i = 0; i < n; i++) {
        int p = sprinkler[i].first;
        int r = sprinkler[i].second;
		//if r small => skip
        if (r * 2 <= W) continue;

		//x axis
        double reach = sqrt(r * r - (W * W) / 4.0);
        double left = p - reach;
        double right = p + reach;
        range.push_back({left, right});
    }
    sort(range.begin(), range.end(), compare);

    double covered = 0;
    int count = 0;
    int i = 0;
    int size = range.size();

    //select sprinklers
    while (covered < L) {
        double maxReach = covered;
        
        //find the farthest sprinkler 
        while (i < size && range[i].left <= covered) {
            if (range[i].right > maxReach) {
                maxReach = range[i].right;
            }
            i++;
        }

        //if not have sprinklers
        if (maxReach == covered) return -1;

        covered = maxReach;
        count++;
    }

    return count;
}

int main() {
    int n, L, W;
    cin>>n>>L>>W;
    vector<pair<int, int> > sprink(n);

    for (int i = 0; i < n; i++) {
        int p, r;
        cin>>p>>r;
        sprink[i] = make_pair(p, r);
    }

    cout<<minSprinklers(n, L, W, sprink);
    return 0;
}

