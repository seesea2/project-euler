// Names scores
/*
	Using names.txt (right click and 'Save Link/Target As...'), a 46K text file 
	containing over five-thousand first names, begin by sorting it into alphabetical order. 
	Then working out the alphabetical value for each name, multiply this value by 
	its alphabetical position in the list to obtain a name score.

	For example, when the list is sorted into alphabetical order, COLIN, 
	which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. 
	So, COLIN would obtain a score of 938 x 53 = 49714.

	What is the total of all the name scores in the file?

	Answer:
	871198282
*/

#include "1_99.h"

bool P22()
{
	try
	{
		vector<string> name_array;
		string str;

		ifstream ifs("./euler_problems/p22_names.txt", ios::in);
		while (ifs.good())
		{
			getline(ifs, str, ',');
			if (str.empty())
				break;

			name_array.push_back(str);
		}
		ifs.clear();
		ifs.close();

		cout << "Qty of names : " << name_array.size() << endl;
		sort(name_array.begin(), name_array.end());

		BigNumber sum_name_scores, name_score;
		auto it = name_array.begin();
		int ind = 0;
		while (it != name_array.end())
		{
			++ind;
			str = it->data();
			name_score = BigNumber(0);
			for (auto &c : str)
			{
				if (c >= 'A' && c <= 'Z')
					name_score += c - 'A' + 1;
				else if (c >= 'a' && c <= 'z')
					name_score += c - 'a' + 1;
			}
			name_score *= ind;

			sum_name_scores += name_score;

			// cout << "Processd name : " << str << " - " << ind << endl;
			++it;
		}

		cout << endl
			 << "Total name scores : " << sum_name_scores << endl
			 << endl;
		return true;
	}
	catch (...)
	{
		return false;
	}
}