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

    long long max = 0;

    for (int i = 0; i < lines.size() - 1; i++)
    {
        for (int j = i + 1; j < lines.size(); j++)
        {
            int count = 0;
            string number;
            stringstream ss(lines[i]);
            long long nums[2];
            long long nums2[2];
            while (getline(ss, number, ','))
            {
                nums[count] = stoll(number);
                count++;
            }
            count = 0;
            stringstream ss2(lines[j]);
            while (getline(ss2, number, ','))
            {
                nums2[count] = stoll(number);
                count++;
            }

            long long dis_x = abs(nums[0] - nums2[0]) + 1;
            long long dis_y = abs(nums[1] - nums2[1]) + 1;

            if (dis_x * dis_y > max)
                max = dis_x * dis_y;
        }
    }

    cout << max;
}