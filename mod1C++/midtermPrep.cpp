#include <iostream>
#include <cstdint>
#include <vector>
#include <ctime>


std::vector<std::vector<int>> generMat(int n, int m) {
    std::vector<std::vector<int>> mat(n, std::vector<int>(m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            mat[i][j] = std::rand() % 101 - 50;
        }
    }
    return mat;
}

void print(const std::vector<std::vector<int>>& m) {
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[i].size(); ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void replace_negative(std::vector<std::vector<int>>& m) {
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[i].size(); ++j) {
            if (m[i][j] < 0) {
                m[i][j] = m[i][j] * m[i][j];
            }
        }
    }
}

std::pair<long long, std::vector<int>> sum_evens(const std::vector<std::vector<int>>& m) {
    int sum = 0;
    std::vector<int> odds;
    for (size_t i = 0; i < m.size(); ++i) {
        for (size_t j = 0; j < m[i].size(); ++j) {
            if (m[i][j] % 2 == 0) {
                sum += m[i][j];
            } else {
                odds.push_back(m[i][j]);
            }
        }
    }
    return {sum, odds};
}

template <class ForwardIt, class UnaryOp>
void transform_range(ForwardIt first, ForwardIt last, UnaryOp op) {
    for (auto i = first; i != last; ++i) {
        *i = op(*i);
    }
}

template <class InputIt , class OutputIt , class Pred >
OutputIt copy_if_range ( InputIt first , InputIt last , OutputIt out , Pred p ) {
    for (auto i = first; i != last; ++i) {
        if (p(*i)) {
            *out = *i;
            ++out;
        }
    }
    return out;
}

void print_vector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::srand(std::time(0));
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> mat = generMat(n, m);
    print(mat);
    replace_negative(mat);
    print(mat);
    std::cout << sum_evens(mat).first << '\n';
    for (size_t i = 0; i < mat.size(); ++i) {
        transform_range(mat[i].begin(), mat[i].end(), [](int x) {
                return x == 0 ? -1 : x;
            });
    }
    print(mat);

    std::vector<int> odds;
    auto is_odd = [](int x) { return x % 2 != 0; };
    for (size_t i = 0; i < mat.size(); ++i) {
        copy_if_range(mat[i].begin(), mat[i].end(), std::back_inserter(odds), is_odd);
    }
    print_vector(odds);
    return 0;
}