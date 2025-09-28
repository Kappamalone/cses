#define ll long long
const ll N = 0;

// --- {{{ TEMPLATE
#include <bits/stdc++.h>

using namespace std;
// using namespace __gnu_pbds;

const ll inf = numeric_limits<ll>::max();

#ifdef DEBUG
void __p(int x) { cerr << x; }
void __p(long x) { cerr << x; }
void __p(long long x) { cerr << x; }
void __p(unsigned x) { cerr << x; }
void __p(unsigned long x) { cerr << x; }
void __p(unsigned long long x) { cerr << x; }
void __p(float x) { cerr << x; }
void __p(double x) { cerr << x; }
void __p(long double x) { cerr << x; }
void __p(char x) { cerr << '\'' << x << '\''; }
void __p(const char *x) { cerr << '"' << x << '"'; }
void __p(const string &x) { cerr << '"' << x << '"'; }
void __p(bool x) { cerr << (x ? "true" : "false"); }

template <typename A> void __p(const A &x);
template <typename A, typename B> void __p(const pair<A, B> &p);
template <typename... A> void __p(const tuple<A...> &t);
template <typename T> void __p(stack<T> s);
template <typename T> void __p(queue<T> q);
template <typename T, typename... U> void __p(priority_queue<T, U...> q);

template <typename A> void __p(const A &x) {
  auto start = true;
  cerr << '[';
  for (const auto &i : x) {
    cerr << (start ? "" : ","), __p(i);
    start = false;
  }
  cerr << ']';
}

template <typename A, typename B> void __p(const pair<A, B> &p) {
  cerr << '(';
  __p(p.first);
  cerr << ",";
  __p(p.second);
  cerr << ')';
}

template <typename... A> void __p(const tuple<A...> &t) {
  auto start = true;
  cerr << '(';
  apply(
      [&start](const auto &...args) {
        ((cerr << (start ? "" : ","), __p(args), start = false), ...);
      },
      t);
  cerr << ')';
}

template <typename T> void __p(stack<T> s) {
  vector<T> v;
  while (!s.empty()) {
    T t = s.top();
    v.push_back(t);
    s.pop();
  }
  reverse(all(v));
  __p(v);
}

template <typename T> void __p(queue<T> q) {
  vector<T> v;
  while (!q.empty()) {
    T t = q.front();
    v.push_back(t);
    q.pop();
  }
  __p(v);
}

template <typename T, typename... U> void __p(priority_queue<T, U...> q) {
  vector<T> v;
  while (!q.empty()) {
    T t = q.top();
    v.push_back(t);
    q.pop();
  }
  __p(v);
}

void _p() { cerr << "\n"; }
template <typename Head, typename... Tail>
void _p(const Head &H, const Tail &...T) {
  __p(H);
  if (sizeof...(T))
    cerr << ", ";
  _p(T...);
}

#define print(...)                                                             \
  cerr << "line: " << __LINE__ << " | ";                                       \
  _p(__VA_ARGS__);

#else
#define print(...) ;
#endif
// --- }}}

ll n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    int row, col;
    cin >> row >> col;

    // the max of the row and col give us which "layer" we're on
    // layer = max(row, col)
    // the max value in a layer is layer^2
    // - when the layer is even, we find this value on the bottom edge
    // - when the layer is odd, we find this value on the right edge
    //
    // therefore, we have four cases to think about:
    // - layer is even + row >= col: layer^2 - col + 1
    // - layer is even + col > row: (layer - 1)^2 + row
    // - layer is odd + col >= row: layer^2 - row + 1
    // - layer is odd + row > col: (layer - 1)^2 + col

    ll layer = max(row, col);
    ll ans;
    if (layer & 1) {
      if (col >= row) {
        ans = layer * layer - row + 1;
      } else {
        ans = (layer - 1) * (layer - 1) + col;
      }
    } else {
      if (row >= col) {
        ans = layer * layer - col + 1;
      } else {
        ans = (layer - 1) * (layer - 1) + row;
      }
    }

    cout << ans << "\n";
  }
}
