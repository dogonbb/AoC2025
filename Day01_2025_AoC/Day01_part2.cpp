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
        bool oldPointZero = point == 0; 
        if (lines[i][0] == 'L') {
            point -= stoi(lines[i].substr(1)) ;
        } else {
            point += stoi(lines[i].substr(1)) ;
        }


        
        if (point <= 0) {
            count += abs(floor(double(point - 1)/100.0)); 
            if(oldPointZero) count -= 1; 
        }else if(point  >= 100 ) {
            count  += abs(floor(double(point)/100)); 
        }

        

        point = ((point % 100) + 100) % 100;


    }

    cout << count << endl;
}
