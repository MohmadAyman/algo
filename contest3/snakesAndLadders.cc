#include <vector>
#include <iostream>
#include <numeric>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <list>
using namespace std;

int board[101]; // postion, adj list
int dist[101];

int board_old[100][100]; // postion, adj list
std::vector<int> adj(100);

// each square has six adjecent squares, ecept the last 5 squares

int main()
{
    int T,N,M,s,d;
    cin >> T;
    while(T!=0){
        T--;
        bool *visited = new bool[101];
        int num=0;
        cin>>N;

        if(N<1||N>15){
            cout<< "Error";
            break;
        }

        for (int i = 0; i < 101; ++i)
        {
            board[i]=0;
        }

        board[101]=-1;

        board[100]=-1;

        for (int i = 0; i < N; ++i)
        {
            cin>>s>>d;
            board[s]=d;
        }
    
        cin>>M;
        for (int i = 0; i < M; ++i)
        {
            cin>>s>>d;
            board[s]=d;
        }
        for(int i = 0; i < 101; i++)
            visited[i] = false;
        
        list<int> queue;
     
        visited[1] = true;
        queue.push_back(1);

        while(!queue.empty()){
            int q = queue.front();
            // cout << q << endl;
            if(board[q]==-1){
                // cout << "num of q = -1";
                num=dist[q];
                break;
            }

            queue.pop_front();

                for(int i = q+1; i <= q+6 && i<101; ++i)
                {
                    if(!visited[i])
                    {
                        visited[i] = true;
                        dist[i]=dist[q]+1;

                        if (board[i]!=0)
                        {
                            // cout << "Ladder or a snake "  << board[i] << endl;
                            queue.push_back(board[i]);
                        }else{
                            queue.push_back(i);
                        }
                    }
                }
        }

        queue.clear();

            cout << dist[100];
        
        if(num){
            cout << dist[100];
        }else{
            cout<<-1;
        }
    }
    return 0;
}
