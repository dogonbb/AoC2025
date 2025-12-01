#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("input.txt"); 

    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    int point = 50; 
    int count = 0; 

    for (int i = 0; i < (int)lines.size(); i++) {
        if (lines[i][0] == 'L') {
            point -= stoi(lines[i].substr(1)) ;
        } else {
            point += stoi(lines[i].substr(1)) ;
        }

        point = ((point % 100) + 100) % 100;
        

        if(point == 0) {
            count++;
        }

    }

    cout << count << endl;
}
