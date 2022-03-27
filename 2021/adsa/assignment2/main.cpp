#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    int height;
    Node* left;
    Node* right;
    Node(int input_value) {     // constructure
        value = input_value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};


int height(Node* X) {
    if (X == NULL) {
        return 0;
    }
    else {
        return X->height;
    }
}


void Set_Height(Node* current_node){
    current_node->height = max(height(current_node->left), height(current_node->right)) + 1;
}


int Get_Balance_Factor(Node* current_node){
    return height(current_node->left) - height(current_node->right);
}


Node* Left_Turn(Node* current_node) {
    // left rotate focuse on right and right_left node, right_left node will connect current_node's right node
    // in the end
    Node* c_right = current_node->right;
    Node* c_right_left = c_right->left;

    c_right->left = current_node;   // Now c_right->left is origin current_node
    current_node->right = c_right_left;     // also origin current_node's right now is c_right_left

    Set_Height(current_node);
    Set_Height(c_right);
    return c_right;     // c_right is Root Now (Actiualy Not, it is the top of THIS SUB-TREE)!!!!!!!!!!!!!!!
}


Node* Right_Turn(Node* current_node) {
    Node* c_left = current_node->left;
    Node* c_left_right = c_left->right;

    c_left->right = current_node;
    current_node->left = c_left_right;

    Set_Height(current_node);
    Set_Height(c_left);
    return c_left;
}


Node* Turn(Node* current_node, int value) {
    // balance_fac show the diff between given node L-R height
    int balance_fac = Get_Balance_Factor(current_node);

    if (balance_fac < -1) {     // L-R<-1, OVERALL RIGHT HEAVY TREE (Right Heavy || Right Left Heavy)!!!!!!!!
        if (value > current_node->right->value) {
            return Left_Turn(current_node);     // Net Right Heavy
        }
        else if (value < current_node->right->value) {
            current_node->right = Right_Turn(current_node->right);  // Right-Left Heavy, Do Right-Left Turn!!!!!!!
            return Left_Turn(current_node);     // last Left Turn
        }
    }
    if (balance_fac > 1) {     // L-R>1, OVERALL LEFT HEAVY TREE (Left Heavy || Left Right Heavy)
        if (value < current_node->left->value) {
            return Right_Turn(current_node);
        }
        if (value > current_node->left->value) {
            current_node->left = Left_Turn(current_node->left);     // L-R Turn
            return Right_Turn(current_node);
        }
    }
    return current_node;
}


Node* Add_Node(Node* current_node, int value) {
    // if current_node is NULL, means can add.
    if (current_node == NULL) {
        Node* new_node = new Node(value);
        return new_node;
    }
    else {
        if (value < current_node->value) {  // go left
            current_node->left = Add_Node(current_node->left, value);
        }
        if (value > current_node->value) {  // go right
            current_node->right = Add_Node(current_node->right, value);
        }
    }
    Set_Height(current_node);       // any new_node have height=1
    return Turn(current_node, value);
}


/*  
    L_Max()
    return a Node with biggest value in l-subtree
*/
Node* L_Max(Node* current_node) {
    if (current_node->right == NULL) {   // left tree biggest is the most right
        return current_node;
    }
    else {
        return L_Max(current_node->right);
    }
}


Node* Delete_Node(Node* current_node, int value) {
      
    if (current_node == NULL) {
        return current_node;
    }
    if ( value < current_node->value ) {    // if less, FIND LEFT TREE
        current_node->left = Delete_Node(current_node->left, value);
    }
    else if( value > current_node->value ) {    // if big, FIND RIGHT TREE
        current_node->right = Delete_Node(current_node->right, value);
    }
    else {  // == FIND!!!!!!!!
        if( (current_node->left == NULL) || (current_node->right == NULL)) {
            Node *temp = current_node->left ? current_node->left : current_node->right;
            if (temp == NULL) {
                temp = current_node;
                current_node = NULL;
            }
            else {
                *current_node = *temp;
            }
            free(temp);
        }
        else {
            // target nede have TWO CHILD, IMPORTANT!!!
            Node* temp = L_Max(current_node->left);
            current_node->value = temp->value;      // First, change the left biggest value to current_node
            current_node->left = Delete_Node(current_node->left,temp->value);   // delete the left biggest nude, tach to current_node->left.
        }
    }


    if (current_node == NULL) {
        return current_node;
    }
    
    Set_Height(current_node);
    int balance_fac = Get_Balance_Factor(current_node);        // balance_fac show the diff between given node L-R height

    // LEFT HEAVY //
    if (balance_fac > 1 && Get_Balance_Factor(current_node->left) >= 0) {   // Net Left Heavy, Do Right Turn
        return Right_Turn(current_node);
    }
    if (balance_fac > 1 && Get_Balance_Factor(current_node->left) < 0) {    // Left-Right Heavy, Do Left-Right Turn
        current_node->left = Left_Turn(current_node->left);
        return Right_Turn(current_node);
    }
    // RIGHT HEAVY //
    if (balance_fac < -1 && Get_Balance_Factor(current_node->right) <= 0) { // Net Right Heavy, Do Left Turn
        return Left_Turn(current_node);
    }
    if (balance_fac < -1 && Get_Balance_Factor(current_node->right) > 0) {  // Right-Left Heavy, Do Right-Left Turn
        current_node->right = Right_Turn(current_node->right);
        return Left_Turn(current_node);
    }


    return current_node;
}


void IN(Node* current_node) {
    if (current_node != NULL) {
        IN(current_node->left);
        cout << current_node->value << " ";
        IN(current_node->right);
    }
}

void POST(Node* current_node) {
    if (current_node != NULL) {
        POST(current_node->left);
        POST(current_node->right);
        cout << current_node->value << " ";
    }
}

void PRE(Node* current_node) {
    if (current_node != NULL) {
        cout << current_node->value << " ";
        PRE(current_node->left);
        PRE(current_node->right);
    }
}

int main() {
    Node* Root = NULL;  // default

    vector<string> str_vec;
    string temp;
    string line;
    getline(cin, line);
    stringstream input(line);

    while(input >> temp){
        str_vec.push_back(temp);
    }

    for(int i=0; i<(int)str_vec.size(); i++) {
        if(str_vec[i][0] == 'A') {
            str_vec[i].erase(0,1);
            Root = Add_Node(Root, stoi(str_vec[i]));
        }
        else if (str_vec[i][0] == 'D') {
            str_vec[i].erase(0,1);
            Root = Delete_Node(Root, stoi(str_vec[i]));
        }
        else if (str_vec[i] == "IN") {
            if(Root == NULL) {
                cout << "EMPTY" << endl;
            }
            else {
                IN(Root);
            }
        }
        else if (str_vec[i] == "POST") {
            if(Root == NULL) {
                cout << "EMPTY" << endl;
            }
            else {
                POST(Root);
            }
        }
        else if (str_vec[i] == "PRE") {
            if(Root == NULL) {
                cout << "EMPTY" << endl;
            }
            else {
                PRE(Root);
            }
        }
    }
    return 0;
}
