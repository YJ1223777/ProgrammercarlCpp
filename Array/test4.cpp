//
// Created by YJ_1223 on 2024/1/15.
// 螺旋矩阵
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    static vector<vector<int>> genMatrix(int n){
        vector<vector<int>> res(n, vector<int>(n,0));
        int startX=0, startY=0;
        int loop = n / 2;
        int middle = n / 2;
        int count = 1;
        int offset = 1;
        int i, j;
        while (loop--){
            i = startX;
            j = startY;

            // 从左上角开始，向右
            for (j; j < n - offset; j++) {
                res[i][j] = count++;
            }
            // 从右上角开始，向下
            for (i; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 从右下角开始，向左
            for (; j > offset-1; j--) {
                res[i][j] = count++;
            }
            // 从左下角开始，向上
            for (; i > offset-1; i--) {
                res[i][j] = count++;
            }

            startX++;
            startY++;
            offset++;

            if(n % 2){
                res[middle][middle] = n*n;
            }

        }
        return res;
    }
};

int main() {

    int n = 3;
    vector<vector<int>> res = Solution::genMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << " " << endl;
    }

    return 0;
}
