//Ques.20) Count trailing zeroes in factorial of a number.
//Sol.
#include <bits/stdc++.h>
using namespace std;
int findTrailingZeros(int n)
{
    if (n < 0)
        return -1;
    int count = 0;
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
    return count;
}
int main()
{
    int n = 100;
    cout << "Count of trailing 0s in " << 100 << "! is "<< findTrailingZeros(n);
    return 0;
}
