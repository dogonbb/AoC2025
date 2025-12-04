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
        for (int j = 0; j < lines[i].size(); j++)
        {
            if (lines[i][j] != '@')
            {
                continue;
            }
            int count = 0;
            if (j > 0 && lines[i][j] == lines[i][j - 1])
            {
                count++;
            }
            if (j < lines[i].size() - 1 && lines[i][j] == lines[i][j + 1])
            {
                count++;
            }
            if (i > 0 && lines[i][j] == lines[i - 1][j])
            {
                count++;
            }
            if (i < lines.size() - 1 && lines[i][j] == lines[i + 1][j])
            {
                count++;
            }
            if (i > 0 && j > 0 && lines[i][j] == lines[i - 1][j - 1])
            {
                count++;
            }
            if (i > 0 && j < lines[i].size() - 1 && lines[i][j] == lines[i - 1][j + 1])
            {
                count++;
            }
            if (i < lines.size() - 1 && j > 0 && lines[i][j] == lines[i + 1][j - 1])
            {
                count++;
            }
            if (i < lines.size() - 1 && j < lines[i].size() - 1 && lines[i][j] == lines[i + 1][j + 1])
            {
                count++;
            }
            if (count < 4)
            {
                amount++;
            }
        }
    }
    cout << amount;
}