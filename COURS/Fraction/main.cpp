#include <iostream>
#include <fstream>

#include "Fraction.hpp"

using namespace std;

int main()
{
	Point2D point1(1,2), point2(5,2), point3(1,2);

	if (point1<point2){
		cout << "point1<point2"<<endl;
	}	

	if (point1>point2){
		cout << "point1>point2"<<endl;
	}	

	if (point1==point3){
		cout << "point1==point3"<<endl;
	}	

	Fraction frac1{6, 2}, frac2{6, 2}, frac3{2, 6};

	int val1 = 3, val2 = 2;

	cout << val2 + frac1 << endl;
	cout << frac1 + val2 << endl;

	if (frac1 == frac2)
	{
		cout << "frac1 == frac2" << endl;
	}

	if (frac1 == frac3)
	{
		cout << "frac1 == frac3" << endl;
	}

	if (frac1 != frac3)
	{
		cout << "frac1 != frac3" << endl;
	}

	if (frac1 > frac3)
	{
		cout << "frac1 > frac3" << endl;
	}

	if (frac3 < frac2)
	{
		cout << "frac3 < frac2" << endl;
	}

	if (frac1 > frac3)
	{
		cout << "frac1 > frac3" << endl;
	}

	if (frac1 < val1)
	{
		cout << "val1 < frac1" << endl;
	}

	if (val1 == frac1)
	{
		cout << "val1 == frac1" << endl;
	}

	if (frac1 == val1)
	{
		cout << "frac1 == val1" << endl;
	}

	if (val1 < frac1)
	{
		cout << "val1 < frac1" << endl;
	}

	ifstream my_file("fraction.txt");

	Fraction my_fraction;

	if (my_file.is_open())
	{
		while (my_file >> my_fraction)
		{
			cout << my_fraction << endl;
		}
	}
	else
	{
		cout << "Cannot open fraction.txt" << endl;
	}
	my_file.close();

	// int val = 1;

	return 0;
}
