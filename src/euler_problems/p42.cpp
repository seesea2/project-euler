/*

The nth term of the sequence of triangle numbers is given by, 
tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to 
its alphabetical position and adding these values we form a word value. 
For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. 
If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), 
a 16K text file containing nearly two-thousand common English words, 
how many are triangle words?


Answer:  162

*/

#include "1_99.h"

bool P42()
{
    try
    {
        // all [A-Z], index is sequence of its alphabetical position
        string chars;
        chars += '"';
        for (auto c = 'A'; c <= 'Z'; ++c)
            chars += c;

        // all words from input file.
        vector<string> words;
        ifstream ifs("./euler_problems/p42_words.txt", ifstream::in);
        string str;
        char delimeter = ',';
        while (getline(ifs, str))
        {
            // cout << str << endl
            //      << "================" << endl;
            while (!str.empty())
            {
                auto ind = str.find(delimeter);
                if (ind > 0 && ind < str.size())
                {
                    words.push_back(str.substr(1, ind - 2));
                    str = str.substr(ind + 1);
                }
                else
                {
                    words.push_back(str.substr(1, str.length() - 2));
                    str.clear();
                }
            }
        }
        ifs.clear();
        ifs.close();
        // for (auto &word : words)
        //     cout << word << endl;

        vector<int> triangle_nums;
        triangle_nums.push_back(0);

        int qty = 0;
        for (auto &word : words)
        {
            // cout << "word: " << word;
            int sum = 0;
            for (auto &c : word)
                sum += chars.find(c);

            // check if word is tn (triangle_number)
            size_t n = 0;
            do
            {
                n++;
                if (n >= triangle_nums.size() - 1)
                    triangle_nums.push_back(n * (n + 1) / 2);
                if (triangle_nums[n] == sum)
                {
                    qty += 1;
                    break;
                }
                if (triangle_nums[n] > sum)
                    break;
            } while (1);
        }

        cout << "Answer: " << qty << endl;
        return true;
    }
    catch (...)
    {
        cout << "Exception" << endl;
        return false;
    }
}