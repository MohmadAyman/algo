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
    int n,d,N,M,node,Nclone,m,i=0;
    short roots=0;
    while(cin >> N >> m){
    M = m;
    M++;
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

    // for(int j=0;j<n+1;j++)visited[j]=false;

    // s.push(1);
    // int num=0;
    //        while(!s.empty()){
    //            num++;
    //            node=s.top();
    //            s.pop();
    //            if(visited[node]){
    //                break;
    //            }
    //            else{
    //                visited[node]=true;
	   //             for (int j = 0; j < adj[node].size(); ++j)
	   //             {
	   //                 s.push(adj[node][j]);
	   //             }
    //            }
    //        }

    //        if(num==N && (M+1)==N)
    //            cout<<"YES"<<endl;
    //        if(num!=N)
    //              cout<<"NO"<<endl;

            
    //     while (!s.empty())
    //       {
    //          s.pop();
    //       }    
    //       adj.clear();
    //     return 0;

    for (int j = 1; j < i; ++j)
    {
        root=true;
        for (int k = 1; k < i; ++k)
        {
            if(src[j]==dst[k]){
                root=false;
                break;
            }
        }
        if (root)
        {
            roots++;
            if(roots>1){
                no=true;
                break;
            }
        }
    }

    if (roots!=1){
        cout<<"NO"<<endl;
        // return 0;
    }

    for (int j = 0; j < m; ++j)
    {
        int a = src[j];
        int b = dst[j];
      for (int k = 0; k < m; ++k)
        {
            if (src[k]==b&&dst[k]==a)
            {
                cycle=true;
                break;
            }
        }        
        if (cycle)
        {
            break;
        }
    }

    if(cycle){
        cout<<"NO"<<endl;
        // return 0;
    }else{
	    cout<<"YES"<<endl;
	}
    // return 0;
    }

    return 0;
}
