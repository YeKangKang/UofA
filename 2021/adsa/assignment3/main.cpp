#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HASHTABLE {
public:
    vector<string> hash;    // size=26, 0-25 repesent 'a'-'z'
    vector<bool> tomb;      // size=25, true IF 'a'-'z' being delete

    HASHTABLE() {
        // set hash and tomb size=26 && to defult
        for (int i=0; i<26; i++) {
            hash.push_back("");
            tomb.push_back(false);
        }
    };
    
    ~HASHTABLE() {};

    // function: Find(string) return an int
    // 1. index if searched element
    // 2. 99, if not find for given KEY
    int Find(string var) {
        int KEY;
        KEY = var[var.length() - 1] - 'a';      // ASCII of 'a' = 97, get index of start point


        // SEARCH IN TABLE
        // 1. FIND, if in first position of KEY
        if (hash[KEY] == var && tomb[KEY] == false) {
            return KEY;
        }
        // 2. first position of KEY is OCCUPIED
        else {
            int index = KEY + 1;
            while (index != KEY) {  // loop untill it meet the KEY again
                // check from begin
                if (index > 25) {
                    index = index % 26;
                }
                if (index == KEY) {
                    break;
                }

                
                // FIND
                if (hash[index] == var && tomb[index] == false) {
                    return index;
                }
                // 'var' class slot NEVER USED, stop
                else if (hash[index] == "" && tomb[index] == false) {
                    return 99;
                }
                index++;
            }
            return 99;  // not find
        }

        return 99;  // not find
    }

    // function Inseart(string) inseart var
    // by check if var is already in hash
    void Inseart(string var) {
        // ALREADY in hash
        if (Find(var) != 99) {
            return;
        }


        int KEY = var[var.length() - 1] - 'a';

        // not-occupide
        if (hash[KEY]=="" || tomb[KEY]==true) {
            // inseart
            hash[KEY] = var;
            tomb[KEY] = false;  // occupied
        }
        else {
            int index = KEY + 1;
            while (index != KEY) {
                if (index > 25) {
                    index = index % 26;
                }
                if (index == KEY) {
                    break;
                }


                // Find not-occupide
                if (hash[index]=="" || tomb[index]==true) {
                    // inseart
                    hash[index] = var;
                    tomb[index] = false;
                    return;
                }
                index++;
            }
        }

        return;
    }

    // function Delete(string) delete var by
    // check if it can be find
    // 1. find, set tomb to true
    // 2. not find, do nothing
    void Delete(string var) {
        int Check_index = Find(var);

        // Check_index == 99, not find
        if (Check_index == 99) {
            return;
        }
        else {
            // tomb[index] = true for reused
            tomb[Check_index] = true;
        }
        return;
    }

    // SHOW() print the hashtable
    void SHOW() {
        bool space = false;

        // for all elements in hash
        for (int i=0; i<(int)hash.size(); i++) {
            // if not "" OR tomb == false
            if (hash[i]!="" && tomb[i]!=true) {
                if (space == true) {
                    cout << " ";    // connect each element
                }

                cout << hash[i];

                if (space == false) {
                    space = true;
                }
            }
        }

        cout << endl;
        return;
    }
};

int main() {
    string l;
    vector<string> cmd;

    getline(cin, l);
    int number_of_cmd = 0;
    int count = -1;
    // for each l, push to cmd
    for (int i=0; i<(int)l.length(); i++) {

        if (l[i] == ' ' || i == (int)l.length()-1) {
            if (i == (int)l.length()-1) {
                i++;
            }

            cmd.push_back("");

            // for each char in line
            for (int o=count+1; o<i; o++) {
                cmd[number_of_cmd] += l[o];     // add each char in l into cmd
            }
            count = i;  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            number_of_cmd++;
        }
    }

    // call HASHTABLE()
    HASHTABLE H;

    for (int i=0; i<(int)cmd.size(); i++) {
        // A, call Inseart()
        if (cmd[i][0] == 'A') {
            cmd[i].erase(cmd[i].begin());
            H.Inseart(cmd[i]);
        }

        // D, call Delete()
        if (cmd[i][0] == 'D') {
            cmd[i].erase(cmd[i].begin());
            H.Delete(cmd[i]);
        }
    }

    // SHOW()
    H.SHOW();
    return 0;
}
