#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void scanDiskScheduling(vector<int> requests, int head, int diskSize, string direction) {
    vector<int> left, right;
    vector<int> seekSequence;
    int seekCount = 0;
    

    // if (direction == "left") {
    //     left.push_back(0);
    // } else if (direction == "right") {
    //     right.push_back(diskSize - 1);
    // }


    for (int req : requests) {
        if (req < head)
            left.push_back(req);
        else
            right.push_back(req);
    }


    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    
    if (direction == "left") {
        for (int i = left.size() - 1; i >= 0; i--) {
            seekSequence.push_back(left[i]);
            seekCount += abs(head - left[i]);
            head = left[i];
        }
        for (int i = 0; i < right.size(); i++) {
            seekSequence.push_back(right[i]);
            seekCount += abs(head - right[i]);
            head = right[i];
        }
    } else if (direction == "right") {
        for (int i = 0; i < right.size(); i++) {
            seekSequence.push_back(right[i]);
            seekCount += abs(head - right[i]);
            head = right[i];
        }
        for (int i = left.size() - 1; i >= 0; i--) {
            seekSequence.push_back(left[i]);
            seekCount += abs(head - left[i]);
            head = left[i];
        }
    }

    
    cout << "Seek Sequence: ";
    for (int pos : seekSequence) {
        cout << pos << " ";
    }
    cout << "\nTotal Seek Operations: " << seekCount << endl;
}

int main() {
    vector<int> requests = {14,20,29,40,50,110};
    int head = 29;
    int diskSize = 200;
    string direction = "right";  

    scanDiskScheduling(requests, head, diskSize, direction);

    return 0;
}
