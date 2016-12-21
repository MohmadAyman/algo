#include <limits.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>    // std::min_element, std::max_element
#include <stdio.h>
std::vector<int> in;
using namespace std;

float distance(int x1, int y1, int x2, int y2){
  double x = x1 - x2; //calculating number to square in next step
  double y = y1 - y2;
  double dist;

  dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
  dist = sqrt(dist);                  

  return dist;
}

struct person{
  string name;
  int x;
  int y;
};
int main (){
  int N ,n , x1, y1, x2 ,y2;
  string s;
  person p;
  double sum;
  int cases = 0;
  std::cin >> N;
  while(N!=0){
    n = N*2;
    double mat[n][n];
    std::vector<person> v;
    for (int i = 0; i < n; ++i)
    {
      cin >> p.name >> p.x >> p.y;
      v.push_back(p);
    }

    for (int i = 0; i < n; ++i)
    {
      x1 = v[i].x;  y1 = v[i].y;
      for (int j = 0; j < n; ++j)
      {
        x2 = v[j].x;  y2 = v[j].y;
        if(x1==x2&&y1==y2){
          mat[i][j] = INT_MAX;
        }else{
             mat[i][j] = distance(x1,y1,x2,y2);
        }
      }
            sum += *std::min_element(&mat[i][0],&mat[i][n-1]);
    }
    ++cases;
   cout << "Case " << cases <<":"<< endl;
   for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
          cout << mat[i][j] << " ";      
        }
        cout << endl;
    }
    v.clear();
    cout << "Sum is " <<  sum << endl;
    cin>>N;  
  }
  return 0;
}
