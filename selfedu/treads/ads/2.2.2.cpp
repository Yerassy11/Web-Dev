#include <iostream>

int main(void)
{
    using namespace std;
    // здесь пишите программу
    char ar[7];
    ar[0]='a';ar[1]='b';ar[2]='c';ar[3]='d';ar[4]='e';ar[5]='f';ar[6]='g';
    for (int i=0;i<7;i++){
        if(ar[i]=='b'){
            ar[i+1]='#';
        }
        ar[i]=ar[i+1];
        
    }

    

    __assertion_tests(ar);    // эту строчку не убирать (должна стоять перед return 0)
    return 0;
}