#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pid[] = {"p1", "p2", "p3", "p4", "p5"};
    int priority[] = {2, 0, 3, 1, 4};
    int arrival[] = {0, 5, 12, 2, 9};
    int burst[] = {11, 28, 2, 10, 16};

    int n = 5;
    int start[5], finish[5], waiting[5], turnaround[5];
    bool completed[5] = {false};

    int time = 0, done = 0;
    vector<int> order;

    while (done < n)
    {
        int idx = -1;
        int bestPriority = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!completed[i] && arrival[i] <= time)
            {
                if (priority[i] < bestPriority)
                {
                    bestPriority = priority[i];
                    idx = i;
                }
            }
        }

        if (idx == -1)
        { // no process has arrived yet
            time++;
            continue;
        }

        start[idx] = time;
        finish[idx] = time + burst[idx];
        turnaround[idx] = finish[idx] - arrival[idx];
        waiting[idx] = turnaround[idx] - burst[idx];
        completed[idx] = true;
        time = finish[idx];
        order.push_back(idx);
        done++;
    }

    cout << left << setw(5) << "PID" << setw(10) << "Arrival"
         << setw(10) << "Burst" << setw(10) << "Priority"
         << setw(10) << "Start" << setw(10) << "Finish"
         << setw(12) << "Waiting" << setw(12) << "Turnaround" << "\n";

    double totalWT = 0, totalTAT = 0;
    for (int idx : order)
    {
        cout << left << setw(5) << pid[idx] << setw(10) << arrival[idx]
             << setw(10) << burst[idx] << setw(10) << priority[idx]
             << setw(10) << start[idx] << setw(10) << finish[idx]
             << setw(12) << waiting[idx] << setw(12) << turnaround[idx] << "\n";
        totalWT += waiting[idx];
        totalTAT += turnaround[idx];
    }

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << "\n";

    return 0;
}
