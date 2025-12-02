#include <bits/stdc++.h>
using namespace std;

void printInt128(__int128 n)
{
    if (n == 0)
    {
        std::cout << "0";
        return;
    }

    std::string s;
    while (n > 0)
    {
        s.push_back('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    std::cout << s;
}

static bool isInvalid(string s)
{
    for (int i = 1; i <= s.size() / 2; i++)
    {
        vector<string> strings;
        for (int j = 0; j < s.size(); j += i)
        {
            strings.push_back(s.substr(j, i));
        }
        bool allEqual = true;
        for (int j = 1; j < strings.size(); j++)
        {
            if (strings[j] != strings[0])
            {
                allEqual = false;
            }
        }
        if (allEqual)
            return allEqual;
    }
    return false;
}

int main()
{
    ifstream file("input.txt");

    vector<string> lines;
    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    __int128 amount = 0;

    stringstream ss(lines[0]);
    string part;
    while (getline(ss, part, ','))
    {
        stringstream ss2(part);
        string part2;
        int count = 0;
        long long int bottom, top;
        while (getline(ss2, part2, '-'))
        {
            if (count == 0)
                bottom = stoll(part2);
            else
                top = stoll(part2);
            count++;
        }
        long long int current = bottom;
        while (current <= top)
        {
            if (isInvalid(to_string(current)))
            {
                amount += current;
            }
            current++;
        }
    }
    printInt128(amount);
}
