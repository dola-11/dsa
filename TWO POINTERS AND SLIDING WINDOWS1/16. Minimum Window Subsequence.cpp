
string minWindow(string S, string T) {
    int m = S.size(), n = T.size();
    int minLen = INT_MAX, start = -1;

    for (int i = 0; i < m; i++) {
        if (S[i] == T[0]) {
            int j = 0, k = i;

            // Forward match
            while (k < m && j < n) {
                if (S[k] == T[j]) j++;
                k++;
            }

            if (j == n) {
                // Backward shrink
                int end = k - 1;
                j = n - 1;
                while (end >= i) {
                    if (S[end] == T[j]) j--;
                    if (j < 0) break;
                    end--;
                }

                if (k - (end + 1) < minLen) {
                    minLen = k - (end + 1);
                    start = end + 1;
                }
            }
        }
    }

    return start == -1 ? "" : S.substr(start, minLen);
}

//TC : O(m²)
//SC : O(1)


//OPTIMISE with O(m*n) solution
