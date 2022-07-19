// CF Contest 702 Problem C (Cellular Network)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <list>
#include <map>
#include <functional>
#include <iomanip>
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

bool doesContiguousWork(vll cities, vll towers, int testNum) {
	ll currentCity = 0, currentTower = 0, res = 0;
	while (currentTower > -1 && currentTower < towers.size() && currentCity < cities.size()) {
		if (cities[currentCity] > (towers[currentTower] + testNum)) {
			// add 1 to currentTower
			currentTower++;
		}
		else if (cities[currentCity] < (towers[currentTower] - testNum)) {
			return false;
		}
		else {
			currentCity++;
		}
	}
	if (currentCity == cities.size()) return true;
	return false;
}

int first_true(int lo, int hi, vll cities, vll towers) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (doesContiguousWork(cities, towers, mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return lo;
}

//ll last_true(ll lo, ll hi, vpll intervals, int cows) {
//	lo--;
//	while (lo < hi) {
//		ll mid = lo + (hi - lo + 1) / 2;
//		if (doesDWork(intervals, mid, cows)) {
//			lo = mid;
//		}
//		else {
//			hi = mid - 1;
//		}
//	}
//	return lo;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("sabotage.in");
	//ofstream cout("sabotage.out");
	int n, k; vll cities, towers;
	cin >> n >> k;
	while (n--) {
		int a; cin >> a;
		cities.pub(a);
	}
	while (k--) {
		int a; cin >> a;
		towers.pub(a);
	}
	sort(cities.begin(), cities.end());
	sort(towers.begin(), towers.end());
	cout << first_true(0, 2147483646, cities, towers) << endl;
	return 0;
}
