#include <iostream>
#include <unordered_set>
using namespace std;
 int GETSUM(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += n % 10 * n % 10;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while(true)
        {
            int sum = GETSUM(n);
            if(sum == 1)
            {
                cout << sum << "1#";
                return true;
            }
            if(set.find(sum) != set.end())
            {
                cout << sum << "2#";
                return false;
            }
            else
            {
                cout << sum << "3#";
                set.insert(sum);
            }
            n = sum;
        }
    }
