// USACO 1/2019 Silver #2 (Icy Perimeter)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <list>
#define pb push_back
#define mp make_pair
#define rs resize
#define loop(n) for(int ii = 0; ii < n; ++ ii)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pi;
typedef vector <pair<int, int> > vpi;

const int MAX_N = 1000;

int grid[MAX_N][MAX_N];  // the grid itself
int row_num;
int col_num;
bool visited[MAX_N][MAX_N];  // keeps track of which nodes have been visited
int curr_size = 0, p = 0;  // reset to 0 each time we start a new component

vpi iceCream;

void floodfill(int r, int c, int color) {
	if (
		(r < 0 || r >= row_num || c < 0 || c >= col_num)  // if out of bounds
		|| grid[r][c] != color  // wrong color
		|| visited[r][c]  // already visited this square
		) {
		return;
	}
	bool rightLimit = (r + 1 >= row_num);
	bool leftLimit = (r - 1 < 0);
	bool upLimit = (c - 1 < 0);
	bool downLimit = (c + 1 >= col_num);
	if (rightLimit) p++; if (leftLimit) p++; if (upLimit) p++; if (downLimit) p++;
	if (!rightLimit && grid[r + 1][c] == 0) p++;
	if (!leftLimit && grid[r - 1][c] == 0) p++;
	if (!upLimit && grid[r][c - 1] == 0) p++;
	if (!downLimit && grid[r][c + 1] == 0) p++;

	visited[r][c] = true; // mark current square as visited
	curr_size++; // increment the size for each square we visit

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, color);
	floodfill(r, c - 1, color);
	floodfill(r - 1, c, color);
	floodfill(r + 1, c, color);
}

bool sortt(const pair<int, int>& a,
	const pair<int, int>& b)
{
	if (a.first != b.first)
		return (a.first > b.first);
	else
		return (a.second < b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//ifstream cin("perimeter.in");
	//ofstream cout("perimeter.out");
	int n; cin >> n;
	iceCream.pb(mp(0, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char output; cin >> output;
			if (output == '#') {
				grid[i][j] = 1;
			}
			else {
				grid[i][j] = 0;
			}
		}
	}
	row_num = n, col_num = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				iceCream.push_back(mp(curr_size, p));
				curr_size = 0; p = 0;
				if (grid[i][j] == 1) {
					floodfill(i, j, 1);
				}
			}
		}
	}
	sort(iceCream.begin(), iceCream.end(), sortt);
	cout << iceCream[0].first << " " << iceCream[0].second << endl;
	return 0;
}
