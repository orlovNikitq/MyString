#include <iostream>
#include<map>
#include<fstream>
#include<string>
using namespace std;

class MyString {
    char* arrayStr = nullptr;
    int size = 0;
    int maxSize = 10;
private:
    int countSymbol(const char array2[]) {
        int counter = 0;
        for (int i = 0; array2[i] != '\0'; i++) {
            counter++;
        }
        return counter;
    }
public:
    MyString() {
        arrayStr = new char[maxSize];
    }
    MyString(const char array2[]) :MyString() {

        operator = (array2);
    }
    ~MyString() {
        if (arrayStr != nullptr) delete[]arrayStr;
    }
    void operator = (const char array2[]) {
        int s2 = countSymbol(array2);
        size = s2;
        if (s2 > maxSize) {
            maxSize = s2;
            delete[]arrayStr;
            arrayStr = new char[maxSize];
        }
        for (int i = 0; i < s2; i++) {
            arrayStr[i] = array2[i];
        }
    }
    bool operator!=(const MyString& str) {
        return !(strcmp(arrayStr, str.arrayStr) == 0);
    }
    bool operator>(const MyString& str){
        int i = 0;
        while (arrayStr[i] != '\0' && str.arrayStr[i] != '\0') {
            if (arrayStr[i] > str.arrayStr[i]) {
                return true;
            }
            else if (arrayStr[i] < str.arrayStr[i]) {
                return false;
            }
            i++;
        }
        return arrayStr[i] > str.arrayStr[i];
    }
    bool operator<(const MyString& str) const {
        int i = 0;
        while (arrayStr[i] != '\0' && str.arrayStr[i] != '\0') {
            if (arrayStr[i] < str.arrayStr[i]) {
                return true;
            }
            else if (arrayStr[i] > str.arrayStr[i]) {
                return false;
            }
            i++;
        }
        return arrayStr[i] < str.arrayStr[i];
    }
    bool operator>=(const MyString& str) const {
        int i = 0;
        while (arrayStr[i] != '\0' && str.arrayStr[i] != '\0') {
            if (arrayStr[i] > str.arrayStr[i]) {
                return true;
            }
            else if (arrayStr[i] < str.arrayStr[i]) {
                return false;
            }
            i++;
        }
        return size >= str.size;  
    }
    bool operator<=(const MyString& str) const {
        int i = 0;
        while (arrayStr[i] != '\0' && str.arrayStr[i] != '\0') {
            if (arrayStr[i] < str.arrayStr[i]) {
                return true;
            }
            else if (arrayStr[i] > str.arrayStr[i]) {
                return false;
            }
            i++;
        }
        return size <= str.size;  
    }
    MyString operator+(const MyString& other) const {
        MyString result;
        int newSize = size + other.size;
        if (newSize > result.maxSize) {
            result.maxSize = newSize;
            delete[] result.arrayStr;
            result.arrayStr = new char[result.maxSize];
        }

        for (int i = 0; i < size; i++) {
            result.arrayStr[i] = arrayStr[i];
        }
        for (int i = size, j = 0; j < other.size; i++, j++) {
            result.arrayStr[i] = other.arrayStr[j];
        }
        result.size = newSize;
        return result;
    }
    void operator +=(const char array2[]) {
        int s2 = countSymbol(array2);
        int newSize = s2 + size;
        if (newSize > maxSize) {
            maxSize = newSize;

        }
        char* buf = new char[maxSize];
        for (int i = 0; i < size; i++) {
            buf[i] = arrayStr[i];
        }
        for (int i = size, k = 0; i < newSize; i++) {
            buf[i] = array2[k++];
        }
        delete[]arrayStr;
        arrayStr = buf;
        size = newSize;

    }
    int stoi() {
        int num = 0;
        int index = 0;
        int k = 1;
        if (arrayStr[0] == '-') {
            k = -1;
            index = 1;
        }

        for (int i = index; i < size; i++) {
            num = num * 10 + arrayStr[i] - '0';
        }
        num *= k;
        return num;
    }
    void show() {
        for (int i = 0; i < size; i++) {
            cout << arrayStr[i];
        }
    }
    int getSize() {
        return size;
    }
    bool empty() {
        if (size == 0) return true;
        else return false;
    }
    void clear() {
        if (arrayStr != nullptr) {
            delete[] arrayStr;
            arrayStr = new char[maxSize];
        }
        size = 0;
    }
    void pop() {
        if (size > 0) {
            int newSize = size - 1;
            char* buf = new char[newSize];

            for (int i = 0; i < newSize; i++) {
                buf[i] = arrayStr[i];
            }

            delete[] arrayStr;
            arrayStr = buf;
            size = newSize;
        }
    }
    void push(char newChar) {
        int newSize = size + 1;
        char* buf = new char[newSize];

        for (int i = 0; i < size; i++) {
            buf[i] = arrayStr[i];
        }

        buf[size] = newChar;

        delete[] arrayStr;
        arrayStr = buf;
        size = newSize;
    }
    void insert(int index, const char array2[]) {
        if (index < 0 || index > size) {
            return;
        }

        int s2 = countSymbol(array2);
        int newSize = size + s2;

        if (newSize > maxSize) {
            maxSize = newSize;
            char* buf = new char[maxSize];
            for (int i = 0; i < index; i++) {
                buf[i] = arrayStr[i];
            }
            for (int i = 0; i < s2; i++) {
                buf[index + i] = array2[i];
            }
            for (int i = index; i < size; i++) {
                buf[i + s2] = arrayStr[i];
            }

            delete[] arrayStr;
            arrayStr = buf;
            size = newSize;
        }
        else {
            char* buf = new char[maxSize];
            for (int i = 0; i < index; i++) {
                buf[i] = arrayStr[i];
            }
            for (int i = 0; i < s2; i++) {
                buf[index + i] = array2[i];
            }
            for (int i = index; i < size; i++) {
                buf[i + s2] = arrayStr[i];
            }
            delete[] arrayStr;
            arrayStr = buf;
            size = newSize;
        }
    }
    /*bool operator!=(const char array2[]) const {
        int i = 0;
        while (arrayStr[i] != '\0' || array2[i] != '\0') {
            if (arrayStr[i] != array2[i]) {
                return true;
            }
            i++;
        }
        return false;
    }*/
    
};
//insert

int main() {
    MyString str1("strict");
    MyString str2("strum");
    MyString str3("strict");

    // проверка !=
    /*
    if (str1 != "strict") {
        cout << "str1 != 'strict'";
    }
    else {
        cout << "str1 = strict";
    }
    
    */
    //проверка =
    /*
    str1 = "asd";
    str1.show();
    */
    //проверка size
    /*
    int maxSize = str2.getSize();
    cout << maxSize;
    */
    //проверка empty
    /*
    bool empty = str3.empty();
    cout << empty;
    */
    //проверка clear
    /*
    str3.clear();
    bool empty = str3.empty();
    cout << empty;
    */
    //проверака pop 
    /*
    str1.pop();
    str1.show();
    str1.pop();
    str1.show();
    */
    //проверка push 
    /*
    str1.push('d');
    str1.show();
    */
    //проверака <
    /*
    if (str1 < str2) {

        cout << "true" << endl;
    }
    else cout << "false";
    */
    //проверка >
    /*
    if (str1 > str2) {
        cout << "true" << endl;
    }
    else cout << "false";
    */
    //проверка <=
    /*
    if (str1 <= str2) {
        cout << "str1 <= str2" << endl;
    }
    else {
        cout << "str1 > str2" << endl;
    }

    if (str2 <= str3) {
        cout << "str1 >= str3" << endl;
    }
    else {
        cout << "str1 < str3" << endl;
    }
    */
    //проверка >=
    /*
    if (str1 >= str2) {
        cout << "str1 <= str2" << endl;
    }
    else {
        cout << "str1 > str2" << endl;
    }

    if (str2 >= str3) {
        cout << "str1 >= str3" << endl;
    }
    else {
        cout << "str1 < str3" << endl;
    }
    */
    //проверка +
    /*
    MyString result = str1 + str2;
    result.show();
    */
    //проверка insert
    str1.insert(2, "123"); 
    str1.show();
}