// Jan 2019 #3 (Mountain View) 
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

vpi visibleMtns;

void checkHeight(pi cdn) {
	// x is cdn.first, y is cdn.second
	int ctr = 0;
	for (pi i : visibleMtns) {
		// this is the bool test to check whether mtn is visible among the already-visible ones
		if (!(abs(i.first - cdn.first) <= abs(i.second - cdn.second))) {
			ctr++;
		}
	}
	if (ctr == visibleMtns.size()) visibleMtns.pub(cdn);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("mountains.in");
	ofstream cout("mountains.out");
	int n; cin >> n; 
	vpi reversedCoordinates, coor;
	while (n--) {
		int x, y; cin >> x >> y;
		reversedCoordinates.pub(mkp(y, x));
	}
	sort(reversedCoordinates.rbegin(), reversedCoordinates.rend());
	for (auto i : reversedCoordinates) {
		coor.pub(mkp(i.second, i.first));
	}
	visibleMtns.pub(mkp(coor[0].first, coor[0].second));
	for (int i = 1; i < coor.size(); i++) {
		// check each to see if in highest
		checkHeight(coor[i]);
	}

	cout << visibleMtns.size() << endl;

	return 0;
}
