#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,head;
    cin >> n >> head;
    string direction;
    cin >> direction;
    string l="left";


    vector<int>v(n);
    for(int i=0; i<n; i++)
    {
        cin>> v[i];
    }

    sort(v.begin(),v.end());
    int mid;

    for(int i=0; i<n; i++)
    {
        if(v[i]>head)
        {
            mid=i;
            break;
        }
    }

    int seektime=0;
    if(direction==l)
    {


        mid--;

        for(int i=mid; i>=0; i--)
        {
            int x=abs(head-v[i]);

            head=v[i];
            seektime+=x;

        }
        mid++;
        for(int i=n-1; i>=mid; i--)
        {
            int x=abs(head-v[i]);

            head=v[i];
            seektime+=x;

        }
    }
    else
    {

          for(int i=mid; i<n; i++)
        {
            int x=abs(head-v[i]);
            head=v[i];
            seektime+=x;

        }


        for(int i=0; i<mid-1; i++)
        {
            int x=abs(head-v[i]);
            head=v[i];
            seektime+=x;

        }
    }
    cout << "total seektime: "<< seektime << endl;

}