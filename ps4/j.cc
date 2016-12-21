#include <iostream>
#include <numeric>
#include <string>
#include <stdio.h>
using namespace std;
int arr[100];
int main()
{
    string num;
    int n,N;
    int digits=0;
    cin>>n;
    N=n;
    int i,j=0;
    while(n--){
        cin>>num;
        i=0;
        digits=num.size();
        bool there_is=false;
        bool S=false;
        for (int k = 0; k < num.size(); ++k)
        {
            arr[k]=num[k];
        }
        if(digits==1){
            cout<<"Case "<<(N-n)<< ": S"<<endl;
            continue;
        }
        for(i=0;i<digits;++i)
        {
            there_is=false;
            for (j = 0; j < digits; ++j)
            {
                if(arr[j]==0)
                    continue;
                if(! ((accumulate(arr,arr+digits,0)-arr[j])%3)){
                        arr[j]=0;
                        there_is=true;
                        break;
                    }
            }

            if(!there_is){
                break;
            }
        }

        if(!there_is){
            // this player has nth to remove, he lost
            if(!(i%2))
                cout<<"Case "<<(N-n)<< ": T"<<endl;
            else
                cout<<"Case "<<(N-n)<< ": S"<<endl;    
        }else{
            if(!(i%2))
                cout<<"Case "<<(N-n)<< ": T"<<endl;
            else
                cout<<"Case "<<(N-n)<< ": S"<<endl;
        }

    }
    return 0;
}

