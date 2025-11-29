#include <iostream>
#include <vector>
#include <functional>
// void print(std::vector<std::vector<int>> mat) {
//     for (size_t i = 0; i < mat.size(); ++i) {
//         for (size_t j = 0; j < mat[i].size(); ++j) {
//             std::cout << mat[i][j] << " ";
//         }
//         std::cout << '\n';
//     }
    
// }



// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> matA(n, std::vector<int>(m));
//     std::vector<std::vector<int>> matB(n, std::vector<int>(m));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cin >> matA[i][j];
//         }
//     }
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cin >> matB[i][j];
//         }
//     }
//     print(matA);
//     print(matB);
//     return 0;
// }

// void print(std::vector<std::vector<int>> mat) {
//     for (size_t i = 0; i < mat.size(); ++i) {
//         for (size_t j = 0; j < mat[i].size(); ++j) {
//             std::cout << mat[i][j] << " ";
//         }
//         std::cout << '\n';
//     }
    
// }

// std::vector<std::vector<int>> add_matrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
//     std::vector<std::vector<int>> C(A.size(), std::vector<int>(A[0].size()));
//     for (size_t i = 0; i < A.size(); ++i) {
//         for (size_t j = 0; j < A[i].size(); ++j) {
//             C[i][j] = A[i][j] + B[i][j];
//         }
//     }
//     return C;
// }
// std::vector<std::vector<int>> sub_matrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
//     std::vector<std::vector<int>> D(A.size(), std::vector<int>(A[0].size()));
//     for (size_t i = 0; i < A.size(); ++i) {
//         for (size_t j = 0; j < A[i].size(); ++j) {
//             D[i][j] = A[i][j] - B[i][j];
//         }
//     }
//     return D;
// }

// int main() {
//     int n, m;
//     std::cin >> n >> m;
//     std::vector<std::vector<int>> matA(n, std::vector<int>(m));
//     std::vector<std::vector<int>> matB(n, std::vector<int>(m));
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cin >> matA[i][j];
//         }
//     }
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             std::cin >> matB[i][j];
//         }
//     }

//     std::vector<std::vector<int>> sum = add_matrices(matA, matB);
//     std::vector<std::vector<int>> sub = sub_matrices(matA, matB);
//     print(sum);
//     print(sub);

    
// }


// size_t count_if(const std::vector<std::vector<int>>& M, std::function<bool(int)> pred) {
//     size_t count = 0;
//     for (size_t i = 0; i < M.size(); ++i) {
//         for (size_t j = 0; j < M[i].size(); ++j) {
//             if (pred(M[i][j])) {
//                 ++count;
//             }
//         }
//     }
//     return count;
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
//     std::function<bool(int)> pred = [](int x) { return x > 0;};
//     std::cout << count_if(mat, pred);
//     return 0;
// }


// void print(std::vector<std::vector<int>> mat) {
//     for (size_t i = 0; i < mat.size(); ++i) {
//         for (size_t j = 0; j < mat[i].size(); ++j) {
//             std::cout << mat[i][j] << " ";
//         }
//         std::cout << '\n';
//     }
    
// }

// template <typename T>
// void modify_if(std::vector<std::vector<T>>& M, std::function<bool(T)> pred, std::function<T(T)> transform) {
//     for (size_t i = 0; i < M.size(); ++i) {
//         for (size_t j = 0; j < M[i].size(); ++j) {
//             if (pred(M[i][j])) {
//                 M[i][j] = transform(M[i][j]);
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
//     std::function<bool(int)> posit = [](int x) { return x > 0; };
//     std::function<int(int)> transf = [](int x) { return x * 10; };
//     modify_if(mat, posit, transf);
//     print(mat);
//     return 0;
// }

void print(std::vector<std::vector<int>> mat) {
    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < mat[i].size(); ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << '\n';
    }
    
}

template <typename T>
std::vector<std::vector<T>> transpose(const std::vector<std::vector<T>>& M) {
    std::vector<std::vector<T>> transpM(M[0].size(), std::vector<T>(M.size()));
    for (size_t i = 0; i < M.size(); ++i) {
        for (size_t j = 0; j < M[i].size(); ++j) {
           transpM[j][i] = M[i][j]; 
        }
    }
    return transpM;
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
    std::vector<std::vector<int>> trnsp = transpose(mat);
    print(trnsp);
    return 0;
}