/*Largest exponential 
Comparing two numbers written in index form like 211 and 37 is not difficult, 
as any calculator would confirm that 211 = 2048 < 37 = 2187.
However, confirming that 632382^518061 > 519432^525806 would be much more difficult, 
as both numbers contain over three million digits.
Using base_exp.txt (right click and 'Save Link/Target As...'), 
a 22K text file containing one thousand lines with a base/exponent pair on each line, 
determine which line number has the greatest numerical value.
NOTE: The first two lines in the file represent the numbers in the example given above.

    Answer:  709
*/

#include "1_99.h"

bool P99()
{
    try
    {
        vector<string> lines;
        ifstream ifs("./euler_problems/p99_base_exp.txt", ifstream::in);
        string str;
        while (getline(ifs, str))
            lines.push_back(str);
        ifs.clear();
        ifs.close();

        int best_base = 0;
        int best_exponent = 0;
        size_t best_ind = 0;

        for (size_t i = 0; i < lines.size(); ++i)
        {
            auto ind = lines[i].find(',');
            auto base = stoi(lines[i].substr(0, ind));
            auto exponent = stoi(lines[i].substr(ind + 1));
            cout << base << " - " << exponent << endl;

            if (best_base == 0 ||
                exponent * log(base) > best_exponent * log(best_base))
            {
                best_base = base;
                best_exponent = exponent;
                best_ind = i + 1;
            }
        }
        cout << "best_base: " << best_base << endl;
        cout << "best_exponent: " << best_exponent << endl;
        cout << "Answer: " << best_ind << endl;

        return true;
    }
    catch (...)
    {
        return false;
    }
}