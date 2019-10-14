#include "Complex.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Implementaion of all friend operator functions
ostream& operator<<(ostream& out, const Complex& theComplex)
{
	out << "(" << theComplex.real
		<< " + " << theComplex.imag
		<< "i)";

	return out;
}

istream& operator>>(istream& in, Complex& theComplex)
{
	string complexNumber;

	getline(in, complexNumber);
	theComplex.convertStringToComplex(complexNumber);

	return in;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex temp;

	temp.real = lhs.real + rhs.real;
	temp.imag = lhs.imag + rhs.imag;

	return temp;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	Complex temp;

	temp.real = lhs.real - rhs.real;
	temp.imag = lhs.imag - rhs.imag;

	return temp;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex temp;

	temp.real = lhs.real * rhs.real;
	temp.imag = lhs.imag * rhs.imag;

	return temp;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex temp;

	temp.real = lhs.real / rhs.real;
	temp.imag = lhs.imag / rhs.imag;

	return temp;
}

// Implementation of class constructor
Complex::Complex(double re, double im) 
{
	setReal(re);
	setImaginary(im);
}

// Implementation of public member functions
double Complex::getReal() const
{
	return real;
}

double Complex::getImaginary() const
{
	return imag;
}

void Complex::setReal(double re)
{
	real = re;
}

void Complex::setImaginary(double im)
{
	imag = im;
}

void Complex::convertStringToComplex(const string& complexString)
{
	char strippedSign;

	stringstream splitString(complexString);
	splitString >> real >> strippedSign >> imag >> strippedSign;
}