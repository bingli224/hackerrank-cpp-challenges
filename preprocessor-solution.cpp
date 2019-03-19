/**
 * By BingLi224
 * 19:25 THA 19/03/2019
 */
#define INF 10000000
#define foreach( v, i ) for ( auto i = 0; i < v.size ( ); i ++ )
#define FUNCTION(fname, op) inline void fname ( auto &a, auto b ) { if ( b op a ) a = b; }
#define io(v)   cin >> v
#define toStr( s ) #s

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}
