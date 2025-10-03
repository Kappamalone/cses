#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll inf = numeric_limits<ll>::max();

const ll N = 0;
ll n;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // palindrome is formed in one of two cases:
  // - all letters occur an even number of times
  // - one letter occurs an odd number of times, rest appear an even number of times
  
  // some examples:
  // baaab
  // racecar
  // a
  // aaabaaa

  std::string str;
  cin >> str;

  std::vector<int> occ(26, 0);
  for (int i = 0; i < str.size(); ++i) {
    ++occ[str[i] - 'A'];
  }

  int odds = 0;
  for (const auto& o: occ) {
    if (o & 1) ++odds;
  }

  if (odds > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }

  // alternatively, could use left and right pointer into a std::stiring

  // print first half
  for (int i = 0; i < occ.size(); ++i) {
    if (occ[i] && !(occ[i] & 1)) {
      for (int j = 0; j < occ[i] / 2; ++j) cout << (char)('A' + i);
    }
  }
  // print odd
  for (int i = 0; i < occ.size(); ++i) {
    if (occ[i] && (occ[i] & 1)) {
      for (int j = 0; j < occ[i]; ++j) cout << (char)('A' + i);
    }

  }
  // print second half
  for (int i = 25; i >= 0; --i) {
    if (occ[i] && !(occ[i] & 1)) {
      for (int j = 0; j < occ[i] / 2; ++j) cout << (char)('A' + i);
    }

  }

}
