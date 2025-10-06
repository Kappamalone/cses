#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll inf = numeric_limits<ll>::max();

const ll N = 0;
ll n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // after writing out the bit strings, the pattern that jumps out is:
  // - difference of 1 bit -> xor is related to the idea of "difference"
  //
  // 00  
  // 01 <- 00 xor 01
  // 10 <- 01 xor 10
  // 11 <- 10 xor 01
  //
  // our xor value is just 1 bit - since we only require one difference
  // and it shifts from right to left to choose which bit is different from the previous string
  // this allows us to enumerate all 2^n bit strings efficiently
  //
  // ... turns out this is completely wrong, shoutout my roommate
  //
  // gray code is mapped from an input of sequential binary numbers
  //
  // eg: n = 2
  //   B     G
  // -----|-----
  //  00     00
  //  01     01
  //  10     11
  //  11     10
  //
  //  we have a box circuit thing take the inputs from B and maps it to G
  //  essentially, the msb in B is preserved in G, and every subsequent ith bit in 
  //  G is the i-1th bit xored with the ith bit. we can represent this as:
  //  i ^ (i >> 1)

  cin >> n;
  ll value = 0;
  for (int i = 0; i < (1 << n); ++i) {
    int value = (i ^ (i >> 1));
    for (int j = n - 1; j >= 0; --j) {
      cout << ((value >> j) & 1);
    }
    cout << "\n";
  }
}
