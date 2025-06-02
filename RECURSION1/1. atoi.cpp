//THIS IS NOT A RECURSION QUESTION, IT IS JUST LISTED IN THE RECURSION SUBMENU
class Solution {
public:
    int myAtoi(string s) 
    {
        int i = 0;
        int n = s.length();
        while(i<n && s[i] == ' ') i++;

        int sign = 1;
        if (i<n && (s[i] == '+' || s[i] == '-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long result = 0;
        while(i<n && isdigit(s[i]))
        {
            int digit = s[i] - '0';

            if (result > (INT_MAX - digit) / 10)
            {
                return (sign == 1) ? INT_MAX : INT_MIN;   
            }
            
            result = result*10 + digit;

            i++;
        }
        return sign* result;
    }
};
//TC : O(n)
//SC : O(1)

//converting to a recursive code:

class Solution {
public:
    int myAtoiHelper(const string& s, int& i, int sign, long result) {
        if (i == s.length() || !isdigit(s[i])) {
            // Base case: when we encounter a non-digit or reach the end of the string
            if (sign * result >= INT_MAX) return INT_MAX;
            if (sign * result <= INT_MIN) return INT_MIN;
            return sign * result;  // Return the result with the appropriate sign
        }
        
        // Recursive step: process the current digit
        result = result * 10 + (s[i] - '0');
        i++; // Move to the next character
        
        // Recursively call the helper function to process the next character
        return myAtoiHelper(s, i, sign, result);
    }
    
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') i++;
        
        // Step 2: Handle the sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;  // Move past the sign
        }
        
        // Step 3: Call the helper function to process digits recursively
        return myAtoiHelper(s, i, sign, 0);
    }
};
