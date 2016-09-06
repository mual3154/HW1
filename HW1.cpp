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



void getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords);
bool isCommonWord(string word, vector<string>& _vecIgnoreWords);
void printTopN(wordItem wordItemList[], int topN);
const int STOPWORD_LIST_SIZE = 50;

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
	cout << "Usage: ";
	cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
	cout << endl;
	return 0;
	}
	
	//end of parameter check --------------------------------------------------------------------
	int size = 100;
	wordItem *library = new wordItem [size];
	int range = stoi(argv[1]);
	string mainFile = argv[2];
	//string ignoreFile = argv[3];
	vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
	getStopWords(argv[3], vecIgnoreWords);
	string ind;
	int totwrds = 0;
	int unqwrds = 0;
	int v = 0;
	int aindex = 0;
	int dbscnt = 0;

	ifstream file;
	file.open(mainFile);
	while(file >> ind)
	{
		totwrds++;
		if(file.is_open())
		{
			bool a = isCommonWord(ind , vecIgnoreWords);
			if(a == false)
			{
				unqwrds++;
				for(int i = 0; i<=aindex; i++)
				{
					if(ind == library[i].word)
					{
						library[i].count++;
						v=1;//resets while loop
					}
				}
				if(v==0)//adds word if not in library
					{	
						library[aindex].word = ind;
						library[aindex].count = 1;
						aindex++;
					}
					for(int z=0;z<size;z++)//ensures that the library is in descending order
					{
						if (library[z+1].count > library[z].count)
						{
							int temp = 0;
							string tem;
							temp = library[z].count;
							library[z].count = library[z+1].count;
							library[z+1].count = temp;
							tem = library[z].word;
							library[z].word = library[z+1].word;
							library[z+1].word = tem;
						}
					}
				if (size <= aindex)//here we double
					{
						dbscnt++;
    					wordItem *newArray = new wordItem[2*size];

    					for (int i=0; i<size; i++)
    					{
        					newArray[i].count = library[i].count;
        					newArray[i].word = library[i].word;
    					}
    							size*=2;
    							delete[] library;
    							library = newArray;	    
					}
				
			}
		}
	v = 0;

	}
	
	
	printTopN(library, range);
	cout<<"#"<<endl;
	cout<<"Array doubled: "<<dbscnt<<endl;
	cout<<"#"<<endl;
	cout<<"Unique non-common words: "<<aindex<<endl;
	cout<<"#"<<endl;
	cout<<"Total non-common words: "<<unqwrds<<endl;
	
	file.close();
	delete[] library;

	return 0;

}

void getStopWords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords)

{
	int i = 0;
	string igword;
	ifstream ignore;
	ignore.open(ignoreWordFileName);
	while(ignore >> igword)
	{
		if(ignore.is_open())
	      {
            _vecIgnoreWords[i] = igword;
            i++;
	      }
	}
	ignore.close();
}

bool isCommonWord(string word, vector<string>& _vecIgnoreWords)

{
	for(int i = 0; i<STOPWORD_LIST_SIZE; i++)
	{
		if(word == _vecIgnoreWords[i])
		{
			return true;
		}
	}
	return false;
}

void printTopN(wordItem wordItemList[], int topN)

{
	for(int x = 0 ; x<topN ; x++)
	{
		cout << wordItemList[x].word << " - " << wordItemList[x].count << endl;
	}
	return;

}
