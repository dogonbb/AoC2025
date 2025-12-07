#include <bits/stdc++.h>
using namespace std;

long long light(vector<string> &lines, int x, int y, vector<vector<long long>> &memo)
{
    if (y == lines.size() - 1)
        return 1;
    if (x < 0 || x == lines[0].length())
        return 1;

    long long &sol = memo[y][x];

    if (sol != -1)
        return sol;

    if (lines[y + 1][x] != '^')
    {
        sol = light(lines, x, y + 1, memo);
        return sol;
    }
    sol = light(lines, x + 1, y + 1, memo) + light(lines, x - 1, y + 1, memo);
    return sol;
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

    int x, y;

    for (int i = 0; i < lines.size(); i++)
    {
        for (int j = 0; j < lines[i].size(); j++)
        {
            if (lines[i][j] == 'S')
            {
                x = j;
                y = i;
            }
        }
    }
    vector<vector<long long>> memo(lines.size(), vector<long long>(lines[0].size(), -1));
    long long total = light(lines, x, y, memo);

    cout << total;
}