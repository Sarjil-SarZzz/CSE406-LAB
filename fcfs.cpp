#include <iostream>
using namespace std;
int main() {
    int n, i;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], wt[n], tat[n];
    float avgwt = 0, avgtat = 0;
    cout << "Enter the Burst Time for each process:\n";
    for(i = 0; i < n; i++) {
        cout << "P" << i+1 << ": ";
        cin >> bt[i];
    }
    wt[0] = 0; // waiting time for first process is 0
    for(i = 1; i < n; i++) {
        wt[i] = 0;
        for(int j = 0; j < i; j++)
            wt[i] += bt[j];
    }
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avgwt += wt[i];
        avgtat += tat[i];
        cout << "P" << i+1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    avgwt /= n;
    avgtat /= n;
    cout << "\nAverage Waiting Time = " << avgwt;
    cout << "\nAverage Turnaround Time = " << avgtat << endl;
    return 0;
}
