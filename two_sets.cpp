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

template <typename A>
void __p(const A &x);
template <typename A, typename B>
void __p(const pair<A, B> &p);
template <typename... A>
void __p(const tuple<A...> &t);
template <typename T>
void __p(stack<T> s);
template <typename T>
void __p(queue<T> q);
template <typename T, typename... U>
void __p(priority_queue<T, U...> q);

template <typename A>
void __p(const A &x) {
  auto start = true;
  cerr << '[';
  for (const auto &i : x) {
    cerr << (start ? "" : ","), __p(i);
    start = false;
  }
  cerr << ']';
}

template <typename A, typename B>
void __p(const pair<A, B> &p) {
  cerr << '(';
  __p(p.first);
  cerr << ",";
  __p(p.second);
  cerr << ')';
}

template <typename... A>
void __p(const tuple<A...> &t) {
  auto start = true;
  cerr << '(';
  apply(
      [&start](const auto &...args) {
        ((cerr << (start ? "" : ","), __p(args), start = false), ...);
      },
      t);
  cerr << ')';
}

template <typename T>
void __p(stack<T> s) {
  vector<T> v;
  while (!s.empty()) {
    T t = s.top();
    v.push_back(t);
    s.pop();
  }
  reverse(all(v));
  __p(v);
}

template <typename T>
void __p(queue<T> q) {
  vector<T> v;
  while (!q.empty()) {
    T t = q.front();
    v.push_back(t);
    q.pop();
  }
  __p(v);
}

template <typename T, typename... U>
void __p(priority_queue<T, U...> q) {
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
  if (sizeof...(T)) cerr << ", ";
  _p(T...);
}

#define print(...)                                              \
  cerr << "line: " << __LINE__ << " | "; \
  _p(__VA_ARGS__);

#else
#define print(...) ;
#endif
// --- }}}

ll n;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  ll sum = (n * (n + 1)) / 2;
  if (sum & 1) {
    cout << "NO\n";
    return 0;
  }

  vector<int> first;
  vector<int> second;
  cout << "YES\n";
  if (n & 1) {
    first.push_back(1); first.push_back(2);
    second.push_back(3);
    for (int i = 4; i < (3 + n) / 2; i += 2) {
      first.push_back(i); 
      first.push_back(n - ((i - 3) - 1));
    }
    for (int i = 5; i <= (3 + n) / 2; i += 2) {
      second.push_back(i); 
      second.push_back(n - ((i - 3) - 1));
    }
  } else {
    for (int i = 1; i < n / 2; i += 2) {
      first.push_back(i); 
      first.push_back(n - (i - 1));
    }
    for (int i = 2; i <= n / 2; i += 2) {
      second.push_back(i); 
      second.push_back(n - (i - 1));
    }

  }

  // extremely janky printing because my test case handler can't deal with whitespace...
  cout << first.size() << "\n";
  for (ll i = 0; i < (int)first.size()-1; ++i) cout << first[i] << " ";
  if (!first.empty()) cout << first[first.size() - 1] << "\n";
  cout << second.size() << "\n";
  for (ll i = 0; i < (int)second.size()-1; ++i) cout << second[i] << " ";
  if (!second.empty()) cout << second[second.size() - 1] << "\n";
}
