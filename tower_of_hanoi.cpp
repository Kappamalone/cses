#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll inf = numeric_limits<ll>::max();

const ll N = 0;
ll n;

void solve(int n, int start, int end) {
  if (n == 0) return;

  int other = 6 - start - end;
  solve(n-1, start, other);
  cout << start << " " << end << "\n";
  solve(n-1, other, end);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  cout << (1 << n) - 1 << "\n";
  solve(n, 1, 3);

  // i cooked so hard coming up with this solution holy shit
  // essentially:
  // - looked at the problem for like 30 mins
  // - defined a recursive function since the first part of the recursion was 
  //   easy enough to spot
  // - realised that to move n disks, you must move n-1 disks to the free idx,
  //   move the biggest disk, then repeat
  //   - second recursion was easy enough to spot, first one was what took time
}
