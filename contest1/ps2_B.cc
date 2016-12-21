#include <iostream>

int main (){
  long value;
  int numberoftests,array_size,j;
  std::cin >> numberoftests;
  for (int i = 0; i < numberoftests; ++i)
  {
    j = 2;
    std::cin>>array_size;
    long src[array_size];
    long long dst[array_size+1];
    for (int i = 0; i < array_size; ++i)
    {
        std::cin>>value;
        src[i]=value;
    }
    dst[0] = 0;
    dst[1] = src[0];
    for (int i = 1; i < array_size; ++i)
    {
      dst[j] = std::max(src[i]+dst[j-2],dst[j-1]);
      j++;
    }
    std::cout << "Case " << i+1<< ": "<< dst[array_size] << '\n';
  }
  return 0;
}