#include <bits/stdc++.h>

const int maxn = 2e5 + 10;

int T, n, m;
int c[maxn], x[maxn];

int f(int a, int b) {
  b = b % n;
  b = (b + n) % n;
  a --;
  a = (a + b) % n;
  a ++;
  return a;
}

void add(int L, int R) {
//printf("[%d, %d]\n", L, R);

  c[L] ++;
  c[R + 1] --;
}

int main() {
  scanf("%d", &T);
  while(T --) {

    memset(c, 0, sizeof c);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i ++) {
      scanf("%d", &x[i]);
    }

    for(int i = 1; i <= m; i ++) {
      int y;
      scanf("%d", &y);

      if(y == 0) add(x[i], x[i]);
      else if(abs(y) == n) { add(1, n); add(x[i], x[i]); }
      else if(abs(y) == n - 1) { add(1, n); }
      else {
        int e = f(x[i], y);

        if(y > 0) {
            if(e >= x[i]) add(x[i], e);
            else { add(x[i], n); add(1, e); }
        }
        else {
            if(e <= x[i]) add(e, x[i]);
            else { add(1, x[i]); add(e, n); }
        }
      }
    }

    for(int i = 1; i <= n + 1; i ++) {
      c[i] = c[i] + c[i - 1];
    }

    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; i ++) {
        if(c[i] > ans1) {
            ans1 = c[i];
            ans2 = i;
        }
    }

    printf("%d %d\n", ans2, ans1);
  }
  return 0;
}