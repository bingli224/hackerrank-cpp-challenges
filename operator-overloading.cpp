#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * By BingLi224
 * 19:56 THA 19/03/2019
 */
class Matrix {
    public:
        vector<vector<int>> a;

        Matrix operator+ ( Matrix &b ) {
            Matrix result;

            int idx = 0,
                sz = a.size ( );
            while ( idx < sz ) {
                vector <int> row;
                int idx1 = 0,
                    sz1 = a [ idx ].size ( );
                while ( idx1 < sz1 ) {
                    row.push_back ( a [ idx ] [ idx1 ] + b.a [ idx ] [ idx1 ] );
                    idx1 ++;
                }
                result.a.push_back ( row );
                idx ++;
            }

            return result;
        }
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
