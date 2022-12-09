#include "iostream"
using int128_t = __int128;
using uint128_t = unsigned __int128;

using namespace std;

inline void read(uint128_t &X)
{
    X = 0;
    int w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    if (w) X = -X;
}

void print(uint128_t x)
{
    if (!x) return ;
    if (x < 0) putchar('-'),x = -x;
    print(x / 10);
    putchar(x % 10 + '0');
}


int main(){
    cout << "hello world" << endl;
    auto a = static_cast<int> (10.11);
    cout << "a is " << a << endl;

    uint128_t b = static_cast<uint128_t>(2807614120560689152)<<64;
    print(b);
    cout << "b is " << b.value << endl; 
    return 0;
}