#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;

// Function Declaration :-

/* Return : void
 * Args : int for counting and char for symbol
 * Working : It takes int : how many time do u want to print
 *            and char : which symbol do you want to print.
 */
void print(int = 5, char = '*');

/* Return : double as an answer
 * Args : double for base and int for exp
 * Working : It calculate base to the power of exp (base ^ exp).
 * Pre-Condition : Do not pass real number for exp
 */
double power(double , int);

/* Return : boolean -> true if string is palindrome
 * Args : string
 * Working : It checks that the string is palindrome or not.
 */
bool isPalindrome(string);

/* Return : void
 * Args : int for number in base 10
 * Working : It takes number in base 10 as an args and print its binary
 */
void printBinary(int);

/* Return : void
 * Args : ifstream for read data from the file
 * Working : Without using any data structure reverse the line of given file.
 */
void reverseLines(ifstream&);


/*
 * Recursion - if(something) {
 *                  easy case
 *                  base case
 *             } else {
 *                  hard case
 *                  recursive case
 *             }
 */
int main() {
    print();
    cout << endl;
    cout << "power(2, -3) = " << power(2, -3) << endl;
    cout << "isPalindrome(\"racecar\") = " << isPalindrome("racecar") << endl;
    cout << "printBinary(-50) = ";
    printBinary(-50);
    cout << endl;
    cout<< "Reading a file :-" << endl;
    ifstream file;
    file.open("Recursion.txt");
    reverseLines(file);
    file.close();
    getch();
}

void print(int n, char ch) {
    /* More efficient :-)
     * cout << ch;
     * if (num > 1) {
     *      print(n - -1, ch)
     *  }
     */
    if (n == 1)  //Base Case
        cout << ch;
    else { // Recursive Case
        cout << ch;
        print(n - 1, ch);
    }
}

double power(double base, int exp) {
    //b ^ e
    if (exp < 0)
        return 1.0 / power(base, -exp);
    else if (exp == 0)
        return 1.0;
    else
        return base * power(base, exp - 1);
}

bool isPalindrome(string s) {
    if (s.length() < 2)
        return true;
    else {
        if (s[0] == s[s.length() - 1])
            return isPalindrome(s.substr(1, s.length() - 2));
        else
            return false;
    }
}

void printBinary(int n) {
    if(n < 0) {
        cout << '-' ;
        printBinary(-n);
    } else if(n < 2)
        cout << n;
    else {
        printBinary(n / 2);
        cout << n % 2;
    }
}

void reverseLines(ifstream& input) {
    string line;
    if (getline(input, line)) {
        reverseLines(input);
        cout << line << endl;
    }
}

