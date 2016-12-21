#include <iostream>

int min(int i, int j){
  if(i<j)
    return i;
  return j;
}

int min(int i, int j, int k){
  if(i<j)
    if(i<k)
      return i;
    if(j<k)
      return j;
    return k;
}

int memo[20000000];

int num_steps(long in){
  if(memo[in]!=0)
    return memo[in];
  if (in==1)
    return 0;
  if((!in%2)&&(!in%3)){
    // std::cout << "Case all " << in << '\n';
    memo[in] = min((num_steps(in/3)+1), (num_steps(in/2)+1), (1+num_steps(in-1)));
  return memo[in];
  }
    else if(!(in%3)){
        // std::cout << "case mod 3 "<<  in << '\n';
      memo[in] = min((num_steps(in/3)+1),(num_steps(in-1)+1));
  return memo[in];
  }
  else if(!(in%2)){
        // std::cout << "case mod 2 "<<  in << '\n';
    memo[in] = min((num_steps(in/2)+1),(num_steps(in-1)+1));
  return memo[in];
  }
  else{
    // std::cout << "case -1 "<<  in << '\n';
    memo[in] = num_steps(in-1);
    return memo[in];
  }
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