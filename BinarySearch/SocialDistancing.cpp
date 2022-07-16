// US Open 2020 #1 (Social Distancing) 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <list>
#include <map>
#include <functional>
#define pub push_back
#define mkp make_pair
#define rs resize
#define loop(n) for(int ii = 0; ii < n; ++ ii)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef vector <pair<int, int> > vpi;
typedef vector <pair<long long, long long> > vpll;
typedef map<int, int> mi;
typedef map<long long, long long> mll;

bool doesDWork(vpll intervals, ll maxD, int cows) {
	ll ctr = 0, starting = intervals[ctr].first; int totCows = 0;
	for (int i = 1; i < cows; i++) {
		if (starting + maxD > intervals[ctr].second) {
			// go to next disjoint int
			while (ctr < intervals.size() && starting + maxD > intervals[ctr].second) {
				ctr++;
			}
			if (ctr < intervals.size()) {
				// valid, can move on, place at base
				starting = max(intervals[ctr].first, starting + maxD);
			}
			else {
				return false;
			}
		}
		else {
			starting += maxD;
		}
		totCows++;
	}
	if (totCows+1 == cows)
		return true;
	return false;
}

ll last_true(ll lo, ll hi, vpll intervals, int cows) {
	lo--;
	while (lo < hi) {
		ll mid = lo + (hi - lo + 1) / 2;
		if (doesDWork(intervals, mid, cows)) {
			lo = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("socdist.in");
	ofstream cout("socdist.out");
	int n, m; cin >> n >> m;
	vpll intervals;
	while (m--) {
		ll a, b; cin >> a >> b;
		intervals.pub(mkp(a, b));
	}
	sort(intervals.begin(), intervals.end());
	cout << last_true(1, intervals[intervals.size() - 1].second - intervals[0].first, intervals, n) << endl;

	return 0;
}
