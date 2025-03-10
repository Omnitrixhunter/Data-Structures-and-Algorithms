//Prime Factorization of a number N in O(logN). Not considering the precomputation time.
//Precompute the Smallest Prime Factor (SPF) or Least Prime for each number from 1 to N using the sieve function.
//SPF is the smallest prime number that divides a given number without leaving a remainder.
//We can use the precomputed SPF array to find the prime factorization of the given number.
//We do this by repeatedly dividing the number by its SPF until it becomes 1.
          
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define mod 1000000007
#define modd 998244353;

vector<int> least_prime(100001, 1); //Least Prime or Smallest Prime Factor

vector<int> prime_factorization(int x)
{
    vector<int> prime_factors;
    while (x != 1) {
        prime_factors.push_back(least_prime[x]);
        x = x / least_prime[x];
    }
    return prime_factors;
}


void leastPrimeFactor() {
    //Computation of Least Prime Factor upto 1e5 (100000)
    least_prime[0] = 0;
    for (int i = 2; i <= 100000; i++) {
        if (least_prime[i] == 1) {
            for (int j = i; j <= 100000; j += i)
                if (least_prime[j] == 1)
                    least_prime[j] = i;
        }
    }
}

void solve() {
    ll n; cin >> n;
    vector<int> prime_factors = prime_factorization(n);
    cout << n << " : ";
    for(auto pf : prime_factors){
      cout << pf << " ";
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    
    int t=1; cin >> t;
    leastPrimeFactor();
    while(t--) solve();
    return 0; 
}
