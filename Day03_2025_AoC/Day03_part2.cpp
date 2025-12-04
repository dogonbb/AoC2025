#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("input.txt");

    vector<string> lines;
    string line;
    while (getline(file, line))
    {
        lines.push_back(line);
    }

    unsigned long long amount = 0;

    for (int i = 0; i < lines.size(); i++)
    {

        int maxInd = 0 - 1;
        for (int j = 11; j >= 0; j--)
        {
            int max = 0;
            for (int k = maxInd + 1; k < lines[i].size() - j; k++)
            {
                if (max < lines[i][k] - '0')
                {
                    max = lines[i][k] - '0';
                    maxInd = k;
                }
            }
            unsigned long long mult = 1;
            for (int o = 0; o < j; o++)
            {
                mult *= 10;
            }
            amount += mult * max;
        }
    }
    cout << amount;
}