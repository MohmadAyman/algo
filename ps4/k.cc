#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;

stack <int>s;

float solve(int x, int p)
{
    powers=0;
    for (int i = 2; i <= p; ++i)
    {
        powers+=1+pow(x,i);
        for (int j = 1; j < i; ++j)
            {
                powers+= i*pow(x,j);
            }    
    }
    return powers;
}

int main()
{
    int x,y;
    double powers;
    while(cin>>x){
        bool not_close=true;
        double guess=0.50;
        double result=0;
        powers=0;
        int arr[x];

        for (int i = 0; i < x; ++i)
        {
            cin>>y;
            arr[i]=y;
        }

        result=arr[0];
        while(not_close){
            for (int i = 1; i < x; ++i)
            {
                result+=arr[x]/pow((1+solve(guess,x)),i);
            }
            if (result>0)
            {
                guess*=2;
            }else{
                guess/=2;
            }
        }

    }
    return 0;
}
