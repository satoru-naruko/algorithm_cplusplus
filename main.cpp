#include <iostream>
#include <algorithm>
#include "calc_max_profit.h"
using namespace std;

static const int MAX=200000;

int main(){
    
    int R[MAX] ={};
    int n;

    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        cin >> R[i];
    }
    
    int maxv = -200000000;
    int minv = R[0];

    auto ans = calcMaxProfit(R, MAX);    

    cout << "***output***" << endl;
    cout << ans << endl;

    return 0;
}