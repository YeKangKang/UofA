#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

/*  addZero function
    if s1 != s2 than
    return abs(s1-s2)   */
string addZero(string first, string second)
{
    string zero = "";

    for (int i = 0; i < abs((int)(first.length() - second.length())); i++)
    {
        zero += "0";
    }

    return zero;
}

/*  addition function
    NEED (s1, s2, base)
    add two num together, have a carrer     */
string add(string f, string s, int b)
{
    // Add zero
    if (f.length() < s.length())
    {
        f = addZero(f, s) + f;
    }
    else
    {
        s = addZero(f, s) + s;
    }

    // add part
    int carry = 0;
    int temp_result;
    string result = "";
    for (int i = f.length() - 1; i > -1; i--)
    {
        temp_result = (f[i] - '0') + (s[i] - '0') + carry; // ASCII
        if (temp_result >= b)
        {
            carry = temp_result / b;       // 取进位
            temp_result = temp_result % b; // 取余
        }
        else
        {
            carry = 0;
        }
        result = char(temp_result + '0') + result; // ASCII
    }
    if (carry != 0)
    {
        result = char(carry + '0') + result; // ASCII
    }

    return result;
}

/*  sub function
    NEED (s1, s2, base)
    sub two num, have a carrer  */
string sub(string f, string s, int b)
{
    // Add Zero
    if (f.length() < s.length())
    {
        f = addZero(f, s) + f;
    }
    else
    {
        s = addZero(f, s) + s;
    }

    // sub part
    int carry = 0;
    int temp_result;
    string result = "";
    for (int i = f.length() - 1; i > -1; i--)
    {
        temp_result = (f[i] - '0') - (s[i] - '0') - carry;
        if (temp_result < 0)
        {
            temp_result = temp_result + b; // 2-3 (base10 is 2+10-3= 9 and carry=1)
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        result = char(temp_result + '0') + result;
    }
    return result;
}

/*  conv function
    NEED (num, base)
    return string
    it convert input number into given bises
    it treat num as base 10
    e.g. num=12 base=2 it return "1100"     */
// string conv(int num, int b)
// {
//     string conv_result = "";
//     // base case
//     if (num < b)
//     {
//         conv_result = to_string(num) + conv_result; // add last num to string
//         return conv_result;
//     }
//     else
//     {
//         int next_num = num / b;                         // e.g. 10/6=1 in next 1/6=0
//         conv_result = to_string(num % b) + conv_result; // prepend
//         return conv(next_num, b);
//     }
// }
string conv(int num, int b)
{
    string mul = ""; // to save result in given base
    while (num > 0)  // num > 0 means num need to be reduice
    {
        mul = to_string(num % b) + mul; // prepend
        num = num / b;                  // e.g. 10/6=1 in next 1/6=0
    }
    return mul;
}

/*  karatsuba function
    NEED (f, s, base)
    return string
    it divided big number to small part do mutiple and convert
    to given bases than use add() sum() times B^2k get result
    *a1, a0, b1, b0 stands for divided part
    *p0, p1, p2 stand for times operator        */
string karatsuba(string f, string s, int b)
{
    // Add Zero
    if (f.length() < s.length())
    {
        f = addZero(f, s) + f;
    }
    else
    {
        s = addZero(f, s) + s;
    }

    // caratsuba part
    // caratsuba base case
    if (f.length() <= 1 && s.length() <= 1)
    {
        int fi, si;
        fi = f[0] - '0';
        si = s[0] - '0';
        string mul_result = conv(fi * si, b); // if n=1 the biggest answer is 81, wont overflow
        return mul_result;
    }
    else
    {
        // divided
        int mid_point = f.length() / 2;

        /* ####### Maybe wrong ####### */
        // string a1 = f.substr(0, f.length() - 1 - mid_point);              // bigpart
        // string a0 = f.substr(f.length() - 1 - mid_point, f.length() - 1); // smallpart
        // string b1 = s.substr(0, s.length() - 1 - mid_point);              // bigpart
        // string b0 = s.substr(s.length() - 1 - mid_point, s.length() - 1); // smallpart
        string a1(f.begin(), f.end() - mid_point); // bigpart
        string a0(f.end() - mid_point, f.end());   // smallpart
        string b1(s.begin(), s.end() - mid_point); // bigpart
        string b0(s.end() - mid_point, s.end());   // smallpart
        /* ####### Maybe wrong ####### */

        string p_0, p_1, p_2;
        string a1a0, b1b0;

        // recurtion
        p_0 = karatsuba(a1, b1, b); // multiple 1 for big * big
        p_1 = karatsuba(a0, b0, b); // mul 2 for small * small

        a1a0 = add(a1, a0, b);
        b1b0 = add(b1, b0, b);

        p_2 = karatsuba(a1a0, b1b0, b);

        string p0p1 = add(p_0, p_1, b);
        string middle = sub(p_2, p0p1, b);

        // add for big part p_0, given base ^ k
        string power_k = "";
        for (int i = 0; i < mid_point; i++)
        {
            power_k = power_k + "0";
        }
        string p_0_power_k = p_0 + power_k + power_k;
        middle = middle + power_k;

        string temp = add(p_0_power_k, middle, b);
        string result = add(temp, p_1, b);
        //return result;

        // remove all 0 prepend
        int i = 0;
        string final = "";
        while (result[i] == '0' && i < (int)result.length())
        {
            i++;
        }
        final = result.substr(i, result.length());
        return final;
    }
}

int main()
{
    // int f;
    // int b;
    // cout << "input for f: ";
    // cin >> f;
    // // cout << "input for s: ";
    // // cin >> s;
    // cout << "input for b: ";
    // cin >> b;

    // string z = conv(f, b);

    // // // int a = (int)f[0] - 48;
    // // // int c = (int)s[0] - 48;

    // // // cout << "f[0] is: " << a << endl;
    // // // cout << "s[0] is: " << c << endl;

    // cout << "convert is: " << z;

    string cin1, cin2;
    int b;

    cin >> cin1;
    cin >> cin2;
    cin >> b;

    string result = "";
    string result2 = "";
    result = add(cin1, cin2, b);

    result2 = karatsuba(cin1, cin2, b);
    cout << result << " " << result2 << endl;

    return 0;
}