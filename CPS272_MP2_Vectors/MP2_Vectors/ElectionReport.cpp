#include "ElectionReport.h"

ostream& operator<< (ostream& out, const ElectionReport& rhs)
{
	cout << fixed << showpoint << setprecision(1);

	cout << "Candidate" << setw(20) << "Votes Received" << setw(13) << "% Votes" << endl;

	for (size_t i = 0; i < rhs.candidates.size(); i++)
	{
		out << left << setw(15) << rhs.candidates[i] << setw(19) << rhs.votesReceived[i]
			<< right << setw(5) << rhs.percentageOfVotesReceived[i] << '%' << endl;
	}
	return out;
}

istream& operator>>(istream& in, ElectionReport& rhs)
{
	string candidateName = "";
	int votes = 0;

	while (!in.eof())
	{
		in >> candidateName;
		rhs.candidates.push_back(candidateName);

		in >> votes;
		rhs.votesReceived.push_back(votes);
	}
	rhs.calculatePercentageOfVotes();
	rhs.sortElectionResults();
	return in;
}

void ElectionReport::sortElectionResults()
{
	int largest = 0;

	for (size_t i = 0; i < candidates.size(); i++)
	{
		largest = i;

		for (size_t j = i + 1; j < candidates.size(); j++)
		{
			if (votesReceived[j] > votesReceived[largest])
				largest = j;
		}

		swap(candidates[largest], candidates[i]);
		swap(votesReceived[largest], votesReceived[i]);
		swap(percentageOfVotesReceived[largest], percentageOfVotesReceived[i]);
	}
}

void ElectionReport::calculatePercentageOfVotes()
{
	double totalVotes = 0.00;

	for (size_t i = 0; i < candidates.size(); i++)
	{
		totalVotes += votesReceived[i];
	}

	for (size_t i = 0; i < candidates.size(); i++)
	{
		percentageOfVotesReceived.push_back((votesReceived[i] / totalVotes) * 100);
	}
}