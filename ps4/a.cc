#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    int n;
    cin>>n;
    while(n--){
        cin>>s;
        for (int i=1; i <= s.size(); ++i)
        {
            if(s.size()%i == 0){
                bool not_a_seq=false;
                        for (int j=i; j < s.size(); ++j)
                        {
                            if(s[j] != s[j%i]){
                                not_a_seq=true;
                                break;
                                }
                        }

                        if(!not_a_seq){
                            cout<< i<<'\n';
                            if(n!=0)
                                cout <<'\n';
                            break;
                        }
                }
        }
    }
    return 0;
}