#include <iostream>

template<typename T>
class Vector {
private:
    T* data;
    size_t size_;
    size_t capacity_;
    
    void resize(size_t ncapacity) {
        T* ndata = new T[ncapacity];

        for(size_t i = 0; i < size_; i++) {
            ndata[i] = data[i];
        }

        delete[] data;
        data = ndata;
        capacity_ = ncapacity;
    }
    

public:
    Vector() : data(nullptr), size_(0), capacity_(0) {}
    
    Vector(size_t size0) : size_(size0), capacity_(size0) {
        data = new T[capacity_];
    }
    

    Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
        data = new T[capacity_];
        for(size_t i = 0; i < size_; i++) {
            data[i] = other.data[i];
        }
    }
    

    ~Vector() {
        delete[] data;
    }
    

    Vector& operator=(const Vector& other) {
        if (this != &other) { 
            delete[] data;
            size_ = other.size_;
            capacity_ = other.capacity_;
            data = new T[capacity_];
            for(size_t i = 0; i < size_; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    

    void push_back(const T& value) {
        if(size_ >= capacity_) {
            if (capacity_ == 0) {
                resize(1);
            } else {
                resize(capacity_ * 2);
            }
        }
        data[size_++] = value;
    }
    

    void pop_back() {
        if(size_ > 0) {
            size_--;
        }
    }
    
    void insert(size_t pos, const T& value) {
        if(pos > size_) {
            throw std::out_of_range("Insert position out of range");
        }
        
        if(size_ >= capacity_) {
            resize(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        
        for(size_t i = size_; i > pos; i--) {
            data[i] = std::move(data[i - 1]);
        }
        
        data[pos] = value;
        size_++;
    }
    

    T& operator[](size_t index) {
        return data[index];
    }
    
    T& at(size_t index) {
        if(index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    
    
    void clear() {
        size_ = 0;
    }
    
    
    T* begin() { return data; }
    T* end() { return data + size_; }
};

int main() {
    Vector<int> vec;
    std::cout << "Empty vector. Size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
    
    for(int i = 0; i < 10; i++) {
        vec.push_back(i * 10);
    }
    
    std::cout << "After change: Size: " << vec.size() << ", capacity: " << vec.capacity() << std::endl;
    

    std::cout << "Vector elements: ";
    for(size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    

    std::cout << "using iterators: ";
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    vec.insert(3, 999);
    std::cout << "Insertint 999 to position 3: ";
    for(size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    

    vec.pop_back();
    std::cout << "After pop_back. size: " << vec.size() << std::endl;
    


    std::cout << "Position 5: " << vec.at(5) << std::endl;

    
    Vector<int> vec2 = vec;
    std::cout << "Copied vector: ";
    for(size_t i = 0; i < vec2.size(); i++) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
    
    Vector<int> vec3;
    vec3 = vec;
    std::cout << "Using =: ";
    for(size_t i = 0; i < vec3.size(); i++) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;
    

    vec3.clear();
    std::cout << "After clear. Size: " << vec3.size() 
                << ", empty: " << (vec3.empty() ? "yes" : "no") << std::endl;
                  
    
    
    return 0;
}