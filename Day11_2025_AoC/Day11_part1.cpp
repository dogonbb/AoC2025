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

    unordered_map<string, vector<string>> g;

    for (int i = 0; i < lines.size(); i++)
    {
        stringstream first(lines[i]);
        string nodeFirst;
        int count = 0;
        string word1;
        while (first >> word1)
        {
            if (count == 0)
            {
                nodeFirst = word1.substr(0, word1.size() - 1);
            }
            else
            {
                string word2;
                stringstream adj(word1);
                while (adj >> word2)
                {
                    g[nodeFirst].push_back(word2);
                }
            }

            count++;
        }
    }

    vector<string> q;
    int currentPaths = 0;

    q.push_back("you");

    while (!q.empty())
    {
        string current = q[q.size() - 1];
        q.pop_back();
        if (current == "out")
        {
            currentPaths += 1;
        }
        else
        {
            for (int i = 0; i < g[current].size(); i++)
            {
                q.push_back(g[current][i]);
            }
        }
    }
    cout << currentPaths;
}