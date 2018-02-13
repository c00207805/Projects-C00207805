#pragma once
#include "VoteClasses.h"
#include "string"
#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include "BillTraitVoters.cpp"






/*for (int i = 0; i < candidates.size(); i++)
{
bool isDQ = false;
for (int k = 0; k < disqualified.size(); k++)
{
//if the candidate is not disqualified
if (candidates[i].name != disqualified[k].name)
{
whoIsLeft.push_back(candidates[i]);
break;
}
else
{
break;
}
}
}*/












//might need this for later.....
/*
//round one knockout
cout << "round " << round<<endl;
for (int i = 0; i < candidates.size(); i++)
{
if (candidates[i].theirCount <= lowestCount)
{
lowestCount = candidates[i].theirCount;
lowestCandidate = candidates[i];
lowestPos = i;
}
}
cout << lowestCandidate.name << " Knocked out! " << endl;
//push the first DQ on to the vector
disqualified.push_back(lowestCandidate);
candidates.erase(candidates.begin()+lowestPos);
//their votes because i want to check through them
for (int i = 0; i < disqualified[round].theVotes.size(); i++)
{
//if they have a vote that is = round+1...eg round 0 they have a 1 pref, needs to be reallocated
if (disqualified[round].theVotes[i] == round + 1)
{
thePosition = i;
for (int k = 0; k < theVoteBallots[thePosition].length(); k++)
{
if (theVoteBallots[k].at(0)-'0' == round+1 )
{
candidates[thePosition].theirCount++;
}
}
}

}

//round 2 time
//minus 1 here because first round already done

lowestCandidate = calcLowest(candidates);
for (int i = 0; i < candidates.size(); i++)
{
if (candidates[i].name == lowestCandidate.name)
{
lowestPos = i;
}
}
cout << lowestCandidate.name << " Knocked out! " << endl;
disqualified.push_back(lowestCandidate);
candidates.erase(candidates.begin() + lowestPos);

//round 3 time
//minus 1 here because first round already done

lowestCandidate = calcLowest(candidates);
for (int i = 0; i < candidates.size(); i++)
{
if (candidates[i].name == lowestCandidate.name)
{
lowestPos = i;
}
}
cout << lowestCandidate.name << " Knocked out! " << endl;
disqualified.push_back(lowestCandidate);
candidates.erase(candidates.begin() + lowestPos);
cout << "hello";






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






//lowestCandidate = calcLowest(candidates);*/
/*class BallotPaper
{
private:
public:
	//this variable is the votes for the ballot eg 1243
	string votes;
	int size;
	vector<Candidate> candidates;
	BallotPaper()
	{

	}
	BallotPaper(int theSize, string theVotes, vector<Candidate> theCandidates)
	{
		size = theSize;
		votes = theVotes;
		candidates = theCandidates;

	}
};*/