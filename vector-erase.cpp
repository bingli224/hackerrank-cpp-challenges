#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    /**
     * By BingLi224
     * 15:43 THA 10/03/2019
     */
    int sz;
    cin >> sz;
    vector <int> v;
    while ( sz --  > 0 ) {
        int i;
        cin >> i;
        v.push_back ( i );
    }
    sz = v.size ( );
    
    // first erase
    int x, y;
    cin >> x;
    if ( -- x > 0 && x < sz )
        v.erase ( v.begin ( ) + x );

    // secnd erase with rage
    cin >> x >> y;
    x --;
    while ( -- y < sz && y > x && x >= 0 ) {
        v.erase ( v.begin ( ) + x );
    }

    sz = v.size ( );
    cout << sz << endl;
    
    x = 0;
    while ( x < sz ) {
        cout << v [ x ++ ] << " ";
    }
    return 0;
}
