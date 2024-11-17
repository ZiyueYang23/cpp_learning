#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct MagicCircle
{
    int position;
    int energy;
};

int main()
{
    int n, c;
    cin >> n >> c;
    c--; // 将c转换为0-based索引

    vector<MagicCircle> circles(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> circles[i].position >> circles[i].energy;
    }

    // 按照位置排序
    sort(circles.begin(), circles.end(), [](const MagicCircle &a, const MagicCircle &b)
         { return a.position < b.position; });

    // dp[i] 代表从位置 i 关闭所有魔法阵的最小能量消耗
    vector<int> dp_left(n, INT_MAX);
    vector<int> dp_right(n, INT_MAX);

    // 从当前位置c出发，计算向左和向右关闭的能量损耗
    dp_left[c] = dp_right[c] = 0;

    // 计算从当前位置向左的最小损耗
    for (int i = c - 1; i >= 0; --i)
    {
        dp_left[i] = dp_left[i + 1] + (circles[c].position - circles[i].position) * circles[i].energy;
    }

    // 计算从当前位置向右的最小损耗
    for (int i = c + 1; i < n; ++i)
    {
        dp_right[i] = dp_right[i - 1] + (circles[i].position - circles[c].position) * circles[c].energy;
    }

    // 输出最终的结果
    int total_damage = dp_left[0] + dp_right[n - 1];
    cout << total_damage << endl;

    return 0;
}
