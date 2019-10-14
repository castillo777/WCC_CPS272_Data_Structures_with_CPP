#include "Complex.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void getNumbers(Complex&, Complex&);
void addNumbers(const Complex&, const Complex&, Complex&);
void subtractNumbers(const Complex&, const Complex&, Complex&);
void multiplyNumbers(const Complex&,const Complex&, Complex&);
void divideNumbers(const Complex&, const Complex&, Complex&);

int main()
{
	Complex firstComplexNumber, secondComplexNumber, resultant;

	getNumbers(firstComplexNumber, secondComplexNumber);

	cout << fixed << showpoint << setprecision(1);

	addNumbers(firstComplexNumber, secondComplexNumber, resultant);
	cout << "ADDITION:" << endl << firstComplexNumber << " + " << secondComplexNumber
		 << " = " << resultant << endl << endl;

	subtractNumbers(firstComplexNumber, secondComplexNumber, resultant);
	cout << "SUBTRACTION:" << endl << firstComplexNumber << " - " << secondComplexNumber
		 << " = " << resultant << endl << endl;

	multiplyNumbers(firstComplexNumber, secondComplexNumber, resultant);
	cout << "MULTIPLICATION:" << endl << firstComplexNumber << " * " << secondComplexNumber
		 << " = " << resultant << endl << endl;

	divideNumbers(firstComplexNumber, secondComplexNumber, resultant);
	cout << "DIVISION:" << endl << firstComplexNumber << " / " << secondComplexNumber
		 << " = " << resultant << endl << endl;

	cout << "All calcuations are complete!" << endl << endl;

	system("pause");
	return 0;
}

void getNumbers(Complex& firstNumber, Complex& secondNumber)
{
	cout << "Please enter the first complex number: ";
	cin >> firstNumber;
	cout << endl << "Please enter the second complex number: ";
	cin >> secondNumber;
	cout << endl;
}

void addNumbers(const Complex& firstNumber, const Complex& secondNumber, Complex& result)
{
	 result = (firstNumber + secondNumber);
}

void subtractNumbers(const Complex& firstNumber, const Complex& secondNumber, Complex& result)
{
	result = (firstNumber - secondNumber);
}

void multiplyNumbers(const Complex& firstNumber,const Complex& secondNumber, Complex& result)
{
	double realNumber = ((firstNumber.getReal() * secondNumber.getReal()) - (firstNumber.getImaginary() * secondNumber.getImaginary()));
	double imaginaryNumber = (firstNumber.getImaginary() - secondNumber.getImaginary());
	
	result.setReal(realNumber);
	result.setImaginary(imaginaryNumber);
}

void divideNumbers(const Complex& firstNumber,const Complex& secondNumber, Complex& result)
{
	double secondRealNumberSquared = sqrt(secondNumber.getReal());
	double secondImaginaryNumberSquared = sqrt(secondNumber.getImaginary());
	double realNumber = (((firstNumber.getReal() * secondNumber.getReal()) + (firstNumber.getImaginary() * secondNumber.getImaginary())) / (secondRealNumberSquared + secondImaginaryNumberSquared));
	double imaginaryNumber = (((firstNumber.getImaginary() * secondNumber.getReal()) - (firstNumber.getReal() * secondNumber.getImaginary())) / (secondRealNumberSquared + secondImaginaryNumberSquared));
	
	result.setReal(realNumber);
	result.setImaginary(imaginaryNumber);
}
