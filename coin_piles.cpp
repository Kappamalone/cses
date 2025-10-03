#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll inf = numeric_limits<ll>::max();

const ll N = 0;
ll n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  // x + 2y = a (1)
  // 2x + y = b (2)
  //
  // (1) + (2)
  // a + b = 3x + 3y
  // x + y = (a + b) / 3
  //
  // so a + b must be divisible by 3 (so that x and y are integers)
  //
  // rearranging (2) gives us y = b - 2x (2')
  // subst. (2') into (1)
  //
  // x + 2(b - 2x) = a
  // x + 2b - 4x = a
  // 3x = 2b - a
  // x = (2b - a) / 3
  //
  // so (2b - a) must be positive (so that x is 0 or positive)
  //
  // rearranging (1) gives us x = a - 2y (1')
  // subst. (1') into (2)
  //
  // 2(a - 2y) + y = b
  // 2a - 4y + y = b
  // 2a - 3y = b
  // 3y = 2a - b
  // y = (2a - b)/3
  //
  // so (2a - b) must be positive (so that y is 0 or positive)

  while (n--) {
    int a, b;
    cin >> a >> b;

    if ((a + b) % 3 == 0 && (2 * a - b) >= 0 && (2 * b - a) >= 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
