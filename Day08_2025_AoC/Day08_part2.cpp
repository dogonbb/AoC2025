#include <bits/stdc++.h>
using namespace std;

struct PairDistance
{
    long double distance;
    int i;
    int j;
};

int find(vector<int> &uf, int node)
{
    if (uf[node] != node)
    {
        uf[node] = find(uf, uf[node]);
    }
    return uf[node];
}

bool unite(vector<string> lines, vector<int> &uf, vector<int> &size, int first, int second)
{
    int rootFirst = find(uf, first);
    int rootSecond = find(uf, second);
    if (rootFirst == rootSecond)
    {
        return false;
    }

    if (size[rootFirst] < size[rootSecond])
    {
        swap(rootFirst, rootSecond);
    }

    uf[rootSecond] = rootFirst;
    size[rootFirst] += size[rootSecond];

    if (size[rootFirst] == uf.size())
    {
        int count = 0;
        string number;
        stringstream ss(lines[first]);
        double nums[3];
        double nums2[3];
        while (getline(ss, number, ','))
        {
            nums[count] = stod(number);
            count++;
        }
        count = 0;
        stringstream ss2(lines[second]);
        while (getline(ss2, number, ','))
        {
            nums2[count] = stod(number);
            count++;
        }
        cout << "==================================================================" << endl;
        cout << std::fixed << std::setprecision(2) << (nums[0] * nums2[0]) << endl;
        cout << "==================================================================" << endl;
    }

    return true;
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

    vector<PairDistance> pairs;
    for (int i = 0; i < lines.size() - 1; i++)
    {
        for (int j = i + 1; j < lines.size(); j++)
        {
            int count = 0;
            string number;
            stringstream ss(lines[i]);
            double nums[3];
            double nums2[3];
            while (getline(ss, number, ','))
            {
                nums[count] = stod(number);
                count++;
            }
            count = 0;
            stringstream ss2(lines[j]);
            while (getline(ss2, number, ','))
            {
                nums2[count] = stod(number);
                count++;
            }

            PairDistance p;
            p.distance = sqrt((nums[0] - nums2[0]) * (nums[0] - nums2[0]) + (nums[1] - nums2[1]) * (nums[1] - nums2[1]) + (nums[2] - nums2[2]) * (nums[2] - nums2[2]));
            p.i = i;
            p.j = j;
            pairs.push_back(p);
            if (j % 100 == 0)
                cout << i << " " << j << endl;
        }
    }

    sort(pairs.begin(), pairs.end(), [](const PairDistance &a, const PairDistance &b)
         { return a.distance < b.distance; });

    vector<int> uf(lines.size());
    iota(uf.begin(), uf.end(), 0);
    vector<int> size(lines.size(), 1);

    for (int i = 0; i < pairs.size(); ++i)
    {
        if (i % 100 == 0)
            cout << i << endl;
        unite(lines, uf, size, pairs[i].i, pairs[i].j);
    }
}