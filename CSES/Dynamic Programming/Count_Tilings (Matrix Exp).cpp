#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
const int MAXM = 1 << 20,  MOD = 1e9 + 7;
uint N, M, N1, mat[MAXM], ans[MAXM];

void mut_fast(uint res[], uint *mata, uint *matb) {
    uint matc[MAXM];
    memset(matc, 0, MAXM * sizeof(uint));
    for (uint i = 0, iN = 0; i < N1; ++i, iN += N1)
        for (uint k = 0, kN = 0, vala; k < N1; ++k, kN += N1)
            if (vala = mata[iN + k])
                for (uint j = 0, iNj = iN, kNj = kN; j < N1;
                     j += 8, iNj += 8, kNj += 8) {
#define unroll(r)                                                              \
    if (matb[kNj + r])                                                         \
        matc[iNj + r] = (matc[iNj + r] + 1ll * vala * matb[kNj + r]) % MOD;
                    unroll(0);
                    unroll(1);
                    unroll(2);
                    unroll(3);
                    unroll(4);
                    unroll(5);
                    unroll(6);
                    unroll(7);
                }
    memcpy(res, matc, MAXM * sizeof(uint));
}

void mut_slow(uint res[], uint *mata, uint *matb) {
    uint matc[MAXM];
    memset(matc, 0, MAXM * sizeof(uint));
    for (uint i = 0, iN = 0; i < N1; ++i, iN += N1)
        for (uint k = 0, kN = 0, vala; k < N1; ++k, kN += N1)
            if (vala = mata[iN | k])
                for (uint j = 0, iNj = iN, kNj = kN; j < N1;
                     j += 1, iNj += 1, kNj += 1) {
                    if (matb[kNj])
                        matc[iNj] = (matc[iNj] + 1ll * vala * matb[kNj]) % MOD;
                }
    memcpy(res, matc, MAXM * sizeof(uint));
}

int main() {
    uint N, M; cin >> N >> M;
    N1 = 1<<N;
	for (int i = 0; i < (1 << N); ++i) {
		for (int j = 0; j < (1 << N); ++j) {
			int num1 = i, num2 = j, ct = 0;
			uint ways = 1; bool shouldBeZero = 0;
			for (int k = N - 1; k >= 0; --k) {
				int bit = (num1>>k)&1, topbit = (num2>>k)&1;
				if (topbit && bit) {
					shouldBeZero = 1; break;
				}
				else if (topbit ^ bit) {
					ways = (ways * !(ct&1)) % MOD; ct = 0;
				}
				else ct++;
			}
			ways = (ways * !(ct&1)) % MOD;
			mat[(i<<N)|j] = shouldBeZero ? 0 : ways;
		}
	}

    ans[0] = 1;
    #define fast_pow(method)                                                       \
        while (M > 128) {                                                            \
            if (M & 1)                                                             \
                method(ans, ans, mat);                                             \
            method(mat, mat, mat);                                                 \
            M >>= 1;                                                               \
        }                                                                          \
        for (uint i = 0; i < M; ++i)                                               \
            method(ans, ans, mat);
    
    if (N > 5) {
        fast_pow(mut_fast);
    } else {
        fast_pow(mut_slow);
    }
    cout << ans[0];

    return 0;
}