#include <iostream>
#include <set>
using namespace std;
int main() {
	int a[] = { 7, 4, 9, 1, 3, 4, 8, 2, 7, 5, 3, 6, 10, 4, 8, 10, 1, 2 };
	set<int> s(&a[0], &a[17]);
	set<int>::iterator p = s.begin();
	while (p != s.end()) cout << *p++ << " ";
	return 0;
}
