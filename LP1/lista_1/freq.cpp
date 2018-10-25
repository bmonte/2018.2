#include <iostream>

using namespace std;

int func1(int n);
int func2(int lower, int upper);

int main()
{
    cout << func2(100, 250);
    cout << endl;
    //cout << frequency(2, 1, 20);
    return 0;
}

int func1(int n, int i)
{
    int count = 0, x = i;
    while (n > 0)
    {
        if (n % 10 == x)
            count++;

        n = n / 10;
    }
    return count;
}

int func2(int lower, int upper)
{
    // Initialize result
    int count = 0;
    // Count 2's in every number
    // from 2 to n
    for (lower; lower <= upper; lower++)
        count += func1(lower, 3);
    return count;
}
