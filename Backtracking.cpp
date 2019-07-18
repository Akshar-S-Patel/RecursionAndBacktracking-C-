#include<iostream>
#include<string>
#include<vector>
#include<conio.h>

using namespace std;

/*
 * Return type : void
 * Args : vector for printing
 * Working : Print the given vector
 */
template <typename type>
void printVector(vector<type>&);

/*
 * Return type : void
 * Args : int for length of binary digits and string for prefix
 * Working : Print every binary number that has exactly the given number of digits.
 */
void printBinaryDigits(int, string = "");

/*
 * Return type : void
 * Args : int for length of decimal digits and string for prefix
 * Working : Print every decimal number that has exactly the given number of digits.
 */
void printDecimalDigits(int, string = "");

/*
 * Return type : void
 * Args : int for number of dice roll and string for prefix
 * Working : It print every possible result of given dices using exhaustive search
 */
void diceRoll_ES(int, string = "");

/*
 * Return type : void
 * Args : int for number of dice roll
 * Working : It print every possible result of given dices using backtracking
 * And it's helper
 */
void diceRoll_BT(int);
void diceRoll_BT(int, vector<int>&); // This is Helper function

/*
 * Return type : void
 * Args : 1st int for number of dice roll
 *        2nd int for desire sun
 *        3rd for sun so far
 *        and last for vector
 * Working : Give only such result that has total sun as desire sum
 */
void diceSum(int, int);
void diceSum(int, int, int, vector<int>&); // This is Helper function

/*
 * Return type : void
 * Args : string for permute auxiliary sting to keep track  of chosen string
 * Working : Print all permutation for the given string.
 */
void permute(string);
void permute(string, string); // This is helper function

/*
 * Return type : void
 * Args : vector of string for list and vector of string for keep track of chosen value
 * Working : print all possible sublist of a given list
 */
void sublist(vector<string>&);
void sublist(vector<string>&, vector<string>&); // This is helper function

/*
 * Exhaustive Search -> in recursive case choose > search
 * Example -> printBinaryDigits(3) , printDecimalDigits(2) , diceRoll_ES(2){It is kind of combination problem}
 * Permutation and Combination (backtracking) -> in recursive case choose > Explore > Un-choose
 * Example ->  diceRoll_BT(2) , diceSum(4, 9), permute("Akshar"), sublist(vector)
 */
int main() {
    cout << "printBinaryDigits(3) : " << endl;
    printBinaryDigits(3);
    cout << endl;
    getch();

    cout << "printDecimalDigits(2) : " << endl;
    printDecimalDigits(2);
    cout << endl;
    getch();

    cout << "diceRoll_ES(2) : " << endl;
    diceRoll_ES(2);
    cout << endl;
    getch();

    cout << "diceRoll_BT(2) : " << endl;
    diceRoll_BT(2);
    cout << endl;
    getch();

    cout << "diceSum(4, 9) : " << endl;
    diceSum(4, 9);
    cout << endl;
    getch();

    cout << "permute(\"Akshar\") : " << endl;
    permute("Akshar");
    cout << endl;
    getch();

    vector<string> sl = {"Jane", "Bob", "Matt", "Sara"};
    cout << "sublist(";
    printVector(sl);
    cout << ") : "<< endl;
    sublist(sl);
    cout << endl;
    getch();
}

template <typename type>
void printVector(vector<type>& v) {
    cout << "{";
    for(int i = 0; i < v.size(); i++) {
        if(i == 0)
            cout << " " << v[i];
        else
            cout << ", " << v[i];
    }
    cout << " }";
}

void printBinaryDigits(int digits, string prefix) {
    if (digits == 0)
        cout << prefix << endl;
    else {
        printBinaryDigits(digits - 1, prefix + "0");
        printBinaryDigits(digits - 1, prefix + "1");
    }
        /* add 0 and 1 at last
     * printBinaryDigits(3 , "")
     *    printBinaryDigits(2, "0")
     *        printBinaryDigits(1, "00")
     *            printBinaryDigits(0, "000")
     *            printBinaryDigits(0, "001")
     *        printBinaryDigits(1, "01")
     *            printBinaryDigits(0, "010")
     *            printBinaryDigits(0, "011")
     *    printBinaryDigits(2, "1")
     *        printBinaryDigits(1, "10")
     *            printBinaryDigits(0, "100")
     *            printBinaryDigits(0, "101")
     *        printBinaryDigits(1, "11")
     *            printBinaryDigits(0, "110")
     *            printBinaryDigits(0, "111")
     */
}

void printDecimalDigits(int digits, string prefix) {
    if (digits == 0)
        cout << prefix << endl;
    else {
        //You can use for loop however i does not have Int_to_string function
        //so i use this redundant trick :-(
        printDecimalDigits(digits - 1, prefix + "0");
        printDecimalDigits(digits - 1, prefix + "1");
        printDecimalDigits(digits - 1, prefix + "2");
        printDecimalDigits(digits - 1, prefix + "3");
        printDecimalDigits(digits - 1, prefix + "4");
        printDecimalDigits(digits - 1, prefix + "5");
        printDecimalDigits(digits - 1, prefix + "6");
        printDecimalDigits(digits - 1, prefix + "7");
        printDecimalDigits(digits - 1, prefix + "8");
        printDecimalDigits(digits - 1, prefix + "9");
        //for(int i = 0; i <= 9; i++)
        //    printDecimalDigits(digits - 1, prefix + Int_to_String(i));
    }
}

void diceRoll_ES(int dice, string prefix) {
    if (dice == 0)
        cout << "{" << prefix << "}" << endl;
    else {
        //You can use for loop however i does not have Int_to_string function
        //so i use this redundant trick :-(
        diceRoll_ES(dice - 1, prefix + " 1 ");
        diceRoll_ES(dice - 1, prefix + " 2 ");
        diceRoll_ES(dice - 1, prefix + " 3 ");
        diceRoll_ES(dice - 1, prefix + " 4 ");
        diceRoll_ES(dice - 1, prefix + " 5 ");
        diceRoll_ES(dice - 1, prefix + " 6 ");
    //for(int i = 1; i <= 6; i++)
        //    diceRoll(digits - 1, prefix + Int_to_String(i));
    }
}

void diceRoll_BT(int dice) {
    vector<int> v;
    diceRoll_BT(dice, v);
}

void diceRoll_BT(int dice, vector<int>& v) {
    if(dice == 0) {
        printVector(v);
        cout << endl;
    } else {
        for (int i = 1; i <= 6; i++) {          // For each value of dice
            v.push_back(i);                     // Choose
            diceRoll_BT(dice - 1, v);    // Explore
            v.pop_back();                       // Un-Choose
        }
    }
}

void diceSum(int dice, int desireSum) {
    vector<int> v;
    diceSum(dice, desireSum, 0, v);
}

void diceSum(int dice, int desireSum, int sumSoFar, vector<int>& v) {
    if(dice == 0) {
        printVector(v);
        cout << endl;
    } else {
        for (int i = 1; i <= 6; i++) {                                  // For each value of dice
            if(sumSoFar + i + 1*(dice - 1) <= desireSum &&
               sumSoFar + i + 6*(dice - 1) >= desireSum) {
                v.push_back(i);                                         // Choose
                diceSum(dice - 1, desireSum, sumSoFar + i, v);    // Explore
                v.pop_back();                                           // Un-Choose
            }
        }
    }
}

void permute(string s) {
    permute(s, "");
}
void permute(string s, string chosen) {
    if (s == "") {
        cout << chosen << endl;
    } else {
        for(int i = 0; i < s.length(); i++) {
            // choose - 1 letter
            char c = s[i];
            chosen += c;
            s.erase(i, 1);

            // explore
            permute(s, chosen);

            // Un - choose - 1 letter
            s.insert(i, 1, c);
            chosen.erase(chosen.length() - 1, 1);
        }
    }
}

void sublist(vector<string>& v) {
    vector<string> chosen;
    sublist(v, chosen);
}

void sublist(vector<string>& v, vector<string>& chosen) {
    if (v.empty()) {
        printVector(chosen);
        cout << endl ;
    } else {
        string first = v[0];
        v.erase(v.begin());

        // choose and explore with it
        chosen.push_back(first);
        sublist(v, chosen);
        // choose and explore without it
        chosen.pop_back();
        sublist(v, chosen);

        v.insert(v.begin(), first);
    }
}

