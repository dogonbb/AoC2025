#include <bits/stdc++.h>
using namespace std;

int light(vector<string> &lines, int x, int y)
{
    if (y == lines.size() - 1)
        return 0;
    if (x < 0 || x == lines[0].length())
        return 0;

    if (lines[y][x] == '|')
        return 0;
    lines[y][x] = '|';

    if (lines[y + 1][x] != '^')
    {
        return light(lines, x, y + 1);
    }

    return light(lines, x + 1, y + 1) + light(lines, x - 1, y + 1) + 1;
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

    int total = light(lines, x, y);
    cout << total;
}