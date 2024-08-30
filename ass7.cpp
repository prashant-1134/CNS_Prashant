//7. Hill Cipher (with matrix inversion)
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> keyMatrix = {
    {6, 24, 1},
    {13, 16, 10},
    {20, 17, 15}
};

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

vector<int> multiplyMatrix(vector<int> vec) {
    vector<int> result(3);
    for (int i = 0; i < 3; i++) {
        result[i] = 0;
        for (int j = 0; j < 3; j++) {
            result[i] += keyMatrix[i][j] * vec[j];
        }
        result[i] = result[i] % 26;
    }
    return result;
}

string hillCipher(string text) {
    vector<int> vec(3);
    for (int i = 0; i < 3; i++) {
