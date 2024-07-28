//
// Created by luka on 7/28/24.
//

#ifndef CPPCODES_LEVENSHTAIN_H
#define CPPCODES_LEVENSHTAIN_H


#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::min

using namespace std;

class LevenshteinDistance {
public:

    static int calculate(const string &s1, const string &s2) {
        const size_t len1 = s1.size();
        const size_t len2 = s2.size();
        vector<vector<unsigned int>> d(len1 + 1, vector<unsigned int>(len2 + 1));


        for (size_t i = 0; i <= len1; ++i) d[i][0] = i;
        for (size_t j = 0; j <= len2; ++j) d[0][j] = j;


        for (size_t i = 1; i <= len1; ++i) {
            for (size_t j = 1; j <= len2; ++j) {
                unsigned int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
                d[i][j] = min({d[i - 1][j] + 1,
                               d[i][j - 1] + 1,
                               d[i - 1][j - 1] + cost});
            }
        }

        return d[len1][len2];
    }


    static double similarity(const string &s1, const string &s2) {
        int distance = calculate(s1, s2);
        double maxLength = max(s1.size(), s2.size());
        return (1.0 - static_cast<double>(distance) / maxLength) * 100;
    }
};



#endif //CPPCODES_LEVENSHTAIN_H
