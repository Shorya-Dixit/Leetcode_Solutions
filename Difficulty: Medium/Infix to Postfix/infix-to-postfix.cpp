//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    int precedence(char c) {
        if (c == '^') return 3;
        else if (c == '*' || c == '/') return 2;
        else if (c == '+' || c == '-') return 1;
        else {
            // Handle invalid character (optional: throw an exception or return -1)
            return 0;
        }
    }

    string infixToPostfix(string s) {
        stack<char> operatorStack;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= 'Z' && s[i] >= 'A') || (s[i] >= '0' && s[i] <= '9')) {
                ans.push_back(s[i]);
            } else if (s[i] == '(') {
                operatorStack.push('(');
            } else if (s[i] == ')') {
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    ans.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                if (operatorStack.empty()) {
                    // Handle missing opening parenthesis (optional: throw an exception or return an error)
                    return ""; // Or any error indicator
                }
                operatorStack.pop(); // Remove the '('
            } else {
                while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(s[i])) {
                    ans.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                operatorStack.push(s[i]);
            }
        }
        while (!operatorStack.empty()) {
            ans.push_back(operatorStack.top());
            operatorStack.pop();
        }
        return ans;
    }
};






//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends