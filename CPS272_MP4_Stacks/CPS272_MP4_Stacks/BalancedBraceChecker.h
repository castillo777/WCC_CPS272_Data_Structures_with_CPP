#pragma once
#include <fstream>
#include <string>
#include "MiniStack.h"
#include <exception>
#include <stdexcept>

const string openBraceChars = { "([{" },
closeBraceChars = { ")]}" };

class balancedBraceChecker
{
public:
	static void runBraceChecker(
		ostream& os = cout,
		istream& is = cin)
	{
		string inputStr;
		os << "Balanced Brace Checker:" << endl;
		while (true)
		{
			os << "Enter the file name, or 'q' to quit: ";
			is >> inputStr;
			try
			{
				if (inputStr == "q" || is.fail())
					throw runtime_error("Program terminating...");
				if (checkBraces(inputStr))
					os << "The symbols in " << inputStr
					<< " are balanced." << endl;
				else
					os << "The symbols in " << inputStr
					<< " are NOT balanced." << endl;
			}
			catch (exception& e)
			{
				os << e.what() << endl;
				os << "Quitting Balanced Brace Checker..." << endl << endl;
				return;
			}
		}

	}
private:
	static bool checkBraces(const string& fileName)
	{
		// Files with strings containing any braces, brackets,
		// or parentheses will cause a false negative.
		char temp = ' ';
		int closeIndex = 0;
		miniStack<char> braceStk;
		ifstream inFile;
		inFile.open(fileName);
		if (inFile.fail())
			throw runtime_error("File " +
				fileName + " cannot be opened. Aborting");
		while (!inFile.eof())
		{
			temp = inFile.get();
			if (openBraceChars.find(temp) != string::npos)
			{
				braceStk.push(temp);
				continue;
			}
			closeIndex = closeBraceChars.find(temp);
			if (closeIndex != string::npos) // found closing brace
			{
				if (braceStk.empty() ||
					openBraceChars.find(braceStk.top()) != closeIndex)
				{
					inFile.close();
					return false;
				}
				braceStk.pop();
			}
		}
		inFile.close();
		return braceStk.empty(); // If not empty, then not balanced
	}
};