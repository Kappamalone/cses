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

  // a trailing zero corresponds to 10 being formed somewhere in a factorial
  // 10 = 2 * 5, we have plenty of 2s, but are limited by the number of 5s that we have
  // therefore we can rephrase this question as:
  // for some n!, count how many 5s exist in the product

  // n! = 1 * 2 * 3 * 4 ... n

  cin >> n;

  ll trailing = 0;
  ll curr = 5;
  while (curr <= n) {
    // question: why aren't we multiplying the number of occurrences by log_5(curr)?
    // reason/example: 
    // the reason we don't count 25 as two occurrences is because we're already counted from 5 once
    trailing += (ll)floor(n / curr);
    curr *= 5;
  }

  cout << trailing << "\n";
}
