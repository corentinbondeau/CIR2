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

    // strong_ordering operator<=>(const Fraction &fraction) const;
    // strong_ordering operator<=>(const int &val) const;

    Fraction operator+(const int &number);

    operator int();

    friend Fraction operator+(const int &val, const Fraction &frac);

    friend ostream &operator<<(ostream &os, const Fraction &fraction);

    friend istream &operator>>(istream &os, Fraction &fraction);
};
