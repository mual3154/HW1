#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

struct wordItem{
	string word;
	int count;
	
};


/*

* Function name: getStopWords

* Purpose: read stop word list from file and store into vector

* @param ignoreWordFile - filename (the file storing ignore words)

* @param _vecIgnoreWords - store ignore words from the file (pass by reference)

* @return - none

* Note: The number of words is fixed to 50

*/

void getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords);

/*

* Function name: isCommonWord

* Purpose: to see if a word is a common word

* @param word - a word (which you want to check if it is a common word)

* @param _vecIgnoreWords - the vector type of string storing ignore/common words

* @return - true (if word is a common word), or false (otherwise)

*/

bool isCommonWord(string word, vector<string>& _vecIgnoreWords);

/*

* Function name: printTopN

* Purpose: to print the top N high frequency words

* @param wordItemList - a pointer that points to an array of wordItems

* @param topN - the number of top frequency words to print

* @return none

*/

void printTopN(wordItem wordItemList[], int topN);

const int STOPWORD_LIST_SIZE = 50;

// ./a.out 10 HW1-HungerGames_edit.txt HW1-ignoreWords.txt

int main(int argc, char* argv[])
{
	
	// verify we have the correct # of parameters, else throw error msg & return
	
	if (argc != 4)
	
	{
	
	cout << "Usage: ";
	
	cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
	
	cout << endl;
	
	return 0;

	}
	//end of parameter check --------------------------------------------------------------------
	int range = stoi(argv[1]);
	string mainFile = argv[2];
	string ignoreFile = argv[3];
	cout << range << " " << mainFile << " " << ignoreFile << endl;
	vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
	getStopWords(ignoreFile, vecIgnoreWords);
	
	

/* **********************************

1. Implement your code here.

Read words from HW1-HungerGames_edit.txt, store and count the words.

2. Implement the three functions after the main() function seperately.

********************************** */
	return 0;

}

void getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords)

{
	string line;
	ignoreWordFileName.open(ignoreWordFileName);
	if(ignoreWordFileName.is_open())
	{
		while(getline(cin, line))
		{
		_vecIgnoreWords.push_back(line);	
		}
	
	}
	else
	{
		cout << "File unable to open!" << endl;
	}
	return;

}

bool isCommonWord(string word, vector<string>& _vecIgnoreWords)

{

	return true;

}

void printTopN(wordItem wordItemList[], int topN)

{
	for(int x = 0 ; x<topN ; x++){
		cout << wordItemList[x].word << " - " << wordItemList[x].count << endl;
	}
	return;

}
