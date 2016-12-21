#include <iostream>
#include <vector>

std::vector<int> in;
using namespace std;
int main (){
  int N;
  int n;
  while(std::cin >> N){
    if(N==0)
      break;
  bool zero = false;
  for (int i = 0; i < N; ++i)    
  {
     cin >> n;
      if(n!=0){
        in.push_back(n);
      }
      else{
        zero = true;
      }
  }
  if(zero && in.size()==0){
    cout << 0;
  }
  for (int i = 0; i < in.size(); ++i)
    {
      cout << in[i]; 
      if(i<(in.size()-1))
        cout << " ";
    }
    cout << endl;
    in.clear();
  }
  return 0;
}
