#include <cstdio>

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>

__m256i a;

int main()
{
    a=_mm256_set_epi32(1,2,3,4,5,6,7,8);
    printf("%d",a[2]);
    return 0;
}