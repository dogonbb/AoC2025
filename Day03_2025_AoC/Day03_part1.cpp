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

    int amount = 0;

    for (int i = 0; i < lines.size(); i++)
    {
        int max = 0;
        int maxInd;
        for (int j = 0; j < lines[i].size() - 1; j++)
        {
            if (max < lines[i][j] - '0')
            {
                max = lines[i][j] - '0';
                maxInd = j;
            }
        }

        int max2 = 0;

        for (int j = maxInd + 1; j < lines[i].size(); j++)
        {
            if (max2 < lines[i][j] - '0')
            {
                max2 = lines[i][j] - '0';
            }
        }

        amount += max * 10 + max2;
    }
    cout << amount;
}