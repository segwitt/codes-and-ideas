#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 7;
int a[500007];


// http://codeforces.com/contest/1038/problem/D
/*

The idea behind the question is that we need to think in terms of signs which we can assign to various numbers of the array
We can assign any sign to any number but all the numbers shouldn't have same sign
PROOF
-----
We can prove the above observation by building from the ground up when we have only 2 nums , 3 nums etc.

TO DO
-----
Think of a better proof


*/
int main(int argc, char const *argv[])
{
	
	int n;
	cin >> n;

	int c1 = 0, c2 = 0, mn = 1e9, mx = -1e9;
	long long res1 = 0, res2 = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		if(a[i] > 0) {
			res1 += a[i];
			c1++;
		}
		else {
			res2 -= a[i];
			c2++;
		}
	}

	if(n == 1) {
		cout << a[0] << endl;
		return 0;
	}


	if(c1 == n) {
		cout << res1 - 2 * 1ll * mn << endl;
	}
	else if(c2 == n) {
		cout << res2 + 2 * 1ll * mx << endl;
	}
	else cout << res1 + res2 << endl;



	return 0;
}
