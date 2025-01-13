#include <bits/stdc++.h>

#define endl "\n";
#define PI 3.14;

using namespace std;
// tognoek begin
const int Nmax = 5005;
const int nMod = 1e9 + 7;
const long long N10e9 = 1000000005;
const int N10e7 = 10000005;
const int N10e6 = 1000005;
const int N10e5 = 100005;
const int N10e4 = 10005;
const int N10e3 = 1005;
vector<short> ArrSangNgto(N10e6 + 1, 0);
long long max(long long __xm, long long __ym)
{
    return __xm > __ym ? __xm : __ym;
}
long long min(long long __xm, long long __ym)
{
    return __xm < __ym ? __xm : __ym;
}

int Lamtron(double __xr)
{
    double k = (__xr - (int)(__xr));
    if (fabs(k) >= 0.5)
        return __xr >= 0 ? (int)(__xr + 1) : (int)(__xr - 1);
    else
        return (int)(__xr);
}

void swap(long long &__xs, long long &__ys)
{
    __xs = __xs + __ys;
    __ys = __xs - __ys;
    __xs = __xs - __ys;
}

long long Tonguoc(int __k)
{
    long long __s = 1;
    for (int __i = 2; __i <= int(sqrt(__k)); __i++)
        if (__k % __i == 0)
        {
            __s = __s + __i;
            if (__i != __k / __i)
                __s = __s + __k / __i;
        }
    return __s;
}

long long luythua(long long __k, int __x)
{
    long long __tmp;
    if (__x == 1)
        return __k % nMod;
    else
    {
        __tmp = luythua(__k, __x / 2) % nMod;
        if (__x % 2 == 0)
            return __tmp * __tmp % nMod;
        else
            return (__tmp * __tmp % nMod) * __k % nMod;
    }
}

void sangNgto()
{
    ArrSangNgto[0] = 1;
    ArrSangNgto[1] = 1;
    for (int __i = 2; __i * __i <= N10e6; __i++)
        if (ArrSangNgto[__i] == 0)
            for (int __t = __i * __i; __t <= N10e6; __t += __i)
                ArrSangNgto[__t] = 1;
}

int Binary_search(int ___Arr[], int ___lenArr, int ___target)
{
    int ___dot, ___dotLeft, ___dotRight;
    ___dotLeft = 1;
    ___dotRight = ___lenArr;
    ___dot = (___dotRight + ___dotLeft) / 2;
    while (___dot >= ___dotLeft && ___dot <= ___dotRight)
    {
        if (___Arr[___dot] == ___target)
            return ___dot;
        if (___Arr[___dot] > ___target)
            ___dotRight = ___dot - 1;
        else
            ___dotLeft = ___dot + 1;
        ___dot = (___dotRight + ___dotLeft) / 2;
    }
    return ___target != 0 ? 0 : -1;
}
long long luyThua(int ___k, int ___n)
{
    if (___n == 1)
        return ___k;
    if (___n % 2 == 1)
        return luyThua(___k * ___k, ___n / 2) * ___k;
    else
        return luyThua(___k * ___k, ___n / 2);
}
short lenInt(long long ___k)
{
    int ___res;
    ___res = 0;
    while (___k > 0)
    {
        ___res++;
        ___k = ___k / 10;
    }
    return ___res;
}
short getCharInt(long long ___k, int ___index)
{
    ___index = lenInt(___k) - ___index + 1;
    while (___index-- > 1)
        ___k = ___k / 10;
    return ___k % 10;
}
int soLuongDoiXungDauDuoi(long long __k)
{
    int ___res;
    ___res = 0;
    if (__k < 10)
    {
        return __k;
    }
    if (__k <= 100)
    {
        int ___x, ___y;
        ___x = __k / 10;
        ___y = __k % 10;
        if (___x <= ___y)
        {
            return ___x + 9;
        }
        else
        {
            return (___x - 1) + 9;
        }
    }

    return ___res;
}
long demUocDuog(long long __k)
{
    long long __n = abs(__k);
    int res = 0;
    for (int ___i = 1; ___i * ___i <= __n; ___i++)
    {
        if (__n % ___i == 0)
        {
            res++;
            if (__n / ___i != ___i)
                res++;
        }
    }
    return res;
}
short kiemTraNamNhuan(int __k)
{
    if ((__k <= 0) || (__k > 100000))
        return -1;
    else
    {
        if (((__k % 4 == 0) && (__k % 100 != 0)) || (__k % 400 == 0))
            return 0;
        else
            return 1;
    }
}
long long toHopChapKcuaN(int n, int __k, vector<vector<long long>> &__memo)
{
    // Nhớ tạo vecotr 2 chiều [n + 1, k + 1] phần tử giá trị -1
    if (__k == 0 || __k == n)
    {
        return 1;
    }
    if (__memo[n][__k] != -1)
    {
        return __memo[n][__k];
    }
    __memo[n][__k] = toHopChapKcuaN(n - 1, __k - 1, __memo) + toHopChapKcuaN(n - 1, __k, __memo);
    return __memo[n][__k];
}
void coutVip(double __k, int __n, bool __endl)
{
    cout << fixed << setprecision(__n) << __k;
    if (__endl)
        cout << endl else cout << " ";
}

bool kiemTraDoiXuong(long long ___k)
{
    if (___k < 0)
    {
        return false;
    }

    int __original = ___k;
    int __reversed = 0;

    while (___k != 0)
    {
        int __digit = ___k % 10;
        __reversed = __reversed * 10 + __digit;
        ___k /= 10;
    }

    return __original == __reversed;
}

bool kiemTraNguyenToCungNhau(long long ___x, long long ___y)
{
    for (int ___i = 2; ___i * ___i <= ___x; ___i++)
    {
        if (___x % ___i == 0)
        {
            if (___y % ___i == 0)
            {
                return false;
            }
            if (___y % (___x / ___i) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

long long power_mod(long long ___a, long long ___b, long long ___M) // Tính ___a^___b % ___M.
{
    if (___b == 0)
        return 1;
    if (___b == 1)
        return ___a;

    long long half = power_mod(___a, ___b / 2, ___M) % ___M;

    if (___b % 2 == 0)
        return (half * half) % ___M;
    else
        return (((half * half) % ___M) * ___a) % ___M;
}

long long modulo_inverse(int ___a, int ___M)
{
    return power_mod(___a, ___M - 2, ___M);
}

long long modulo_divide(long long ____a, long long ____b, long long ____c)
{
    long long inverse = modulo_inverse(____b, ____c);
    return (____a % ____c * inverse) % ____c;
}

long long binomial_coefficient_mod(long long ___n, long long ___k, long long ___M)
{
    if (___k > ___n)
        return 0;
    if (___k == 0 || ___k == ___n)
        return 1;

    vector<long long> fact(___n + 1, 1);
    for (int __i = 2; __i <= ___n; ++__i)
    {
        fact[__i] = (fact[__i - 1] * __i) % ___M;
    }

    long long numerator = fact[___n];
    long long denominator = (fact[___k] * fact[___n - ___k]) % ___M;

    return (numerator * modulo_inverse(denominator, ___M)) % ___M;
}
unsigned long long mod_inverse(long long a)
{
    unsigned long long res = 1;
    unsigned long long ex = nMod - 2;
    while (ex > 0)
    {
        if (ex % 2 == 1)
        {
            res = (res * a) % nMod;
        }
        a = (a * a) % nMod;
        ex /= 2;
    }
    return res;
}
bool isPrime(long long ___n)
{
    if (___n <= 1)
        return false;
    if (___n <= 3)
        return true;
    if (___n % 2 == 0 || ___n % 3 == 0)
        return false;

    for (long long ___i = 5; ___i * ___i <= ___n; ___i += 6)
    {
        if (___n % ___i == 0 || ___n % (___i + 2) == 0)
            return false;
    }

    return true;
}

bool doiXungInt(long long ___n)
{
    string ___s = to_string(___n);
    string ___ss = ___s;
    reverse(___ss.begin(), ___ss.end());
    return ___ss == ___s;
}

long long math(long long count, long long size)
{
    long long result;
    result = 0;
    if (count > 2)
    {
        result += (count * (count - 1) * (count - 2) / 6);
    }
    if (count > 1)
    {
        result += (count * (count - 1) / 2) * size;
    }
    return result;
}

// tognoek end

// Khai báo biến toàn cục
int a[N10e6];
long long a_long[N10e6];
short b[N10e6];
long long a2[N10e3][N10e3];
int e[35];
int er[9];
// tognoek

// solve
void solve()
{
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<pair<int, int>> b;
    vector<vector<long long>> a(n + 5, vector<long long>(m + 5));
    b.push_back(make_pair(1, 1));
    vector<int> x(n + 5, 0);
    vector<int> y(m + 5, 0);
    int r, t;
    r = 1;
    t = 1;
    x[1] = 1;
    y[1] = 1;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'D'){
            r = r + 1;
            b.push_back(make_pair(r, t));
            x[r]++;
            y[t]++;
        }else{
            t = t + 1;
            b.push_back(make_pair(r, t));
            x[r]++;
            y[t]++;
        }
    }
    vector<long long> row(n+5, 0);
    vector<long long> colum(m+5, 0);
    for (int i = 1; i <= n; i++){
        for (int t = 1; t <= m; t++){
            cin >> a[i][t];
            row[i] = row[i] + a[i][t];
            colum[t] = colum[t] + a[i][t];
        }
    }
    for (int i = 0; i < b.size(); i++){
        int u = b[i].first;
        int v = b[i].second;
        if (x[u] == 1){
            x[u]++;
            y[v]--;
            a[u][v] = 0 - row[u];
            row[u] += a[u][v];
            colum[v] += a[u][v];
        }else{
            y[v]++;
            x[u]--;
            a[u][v] = 0 - colum[v];
            row[u] += a[u][v];
            colum[v] += a[u][v];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int t = 1; t <= m; t++){
            cout << a[i][t] << " ";
        }
        if (n != i)
            cout << endl;
    }
}


// tognoek

// compare

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    bool tognoek;
    tognoek = false;
    // Đọc file
    if (tognoek)
    {
        freopen("canhnhau.inp", "r", stdin);
        freopen("canhnhau.out", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // tognoek
    int T;
    cin >> T;
    while (T--)
    {
        solve();
        cout << endl;
    }
    // tognoek
    return 0;
}