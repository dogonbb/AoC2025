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

    for (int i = 0; i < ranges.size() - 2; i += 2)
    {
        for (int j = i + 2; j < ranges.size(); j += 2)
        {
            if (ranges[j] <= ranges[i] && ranges[j + 1] >= ranges[i] && ranges[j + 1] < ranges[i + 1])
            {
                ranges[i] = ranges[j + 1] + 1;
            }
            else if (ranges[j] > ranges[i] && ranges[j] <= ranges[i + 1] && ranges[j + 1] >= ranges[i + 1])
            {
                ranges[i + 1] = ranges[j] - 1;
            }
            else if (ranges[j] > ranges[i] && ranges[j + 1] < ranges[i + 1])
            {
                ranges.push_back(ranges[j + 1] + 1);
                ranges.push_back(ranges[i + 1]);
                ranges[i + 1] = ranges[j] - 1;
            }
            else if (ranges[j] <= ranges[i] && ranges[j + 1] >= ranges[i + 1])
            {
                ranges[i] = -1;
                ranges[i + 1] = -1;
            }
        }
    }

    unsigned long long allFreshFruits = 0;
    for (int i = 0; i < ranges.size(); i += 2)
    {
        if (ranges[i] != -1)
        {
            allFreshFruits += ranges[i + 1] - ranges[i] + 1;
        }
    }

    cout << allFreshFruits;
}