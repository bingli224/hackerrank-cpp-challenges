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
     * 01:04 THA 20/03/2019
     */
    int n, idx;
    scanf ( "%d", &n );

    if ( n <= 0 )
        return -1;

    // get sorted int list
    int list [ n ];
    idx = 0;
    while ( idx < n ) {
        scanf ( "%d", &list [ idx ] );
        idx ++;
    }

    // get queries
    int q_sz, q;
    scanf ( "%d", &q_sz );
    idx = 0;
    while ( idx < q_sz ) {
        
        scanf ( "%d", &q );

        // binary search
        int idxSearch = n / 2, lBound = 0, rBound = n;
        while ( true ) {
            // found
            if ( q == list [ idxSearch ] && ( idxSearch <= 0 ? 1 : q > list [ idxSearch - 1 ] ) ) {
                printf ( "Yes %d\n", idxSearch + 1 );
                break;
            }
            // target < this
            else if ( q > list [ idxSearch ] ) {
                int offset = ( rBound - idxSearch ) / 2;

                if ( offset == 0 ) {
                    // no more bigger. the next index is smallest bigger
                    printf ( "No %d\n", idxSearch + 2 );
                    break;
                }

                lBound = idxSearch;
                idxSearch += offset;
            }
            // target > this || ( target == this && target > this[-1] )
            else {
                int offset = ( idxSearch - lBound ) / 2;

                if ( offset == 0 && idxSearch == lBound ) {
                    // no more lower. this is the smallest bigger
                    printf ( "No %d\n", idxSearch + 1 );
                    break;
                }

                rBound = idxSearch;
                idxSearch = lBound + offset;
            }
        }

        idx ++;
    }
    return 0;
}
