#pragma once
#include <iostream>
using namespace std;

enum class Color : unsigned char
{
    blue = 0,
    green = 1,
    orange = 2,
    brown = 3
};

std::ostream &operator<<(std::ostream &os, const Color &color);

class Shape
{
private:
    static unsigned global_count_;
    unsigned count_;

protected:
    const Color color_;

public:
    void print_data();
    Shape(const Color &color = Color::blue);
};

class Shape_virtual : public Shape
{

public:
    Shape_virtual(const Color &color = Color::blue);
    virtual void print_data();
};

class Shape_pure_virtual : public Shape
{
public:
    Shape_pure_virtual(const Color &color = Color::blue);
    virtual void print_data() = 0;
};

class Rectangle_pure_virtual : public Shape_pure_virtual
{
private:
    float length_;
    float width_;

public:
    void print_data();
    Rectangle_pure_virtual(const float &length, const float &width, const Color &color = Color::blue);
};

class Rectangle_virtual : public Shape_virtual
{
private:
    float length_;
    float width_;

public:
    void print_data();
    Rectangle_virtual(const float &length, const float &width, const Color &color = Color::blue);
};

class Rectangle : public Shape
{
private:
    float length_;
    float width_;

public:
    void print_data();
    Rectangle(const float &length, const float &width, const Color &color = Color::blue);
};

class Quadrupede {
public:
    Quadrupede(const string& in_nom) : nom(in_nom)
    {
        cout << "Naissance d'un quadripede" << endl;
    }
    ~Quadrupede() {}
    virtual void speak() = 0;
    const string& getNom() const {
        return nom;
    }
    void setNom(const string& nom) {
        this->nom = nom;
    }
protected:
    string nom;
};

class Chien : public Quadrupede {
public:
    Chien(const string& in_nom) : Quadrupede(in_nom) {
        cout << "Naissance d'un chien." << endl;
    }
    ~Chien() {}
    void speak() { cout << "Ouaf ouaf et pis ouaf" << endl; }
};

class Chat : public Quadrupede {
public:
	Chat(const string& in_nom) : Quadrupede(in_nom) {
		cout << "Naissance d'un chat." << endl;
	}
	~Chat() {}
	void speak() { cout << "Miaou miaou et pis miaou" << endl; }
};
