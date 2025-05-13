//Recursive solution

#include <iostream>
using namespace std;

int fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}
//TC : O(2^n), SC : O(n)

//Memoization solution

#include <iostream>
#include <vector>
using namespace std;

int fib_memo(int n, vector<int>& dp) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];
    return dp[n] = fib_memo(n - 1, dp) + fib_memo(n - 2, dp);
}
//TC : O(n), SC : O(n)

//Tabulation method
#include <iostream>
#include <vector>
using namespace std;

int fib_tabulation(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
//TC : O(n), SC : O(n)

//Space optimization
#include <iostream>
using namespace std;

int fib_space_optimized(int n) {
    if (n <= 1) return n;

    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++) {
        int cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }

    return prev;
}
//TC : O(n), SC : O(1)

//main function
int main() {
    int n = 10;

    cout << "Fibonacci of " << n << " using Recursive: " << fib_recursive(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Fibonacci of " << n << " using Memoization: " << fib_memo(n, dp) << endl;

    cout << "Fibonacci of " << n << " using Tabulation: " << fib_tabulation(n) << endl;

    cout << "Fibonacci of " << n << " using Space Optimization: " << fib_space_optimized(n) << endl;

    return 0;
}

