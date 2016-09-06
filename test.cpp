nclude <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include <math.h>
#include <string>
#include <vector>


using namespace std;

//int check(string ind);
//int *dubs(int array[], int size, int number);
struct wordItem//structure for the words
{
	string word;
	int count;
};

void getStopwords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords);
void printTopN(wordItem *&wordItemList, int topN);
bool isCommonWord(string word, vector<string>& _vecIgnoreWords);
const int STOPWORD_LIST_SIZE = 50;


int main(int argc, char *argv[])
{
	int size = 100;//initialize array/size
	wordItem *library = new wordItem[size];//use later for doubling
	
	vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);
	int t = atoi(argv[1]);//This changes the command line argument to an integer
	getStopwords(argv[3], vecIgnoreWords);
	string ind;
	int totwrds = 0;//total words in document
	int unqwrds = 0;//total "unique" words
	int v=0;//
	int aindex=0;
	int dbscnt=0;

	
	ifstream file;
	file.open(argv[2]);
	while(file >> ind)
	{	
		totwrds = totwrds + 1;
		if(file.is_open())
		{
			bool a = isCommonWord(ind, vecIgnoreWords);
			if (a == false)//only continues if the word is unique
			{
				unqwrds++;
				for(int i = 0; i<=aindex; i++)//if the word is already in library the counter goes up
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
	v=0;

	}
	printTopN(library, t);
	cout<<"#"<<endl;
	cout<<"Array doubled: "<<dbscnt<<endl;
	//cout<<size<<endl;
	//cout<<totwrds<<endl;
	cout<<"#"<<endl;
	cout<<"Unique non-common words: "<<aindex<<endl;
	cout<<"#"<<endl;
	cout<<"Total non-common words: "<<unqwrds<<endl;
	
	file.close();
	delete[] library;
}


/*int check(string ind)
{
	if (ind == "the")
		return 1;
	if (ind == "be")
		return 1; 
	if (ind == "to")
		return 1; 
	if (ind == "of")
		return 1; 
	if (ind == "and")
		return 1; 
	if (ind == "a")
		return 1; 
	if (ind == "in")
		return 1; 
	if (ind == "that")
		return 1; 
	if (ind == "have")
		return 1; 
	if (ind == "i")
		return 1; 
	if (ind == "it")
		return 1; 
	if (ind == "for")
		return 1; 
	if (ind == "not")
		return 1; 
	if (ind == "on")
		return 1; 
	if (ind == "with")
		return 1; 
	if (ind == "he")
		return 1; 
	if (ind == "as")
		return 1; 
	if (ind == "you")
		return 1; 
	if (ind == "do")
		return 1; 
	if (ind == "at")
		return 1; 
	if (ind == "this")
		return 1; 
	if (ind == "but")
		return 1; 
	if (ind == "his")
		return 1; 
	if (ind == "by")
		return 1; 
	if (ind == "from")
		return 1; 
	if (ind == "they")
		return 1; 
	if (ind == "we")
		return 1; 
	if (ind == "say")
		return 1; 
	if (ind == "her")
		return 1; 
	if (ind == "she")
		return 1; 
	if (ind == "or")
		return 1; 
	if (ind == "an")
		return 1; 
	if (ind == "will")
		return 1; 
	if (ind == "my")
		return 1; 
	if (ind == "one")
		return 1; 
	if (ind == "all")
		return 1; 
	if (ind == "would")
		return 1; 
	if (ind == "there")
		return 1; 
	if (ind == "their")
		return 1; 
	if (ind == "what")
		return 1; 
	if (ind == "so")
		return 1; 
	if (ind == "up")
		return 1; 
	if (ind == "out")
		return 1; 
	if (ind == "if")
		return 1; 
	if (ind == "about")
		return 1; 
	if (ind == "who")
		return 1; 
	if (ind == "get")
		return 1; 
	if (ind == "which")
		return 1;
	if (ind == "go")
		return 1; 
	if (ind == "me")
		return 1;  
	return 0;}*/
void getStopwords(char *ignoreWordFileName, vector<string>& _vecIgnoreWords)
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
void printTopN(wordItem *&wordItemList, int topN)
{
	for (int i = 0; i < topN; ++i)
	{
		cout<<wordItemList[i].count<<"-"<<wordItemList[i].word<<endl;	
	}
}
