#include <iostream>

int memo[20000000];

int num_steps(long in){
  if(memo[in]!=0)
    return memo[in];

  if (in==1)
    return 0;

  int minimum = num_steps(in-1)+1;

  if(!(in%3))
      minimum = std::min((num_steps(in/3)+1), minimum);
  if(!(in%2))
    minimum = std::min((num_steps(in/2)+1), minimum);
  
  memo[in] = minimum;
  return minimum;
}

int main (){
  long value;
  int numberoftests,array_size,j;
  std::cin >> numberoftests;
  for (int i = 0; i < numberoftests; ++i)
  {
    std::cin>>value;
    std::cout << "Case " << i+1<< ": " << num_steps(value) <<  '\n';
  }
  return 0;
}