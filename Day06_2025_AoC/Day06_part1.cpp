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

    vector<vector<int>> numbers;

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
            numbers[count].push_back(stoi(number));

            count++;
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
        for (int i = 0; i < numbers[count].size(); i++)
        {
            if (op == "*")
            {
                sub_result *= numbers[count][i];
            }
            else
            {
                sub_result += numbers[count][i];
            }
        }
        result += sub_result;
        count++;
    }
    cout << result;
}