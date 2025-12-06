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

    vector<vector<string>> numbers;

    for (int i = 0; i < lines.size() - 1; i++)
    {
        istringstream ss(lines[i]);
        string number;
        int count = 0;
        while (ss >> number)
        {
            if (i == 0)
            {
                numbers.push_back({});
            }
            numbers[count].push_back((number));

            count++;
        }
    }

    vector<int> lengthes;

    for (int i = 0; i < numbers.size(); i++)
    {
        int max = 0;
        for (int j = 0; j < numbers[i].size(); j++)
        {
            if (max < numbers[i][j].length())
            {
                max = numbers[i][j].length();
            }
        }
        lengthes.push_back(max);
    }

    vector<vector<string>> numbersReal;

    for (int i = 0; i < lines.size() - 1; i++)
    {
        int current = 0;
        for (int j = 0; j < lengthes.size(); j++)
        {
            if (i == 0)
                numbersReal.push_back({});
            numbersReal[j].push_back(lines[i].substr(current, lengthes[j]));
            current += lengthes[j] + 1;
        }
    }

    istringstream ss(lines[lines.size() - 1]);
    string op;
    int count = 0;
    long long result = 0;

    while (ss >> op)
    {
        long long sub_result;
        if (op == "*")
        {
            sub_result = 1;
        }
        else
        {
            sub_result = 0;
        }

        vector<string> new_numbers = {};

        for (int i = 0; i < lengthes[count]; i++)
        {
            new_numbers.push_back("");
        }

        for (int i = 0; i < lengthes[count]; i++)
        {
            for (int j = 0; j < numbersReal[count].size(); j++)
            {
                new_numbers[i] += numbersReal[count][j][i];
            }
        }

        for (int i = 0; i < new_numbers.size(); i++)
        {
            if (op == "*")
            {
                sub_result *= stoi(new_numbers[i]);
            }
            else
            {
                sub_result += stoi(new_numbers[i]);
            }
        }

        result += sub_result;
        count++;
    }
    cout << result;
}