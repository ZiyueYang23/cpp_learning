#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int Function(vector<int>dist,int speed,int hoursBefore)
{
    unordered_set<double> a;
    int gap(0);
    double sum(0.0);
    for (int i(0); i < dist.size();i++)
    {
        sum += dist[i] / speed;
    }

    if(sum > (double)hoursBefore)
    {
        return -1;
    }
}

int main(void)
{
    return 0;
}