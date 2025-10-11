#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word, result = "";

        while (ss >> word) {
            if (word[0] == '$' && word.size() > 1) {
                bool isNumber = true;

                // check all chars after '$' are digits
                for (int j = 1; j < word.size(); j++) {
                    if (!isdigit(word[j])) {
                        isNumber = false;
                        break;
                    }
                }

                // apply discount
                if (isNumber) {
                    long long price = stoll(word.substr(1));
                    double discounted = price * (1 - discount / 100.0);

                    stringstream formatted;
                    formatted << fixed << setprecision(2) << discounted;
                    word = "$" + formatted.str();
                }
            }

            if (!result.empty()) result += " ";
            result += word;
        }

        return result;
    }
};
