#include <bits/stdc++.h>
using namespace std;

/*
Some notes for my solution: 
This code doesn't return the complete solution for part2.
Through some investigations i found out that (at least in my input) there are no connections between dac -> fft (with my code from part1)
That means the only path possible is svr -> fft -> dac -> out
With my code from part1 (and the inverse graph of the input and then going backwards thats why there is a init of "g2") i found all paths from svr -> fft and dac -> out 
There were too many paths from fft -> dac for my part1 to run efficiently
However that meant i only needed code for the paths from fft -> dac which you can find here (by memo. the amount of paths from already seen nodes)
After that i could multiply the three amounts
*/


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
    unordered_map<string, vector<string>> g2;

    for (int i = 0; i < (int)lines.size(); i++)
    {
        stringstream first(lines[i]);
        string nodeFirst;
        int count = 0;
        string word1;
        while (first >> word1)
        {
            if (count == 0)
            {
                nodeFirst = word1.substr(0, (int)word1.size() - 1);
            }
            else
            {
                string word2;
                stringstream adj(word1);
                while (adj >> word2)
                {
                    g[nodeFirst].push_back(word2);
                    g2[word2].push_back(nodeFirst);
                }
            }
            count++;
        }
    }

    unordered_map<string,int> memo;

    vector<pair<string,bool>> q;
    q.push_back({"fft", false});

    while (!q.empty())
    {
        auto [current, processed] = q[q.size() - 1];
        q.pop_back();

        if (processed)
        {
            if (memo.count(current)) continue;

            if (current == "dac")
            {
                memo[current] = 1;
            }
            else
            {
                int total = 0;
                for (string u : g[current]) total += memo[u];
                memo[current] = total;
            }
        }
        else
        {
            if (memo.count(current)) continue;
            q.push_back({current, true});      
            for (int i = 0; i < (int)g[current].size(); i++)
            {
                string nxt = g[current][i];
                if (!memo.count(nxt)) q.push_back({nxt, false});
            }
        }
    }

    int currentPaths = memo["fft"];
    cout << currentPaths << endl;
}
