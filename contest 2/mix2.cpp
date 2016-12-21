#include <utility>
#include <iostream>
#include <algorithm>    // std::is_sorted, std::prev_permutation
#include <vector>

struct pair{
  int first;
  long second;
};

std::vector<int> price_vector;
std::vector<long> avilable_milk_vector;
std::pair <int, long> boo;
std::vector<pair> pairs_vector;

bool compare(pair a, pair b){
  return a.first<b.first;
}
int main (){
  pair boo;
  long milk_needed;
  int no_of_farmers;
  int price;
  long avilable_milk;
  long min_money_tobe_paid=0;
  int it = 0;
  std::cin >> milk_needed >> no_of_farmers;
  // pairs_vector.resize(no_of_farmers);
    for (long i = 0; i < no_of_farmers; ++i)
      {
              std::cin >> price >> avilable_milk;
              boo.first = price;
              boo.second = avilable_milk;
              pairs_vector.push_back(boo);        
      }
      std::sort(pairs_vector.begin(), pairs_vector.end(), compare);
      
      while(milk_needed!=0){
        if(milk_needed>pairs_vector[it].second){
          milk_needed -= pairs_vector[it].second;
          min_money_tobe_paid += pairs_vector[it].first * pairs_vector[it].second;        
        }else{
          min_money_tobe_paid += pairs_vector[it].first * milk_needed;
          std::cout << min_money_tobe_paid << std::endl; 
          break;
        }
        it++; 
      }
  return 0;
}
 