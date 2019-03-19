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
     * 13:39 THA 19/03/2019
     */

    int n, q, idx;

    scanf ( "%d %d", &n, &q );
    if ( n < 0 ) {
        // no data
        return 0;
    }

    // create the array of arrays
    int * table [ n ];

    idx = 0;
    while ( idx < n ) {
        int sz;
        scanf ( "%d", &sz );
        if ( sz > 0 ) {
            table [ idx ] = new int [ sz ];
            int idx1 = 0;
            while ( idx1 < sz ) {
                scanf ( "%d", & table [ idx ] [ idx1 ] );
                idx1 ++;
            }
        }
        idx ++;
    }

    // get the queries
    while ( q -- > 0 ) {
        int i, j;

        scanf ( "%d %d", &i, &j );
        printf ( "%d\n", table [ i ] [ j ] );
    }

    // clean up
    idx = n;
    while ( -- idx >= 0 )
        delete ( table [ idx ] );

    return 0;
}

