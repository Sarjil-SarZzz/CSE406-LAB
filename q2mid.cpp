#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, head;
    cin >> n >> head;
    vector<int> a(n);
    vector<bool> visited(n);
    int total_movement = 0;
    int current = head;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int idx = -1;
        int min_dist = INT32_MAX;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                int dist = abs(current - a[j]);
                if (dist < min_dist)
                {
                    min_dist = dist;
                    idx = j;
                }
            }
        }
        visited[idx] = true;
        total_movement+=min_dist;
        current=a[idx];
    }
    cout << total_movement << endl;
    return 0;
}
