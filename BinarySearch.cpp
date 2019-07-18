#include<iostream>
#include<conio.h>
#include<vector>

using namespace std;

/* Return type : Is return index of that element
 * Args : it takes template vector
 * Working : It search element in O(log(n)) time so it is quick
 */
template <typename type>
int binarySearch(vector<type>&, type);

/*
 * This is the helper function of binary search
 */
template <typename type>
int binarySearchHelper(vector<type>&, type, int, int);

int main() {
    int num;
    vector<int> numbers = {-4, 2, 7, 10, 15, 20, 22, 25, 30, 36, 42, 50, 56, 68, 85, 92, 103};
    for(int i : numbers)
        cout << i << " ";
    cout << endl ;
    while(true) {
        cout << "Enter element you want to search :: ";
        cin >> num;
        cout << "It is at index "<< binarySearch(numbers, num) << endl;
    }
    getch();
}

template <typename type>
int binarySearch(vector<type>& v, type value) {
    return binarySearchHelper(v, value, 0, v.size()-1);
}

template <typename type>
int binarySearchHelper(vector<type>& v, type value, int start, int end) {
    int middle = (start + end) / 2;
    if (value == v[middle])
        return middle;
    else if (start > end)
        return -1;
    else if (value < v[middle])
        return binarySearchHelper(v, value, start, middle - 1);
    else //if (value > v[middle])
        return binarySearchHelper(v, value, middle + 1, end);

}
