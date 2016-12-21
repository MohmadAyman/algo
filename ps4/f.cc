#include <vector>
#include <iostream>
#include <numeric>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int src[20000];
int dst[20000];

int main()
{
    bool no,root,cycle=false;
    int n,d,N,Nclone,m,i=0;
    short roots=0;
    cin >> N >> m;
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
        return 0;
    }


    for (int j = 0; j < Nclone; ++j)
    {
        for (int k = 0; k < adj[j].size(); ++k)
        {
            if(find(adj[adj[j][k]].begin(),adj[adj[j][k]].end(),j)!=adj[adj[j][k]].end()){
                cycle=true;
                break;
            }            
        }
        if(cycle)
            break;
    }


    if(cycle){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;

    return 0;
}
