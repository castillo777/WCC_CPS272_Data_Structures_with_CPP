#pragma once
#include "MiniVector.h"

class ElectionReport
{
	friend ostream& operator<< (ostream& out, const ElectionReport& rhs);
	friend istream& operator>> (istream& in, ElectionReport& rhs);

public:
	void sortElectionResults();
	void calculatePercentageOfVotes();
private:
	MiniVector<string> candidates;
	MiniVector<int> votesReceived;
	MiniVector<double> percentageOfVotesReceived;
};