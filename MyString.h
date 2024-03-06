// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
private:
    char* data_;      // character array
    size_t size_;      // current number of elements in the array
    size_t capacity_;  // maximum number of elements that can be held

    // Custom implementations
    size_t customStrlen(const char* str) const;
    void customStrcpy(char* dest, const char* src) const;
    void customStrcat(char* dest, const char* src) const;
    const char* customStrstr(const char* haystack, const char* needle) const;
    int customStrcmp(const char* str1, const char* str2) const;

public:
    // Constructors
    MyString();                     // default constructor
    MyString(const MyString& other); // copy constructor
    MyString(const char* str);       // constructor from c-string
    MyString(char c); //single character

    // Destructor
    ~MyString();

    //size_t getSize() const
    //    return size_;
    //}

    // Member functions
    void resize(size_t n);
    size_t capacity() const;
    size_t size() const;
    size_t length() const;
    const char* data() const;
    bool empty() const;
    const char& front() const;
    const char& at(size_t pos) const;
    void clear();
    MyString& operator=(const MyString& other);
    MyString& operator+=(const MyString& other);
    size_t find(const MyString& str, size_t pos = 0) const;

    // Additional functions for extra credit
    bool operator==(const MyString& other) const;
    MyString operator+(const MyString& other) const;

    // Helper functions
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
    friend std::istream& operator>>(std::istream& is, MyString& str);

};
int stoi(const MyString& str);

#endif // MYSTRING_H

