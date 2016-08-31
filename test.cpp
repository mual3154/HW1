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

int main(int argc, char* argv[])
{
	string ignoreWordFileName = argv[1];
	string line;
	ifstream infile;
	infile.open(ignoreWordFileName);
	vector<string> _vecIgnoreWords(50); 
	if(infile.is_open())
	{
		while(getline(infile, line))
		{
		cout << line << endl;
		_vecIgnoreWords.push_back(line);	
		}
	
	}
	else
	{
		cout << "File unable to open!" << endl;
	}
}
