#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> input = {{1,2,3}, {4,5,6}, {7,8,9}};
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        if (matrix.empty()) return output;

        int interation;
        if (matrix.at(0).size() <= matrix.size()) {
            interation = matrix.at(0).size() / 2;
        } else {
            interation = matrix.size() / 2;
        }

        for (auto k = 0; k <= interation; ++k) {
            vector<int> tmp;
            for (auto i = k; i < matrix.size() - k; ++i){
                vector<int> row = matrix.at(i);
                if (i == k) {
                    // up row
                    for (auto j = k; j < row.size() - k; ++j) {
                        output.push_back(row.at(j));
                    }
                } else if ((i == matrix.size() - k - 1) && (matrix.size() - 1 !=  2 * k)) {
                    // down row
                    for (int j = row.size() - k - 1; j >= k; --j) { // inverse order with int, do not use auto -> unsign int
                        output.push_back(row.at(j));
                    }
                    // left column
                    for (int j = tmp.size() - 1; j >= 0; --j) { // inverse order with int, do not use auto -> unsign int
                        output.push_back(tmp.at(j));
                    }
                } else {
                    if ((k != row.size() - k - 1) && ((row.size() - k - 1) > 0)) {
                        tmp.push_back(row.at(k)); // catch the left column
                    }
                    if ((row.size() - k - 1) >= k) {
                        output.push_back(row.at(row.size() - k - 1)); // right column
                    }
                }
            }
        }
        return output;
    }
};