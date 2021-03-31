//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
// Related Topics 数组 
// 👍 742 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
//leetcode submit region end(Prohibit modification and deletion)
