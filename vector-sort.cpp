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
     * 19:24 THA 24/03/2019
     * 
     * insertion and for loop are of linear complexity.
     */

    vector <int> v;
    int N;
    cin >> N;
    while ( N -- > 0 ) {
        int i;
        cin >> i;
        v.push_back ( i );
        /*
        bool bNotAdded = true;
        for ( vector <int>::iterator it = v.begin ( ); bNotAdded && it != v.end ( ); it ++ ) {
            if ( *it > i ) {
                bNotAdded = false;
                v.insert ( it, i );
                break;
            }
        }

        if ( bNotAdded )
            v.push_back ( i );
        */
    }

    std::sort ( v.begin ( ), v.end ( ) );
    std::for_each ( v.begin ( ), v.end ( ), [&] ( auto i ) { cout << i << " "; } );
    return 0;
}
