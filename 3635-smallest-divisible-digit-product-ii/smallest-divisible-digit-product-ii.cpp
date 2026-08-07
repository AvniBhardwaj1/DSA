#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
    const unordered_map<int, unordered_map<int, int>> kFactorCounts = {
        {0, {}}, {1, {}}, {2, {{2, 1}}}, {3, {{3, 1}}}, 
        {4, {{2, 2}}}, {5, {{5, 1}}}, {6, {{2, 1}, {3, 1}}}, 
        {7, {{7, 1}}}, {8, {{2, 3}}}, {9, {{3, 2}}}
    };

    pair<unordered_map<int, int>, bool> getPrimeCount(long long t) {
        unordered_map<int, int> count = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for (int prime : {2, 3, 5, 7}) {
            while (t % prime == 0) {
                t /= prime;
                count[prime]++;
            }
        }
        return {count, t == 1};
    }

    unordered_map<int, int> getPrimeCountFromString(const string& s) {
        unordered_map<int, int> count = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for (char c : s) {
            if (c == '0') continue;
            for (auto& [prime, freq] : kFactorCounts.at(c - '0')) {
                count[prime] += freq;
            }
        }
        return count;
    }

    unordered_map<int, int> subtract(const unordered_map<int, int>& a, const unordered_map<int, int>& b) {
        unordered_map<int, int> res = a;
        for (auto& [k, v] : b) {
            res[k] = max(0, res[k] - v);
        }
        return res;
    }

    bool isSubset(const unordered_map<int, int>& a, const unordered_map<int, int>& b) {
        for (auto& [k, v] : a) {
            if (b.at(k) < v) return false;
        }
        return true;
    }

    int sumValues(const unordered_map<int, int>& m) {
        int sum = 0;
        // Count total factors needed represented as individual single-digit multipliers
        unordered_map<int, int> temp = m;
        int c2 = temp[2], c3 = temp[3], c5 = temp[5], c7 = temp[7];
        
        int count7 = c7;
        int count5 = c5;
        int count9 = c3 / 2;
        int rem3 = c3 % 2;
        int count8 = c2 / 3;
        int rem2 = c2 % 3;
        int count4 = rem2 / 2;
        int count2 = rem2 % 2;
        
        int count6 = 0;
        if (count2 == 1 && rem3 == 1) { count2 = 0; rem3 = 0; count6 = 1; }
        if (rem3 == 1 && count4 >= 1) { count2 = 1; count6 = 1; rem3 = 0; count4--; }

        return count7 + count5 + count9 + count8 + count4 + count2 + count6 + rem3;
    }

    string construct(unordered_map<int, int> count) {
        int c2 = count[2], c3 = count[3], c5 = count[5], c7 = count[7];
        int count7 = c7;
        int count5 = c5;
        int count9 = c3 / 2;
        int rem3 = c3 % 2;
        int count8 = c2 / 3;
        int rem2 = c2 % 3;
        int count4 = rem2 / 2;
        int count2 = rem2 % 2;
        
        int count6 = 0;
        if (count2 == 1 && rem3 == 1) { count2 = 0; rem3 = 0; count6 = 1; }
        if (rem3 == 1 && count4 >= 1) { count2 = 1; count6 = 1; rem3 = 0; count4--; }

        string res = "";
        res.append(count2, '2');
        res.append(rem3, '3');
        res.append(count4, '4');
        res.append(count5, '5');
        res.append(count6, '6');
        res.append(count7, '7');
        res.append(count8, '8');
        res.append(count9, '9');
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        auto [primeCount, isDivisible] = getPrimeCount(t);
        if (!isDivisible) return "-1";

        int n = num.length();
        auto primeCountPrefix = getPrimeCountFromString(num);
        int firstZeroIndex = num.find('0');

        if (firstZeroIndex == string::npos) {
            firstZeroIndex = n;
            if (isSubset(primeCount, primeCountPrefix)) return num;
        }

        for (int i = n - 1; i >= 0; --i) {
            int d = num[i] - '0';
            if (d != 0) {
                for (auto& [p, f] : kFactorCounts.at(d)) {
                    primeCountPrefix[p] = max(0, primeCountPrefix[p] - f);
                }
            }
            int spaceAfterThisDigit = n - 1 - i;
            if (i > firstZeroIndex) continue;

            for (int biggerDigit = d + 1; biggerDigit < 10; ++biggerDigit) {
                auto needed = subtract(primeCount, primeCountPrefix);
                for (auto& [p, f] : kFactorCounts.at(biggerDigit)) {
                    needed[p] = max(0, needed[p] - f);
                }
                if (sumValues(needed) <= spaceAfterThisDigit) {
                    int fillOnes = spaceAfterThisDigit - sumValues(needed);
                    return num.substr(0, i) + to_string(biggerDigit) + string(fillOnes, '1') + construct(needed);
                }
            }
        }

        string extraOnes = string(max(0, (int)(n + 1 - sumValues(primeCount))), '1');
        // Fallback length extension if same-length fails
        auto needed = primeCount;
        return string(max(0, (int)(n + 1 - sumValues(needed))), '1') + construct(needed);
    }
};