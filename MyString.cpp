#include "MyString.h"


// Custom implementation of strlen
size_t MyString::customStrlen(const char* str) const {
    const char* end = str;
    while (*end) {
        ++end;
    }
    return end - str;
}

// Custom implementation of strcpy
void MyString::customStrcpy(char* dest, const char* src) const {
    while ((*dest++ = *src++)) {
        // Copy characters until null terminator
    }
}
void MyString::customStrcat(char* dest, const char* src) const {
    while (*dest) {
        ++dest;
    }
    while ((*dest++ = *src++)) {
        // Concatenate characters until null terminator
    }
}

const char* MyString::customStrstr(const char* haystack, const char* needle) const {
    while (*haystack) {
        const char* h = haystack;
        const char* n = needle;
        while (*h && *n && *h == *n) {
            ++h;
            ++n;
        }
        if (!*n) {
            return haystack;
        }
        ++haystack;
    }
    return nullptr;
}

int MyString::customStrcmp(const char* str1, const char* str2) const {
    while (*str1 && *str2 && *str1 == *str2) {
        ++str1;
        ++str2;
    }
    return *str1 - *str2;
}

// Constructors
MyString::MyString() : data_(nullptr), size_(0), capacity_(0) {
    data_ = new char[capacity_ + 1]; // +1 for null terminator
    data_[0] = '\0';
}

MyString::MyString(const MyString& other) : data_(nullptr), size_(0), capacity_(0) {
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new char[capacity_ + 1];
    customStrcpy(data_, other.data_);
}

MyString::MyString(const char* str) : data_(nullptr), size_(0), capacity_(0) {
    size_ = customStrlen(str);
    capacity_ = size_;
    data_ = new char[capacity_ + 1];
    customStrcpy(data_, str);
}
MyString::MyString(char c) : data_(nullptr), size_(0), capacity_(0) {
    data_ = new char[2]; // +1 for null terminator
    data_[0] = c;
    data_[1] = '\0';
}

// Destructor
MyString::~MyString() {
    // Destructor
    delete[] data_;
}

// Member functions
void MyString::resize(size_t n) {
    // Resize
    if (n > capacity_) {
        char* newData = new char[n + 1];
        customStrcpy(newData, data_);
        delete[] data_;
        data_ = newData;
        capacity_ = n;
    }
}

size_t MyString::capacity() const {
    // Get capacity
    return capacity_;
}

size_t MyString::size() const {
    // Get size
    return size_;
}

size_t MyString::length() const {
    // Length
    return size_;
}

const char* MyString::data() const {
    // Get data
    return data_;
}

bool MyString::empty() const {
    // Empty
    return size_ == 0;
}

const char& MyString::front() const {
    // Front
    return data_[0];
}

const char& MyString::at(size_t pos) const {
    // At with bounds checking
    if (pos >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return data_[pos];
}

void MyString::clear() {
    // Clear
    delete[] data_;
    size_ = 0;
    capacity_ = 0;
    data_ = new char[capacity_ + 1];
    data_[0] = '\0';
}

MyString& MyString::operator=(const MyString& other) {
    // Copy assignment operator
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new char[capacity_ + 1];
        customStrcpy(data_, other.data_);
    }
    return *this;
}

MyString& MyString::operator+=(const MyString& other) {
    // Concatenation operator
    size_t newCapacity = capacity_ + other.size_;
    char* newData = new char[newCapacity + 1];
    customStrcpy(newData, data_);
    customStrcat(newData, other.data_); // Corrected line
    delete[] data_;
    data_ = newData;
    size_ += other.size_;
    capacity_ = newCapacity;
    return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const {
    // Find substring
    if (pos > size_) {
        return std::string::npos;
    }

    const char* result = customStrstr(data_ + pos, str.data_);
    if (result == nullptr) {
        return std::string::npos;
    }

    return result - data_;
}

// Additional functions for extra credit
bool MyString::operator==(const MyString& other) const {
    // Equality operator
    return customStrcmp(data_, other.data_) == 0;
}

MyString MyString::operator+(const MyString& other) const {
    // Addition operator
    MyString result(*this);
    result += other;
    return result;
}

// Helper functions
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    // Output operator
    os << str.data_;
    return os;
}

std::istream& operator>>(std::istream& is, MyString& str) {
    // Input operator
    str.clear();
    char c;
    //while (is.get(c) && !isspace(c)) {
    //    str += MyString(&c, 1); // Create a MyString from a single character
    //}
     while (is.get(c) && !isspace(c)) {
        str += MyString(c);
     }
    return is;
}

int stoi(const MyString& str) {
    // Simple stoi implementation for base 10
    int result = 0;
    for (size_t i = 0; i < str.size(); i++) {
        if (isdigit(str.data()[i])) {
            result *= 10;
            result += str.data()[i] - '0';
        }
    }
    return result;
}
