#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, frames;
    cout << "Enter number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frames;

    queue<int> q;               
    unordered_set<int> s;       
    int pageFaults = 0;

    cout << "\nPage\tFrames\t\tStatus\n";
    cout << "---------------------------------\n";

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool fault = false;

       
        if (s.find(page) == s.end()) {
            fault = true;
            pageFaults++;
            if (s.size() == frames) {
                int oldest = q.front();
                q.pop();
                s.erase(oldest);
            }
            q.push(page);
            s.insert(page);
        }
        cout << page << "\t";
        vector<int> temp;
        queue<int> qtemp = q;
        while (!qtemp.empty()) {
            temp.push_back(qtemp.front());
            qtemp.pop();
        }
        for (int j = 0; j < temp.size(); j++)
            cout << temp[j] << " ";
        for (int j = temp.size(); j < frames; j++)
            cout << "- "; 
        cout << "\t";

        if (fault)
            cout << "Page Fault";
        else
            cout << "Hit";

        cout << endl;
    }
    cout << "---------------------------------\n";
    cout << "Total Page Faults = " << pageFaults << endl;

    return 0;
}

