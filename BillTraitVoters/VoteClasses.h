//VoteClasses.h
//Author Bill Trait C00207805

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
			//Preference thePreference = Preference(votes[i], candidates[i]);
			//then push it on to a vector
			//preferenceVector.push_back(thePreference);
		}
	}
	void getPreference(int n)
	{
		for (int i = 0; i < votes.length(); i++)
		{
			if (votes.at(i) - '0' == n)
			{
				cout << candidates[i].name;
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
		//now loop thru candidates
		for (int i = 0; i < candidates.size(); i++)
		{
			//if current inspected candidate != one that was just eliminated
			if (candidates[i].name != theEliminatedCandidate.name)
			{
				//loop through their votes
				for (int k = 0; k < candidates[i].theVotes.size(); k++)
				{
					//if their is a 1 in their vote
					if (candidates[i].theVotes[k] == 1)
					{
						//increment their vote count
						candidates[i].theirCount++;
					}
				}
			}
			//however if the current candidate is the newly eleiminated candidate
			else if (candidates[i].name == theEliminatedCandidate.name)
			{
				//loop through their votes
				for (int j = 0; j < theEliminatedCandidate.theVotes.size(); j++)
				{
					//if they got a first preference
					if (theEliminatedCandidate.theVotes[j] == 1)
					{
						//get the position of that preference
						int thePos = j;
						//loop through the ballotsVector at the position
						for (int g = 0; g < theVoteBallots[j].length(); g++)
						{
							if (theVoteBallots[j].at(g) - '0' >1)
							{
								int votePos = g;
								candidates[g].theirCount++;
								break;
							}
						}
					}
				}
			}
		}
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
			cout << "Who is left?" << endl;
			for (int e = 0; e < candidates.size(); e++)
			{
				cout << candidates[e].name << " ";
				cout << candidates[e].theirCount << endl;
			}
			cout << "round " << round << endl;
			if (candidates.size() == 1)
			{
				break;
			}
			else
			{
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
			
		}
		lowestCandidate = calcLowest(candidates);
	}

};