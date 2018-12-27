#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define pii pair<int,int>

priority_queue<int, vector<int>, greater<int> > pq;


int main() {
	// your code goes here
	int n;
	cin >> n;
	vector<pii> v;
	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	// n is even
	int cost = 0;
	for(int i = 0; i < n - 1 ; i+=2) {
		pii& ass = v[i];
		pii& cap = v[i+1];
		cost += ass.second + cap.first;
		if(!pq.empty()) {
			int delta = (ass.first - ass.second) - pq.top();
			if (delta < 0) {
				cost += delta;
				pq.pop();
				pq.push(ass.first - ass.second);
			}
		}
		// cout << " cost " << cost << endl;
		pq.push(cap.first-cap.second);
	}
	cout << cost << endl;
	
	
	return 0;
}

/*

The question is an awesome question for understanding dp, PQ and balanced parantheses concepts.
out of i considered pilots we have only j captains j <= i / 2
using dp it can be solved as dp[i,j] = min ( dp[i-1,j] + ass[i] , dp[i-1,j-1] + cap[i] )

it can be also solved using PQ(current soln) when we take up two pilots at a time, one is assistant and one is captain, we can swap
the assistant with the priority queue topmost element if swapping leads to a better solution

this is like a balanced parantheses where we know that the no of opening brackets at any point i should be >=(i+1)/2





*/

