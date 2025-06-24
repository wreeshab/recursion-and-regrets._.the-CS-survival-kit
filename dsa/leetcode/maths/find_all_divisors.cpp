🔍 Logic Behind the √n Divisor Method:
If i is a divisor of n, then n / i is also a divisor.

So for every divisor pair (i, n/i):

One of them is always ≤ √n

The other is ≥ √n

Hence, you only need to check up to √n:

If i divides n, you found two divisors: i and n/i


vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i)  // avoid duplicate when i*i == n
                divisors.push_back(n / i);
        }
    }
    return divisors;
}
