#include "ElectionReport.h"

using namespace std;

int main()
{
	ifstream inFile("candidates.txt");
	ElectionReport cityElectionReport;

	if (!inFile)
	{
		cerr << "Unable to open file. Terminating program."
			<< endl;
		
		system("pause");
		exit(1);
	}

	inFile >> cityElectionReport;

	cout << cityElectionReport;

	inFile.close();

	system("pause");
	return 0;
}