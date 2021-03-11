#include <iostream>
 
using namespace std;
 
int main()
{
    int n, a1, a2, a3, a, i, ans = 0, kol = 0;
 
    cin >> n >> a3 >> a2 >> a1;
 
    for (i = 3; i < n; i++)
    {
        cin >> a;
 
        if (a % 31 == 0 && i > 3)
            ans += i - 3;
        else
            ans += kol;
 
        if (a3 % 31 == 0)
            kol++;
 
        a3 = a2;
        a2 = a1;
        a1 = a;
    }
 
    cout << ans << endl;
 
    return 0;
}
