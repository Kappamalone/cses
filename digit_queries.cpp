#include <bits/stdc++.h>
#include <string>
#define ll long long

using namespace std;
const ll inf = numeric_limits<ll>::max();

const ll N = 0;
ll n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;

  while (t--) {
    ll idx;
    cin >> idx;

    std::cerr << "index: " << idx << "\n";

    // range = [idx begin, idx end]
    // base = power of 10 of the range we're considering
    ll base = 1;
    ll width = 1;
    ll start = 1;
    ll end = 9;
    ll start_idx = 1;
    ll end_idx = 9;

    while (!(idx >= start_idx && idx <= end_idx)) {
      ++width;
      start = end + 1;
      start_idx = end_idx + 1;

      base *= 10;
      end = end + (9 * base);
      // NOTE: i messed up the +1 before, a range from 10-99 is 90 numbers, not 89 for eg
      end_idx = end_idx + (end - start + 1) * width;

      // cerr << "start: " << start << " start_idx: " << start_idx << " end: " << end << " end_idx: " << end_idx << "\n";
    }

    ll full_number = base + static_cast<ll>((idx - start_idx) / width);
    ll digit = (idx - (start_idx)) % width;
    // cerr << "number: " << full_number << " digit: " << digit << " width: " << width << "\n";
    // cerr << "=================\n";
    cout << std::to_string(full_number)[digit] << "\n";
  }
}
