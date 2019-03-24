#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <map>

/**
 * By BingLi224
 * 18:54 THA 24/03/2019
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    map <string, int> markMap;

    int N;
    cin >> N;
    while ( N -- > 0 ) {
        int q;
        string name;

        cin >> q >> name;
        switch ( q ) {
            case 1:
                int mark;
                cin >> mark;
                markMap [ name ] = markMap [ name ] + mark;
                break;
            case 2:
                markMap.erase ( name );
                break;
            case 3:
                cout << markMap [ name ] << endl;
                break;
        }
    }

    return 0;
}
