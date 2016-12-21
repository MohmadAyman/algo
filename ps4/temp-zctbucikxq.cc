#include <vector>
#include <iostream>
#include <numeric>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

int src[20000];
int dst[20000];
stack <int>s;
int main()
{
    bool no,root,cycle=false;
    int n,d,N,node,Nclone,m,i=0;
    short roots=0;
    while(cin >> N >> m){

     bool visited[10000];
    Nclone=N+1;
    std::vector< std::vector<int> > adj(N+1);

    while(m--)
    {
        cin>>n>>d;
        src[i]=n;
        dst[i]=d;
        adj[n].push_back(d);
        i++;
    }

    s.push(1);
    int num=0;
           while(!s.empty()){
               node=s.top();
               s.pop();
               for (int i = 0; i < adj[node].size(); ++i)
               {
                   s.push(adj[node][i]);
               }
               
               if(visited[node]){
                   break;
               }
               else{
                   visited[node]=true;
                   num++;
               }
           }

           if(num!=N || !s.empty())
                 cout<<"NO"<<endl;
           else
               cout<<"YES"<<endl;
            
        while (!s.empty())
          {
             s.pop();
          }    
          adj.clear();
    //     return 0;

    // for (int j = 1; j < i; ++j)
    // {
    //     root=true;
    //     for (int k = 1; k < i; ++k)
    //     {
    //         if(src[j]==dst[k]){
    //             root=false;
    //             break;
    //         }
    //     }
    //     if (root)
    //     {
    //         roots++;
    //         if(roots>1){
    //             no=true;
    //             break;
    //         }
    //     }
    // }

    // if (roots!=1){
    //     cout<<"NO"<<endl;
    //     return 0;
    // }

    // for (int j = 0; j < m; ++j)
    // {
    //     int a = src[j];
    //     int b = dst[j];
    //   for (int k = 0; k < m; ++k)
    //     {
    //         if (src[k]==b&&dst[k]==a)
    //         {
    //             cycle=true;
    //             break;
    //         }
    //     }        
    //     if (cycle)
    //     {
    //         break;
    //     }
    // }

    // if(cycle){
    //     cout<<"NO"<<endl;
    //     return 0;
    // }

    // cout<<"YES"<<endl;
    // return 0;
    }
    return 0;
}
