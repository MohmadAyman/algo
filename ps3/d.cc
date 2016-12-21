#include <iostream>
#include <vector>

std::vector<int> in;

using namespace std;
int main (){
  int N;
  int n;
  char c;
  int cases = 0;
  bool constrain_exists = false;
  char best_char = 'A';
  std::cin >> N;
  while(N--){
   cin >> n;
    if(!n)
      break;
    char mat[n][n];
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        cin >> c;
        mat[i][j] = c;      
      }
    }

  for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if(mat[i][j]=='.'){
          best_char = 'A';
          if(i>0){
            if(mat[i-1][j]==best_char)
              constrain_exists=true;
          }
          if(i<(n-1)){
            if(mat[i+1][j]==best_char)
              constrain_exists=true;
          }
          if(j>0){
            if(mat[i][j-1]==best_char)
              constrain_exists=true;
          }
          if(j<(n-1)){
            if(mat[i][j+1]==best_char)
              constrain_exists=true;
          }

          while(constrain_exists){
            ++best_char;
            constrain_exists = false;
            if(i>0){
              if(mat[i+1][j]==best_char)
                constrain_exists=true;
            }
            if(i<(n-1)){
              if(mat[i-1][j]==best_char)
                constrain_exists=true;
            }
            if(j>0){
              if(mat[i][j-1]==best_char)
                constrain_exists=true;
            }
            if(j<(n-1)){
              if(mat[i][j+1]==best_char)
                constrain_exists=true;
            }
          }
          mat[i][j] = best_char; 
        }     
      }
    }

   ++cases;
   cout << "Case " << cases <<":"<< endl;
   for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
          cout << mat[i][j] ;      
        }
        cout << endl;
      }
    }
  return 0;
}
