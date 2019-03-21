#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

        /**
         * By BingLi224
         * 22:03 THA 20/03/2019
         */
        /*
        char b [ 17 ];
        sprintf ( b, "% +15.2f", B );
        int idx = 0;
        while ( b [ idx ] == ' ' && idx < 15 ) b [ idx ++ ] = '_';
        printf ( "%#x\n%15s\n%.9E\n", (long) floor(A), b, C );
        */
        /**
         * By BingLi224
         * 23:28 THA 21/03/2019
         */
        cout.unsetf ( std::ios::scientific | std::ios::fixed );
        cout << nouppercase << setw ( 0 ) << showbase << hex << (long int) A << endl;

        cout << setprecision ( 2 ) << fixed << setfill ('_') << showpoint << dec << right << showpos << setw ( 15 ) << B << endl;

        cout << noshowpos << right << setfill ( ' ' ) << setprecision ( 9 ) << uppercase << scientific << C << endl;
	}
	return 0;

}
