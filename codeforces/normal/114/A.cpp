/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x, y;
    cin >> x;
    cin >> y;
    bool valid = true;
    long long counter = 0;
    while ( y != 1){
        //cout << y << " " << x << endl;
        if (y % x != 0){ valid = false; break;}
        y/= x;
        counter++;
    }
    
    if (valid){
        cout << "YES\n" << counter - 1; 
    }else{
        cout << "NO";
    }

    return 0;
}