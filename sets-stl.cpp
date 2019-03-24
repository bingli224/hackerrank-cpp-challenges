#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

/**
 * By BingLi224
 * 17:42 THA 24/03/2019
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::set <int> intSet;

    int N;
    cin >> N;
    while ( N -- > 0 ) {
        int q, val;
        cin >> q >> val;
        
        switch ( q ) {
            case 1 :
                intSet.insert ( val );
                break;
            case 2 :
                intSet.erase ( val );
                break;
            case 3 :
                cout << ( intSet.end ( ) == intSet.find ( val ) ? "No" : "Yes" ) << endl;
                break;
        }
    }

    return 0;
}
