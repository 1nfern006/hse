#include <iostream>
#include <vector>

template <class T, class F>
void map2d(std::vector<std::vector<T>>& a, F f) {
    for (auto& row : a) {
        for (auto& elem : row) {
            elem = f(elem);
        }
    }
}

template <class T, class Pred>
std::size_t count_if2d(const std::vector<std::vector<T>>& a, Pred p) {
    std::size_t cnt = 0;
    for (int _i = 0; _i < a.size(); ++_i) {
        for (int _j = 0; _j < a[_i].size(); ++_j) {
            if (p(a[_i][_j])) {
                ++cnt;
            }
        }
    }
    return cnt;
}

template <class T, class U, class Op>
U reduce2d(const std::vector<std::vector<T>>& a, U init, Op op) {
    U result = init;
    for (int _i = 0; _i < a.size(); ++_i) {
        for (int _j = 0; _j < a[_i].size(); ++_j) {
            result = op(a[_i][_j], result);
        }
    }
    return result;
}

void _print(const std::vector<std::vector<int>> mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            std::cout << mat[i][j] << " ";

        }
        std::cout << '\n';
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> mat(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> mat[i][j];

        }
    }
    _print(mat);
    int q;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        std::string str1, str2;
        std::cin >> str1 >> str2;
        if (str1 == "MAP") {
            int x;
            std::cin >> x;
            if (str2 == "ADD") {
                map2d(mat, [x](int xn) {return x + xn;});
                _print(mat);
            } else {
                map2d(mat, [x](int xn) {return x * xn;});
                _print(mat);
            }
        } else if (str1 == "FILTER") {
            int x;
            std::cin >> x;
            if (str2 == "GT") {
                std::cout << count_if2d(mat, [x](int xn) {return xn > x;});
            } else if (str2 == "GE") {
                std::cout << count_if2d(mat, [x](int xn) {return xn >= x;});
            } else {
                std::cout << count_if2d(mat, [x](int xn) {return xn == x;});
            }
        } else {
            if (str2 == "SUM") {
                std::cout << reduce2d(mat, 0, [](int x, int y) {return y + x;});
            } else if (str2 == "MAX") {
                std::cout << reduce2d(mat, mat[0][0], [](int x, int y) {return y > x ? y : x;});
            } else {
                std::cout << reduce2d(mat, mat[0][0], [](int x, int y) {return y < x ? y : x;});
            }
        }        
    }
    return 0;
}