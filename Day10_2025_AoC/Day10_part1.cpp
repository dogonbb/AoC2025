#include <bits/stdc++.h>
using namespace std;

static const int INF = 1e9;

bool isCurrentTrue(vector<int> current, vector<int> wanted_state)
{
    for (int i = 0; i < current.size(); i++)
    {
        if (current[i] != wanted_state[i])
        {
            return false;
        }
    }
    return true;
}

int isCurrentKnown(unordered_map<string, int> &memory, vector<int> current)
{
    string toCheck = "";
    for (int i = 0; i < current.size(); i++)
    {
        toCheck += to_string(current[i]);
    }
    return memory[toCheck];
}

int onemove(unordered_map<string, int> &memory, vector<vector<int>> moves, vector<int> current, vector<int> wanted_state, int amount, int move)
{
    for (int i = 0; i < current.size(); i++)
    {
        current[i] = (current[i] + moves[move][i]) % 2;
    }
    amount++;

    if (isCurrentTrue(current, wanted_state))
        return amount;

    string toCheck = "";
    for (int i = 0; i < current.size(); i++)
    {
        toCheck += to_string(current[i]);
    }

    if (memory[toCheck] == -2)
        return INF;
    if (memory[toCheck] >= 0)
        return amount + memory[toCheck];

    memory[toCheck] = -2;

    int min = INF;
    for (int i = 0; i < moves.size(); i++)
    {
        int newmin = onemove(memory, moves, current, wanted_state, amount, i);
        if (newmin < min)
        {
            min = newmin;
        }
    }
    memory[toCheck] = (min == INF ? INF : (min - amount));
    return min;
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
    int sol = 0;
    for (int i = 0; i < lines.size(); i++)
    {
        stringstream ss(lines[i]);
        string word;
        int count = 0;

        vector<int> wanted_result;
        vector<vector<int>> moves;
        while (ss >> word)
        {
            if (count == 0)
            {
                for (int i = 1; i < word.size() - 1; i++)
                {
                    if (word[i] == '.')
                        wanted_result.push_back(0);
                    else
                        wanted_result.push_back(1);
                }
            }
            else if (word[0] == '(')
            {
                stringstream comma(word.substr(1, word.size() - 2));
                string word_comma_sep;
                vector<int> move(wanted_result.size(), 0);
                moves.push_back(move);
                while (getline(comma, word_comma_sep, ','))
                {
                    moves[moves.size() - 1][stoi(word_comma_sep)] = 1;
                }
            }
            count++;
        }
        unordered_map<string, int> memory;
        for (int i = 0; i < (1 << wanted_result.size()); ++i)
        {
            string word;
            for (int j = wanted_result.size() - 1; j >= 0; --j)
            {
                word += ((i >> j) & 1) ? '1' : '0';
            }
            memory[word] = -1;
        }
        vector<int> current;
        for (int i = 0; i < wanted_result.size(); i++)
        {
            current.push_back(0);
        }

        int min = INF;
        for (int i = 0; i < moves.size(); i++)
        {
            int newmin = onemove(memory, moves, current, wanted_result, 0, i);
            if (newmin < min)
            {
                min = newmin;
            }
        }
        sol += min;
        cout << i;
    }
    cout << sol;
}