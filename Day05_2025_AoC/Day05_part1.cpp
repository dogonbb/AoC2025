#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("input.txt");

    vector<string> lines;
    string line;
    int countEntries = 0;
    vector<long long> ranges;
    long long min = LLONG_MAX;
    long long max = 0;
    while (getline(file, line))
    {
        if (line.empty())
            break;
        stringstream ss(line);
        string part;
        int count = -1;
        while (getline(ss, part, '-'))
        {
            ranges.push_back(stoll(part));
            if (count == -1)
            {
                if (stoll(part) < min)
                    min = stoll(part);
            }
            else
            {
                if (stoll(part) > max)
                {
                    max = stoll(part);
                }
            }
            count++;
        }
        countEntries++;
    }
    int fresh = 0;
    while (getline(file, line))
    {
        long long current = stoll(line);

        for (int i = 0; i < ranges.size(); i += 2)
        {
            if (current >= ranges[i] && current <= ranges[i + 1])
            {
                fresh += 1;
                break;
            }
        }
    }

    cout << fresh;
}