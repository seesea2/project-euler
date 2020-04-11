/*
Let us call an integer sided triangle with sides a ≤ b ≤ c barely acute 
if the sides satisfy a^2 + b^2 = c^2 + 1.

How many barely acute triangles are there with perimeter ≤ 25,000,000?

*/

#include "200_299.h"

bool P223()
{
    try
    {
        const uint64_t kMaxPerimeter = 25000000;
        uint64_t qty = 0;
        for (auto perimeter = kMaxPerimeter; perimeter > 1; --perimeter)
        {
            // assume edge: c > b >= a
            // perimeter = a + b + c  > c + c ==> c < perimeter / 2
            // perimeter = a + b + c  < c + c + c ==> c > perimeter / 3
            cout << "perimeter: " << perimeter << endl;
            for (auto c = perimeter / 2; c > perimeter / 3; --c)
            {
                // b + b >= a + b > c ==> b > c/2
                for (auto b = c - 1; b > c / 2; --b)
                {
                    auto a = perimeter - c - b;

                    // 2 * a * b < c*c + 1
                    if (a * a + b * b == c * c + 1)
                        qty += 1;
                }
            }
        }

        cout << "Answer: " << qty << endl;
        return true;
    }
    catch (...)
    {
        return false;
    }
}