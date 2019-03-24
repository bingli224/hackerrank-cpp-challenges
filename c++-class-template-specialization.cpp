#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

/**
 * By BingLi224
 * 21:53 24/03/2019
 */
template < >
struct Traits <enum Fruit> {
    static string name ( int f ) {
        switch ( static_cast<Fruit> ( f ) ) {
            case Fruit::apple:
                return "apple";
            case Fruit::orange:
                return "orange";
            case Fruit::pear:
                return "pear";
            default:
                return "unknown";
        }
    }
};
template < >
struct Traits <enum Color> {
    static string name ( int c ) {
        switch ( static_cast <Color> ( c ) ) {
            case Color::red:
                return "red";
            case Color::green:
                return "green";
            case Color::orange:
                return "orange";
            default:
                return "unknown";
        }
    }
};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
