#include <iostream>
#include <vector>
#include <limits>
// void cube_positives(std::vector<std::vector<int>>& mat) {
//     for (size_t i = 0; i < mat.size(); ++i) {
//         for (size_t j = 0; j < mat[i].size(); ++j) {
//             if (mat[i][j] > 0) {
//                 mat[i][j] = mat[i][j] * mat[i][j] * mat[i][j];
//             }
//         }
//     }
// }

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> mat(n, std::vector<int>(m));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cin >> mat[i][j];
//         }
//     }
//     cube_positives(mat);
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cout << mat[i][j] << " ";
//         }
//         std::cout << '\n';
//     }
// }


// template<class ForwardIt, class Pred, class UnaryOp>
// void apply_if_range(ForwardIt first, ForwardIt last, Pred p, UnaryOp op) {
//     for (auto it = first; it != last; ++it) {
//         if (p(*it)) {
//             *it = op(*it);
//         }
//     }
// }

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> mat(n, std::vector<int>(m));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cin >> mat[i][j];
//         }
//     }
//     for (auto& row : mat) {
//         apply_if_range(
//             row.begin(), 
//             row.end(), 
//             [](int x) { return x % 3 == 0; },  
//             [](int x) { return x + 5; } 
//         );
//     }
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cout << mat[i][j];
//         }
//     }
//     return 0;
// }



// std::pair<std::vector<int>, long long> column_maxima_and_negative_product(const std::vector<std::vector<int>>& mat) {
//     std::vector<int> maxels;
//     int maxi = std::numeric_limits<int>::min();
//     for (size_t j = 0; j < mat[0].size(); ++j) {
//         maxi = std::numeric_limits<int>::min();
//         for (size_t i = 0; i < mat.size(); ++i) {
//             maxi = std::max(maxi, mat[i][j]);
//         }
//         maxels.push_back(maxi);
        
//     }

//     long long prod = 1;
//     bool found_n = false;
//     for (size_t i = 0; i < mat.size(); ++i) {
//         for (size_t j = 0; j < mat[i].size(); ++j) {
//             if (mat[i][j] < 0) {
//                 prod *= mat[i][j];
//                 found_n = true;
//             }
//         }
//     }
//     if (!found_n) {
//         prod = 0;
//     }

//     return {maxels, prod};
// }

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> mat(n, std::vector<int>(m));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cin >> mat[i][j];
//         }
//     }
//     std::pair<std::vector<int>, long long> pair1 = column_maxima_and_negative_product(mat);
//     std::vector<int> col = pair1.first;
    

//     for (size_t i = 0; i < col.size(); ++i) {
//         std::cout << col[i] << " ";
//     }
//     std::cout << '\n';
//     std::cout << pair1.second;
//     return 0;
// } 


// std::vector<std::vector<int>> generate_matrix(int n, int m) {
//     std::vector<std::vector<int>> mat(n, std::vector<int>(m));
//     for (size_t i = 0; i < mat.size(); ++i) {
//         for (size_t j = 0; j < mat[i].size(); ++j) {
//             std::cin >> mat[i][j];
//         }
//     }
//     return mat;
// }

// void print_matrix(const std::vector<std::vector<int>>& mat) {
//     for (size_t i = 0; i < mat.size(); ++i) {
//         for (size_t j = 0; j < mat[i].size(); ++j) {
//             std::cout << mat[i][j] << " ";
//         }
//         std::cout << '\n';
//     }
// }

// std::vector<std::vector<int>> transpose(const std::vector<std::vector<int>>& mat) {
//     std::vector<std::vector<int>> trM(mat[0].size(), std::vector<int>(mat.size()));
//     for (size_t i = 0; i < mat.size(); ++i) {
//         for (size_t j = 0; j < mat[i].size(); ++j) {
//             trM[j][i] = mat[i][j];
//         }
//     }
//     return trM;
// }

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> mat = generate_matrix(n, m);
//     print_matrix(mat);
//     std::vector<std::vector<int>> transpM = transpose(mat);
//     print_matrix(transpM);
//     return 0;
// }




template<class InputIt, class OutputItTrue, class OutputItFalse, class Pred>
std::pair<OutputItTrue, OutputItFalse> partition_copy_range(InputIt first, InputIt last, OutputItTrue out_true, OutputItFalse out_false, Pred p) {
    for (auto it = first; it != last; ++it) {
        if(p(*it)) {
            *out_true = *it;
            ++out_true;
        } else {
            *out_false = *it;
            ++out_false;
        }
    }
    return {out_true, out_false};
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
    std::vector<int> tr;
    std::vector<int> fa;
    auto ifnonn = [](int x) { return x >= 0; };

    for (int i = 0; i < n; ++i) {
        partition_copy_range(mat[i].begin(), mat[i].end(), std::back_inserter(tr), std::back_inserter(fa), ifnonn);
    }

    for (size_t i = 0; i < tr.size(); ++i) {
        std::cout << tr[i] << " ";
    }
    std::cout << std::endl;
    
    for (size_t i = 0; i < fa.size(); ++i) {
        std::cout << fa[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}