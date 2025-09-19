#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, head;
    cout << "Enter number of requests: ";
    cin >> n;

    cout << "Enter head position: ";
    cin >> head;

    cout << "Enter direction (left/right): ";
    string direction;
    cin >> direction;

    vector<int> requests(n);
    cout << "Enter requests: ";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    
    sort(requests.begin(), requests.end());

    vector<int> order;
    int seek_count = 0;
    int pos = lower_bound(requests.begin(), requests.end(), head) - requests.begin();

    if (direction == "right") {
        
        for (int i = pos; i < n; i++) {
            order.push_back(requests[i]);
            seek_count += abs(head - requests[i]);
            head = requests[i];
        }

    
        if (pos > 0) {
            seek_count += abs(head - requests[0]);
            head = requests[0];

            for (int i = 0; i < pos; i++) {
                order.push_back(requests[i]);
                seek_count += abs(head - requests[i]);
                head = requests[i];
            }
        }

    } else { 
        for (int i = pos - 1; i >= 0; i--) {
            order.push_back(requests[i]);
            seek_count += abs(head - requests[i]);
            head = requests[i];
        }

        
        if (pos < n) {
            seek_count += abs(head - requests[n - 1]);
            head = requests[n - 1];

            for (int i = n - 1; i >= pos; i--) {
                order.push_back(requests[i]);
                seek_count += abs(head - requests[i]);
                head = requests[i];
            }
        }
    }

    cout << "\nSeek Sequence: ";
    for (int r : order) cout << r << " ";
    cout << "\nTotal Seek Operations: " << seek_count << "\n";

    return 0;
}
