#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int fuel=0, start=0, loss=0;
        for(int i=0;i<n;i++){
            fuel+=(p[i].petrol-p[i].distance);
            if(fuel<0){
                loss+=fuel;
                fuel=0;
                start=i+1;
            }
        }
        return (fuel+loss>=0) ? start : -1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}