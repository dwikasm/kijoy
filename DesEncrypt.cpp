// PROGRAM UNTUK MELAKUKAN DES ENCRYPT
#include<iostream>
#include<string>
#include<bitset>
using namespace std;

// FUNGSI SHIFT LEFT
string shiftleft(string input)
{
    string output = input;
    for(int i=0; i<input.size(); i++)
    {
        if(i==input.size()-1) output[i]=input[0];
        else output[i]=input[i+1];
    }
    return output;
}

// FUNGSI PERMUTASI
string permutate(string input, int table[], int tablesize)
{
    string output="", temp="";
    for(int i=0; i<tablesize; i++)
    {
        temp = input[table[i]-1];
        output.append(temp);
    }
    return output;
}

int main()
{
    string  msg = "",
            msg_binary = "",
            m = "",
            key = "",
            key_binary = "",
            k[17] = "",
            c[17] = "",
            d[17] = "",
            l[17] = "",
            r[17] = "";
    int PC1[56] =  {57,49,41,33,25,17,9,
                    1,58,50,42,34,26,18,
                    10,2,59,51,43,35,27,
                    19,11,3,60,52,44,36,
                    63,55,47,39,31,23,15,
                    7,62,54,46,38,30,22,
                    14,6,61,53,45,37,29,
                    21,13,5,28,20,12,4};
    int PC2[48] =  {14,17,11,24,1,5,
                    3,28,15,6,21,10,
                    23,19,12,4,26,8,
                    16,7,27,20,13,2,
                    41,52,31,37,47,55,
                    30,40,51,45,33,48,
                    44,49,39,56,34,53,
                    46,42,50,36,29,32};
    int IP[64] =   {58,50,42,34,26,18,10,2,
                    60,52,44,36,28,20,12,4,
                    62,54,46,38,30,22,14,6,
                    64,56,48,40,32,24,16,8,
                    57,49,41,33,25,17,9,1,
                    59,51,43,35,27,19,11,3,
                    61,53,45,37,29,21,13,5,
                    63,55,47,39,31,23,15,7};
    int s[8][4][16]=
    {
        {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
        ,
        {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
        ,
        {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
        ,
        {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
        ,
        {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
        ,
        {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
        ,
        {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
        ,
        {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
    };
    cout << "\t=== DES Encryptor ===" << endl;
    cout << "\nInput message (exactly 8 characters) :\n>";
//    getline(cin, msg, '\n');
    msg = "COMPUTER";
    cout << "\nInput key (exactly 16 hex characters) :\n>";
//    getline(cin, key, '\n');
    key = "0123456789ABCDEF";
    cout << "\nMessage used : '";
    for(int i=0; i<8; i++) cout << msg[i];
    cout << "'" << endl;
    cout << "Key used : '";
    for(int i=0; i<16; i++) cout << key[i];
    cout << "'" << endl;

//    NGUBAH PLAINTEXT KE BINARY
    for(int ctr=0; ctr<8; ctr++)
    {
        bitset<8> msg_bin(msg[ctr]);
        string temp;
        temp = msg_bin.to_string();
        msg_binary.append(temp);
    }
    cout << "Message in binary :\n> " << msg_binary << endl;
    cout << "Message size = " << msg_binary.size() << endl;

//    NGUBAH KEY KE BINARY
    for(int ctr=0; ctr<16; ctr++)
    {
        switch(key[ctr])
        {
            case '0': key_binary.append("0000"); break;
            case '1': key_binary.append("0001"); break;
            case '2': key_binary.append("0010"); break;
            case '3': key_binary.append("0011"); break;
            case '4': key_binary.append("0100"); break;
            case '5': key_binary.append("0101"); break;
            case '6': key_binary.append("0110"); break;
            case '7': key_binary.append("0111"); break;
            case '8': key_binary.append("1000"); break;
            case '9': key_binary.append("1001"); break;
            case 'A': key_binary.append("1010"); break;
            case 'B': key_binary.append("1011"); break;
            case 'C': key_binary.append("1100"); break;
            case 'D': key_binary.append("1101"); break;
            case 'E': key_binary.append("1110"); break;
            case 'F': key_binary.append("1111"); break;
        }
    }
    cout << "key_binary : \n> " << key_binary << endl;
    k[0] = permutate(key_binary, PC1, sizeof(PC1)/sizeof(PC1[0]));
    cout << "k[0] :\n> " << k[0] <<endl;
    c[0] = k[0].substr(0,k[0].size()/2);
    d[0] = k[0].substr(k[0].size()/2,k[0].size()/2);
    cout<< "c[0] = " << c[0]<<endl;
    cout<< "d[0] = " << d[0]<<endl;
    for(int i=1; i<17; i++)
    {
        if(i==1 || i==2 || i==9 || i==16)
        {
            c[i] = shiftleft(c[i-1]);
            d[i] = shiftleft(d[i-1]);
        } else
        {
            c[i] = shiftleft(c[i-1]);
            c[i] = shiftleft(c[i]);
            d[i] = shiftleft(d[i-1]);
            d[i] = shiftleft(d[i]);
        }
//        cout << c[i] << " : " << d[i] <<endl;
        k[i].append(c[i]);
        k[i].append(d[i]);
        k[i] = permutate(k[i], PC2, sizeof(PC2)/sizeof(PC2[0]));
        cout << "k[" << i << "] = " << k[i] <<endl;
    }
    m = permutate(msg_binary, IP, sizeof(IP)/sizeof(IP[0]));
    l[0] = m.substr(0,m.size()/2);
    r[0] = m.substr(m.size()/2,m.size()/2);
    cout << l[0] << endl;
    cout << r[0] << endl;
    for(int i=1; i<17; i++)
    {
//        l[i]=r[i-1];
//        r[i]=l[i-1]XOR f(r[i-1],k[i])
    }
}
