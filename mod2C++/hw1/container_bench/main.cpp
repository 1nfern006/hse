#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <chrono>
#include <random>
#include <string>
#include <fstream> 


enum class ContainerType { Vector, Deque, List };
enum class Operation { 
        PushBack, PushFront, RandomInsert, 
        RandomErase, IterateSum, RandomAccess 
};
enum class TimeUnit { Milliseconds, Seconds };

union TimeValue { 
        double ms; 
        double sec; 
};

struct TimeResult { ContainerType ct; Operation op; TimeUnit unit; TimeValue val; };





std::string containerToString(ContainerType ct) {
    if (ct == ContainerType::Vector) return "vector";
    else if (ct == ContainerType::Deque) return "deque";
    else return "list";

}
std::string operationToString(Operation op) {
    if (op == Operation::PushBack) return "PushBack";
    else if (op == Operation::PushFront) return "PushFront";
    else if (op == Operation::RandomInsert) return "RandomInsert";
    else if (op == Operation::RandomErase) return "RandomErase";
    else if (op == Operation::IterateSum) return "IterateSum";
    else return "RandomAccess";
}




template<class Seq>
double measure_push_back(int N, int repeats = 10) {
    std::vector<int> payload(N);
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int &x : payload) x = dist(gen);
    double total = 0.0;
    for (int i = 0; i < repeats; ++i) {
        Seq c;
        auto start = std::chrono::high_resolution_clock::now();
        for (int x : payload) c.push_back(x);
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}




template<class Seq>
double measure_push_front(int N, int repeats = 10) {
    std::vector<int> payload(N);
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int &x : payload) x = dist(gen);
    double total = 0.0;
    for (int i = 0; i < repeats; ++i) {
        Seq c;
        auto start = std::chrono::high_resolution_clock::now();
        for (int x : payload) c.push_front(x);
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}

template<>
double measure_push_front<std::vector<int>>(int N, int repeats) {
    std::vector<int> payload(N);
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int &x : payload) x = dist(gen);
    double total = 0.0;
    for (int i = 0; i < repeats; ++i) {
        std::vector<int> c;
        auto start = std::chrono::high_resolution_clock::now();
        for (int x : payload) c.insert(c.begin(), x);
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}





template<class Seq>
double measure_random_insert(int N, int repeats = 10) {
    std::vector<int> payload(N);
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int &x : payload) x = dist(gen);
    
    double total = 0.0;
    for (int i = 0; i < repeats; ++i) {
        Seq c;
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < N; ++j) {
            auto it = c.begin() + (gen() % (c.size() + 1));
            c.insert(it, payload[j]);
        }
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}


template<>
double measure_random_insert<std::list<int>>(int N, int repeats) {
    std::vector<int> payload(N);
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int &x : payload) x = dist(gen);
    
    double total = 0.0;
    for (int i = 0; i < repeats; ++i) {
        std::list<int> c;
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < N; ++j) {
            auto it = c.begin();
            int offset = gen() % (c.size() + 1);
            for (int k = 0; k < offset; ++k) {
                ++it;
            }
            c.insert(it, payload[j]);
        }
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}





template<class Seq>
double measure_random_erase(int N, int repeats = 10) {
    std::vector<int> payload(N);
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int &x : payload) x = dist(gen);
    
    double total = 0.0;
    for (int i = 0; i < repeats; ++i) {
        Seq c;
        for(int val : payload) c.push_back(val);
        
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < N; ++j) {
            auto it = c.begin() + (gen() % c.size());
            c.erase(it);
        }
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}


template<>
double measure_random_erase<std::list<int>>(int N, int repeats) {
    std::vector<int> payload(N);
    std::mt19937 gen(12345);
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (int &x : payload) x = dist(gen);
    
    double total = 0.0;
    for (int i = 0; i < repeats; ++i) {
        std::list<int> c;
        for(int val : payload) c.push_back(val);
        
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < N; ++j) {
            auto it = c.begin();
            int offset = gen() % c.size();
            for (int k = 0; k < offset; ++k) {
                ++it;
            }
            c.erase(it);
        }
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}





template<class Seq>
double measure_iterate_sum(int N, int repeats = 10) {
    Seq c;
    for (int i = 0; i < N; ++i) c.push_back(i);
    double total = 0.0;
    for (int i = 0; i < repeats; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        volatile long long sum = 0; 
        for (const auto& val : c) {
            sum += val;
        }
        auto end = std::chrono::high_resolution_clock::now();
        total += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total / repeats;
}





template<class Seq>
double measure_random_access(int N, int repeats = 10) {
    Seq c;
    for (int i = 0; i < N; ++i) c.push_back(i);
    
    std::vector<int> indices(N);
    std::mt19937 gen(12345);
    for (int i = 0; i < N; ++i) indices[i] = gen() % N;
    
    double total_time = 0.0;
    for (int i = 0; i < repeats; ++i) {
        volatile long long sum = 0;
        auto start = std::chrono::high_resolution_clock::now();
        for (int idx : indices) {
           sum += c[idx];
        }
        auto end = std::chrono::high_resolution_clock::now();
        total_time += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total_time / repeats;
}

template<>
double measure_random_access<std::list<int>>(int N, int repeats) {
    std::list<int> c;
    for (int i = 0; i < N; ++i) c.push_back(i);

    std::vector<int> indices(N);
    std::mt19937 gen(12345);
    for (int i = 0; i < N; ++i) indices[i] = gen() % N;
    
    double total_time = 0.0;
    for (int i = 0; i < repeats; ++i) {
        volatile long long sum = 0;
        auto start = std::chrono::high_resolution_clock::now();
        for (int idx : indices) {
            auto it = c.begin();
            std::advance(it, idx);
            sum += *it;
        }
        auto end = std::chrono::high_resolution_clock::now();
        total_time += std::chrono::duration<double, std::milli>(end - start).count();
    }
    return total_time / repeats;
}


int main() {
    std::ofstream results_file("result.txt");
    results_file << std::fixed << std::setprecision(2);

    std::vector<int> data_sizes = {8192, 32768, 262144, 1048576};

    std::vector<Operation> operations_to_test = {
        Operation::PushBack,
        Operation::PushFront,
        Operation::RandomInsert,
        Operation::RandomErase,
        Operation::IterateSum,
        Operation::RandomAccess
    };

    for (Operation op : operations_to_test) {
        std::cout << "Processing " << operationToString(op) << std::endl;
        results_file << "Operation " << operationToString(op) << "\n";

        for (int n : data_sizes) {
            std::cout << "  Testing N = " << n << "..." << std::endl;
            
            
            TimeResult v_res{}, d_res{}, l_res{};
            bool vector_measured = false;
            bool deque_measured = false;
            bool list_measured = false;

            switch (op) {
                case Operation::PushBack:
                    v_res = {ContainerType::Vector, op, TimeUnit::Milliseconds, measure_push_back<std::vector<int>>(n)};
                    vector_measured = true;
                    d_res = {ContainerType::Deque,  op, TimeUnit::Milliseconds, measure_push_back<std::deque<int>>(n)};
                    deque_measured = true;
                    l_res = {ContainerType::List,   op, TimeUnit::Milliseconds, measure_push_back<std::list<int>>(n)};
                    list_measured = true;
                    break;
                case Operation::PushFront:
                    if (n <= 262144) {
                        v_res = {ContainerType::Vector, op, TimeUnit::Milliseconds, measure_push_front<std::vector<int>>(n)};
                        vector_measured = true;
                        d_res = {ContainerType::Deque,  op, TimeUnit::Milliseconds, measure_push_front<std::deque<int>>(n)};
                        deque_measured = true;
                        l_res = {ContainerType::List,   op, TimeUnit::Milliseconds, measure_push_front<std::list<int>>(n)};
                        list_measured = true;
                    }
                    break;
                case Operation::RandomInsert: {
                    if (n <= 32768) {
                        v_res = {ContainerType::Vector, op, TimeUnit::Milliseconds, measure_random_insert<std::vector<int>>(n)};
                        vector_measured = true;
                        d_res = {ContainerType::Deque,  op, TimeUnit::Milliseconds, measure_random_insert<std::deque<int>>(n)};
                        deque_measured = true;
                        l_res = {ContainerType::List,   op, TimeUnit::Milliseconds, measure_random_insert<std::list<int>>(n)};
                        list_measured = true;
                    }
                    break;
                }
                case Operation::RandomErase: {
                    if (n <= 32768) {
                        v_res = {ContainerType::Vector, op, TimeUnit::Milliseconds, measure_random_erase<std::vector<int>>(n)};
                        vector_measured = true;
                        d_res = {ContainerType::Deque,  op, TimeUnit::Milliseconds, measure_random_erase<std::deque<int>>(n)};
                        deque_measured = true;
                        l_res = {ContainerType::List,   op, TimeUnit::Milliseconds, measure_random_erase<std::list<int>>(n)};
                        list_measured = true;
                    }
                    break;
                }
                case Operation::IterateSum:
                    v_res = {ContainerType::Vector, op, TimeUnit::Milliseconds, measure_iterate_sum<std::vector<int>>(n)};
                    vector_measured = true;
                    d_res = {ContainerType::Deque,  op, TimeUnit::Milliseconds, measure_iterate_sum<std::deque<int>>(n)};
                    deque_measured = true;
                    l_res = {ContainerType::List,   op, TimeUnit::Milliseconds, measure_iterate_sum<std::list<int>>(n)};
                    list_measured = true;
                    break;
                case Operation::RandomAccess:
                    v_res = {ContainerType::Vector, op, TimeUnit::Milliseconds, measure_random_access<std::vector<int>>(n)};
                    vector_measured = true;
                    d_res = {ContainerType::Deque,  op, TimeUnit::Milliseconds, measure_random_access<std::deque<int>>(n)};
                    deque_measured = true;
                    if (n <= 32768) {
                        l_res = {ContainerType::List, op, TimeUnit::Milliseconds, measure_random_access<std::list<int>>(n)};
                        list_measured = true;
                    }
                    break;
            }

            results_file << "n = " << n << ": ";

            results_file << "vector: ";
            if (vector_measured) {
                results_file << v_res.val.ms << " ms, ";
            } else {
                results_file << "Too long test, ";
            }

            results_file << "deque: ";
            if (deque_measured) {
                results_file << d_res.val.ms << " ms, ";
            } else {
                results_file << "Too long test, ";
            }

            results_file << "list: ";
            if (list_measured) {
                results_file << l_res.val.ms << " ms\n";
            } else {
                results_file << "Too long test\n";
            }
            results_file << "\n";
        }
    }
    results_file.close();
    return 0;
}