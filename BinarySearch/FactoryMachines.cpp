// CSES - Factory Machines
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

ll k;

bool doesContiguousWork(vi times, ll testNum) {
	ll sum = 0;
	for (auto time : times) {
		sum += (testNum / time);
	}
	if (sum >= k) return true;
	return false;
}

ll first_true(ll lo, ll hi, vi times) {
	hi++;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (doesContiguousWork(times, mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return lo;
}

//int last_true(int lo, int hi, vi times) {
//	lo--;
//	while (lo < hi) {
//		int mid = lo + (hi - lo + 1) / 2;
//		if (doesContiguousWork(times, mid)) {
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
	int n; cin >> n >> k; vi times;
	while (n--) {
		int a; cin >> a;
		times.pub(a);
	}
	sort(times.begin(), times.end());
	cout << first_true(1, (k * times[0]), times) << endl;
	return 0;
}
