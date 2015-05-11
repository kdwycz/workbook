// http://www.slyar.com/blog/poj-1019-cpp.html
 
#include <iostream>
#include <cmath>
 
using namespace std;
 
unsigned int a[31270], s[31270];
 
/* 打表 */
void reset()
{
    int i;
    a[1] = 1;
    s[1] = 1;
    for(i = 2; i < 31270; i++)
    {
        /* 每一组数字都比上一组长 (int)log10((double)i) + 1 */
        a[i] = a[i-1] + (int)log10((double)i) + 1;
        s[i] = s[i-1] + a[i];
    }
}
 
/* 计算 */
int work(int n)
{
    int i = 1;
    int length = 0;
 
    /* 找到 n 所在的组 */
    while (s[i] < n) i++;
 
    /* n 在该组的下标 */
    int pos = n - s[i-1];
 
    /* length: n指向的数字的最后一位的下标 */
    for (i = 1; length < pos; i++)
    {
        length += (int)log10((double)i) + 1;
    }
 
    /* 去掉所求位后面的数字然后取余 */
    /* i: n指向的数字 + 1 */
    return ((i-1) / (int)pow((double)10, length - pos)) % 10;
}
 
int main()
{
    int t;
    unsigned int n;
    reset();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << work(n) << endl;
    }
    //system("pause");
    return 0;
}
