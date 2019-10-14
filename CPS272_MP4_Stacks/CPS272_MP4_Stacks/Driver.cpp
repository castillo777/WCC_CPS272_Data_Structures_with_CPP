#include "PalindromeTester.h"
#include "BaseConverter.h"
#include "BalancedBraceChecker.h"

int main()
{
	PalindromeTester palindromeTestingProgram;
	palindromeTestingProgram.runPalindromeTests(cout, cin);

	BaseConverter baseConvertionProgram;
	baseConvertionProgram.runBaseConverter(cout, cin);

	balancedBraceChecker braceCheckingProgram;
	braceCheckingProgram.runBraceChecker(cout, cin);

	system("pause");
	return 0;
}