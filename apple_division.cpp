#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll inf = numeric_limits<ll>::max();

const ll N = 0;
ll n;

ll best = inf;

void backtrack(ll idx, ll group1, ll group2, std::vector<ll> &nums) {
  if (idx == nums.size()) {
    best = min(best, std::abs(group1 - group2));
    return;
  }

  backtrack(idx + 1, group1 + nums[idx], group2, nums);
  backtrack(idx + 1, group1, group2 + nums[idx], nums);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  std::vector<ll> nums;
  for (int i = 0; i < n; ++i) {
    ll num;
    cin >> num;
    nums.push_back(num);
  }

  backtrack(0, 0, 0, nums);
  cout << best << "\n";
  
}
