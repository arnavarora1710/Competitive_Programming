#include <bits/stdc++.h>

int T;
long long N, K;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &N, &K);
        if (N == K) {
            puts("YES");
            printf("%d\n%lld\n", 1, 1ll);
        } else if (N - (K - 1) > (K - 1)) {
            puts("YES");
            printf("%d\n%lld %lld\n", 2, N - (K - 1), 1ll);
        } else {
            puts("NO");
        }
    }
}
