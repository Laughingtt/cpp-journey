#include "iostream"
#include "vector"

using namespace std;

vector<int> primesc(unsigned int nb_primes)
{
    int n, i;
    vector<int> p;
    p.reserve(nb_primes);
    n = 2;

    while (p.size() < nb_primes)
    {
        bool s = false;
        for (size_t i = 0; i < p.size(); i++)
        {
            if (n % p[i] == 0)
            {
                s = true;
                break;
            }
        }
        if (!s)
        {
            p.push_back(n);
        }
        n++;
    }
    return p;
}

int main()
{
    vector<int> res = primesc(100);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}