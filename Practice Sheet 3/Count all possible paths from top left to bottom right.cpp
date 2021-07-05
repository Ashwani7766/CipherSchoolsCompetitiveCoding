//Ques.4) Count all possible paths from top left to bottom right.
//Sol.
#include <iostream>
using namespace std;
int numberOfPaths(int m, int n)
{
    if (m == 1 || n == 1)
        return 1;
    return numberOfPaths(m - 1, n) + numberOfPaths(m, n - 1);
}
 int main()
{
    cout << numberOfPaths(3, 3);
    return 0;
}
