#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,a,
        xa,xb,
        ya=1,yb=1,
        ka=1,kb=1;
    cout << "Masukkan q: ";
    cin >> q;
    cout << "Masukkan a: ";
    cin >> a;
    //CLIENT A
    cout << "Masukkan xa: ";
    cin >> xa;
    for(int i=0;i<xa;i++) ya=ya*a%q;
    //CLIENT B
    cout << "Masukkan xb: ";
    cin >> xb;
    for(int i=0;i<xb;i++) yb=yb*a%q;
    //KEY CLIENT A
    for(int i=0;i<xa;i++) ka=ka*yb%q;
    cout << "Key di client A adalah : " << ka << endl;
    //KEY CLIENT B
    for(int i=0;i<xb;i++) kb=kb*ya%q;
    cout << "Key di client B adalah : " << kb << endl;
    return 0;
}
