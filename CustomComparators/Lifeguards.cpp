// 8 AC, 2 TLE. Jan 2018 Lifeguards (#1).
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream cin("lifeguards.in");
	ofstream cout("lifeguards.out");
	int n; cin >> n;
	vpi shifts, arrToBeUsedLater;
	while (n--) {
		int a, b; cin >> a >> b;
		shifts.pub(mkp(a, 1));
		shifts.pub(mkp(b, -1));
		arrToBeUsedLater.pub(mkp(a, b));
	}
	sort(shifts.begin(), shifts.end());
	vector <pair<pair<int, int>, int> > tlOfShifts; int totalTimeWorking = 0;
	mi indicesOfTimes;
	tlOfShifts.pub(mkp(mkp(shifts[0].first, shifts[1].first), shifts[0].second));
	for (int i = 1; i < shifts.size()-1; i++) {
		tlOfShifts.pub(mkp(mkp(shifts[i].first, shifts[i + 1].first), shifts[i].second + tlOfShifts[i - 1].second));
		indicesOfTimes[shifts[i].first] = tlOfShifts.size() - 1;
	}
	tlOfShifts.pub(mkp(mkp(shifts[shifts.size() - 1].first, shifts[shifts.size() - 1].first), 0));
	indicesOfTimes[shifts[shifts.size() - 1].first] = tlOfShifts.size()-1;

	for (auto i : tlOfShifts) {
		if (i.second > 0) {
			totalTimeWorking += (i.first.second - i.first.first);
		}
	}
	int minTimeLost = 0;
	for (auto i : arrToBeUsedLater) {
		int timeLost = totalTimeWorking;
		for (int a = indicesOfTimes[i.first]; a < indicesOfTimes[i.second]; a++) {
			if (tlOfShifts[a].second == 1) {
				timeLost -= tlOfShifts[a].first.second - tlOfShifts[a].first.first;
			}
		}
		minTimeLost = max(minTimeLost, timeLost);
	}
	cout << minTimeLost << endl;

	return 0;
}
