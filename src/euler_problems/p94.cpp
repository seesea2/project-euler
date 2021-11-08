/*Almost equilateral triangles

It is easily proved that no equilateral triangle exists 
with integral length sides and integral area. 
However, the almost equilateral triangle 5-5-6 has an area of 12 square units.

We shall define an almost equilateral triangle to be a triangle 
for which two sides are equal and the third differs by no more than one unit.

Find the sum of the perimeters of all almost equilateral triangles with integral 
side lengths and area and whose perimeters do not exceed one billion (1,000,000,000).

    Answer:  
*/

#include "1_99.h"

bool P97()
{
    try
    {
        const uint64_t perimeter_limit = 1000000000;

        uint64_t perimeter_sum = 0;
        for (uint64_t a = 1; a <= perimeter_limit / 3; a += 2)
        {
            if (a * 2 + (a + 1) <= perimeter_limit)
            {
                auto h1 = sqrt(a * a - (a + 1) * (a + 1) / 4);
                if (h1 == ceil(h1))
                    perimeter_sum += 2 * a + (a + 1);
            }

            if (a * 2 + (a - 1) <= perimeter_limit)
            {
                auto h2 = sqrt(a * a - (a - 1) * (a - 1) / 4);
                if (h2 == ceil(h2))
                    perimeter_sum += 2 * a + (a - 1);
            }
        }

        cout << "Answer: " << perimeter_sum << endl;
        return true;
    }
    catch (...)
    {
        return false;
    }
}