#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll inf = numeric_limits<ll>::max();

const ll N = 0;
ll n;

ll factorial(ll n) {
  ll res = 1;
  for (int i = 1; i <= n; ++i)
    res *= i;
  return res;
}

void backtrack(std::string &curr, std::map<char, int> &o,
               std::vector<std::string> &res, ll str_size) {
  if (curr.size() == str_size) {
    res.push_back(curr);
    return;
  }

  for (const auto &[c, v] : o) {
    if (v == 0)
      continue;

    curr += c;
    --o[c];
    backtrack(curr, o, res, str_size);
    curr.pop_back();
    ++o[c];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  std::string str;
  cin >> str;

  // number of strings:
  // - from first principles, we know that we can order n objects as n!
  // - then, we must handle duplicates by grouping them together, which results
  // in:
  //   - n! / (n1! * n2! * n3!...)

  std::map<char, int> o;
  for (const auto &c : str) {
    ++o[c];
  }

  auto count = factorial(str.size());
  for (const auto &[_, v] : o) {
    count /= factorial(v);
  }
  cout << count << "\n";

  std::vector<std::string> res;
  std::string curr;
  backtrack(curr, o, res, str.size());
  for (const auto &s : res) {
    cout << s << "\n";
  }
}
