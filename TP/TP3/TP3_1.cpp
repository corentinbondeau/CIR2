#include <iostream>
using namespace std;

class A {
public:
	A() { x = 0; cout << "1"; }
	A(int px) { x = px; cout << "2"; }
	A(const A& pa) { x = pa.x; cout << "3"; }
protected:
	int x;
};

class B {
public:
	B(const A& pa = A()) : a(pa) { cout << "4"; }
	B(const A& pa, int py) { a = pa; y = py; cout << "5"; }
protected:
	A a;
	int y;
};

class C : public B {
public:
	C(int pz = 1) { z = pz; cout << "6"; }
	C(A pa) : B(pa) { z = 0; cout << "7"; }
	C(const B& pb) : B(pb), a(1) { z = 0; cout << "8"; }
protected:
	A a;
	int z;
};

int main() {

	A a0; cout << endl; // Appel du constructeur par défaut de A, affichant 1.
	A a1(3); cout << endl; // Appel du constructeur avec paramètre de A, affichant 2.
	A a2(a1); cout << endl; // Appel du constructeur de copie de A, affichant 3.
	A a3 = a2; cout << endl; // Appel du constructeur de copie de A, affichant 3.
	a3 = a1; cout << endl; // Appel du constructeur de copie de A, affichant 2 (car a1 est initialisé avec le constructeur avec paramètre).

	B b0(a0, 3); cout << endl; // Appel du constructeur avec paramètres de B, affichant 1 (constructeur de copie de A appelé par le constructeur de B) puis 5.
	B b1(a1); cout << endl; // Appel du constructeur avec paramètre de B, affichant 2 (constructeur de copie de A appelé par le constructeur de B) puis 4.
	B b2; cout << endl; // Appel du constructeur par défaut de B, affichant 4.

	C c0; cout << endl; // Appel du constructeur par défaut de C, affichant 6.
	C c1(a1); cout << endl; // Appel du constructeur avec paramètre A de C, affichant 2 (constructeur de copie de A appelé par le constructeur de B) puis 7.
	C c2(b2); cout << endl; // Appel du constructeur avec paramètre B de C, affichant 4 (constructeur de copie de A appelé par le constructeur de B) puis 8.

}