#pragma once

#include <iostream>
#include <compare>

class Fraction
{
private:
    int num_ = 0, den_ = 1;

public:
    Fraction(const Fraction &fraction);
    Fraction(const int &num = 0, const int &den = 1);
    void set_num(const int &num);
    void set_den(const int &deno);
    int get_num() const;
    int get_den() const;

    Fraction operator+(const Fraction &fraction);

    bool operator<(const Fraction &fraction) const;
    bool operator>(const Fraction &fraction) const;
    bool operator!=(const Fraction &fraction) const;
    bool operator<=(const Fraction &fraction) const;
    bool operator>=(const Fraction &fraction) const;

    bool operator<(const int &val) const;
    bool operator>(const int &val) const;
    bool operator!=(const int &val) const;
    bool operator<=(const int &val) const;
    bool operator>=(const int &val) const;

    friend bool operator<(const int &val, const Fraction &frac);
    friend bool operator>(const int &val, const Fraction &frac);

    bool operator==(const Fraction &fraction) const;
    bool operator==(const int &val) const;

    strong_ordering operator<=>(const Fraction &fraction) const;
    strong_ordering operator<=>(const int &val) const;

    Fraction operator+(const int &number);

    operator int();

    friend Fraction operator+(const int &val, const Fraction &frac);

    friend ostream &operator<<(ostream &os, const Fraction &fraction);

    friend istream &operator>>(istream &os, Fraction &fraction);
};

class Point2D
{
private:
	int x_ = 0, y_ = 0;

public:
	Point2D(const Point2D& point);
	Point2D(const int& x = 0, const int& y = 0);
	void set_x(const int& x);
	void set_y(const int& y);
	int get_x() const;
	int get_y() const;

	Point2D operator+(const Point2D& point);

	bool operator<(const Point2D& point) const;
	bool operator>(const Point2D& point) const;
	bool operator!=(const Point2D& point) const;
	bool operator<=(const Point2D& point) const;
	bool operator>=(const Point2D& point) const;

	bool operator<(const int& val) const;
	bool operator>(const int& val) const;
	bool operator!=(const int& val) const;
	bool operator<=(const int& val) const;
	bool operator>=(const int& val) const;

	friend bool operator<(const int& val, const Point2D& point);
	friend bool operator>(const int& val, const Point2D& point);

	bool operator==(const Point2D& point) const;
	bool operator==(const int& val) const;

	strong_ordering operator<=>(const Point2D& point) const;
	strong_ordering operator<=>(const int& val) const;

	Point2D operator+(const int& number);

	operator int();

	friend Point2D operator+(const int& val, const Point2D& point);

	friend ostream& operator<<(ostream& os, const Point2D& point);

	friend istream& operator>>(istream& os, Point2D& point);
};