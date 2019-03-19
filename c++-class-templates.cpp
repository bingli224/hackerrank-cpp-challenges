#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/
/**
 * By BingLi224
 * 17:28 THA 19/03/2019
 */
template <class T>
class AddElements {
    private:
        T value;
    public:
        AddElements ( T t ) {
            value = t;
        }

        T add ( T t ) {
            return value + t;
        }
};

template < >
class AddElements <string> {
    private:
        string value;
    public:
        AddElements ( string s ) {
            value = s;
        }

        string concatenate ( string s ) {
            return value + s;
        }
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
