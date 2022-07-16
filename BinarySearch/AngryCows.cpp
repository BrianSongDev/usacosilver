// Jan 2016 #1 (Angry Cows) 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <list>
#include <map>
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
typedef map<int, int> mi;
typedef map<long long, long long> mll;

bool canShootEveryone(vi bales, int birds, int radius) {
	int loc1 = bales[0] + radius, xtr = 0, counted = 0;
	while (xtr < bales.size()) {
		// check if covered. if not, add 1
		if (!(abs(loc1 - bales[xtr]) <= radius)) {
			loc1 = bales[xtr] + radius;
			birds--;
		}
		xtr++;
	}
	if (birds > 0) return true;
	return false;
}


int first_true(int lo, int hi, vi bales, int birds) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (canShootEveryone(bales, birds, mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("angry.in");
	ofstream cout("angry.out");
	int n, k; cin >> n >> k;
	vi locs;
	while (n--) {
		int a; cin >> a;
		locs.pub(a);
	}
	sort(locs.begin(), locs.end());
	cout << first_true(1, (locs[locs.size() - 1] - locs[0])/2, locs, k) << endl;

	return 0;
}
