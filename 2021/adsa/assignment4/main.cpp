#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct road {
    int cost;
    int row, col;               // the city Array.  1 2 means the Road connect city 1 and 2
} Road[1000];

int check_connected[300];



int Check_connected(int check) {
    if (check != check_connected[check]) {          // not connected, need to build
        check = Check_connected( check_connected[check] );
    }
    return check;
}

// count total num of country until meet first comma
int TotalCountry(string input) {
    int num = 0;
    for (int i=0; i<(int)input.length(); i++) {
        if (input[i] != ',') {
            num = num + 1;
        }
        else {
            return num;
        }
    }
    return 0;                                       // if have 1 country
}

// s2i Turn input character from ASCII to int
int* s2i(int* arr, int num_of_array) {
    for (int i = 0; i<(int)num_of_array; i++) {
        if (arr[i]==48) {                       // char '0' = 48
            arr[i] = arr[i] - 48;
        }
        else if (arr[i]==49) {                  // char '1' = 49
            arr[i] = arr[i] - 48;
        }
        else if (arr[i]>=97 && arr[i]<=122) {   // 'a' to 'z'
            arr[i] = arr[i] - 71;
        }
        else if (arr[i]>=65 && arr[i]<=90) {    // 'A' to 'Z'
            arr[i] = arr[i] - 65;
        }
    }
    return arr;
}

bool sort_help(road r1, road r2) {
    if (r1.cost < r2.cost) {
        return true;
    }
    return false;
}

int main() {
    // get input
    string In;
    getline(cin, In);

    int total_num_of_country = TotalCountry(In);            // get num of country
    // int total_num_of_country = 0;
    // int t = 0;
    // while (In[t] != ',' || In[t] == '\n') {
    //     total_num_of_country++;
    // }

    // delete white space and comma
    In.erase(remove(In.begin(), In.end(),' '), In.end());   // remove comma
    In.erase(remove(In.begin(), In.end(),','), In.end());   // remove white space


    int lengthOfInput = (int)In.length();
    int temp[lengthOfInput];
    for (int i=0; i<lengthOfInput; i++) {                   // copp input to int arr without change ASCII
        temp[i] = In[i];
    }



    int* Arr = s2i(temp, lengthOfInput);                    // pure input
    //cout << total_num_of_country;


    int Node_table[total_num_of_country][total_num_of_country];
    int Build_table[total_num_of_country][total_num_of_country];
    int Distory_table[total_num_of_country][total_num_of_country];
    int o1 = 0;
    int o2 = 0;

    // set Node_table contain info of connection between country
    for(int i=0; i< total_num_of_country; i++) {
        for (int j=0; j<total_num_of_country; j++) {
            Node_table[i][j] = Arr[o1];
            o1 = o1 + 1;
            //cout << Node_table[i][j] << " ";
        }
    }
    // Build_table show cost of each posiable way
    for(int i=0; i<total_num_of_country; i++) {
        for(int j=0; j<total_num_of_country; j++) {
            Build_table[i][j]=Arr[o1];
            o1 = o1 + 1;
        }
    }
    // Distory_table show cost of each posiable way
    for(int i = 0; i < total_num_of_country; i++) {
        for(int j = 0; j < total_num_of_country; j++) {
            Distory_table[i][j] = Arr[o1];
            o1 = o1 + 1;
            //cout << Distory_table[i][j] << " ";
        }
    }


    int marge_table[total_num_of_country][total_num_of_country];
    for(int i = 0; i < total_num_of_country; i++) {
        for(int j = 0; j < total_num_of_country; j++)
        {
            if (Node_table[i][j] == 1) {        // Have road, distory cost
                marge_table[i][j] = -Distory_table[i][j];
                //cout << marge_table[i][j] << " ";
            }
            else {                              // Don't have Road, build cost
                marge_table[i][j] = Build_table[i][j];
                //cout << marge_table[i][j] << " ";
            }
        }
    }

    // calculate the cost of input table
    int start = 0;                                          // cost of input case
    for(int i=1;i<total_num_of_country;i++) {
        for(int j=0; j<i; j++) {
            if (Node_table[i][j] == 1) {        // have road
                start = start - Distory_table[i][j];
            }
        }
    }

    // push the marge_table into the object
    for(int i=0; i<total_num_of_country; i++) {
        for(int j=i+1; j<total_num_of_country; j++,o2++) {
            Road[o2].row = i;
            Road[o2].col = j;
            Road[o2].cost = marge_table[i][j];
        }
    }

    



    // Use Kruskal to sort and calculate the MST cost
    // use the MST result - start of cost is the final cost
    int result = 0;                                         // Kruskal find MST, this var save the sum of MST
    for (int i=0; i<=total_num_of_country; i++) {           // default: set each node connect to it self
        check_connected[i] = i;
    }

    sort(Road, Road+o2, sort_help);              // sort by length of Road.orst

    for (int i=0; i<o2; i++) {
        int connected_row = Check_connected(Road[i].row);
        int connected_col = Check_connected(Road[i].col);

        if (connected_row != connected_col) {
            check_connected[connected_row] = connected_col;
            result = result + Road[i].cost;             // add cosult to result
        }
    }

    cout << result - start << endl;
}
