#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cout<<"enter number of id: ";
    cin>>n;
    int arrival[n],bt[n],pid[n],wt[n],tat[n];
    cout<<"enter arrival: ";
    loop(i,n) cin>>arrival[i];
    cout<<"enter burst: ";
    loop(i,n) {pid[i]=i+1,cin>>bt[i];}
    int temp;

    loop(i,n){
        int pos;
        for(int j=i+1;j<n;j++){
            if(bt[j]<bt[i]){
                swap(pid[i],pid[j]);
                swap(bt[i],bt[j]);
                swap(arrival[i],arrival[j]);
            }
        }
    }
    loop(i,n){
        wt[i]=0;
        for(int j=0;j<i;j++){
            wt[i]+=bt[j];
        }
    }
    double avgWT=0,avgTAT=0;
    loop(i,n){
        tat[i]=bt[i]+wt[i];
        avgWT+=wt[i];
        avgTAT+=tat[i];

    }
    cout<<left<<setw(5)<<"PID"<<setw(10)<<"Arrival"<<setw(10)<<"Burst"<<setw(10)<<"Waiting"<<setw(10)<<"Turnaround"<<"\n";

    loop(i,n){
        cout<<"P"<<pid[i]<<setw(10)<<arrival[i]<<setw(10)<<bt[i]<<setw(10)<<wt[i]<<setw(10)<<tat[i]<<"\n";

    }
    cout<<"Average Waiting Time: "<<avgWT<<endl;
    cout<<"Average Turnaround Time: "<<avgTAT<<endl;
}
