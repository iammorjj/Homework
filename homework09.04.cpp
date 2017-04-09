#include <iostream>
using namespace std;
template <class T1,
	class T2,
	class T3>
struct Three {
	T1 first;
	T2 second;
	T3 third;
};
int main() {
	Three<int, Three<int, char, double>, char> obj;
	obj.first = 1;
	obj.second.third = 3.14;
	obj.third = 'a';
	cout << obj.first << ' ' << obj.second.third << ' ' << obj.third;
	return 0;
}
