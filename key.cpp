#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    int q = 353;
    int a = 3;
    int x;
    int k = 1;
    int ya = 1;

    cout << "Pilih angka antara " << a << " dan " << q << ":" << endl;
    cin >> x;
    for (int i=0; i<x; i++){
        ya = ya * a % q;
    }
    cout << ya << endl;

    for (int j=0; j<x; j++){
        k = k * 248 % q;
        //k = k * 40 % q; //Kalau input x = 233
    }
    cout << k << endl;
}
