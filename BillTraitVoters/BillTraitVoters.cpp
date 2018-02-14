// BillTraitVoters.cpp : Defines the entry point for the console application.
//
//Author: Bill Trait C00207805

#include "stdafx.h"
#include <iostream>
#include "VoteClasses.h"
#include <fstream> //input file stream for text input
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//method that creates candidate objects from data and puts them into a vector
void createCandidate(vector<string>& names, vector<string>& parties, vector<Candidate>& candidates)
{
	for (int i = 0; i < names.size(); i++)
	{
		Candidate candidate(names[i], parties[i]);
		candidates.push_back(candidate);
	}
}

//checks for ballot paper line or name/party
bool checkForName(string theSubject)
{
	bool isTrue = true;
	for (int i = 0; i < theSubject.length(); i++)
	{
		if (isdigit(theSubject[i]))
		{
			isTrue = false;
		}
	}
	return isTrue;
}

int main()
{
	ifstream inputFile;
	inputFile.open("Candidates.txt");
	vector<string> stringVector;
	vector<string> votesStringVector;
	vector<string> nameVector;
	vector<string> partyVector;
	vector<Candidate> candidateVector;
	vector<BallotPaper> ballotVector;
	int numberOfCandidates;
	int numberOfBallots;
	for (std::string line; getline(inputFile, line); )
	{
		//push to here if it is a name 
		if (checkForName(line) == true)
		{
			stringVector.push_back(line);
		}
		//otherwise put it to the votes array, for ballots
		else
		{
			votesStringVector.push_back(line);
		}
	}
	//loop through the vector of names/parties
	for (int i = 0; i < stringVector.size(); i++)
	{
		// i%2 here because each party is on an odd line 
		if (i % 2 == 0)
		{
			nameVector.push_back(stringVector[i]);
		}
		else
		{
			partyVector.push_back(stringVector[i]);
		}
	}

	//send candidates off for creation
	createCandidate(nameVector, partyVector, candidateVector);
	//this loop will create the ballots
	for (int i = 0; i < votesStringVector.size(); i++)
	{
		BallotPaper b = BallotPaper(votesStringVector.size(), votesStringVector[i], candidateVector);
		ballotVector.push_back(b);
	}
	//nested loop to input the votes onto vectors
	//first iteration for first vote line 1234
	for (int i = 0; i < votesStringVector.size(); i++)
	{
		for (int l = 0; l < candidateVector.size(); l++)
		{
			//iteration one
			//candidate vector[0] "gerry adams"
			//push onto the votes vector
			//the value of the ballotvector 0,0
			//then 0,1 etc
			candidateVector[l].theVotes.push_back(ballotVector[i].votes.at(l)- '0');
		}
	}
	VoteCounter voteController;
	voteController.countVotes(candidateVector,votesStringVector,ballotVector);


	std::cin.ignore();
    return 0;
}

