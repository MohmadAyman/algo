#include <iostream>

unsigned long long max_max(unsigned long long i, unsigned long long j){
  if(i>j)
    return i;
  return j;
}

void solve(int number, long* src, int array_size){
  unsigned long long v = 0;
  unsigned long dst[array_size+1];
  int result[array_size/2];
    dst[0] = 0;
    dst[1] = src[0];
    int j = 2;
    for (int i = 1; i < array_size; ++i)
    {
      dst[j] = max_max(src[i]+dst[j-2],dst[j-1]);
      j++;
    }
    int result_init = 0;
  unsigned long long vu = -1;
    for (int i = array_size; i > 0;)
    {
      if(dst[i]!=vu){
          while(dst[i-1]==dst[i])
          {
            i -=1;  
          }
           result[result_init] = i;
           result_init++;
           vu = dst[i];
           i = i-2;
        }
    }
    for (int i = 0; i < result_init; ++i)
    {
      v+=src[result[i]-1];
    }
    std::cout << "Case " << number<< ": "<< v << '\n';
}

int main (){
  long value;
  int numberoftests;
  int array_size;
  std::cin >> numberoftests;
  for (int i = 0; i < numberoftests; ++i)
  {
    std::cin>>array_size;
    long src[array_size];
    for (int i = 0; i < array_size; ++i)
    {
        std::cin>>value;
        src[i]=value;
    }
    solve(i+1 ,src, array_size);
  }
  return 0;
}