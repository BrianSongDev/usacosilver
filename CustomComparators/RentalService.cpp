// Jan 2018 #2 (Rental Service)
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
	ifstream cin("rental.in");
	ofstream cout("rental.out");
	int n; cin >> n; int numStores; cin >> numStores; int neighbors; cin >> neighbors;
	vi cows;
	while (n--) {
		int cow; cin >> cow;
		cows.pub(cow);
	}
	vpi stores;
	while (numStores--) {
		int b, a; cin >> a >> b;
		stores.pub(mkp(b, a));
	}
	vll prices;	prices.pub(0);
	while (neighbors--) {
		ll price; cin >> price;
		prices.pub(price);
	}

	sort(cows.rbegin(), cows.rend());
	sort(stores.rbegin(), stores.rend());
	sort(prices.begin(), prices.end());

	// create prefix sum for prices
	for (int i = 1; i < prices.size(); i++) {
		prices[i] += prices[i - 1];
	}
	vll totalRevFromRenting;
	for (int i = max(0, (int)prices.size()-(int)cows.size()); i < prices.size(); i++) {
		ll currRevenue = prices[prices.size()-1] - prices[i];
		totalRevFromRenting.pub(currRevenue);
	}

	vll totalRevFromStores;
	// iterate from 0 cows to all cows

	int ctr = 0;
	for (int i = 0; i < prices.size(); i++) {
		ll nextCowRev = i != 0 ? totalRevFromStores[i - 1] : 0;
		while (ctr < stores.size() && cows[i] > 0) {
			ll minEither = min(stores[ctr].second, cows[i]);
			nextCowRev += stores[ctr].first * minEither;
			stores[ctr].second -= minEither;
			cows[i] -= minEither;
			if (stores[ctr].second == 0) {
				ctr++;
			}
		}
		totalRevFromStores.pub(nextCowRev);
	}

	vll totals;
	for (int i = 0; i < min(totalRevFromRenting.size(), totalRevFromStores.size()); i++) {
		totals.pub(totalRevFromRenting[i] + totalRevFromStores[i]);
	}
	sort(totals.begin(), totals.end());

	cout << totals[totals.size()-1] << endl;

	return 0;
}
