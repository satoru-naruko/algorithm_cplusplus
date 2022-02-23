#include<iostream>
#include<algorithm>
using namespace std;

int calcMaxProfit(const int* dataBuf, int dataBufSize)
{
    int maxv = -200000000;
    int minv = dataBuf[0];

    for (size_t i = 0; i < dataBufSize; i++)
    {
        maxv = max(maxv, dataBuf[i] - minv);
        minv = min(minv, dataBuf[i]);
    }
    
    cout << "***output***" << endl;
    cout << maxv << endl;
}