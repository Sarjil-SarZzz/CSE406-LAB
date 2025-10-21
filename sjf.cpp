#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int pid[n], bt[n], wt[n], tat[n];
    float avg_wt = 0, avg_tat = 0;
    for(int i = 0; i < n; i++) {
        cout << "Enter burst time for process " << i+1 << ": ";
        cin >> bt[i];
        pid[i] = i + 1;
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }
    wt[0] = 0;
    for(int i = 1; i < n; i++) {
        wt[i] = 0;
        for(int j = 0; j < i; j++)
            wt[i] += bt[j];
    }
    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i = 0; i < n; i++)
        cout << "P" << pid[i] << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;

    cout << "\nAverage Waiting Time = " << avg_wt;
    cout << "\nAverage Turnaround Time = " << avg_tat << endl;
    return 0;
}
