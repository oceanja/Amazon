Step 1 – Understanding the problem
“The problem is: convert a non-negative integer into its English words representation. For example, 
123 should return One Hundred Twenty Three. The challenge is to handle different ranges consistently: single digits, 
teens, tens, hundreds, thousands, millions, and billions.”

Step 2 – First intuition
“My first instinct was to break this problem down by ranges:
Numbers below 10 are direct words like One, Two, Three.
Numbers between 10 and 19 are special cases like Eleven, Twelve, Thirteen.
Numbers from 20 to 99 are combinations like Twenty + digit.

Then we build larger units like Hundreds, Thousands, Millions, Billions by recursion.”

Step 3 – Approach design
“To avoid a lot of repetitive code, 
I used three hash maps:

belowTen for digits 1–9.

belowTwenty for 10–19.

belowHundred for tens like Twenty, Thirty, Forty.

Then I built a recursive function solve(num) that:
Directly returns for numbers < 10 or < 20.
For < 100, combines the tens word with the ones word.
For < 1000, uses recursion to handle X Hundred Y.
For thousands, millions, billions, I divide the number by 1000/1,000,000/1,000,000,000 to get the higher part, 
append the scale word, and then recurse on the remainder if it’s non-zero.

This recursion ensures the same logic applies repeatedly at each scale.”

Step 4 – Edge cases
“I explicitly handle num == 0 as Zero. Also, whenever I concatenate, I add spaces only 
if the remainder is non-zero, so I don’t get trailing or double spaces.”

Step 5 – Complexity analysis

Time complexity: The recursion essentially breaks the number down by digits, so it processes each digit 
a constant number of times → O(log₁₀(num)), since the number of digits is proportional to log of the number.

Space complexity: The recursion depth is bounded (at most billions → 4 recursive calls), so the space i
s O(1) apart from the output string.

Step 6 – Quick dry run
“Let’s dry run 12345:

num = 12345 → < 1,000,000, so we split: solve(12) + Thousand + solve(345).

solve(12) = Twelve.

solve(345) = solve(3) + Hundred + solve(45).

solve(45) = Forty Five.
Final result = Twelve Thousand Three Hundred Forty Five.”





class Solution {
public:

  unordered_map<int, string> belowTen = { {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"} };
    unordered_map<int, string> belowTwenty = { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"} };
    unordered_map<int, string> belowHundred = { {1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} };

    string solve(int num){
        if(num<10){
            return belowTen[num];
        }
        if(num<20){
            return belowTwenty[num];
        }

        if(num<100){
         return belowHundred[num/10] + ((num%10 != 0) ? " " + belowTen[num%10] : "");
        }

        if(num<1000){
            return solve(num/100) + " Hundred" + ((num%100 != 0) ? " " + solve(num%100) : "");
        }

        if(num<1000000){
              return solve(num/1000) + " Thousand" + ((num%1000 != 0) ? " " + solve(num%1000) : "");
        }

         if(num < 1000000000) {
            return solve(num/1000000) + " Million" + ((num%1000000 != 0) ? " " + solve(num%1000000) : "");
        }

    return solve(num/1000000000) + " Billion" + ((num%1000000000 != 0) ? " " + solve(num%1000000000) : "");

    }

    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }

        return solve(num);
        
    }
};
