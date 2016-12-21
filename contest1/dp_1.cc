#include <iostream>
#include <algorithm>    // std::is_sorted, std::prev_permutation
#include <deque>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

std::deque<int> station;
std::vector<int> src;
int numberofcarots;
std::set<int> sett;


int numlist[]={2,5,7,3,4,6};
const int m = 7;

int LIS(int i, int pre){
  if(i==m)
    return 0;
  int choice1 = LIS(i+1,pre);
  int choics2 = 0;
  if (pre == m ||numlist[pre]<=numlist[i])
  {
    choics2 = LIS(i+1,i)+1;
  }
  return max(choics2, choice1);
}

const int MAX = 5;
int n =5;

int weights[MAX] = {10, 4, 20, 5, 7};
int benfit[MAX] = {10, 15, 3, 1, 4};
 
// called with knapsack(0, intialWeight)
int knapsack(int i, int reminder)   // aka 0/1 knapsack
{
    if(i == n)
        return 0;
 
    int choice1 = knapsack(i+1, reminder);
    int choice2 = 0;
 
    if(reminder >= weights[i])
        choice2 = knapsack(i+1, reminder - weights[i]) + benfit[i];
 
    return max(choice1, choice2);
}

string str1 = "abcdejhk";
string str2 = "bcdefghi";
int LCS(int i, int j)   // aka 0/1 knapsack
{
    if(i==str1.length() || j== str2.length())
        return 0;
 
    if(str1[i] == str2[j])
      return 1+LCS(i+1,j+1);

    int    choice1 = LCS(i+1,j);
    int    choice2 = LCS(i,j+1);
 
    return max(choice1, choice2);
}

int main (){
  std::cout << knapsack(0,10) << '\n';
  for (std::set<int>::iterator i = sett.begin(); i != sett.end(); ++i)
  {
    cout << *i;
  }
  std::vector<int> dst;
  int order;
  bool carotsChanged = false;
  
  std::cin >> numberofcarots;

  return 0;
}
 