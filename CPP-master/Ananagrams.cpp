#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
	/*
	 * Obtain input and create the tokens.
	 * Store the values into the vector array.
	 */
	string line;
	vector<string> array;
	while(true)
	{
		getline(cin, line);
		stringstream os(line); //a standard string stream which parses line
		string temp; //a temporary string
		if(line == "#")
			break;
		while(os >> temp)
		{
			array.push_back(temp);
		}
	}
	/*
	 * Printing listings in vector
	 */
	/*
	 * Find the ananagrams
	 * array contains the list of words
	 */
	vector<string> temp;
	vector<string> temp1;
	vector<string> ananagrams;

	bool add_ananagram = false;

	for	(int i = 0; i < array.size(); i++ )
	{
		//Convert the string to character array and toLowerCase for comparison
		string word = array[i];
		vector<char> word_array;
		word_array.clear();
		//vector containing the characters of the word in sorted order
		for	(int n = 0; n < word.length(); n++)
		{
			char temp = tolower(word[n]);
			word_array.push_back(temp);
		}
		sort(word_array.begin(), word_array.end());

		temp.clear();

		bool flag1 = true;
		bool ana = true;

		for	(int i1 = 0; i1 < array.size(); i1++)
		{
			flag1 = true;

			if(array[i] == array[i1])
			{
				continue;
			}
			//convert the word that is going to be tested against the current word to vector
			//to lowercase

			string word1 = array[i1];
			vector<char> word1_array;
			word1_array.clear();
			//vector containing the characters of the word in sorted order
			for	(int n1 = 0; n1 < word1.length(); n1++)
			{
				char temp = tolower(word1[n1]);
				word1_array.push_back(temp);
			}
			sort(word1_array.begin(), word1_array.end());

			if(word_array.size() != word1_array.size())
			{
				continue;
			}else
			{
				for (int i3 = 0; i3 < word_array.size(); i3++)
				{
					if(!(word_array[i3] == word1_array[i3]))
					{
						flag1 = false;
						break;
					}
					flag1 = true;
				}
				if(flag1 == false)
				{
					ana = true;
				}
				else
				{
					ana = false;
					break;
				}
			}
		}
		if(ana == true)
		{
			ananagrams.push_back(array[i]);
			sort(ananagrams.begin(), ananagrams.end());
		}
	}
	for	(int i = 0; i < ananagrams.size(); i++)
	{
		cout << ananagrams[i] << endl;
	}
	return (0);
}
