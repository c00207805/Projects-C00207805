#pragma once
#include "string"
#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
using namespace std;

class Candidate
{
private:
public:
	//each candidate will have a vector of ballot paper objects
	//the ballot paper objects are here because the specific 
	//candidate has recieved a preference of 1 in it
	string name;
	string party;
	vector<int> theVotes;
	int theirCount;
	Candidate()
	{
		name = "";
		party = "";
	}
	Candidate(string theName, string theParty)
	{
		name = theName;
		party = theParty;
	}
	string getName()
	{
		return name;
	}
	void setName(string theName)
	{
		name = theName;
	}
	string getParty()
	{
		return party;
	}
	void setParty(string theParty)
	{
		party = theParty;
	}
};

class Preference
{
public:
	char thePreference;
	Candidate theCandidate;
	Preference(char pref, Candidate c)
	{
		theCandidate = c;
		thePreference = pref;
	}
};

class BallotPaper
{
private:
public:
	//this variable is the votes for the ballot eg 1243
	string votes;
	int size;
	vector<Candidate> candidates;
	vector <Preference> preferenceVector;
	
	BallotPaper()
	{

	}
	BallotPaper(int theSize, string theVotes, vector<Candidate> theCandidates)
	{
		size = theSize;
		votes = theVotes;
		candidates = theCandidates;
		for (int i = 0; i < size; i++)
		{
			//create a preference object and pass in the vote and the candidate
			Preference thePreference = Preference(votes[i], candidates[i]);
			//then push it on to a vector
			preferenceVector.push_back(thePreference);
		}
		
	}
	void getPreference(int n)
	{
		for (int i = 0; i < size; i++)
		{
			if (preferenceVector[i].thePreference - '0' == n)
			{
				cout << preferenceVector[i].theCandidate.getName();
			}
		}
	}
};

class VoteCounter
{
public:
	
	Candidate calcLowest(vector<Candidate> whatsLeft)
	{
		int lowest = whatsLeft[0].theirCount;
		Candidate lowestCandidate;
		lowestCandidate.name = "";
		if (whatsLeft.size() ==1)
		{
			cout << whatsLeft[0].name << " wins!!";
			cout << whatsLeft[0].theirCount;
		}
		else
		{
			for (int i = 0; i < whatsLeft.size(); i++)
			{
				if (whatsLeft[i].theirCount <= lowest)
				{
					lowest = whatsLeft[i].theirCount;
					lowestCandidate = whatsLeft[i];
				}
			}
		}
		return lowestCandidate;
	}
	void reDistribute(vector<Candidate> &disqualified,Candidate theEliminatedCandidate,int round,vector<string> &theVoteBallots,vector<Candidate> &candidates)
	{
		//reset their counts
		for (int i = 0; i < candidates.size(); i++)
		{
			candidates[i].theirCount = 0;
		}
		//redistribute votes to all candidates 
		for (int i = 0; i < candidates.size(); i++)
		{
			for (int k = 0; k < candidates.size(); k++)
			{

				if (candidates[i].name == theEliminatedCandidate.name)
				{
					if (theEliminatedCandidate.theVotes[k] == 1)
					{

					}
				}
				else if (candidates[i].theVotes.at(k) == 1)
				{
					candidates[i].theirCount += 1;
				}
			}
		}














		/*for (int i = 0; i < theVoteBallots.size(); i++)
		{
			//if they have a vote that is = round+1...eg round 0 they have a 1 pref, needs to be reallocated
			//edit, if they have a vote of one,,,it needs to be redistributed
			if (theEliminatedCandidate.theVotes[i] == 1)
			{
				//save its position (vertically)
				int thePosition = i;
				//then get that row of ballots to search for next smallest (horizontal)
				string ballots = theVoteBallots[thePosition];
				int lowestPossibleNext = theVoteBallots[thePosition].at(0);
				int lowestPossiblePosition = 0;
				for (int k = 0; k < theVoteBallots[thePosition].length(); k++)
				{
					if (theVoteBallots[thePosition].at(k) < lowestPossibleNext)
					{
						lowestPossibleNext = theVoteBallots[thePosition].at(k);
						lowestPossiblePosition = k;
					}

				}
				candidates[lowestPossiblePosition-1].theirCount++;
			}

		}*/
	}
	VoteCounter()
	{

	}
	void countVotes(vector<Candidate> candidates,vector<string> ballots, vector<BallotPaper> ballotPapers)
	{
		int lowestPos;
		int thePosition = INT_MAX;
		vector <Candidate> whoIsLeft;
		vector<string> theVoteBallots = ballots;
		vector<Candidate> disqualified;
		Candidate lowestCandidate = candidates[0];
		int lowestCount = candidates[0].theirCount;
		int round = 0;
		//giving each candidate their respective counts
		for (int i = 0; i < candidates.size(); i++)
		{
			for (int k = 0; k < candidates.size(); k++)
			{
				if (candidates[i].theVotes.at(k) == 1)
				{
					candidates[i].theirCount += 1;
				}
			}
		}
		//minus one here because we want the last one as a winner BOYOOOOOOO
		for (int omega = 0; omega < ballots.size()-1; omega++)
		{
			cout << "round " << round << endl;
			lowestCandidate = calcLowest(candidates);
			for (int i = 0; i < candidates.size(); i++)
			{
				if (candidates[i].name == lowestCandidate.name)
				{
					lowestPos = i;
				}
			}
			cout << lowestCandidate.name << " Knocked out! " << endl;
			cout << "Their number of high preference votes: " << lowestCandidate.theirCount << endl;
			//push the first DQ on to the vector
			disqualified.push_back(lowestCandidate);
			reDistribute(disqualified, lowestCandidate, round, theVoteBallots, candidates);
			candidates.erase(candidates.begin() + lowestPos);
			round++;
		}
		lowestCandidate = calcLowest(candidates);
	}

};