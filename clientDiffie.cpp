#include <winsock2.h>
#define _WIN32_WINNT 0x502
#include <ws2tcpip.h>
#include <iostream>
#include <string>
#include <thread>
#include<bitset>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define IP_ADDRESS "192.168.0.144"
#define DEFAULT_PORT "3504"
//#define KEY "COMPUTER"
string KEY;

struct client_type
{
    SOCKET socket;
    int id;
    char received_message[DEFAULT_BUFLEN];
};

string asciiToBinary(string input);
string hexToBinary(string input);
string binaryToHex(string input);
string hexToAscii(string input);
string shiftleft(string input);
string permutate(string input, int table[], int tablesize);
string xorr(string input1, string input2, int insize);
string sbox(string input, int table[4][16]);
string f(string input1, string input2);
string des(string input, string key, int mode);
string ctr(string input, int mode);
int process_client(client_type &new_client);
int main();


// FUNGSI ASCII TO BINARY
string asciiToBinary(string input)
{
    string output="", temp;
    for(int i=0; i<input.size(); i++)
    {
        bitset<8> bin(input[i]);
        temp = bin.to_string();
        output.append(temp);
    }
    return output;
}

// FUNGSI HEX TO BINARY
string hexToBinary(string input)
{
    string output="";
    for(int i=0; i<input.size(); i++)
    {
        switch(input[i])
        {
            case '0' : output.append("0000"); break;
            case '1' : output.append("0001"); break;
            case '2' : output.append("0010"); break;
            case '3' : output.append("0011"); break;
            case '4' : output.append("0100"); break;
            case '5' : output.append("0101"); break;
            case '6' : output.append("0110"); break;
            case '7' : output.append("0111"); break;
            case '8' : output.append("1000"); break;
            case '9' : output.append("1001"); break;
            case 'A' : output.append("1010"); break;
            case 'B' : output.append("1011"); break;
            case 'C' : output.append("1100"); break;
            case 'D' : output.append("1101"); break;
            case 'E' : output.append("1110"); break;
            case 'F' : output.append("1111"); break;

        }
    }
    return output;
}

// FUNGSI BINARY TO HEX
string binaryToHex(string input)
{
    string output="", temp;
    for(int i=0;i<input.size();i+=4)
    {
        temp = input.substr(i,4);
        if (!temp.compare("0000")){output.append("0");}
        else if (!temp.compare("0001")){output.append("1");}
        else if (!temp.compare("0010")){output.append("2");}
        else if (!temp.compare("0011")){output.append("3");}
        else if (!temp.compare("0100")){output.append("4");}
        else if (!temp.compare("0101")){output.append("5");}
        else if (!temp.compare("0110")){output.append("6");}
        else if (!temp.compare("0111")){output.append("7");}
        else if (!temp.compare("1000")){output.append("8");}
        else if (!temp.compare("1001")){output.append("9");}
        else if (!temp.compare("1010")){output.append("A");}
        else if (!temp.compare("1011")){output.append("B");}
        else if (!temp.compare("1100")){output.append("C");}
        else if (!temp.compare("1101")){output.append("D");}
        else if (!temp.compare("1110")){output.append("E");}
        else if (!temp.compare("1111")){output.append("F");}
    }
    return output;
}

// FUNGSI HET TO ASCII
string hexToAscii(string input)
{
    string output, temp;
    char chr;
    for(int i=0; i<input.size(); i+=2)
    {
        temp = input.substr(i,2);
        chr = (char) (int)strtol(temp.c_str(), NULL, 16);
        output.push_back(chr);
    }
    return output;
}

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

// FUNGSI XOR
string xorr(string input1, string input2, int insize)
{
    string output="";
    for(int i=0; i<insize; i++)
    {
        if(input1[i] == input2[i]) output.append("0");
        else output.append("1");
    }
    return output;
}

// FUNGSI SBOX
string sbox(string input, int table[4][16])
{
    string kolom="",baris="", output="";
    int kolomi=0, barisi=0, outputi;
    kolom.append(input.substr(1,4));
    baris.append(input.substr(0,1));
    baris.append(input.substr(5,1));
    for(int i=kolom.size()-1 , j=0; i>=0; i--, j++)
    {
        kolomi += (pow(2,j) * ((int)kolom[i]-48));
    }
    for(int i=baris.size()-1 , j=0; i>=0; i--, j++)
    {
        barisi+= (pow(2,j) * ((int)baris[i]-48));
    }
    outputi = table[barisi][kolomi];
    output = bitset<4> (outputi).to_string();
    return output;
}

// FUNGSI F
string f(string input1, string input2)
{
    int E[48] ={32,1,2,3,4,5,
                4,5,6,7,8,9,
                8,9,10,11,12,13,
                12,13,14,15,16,17,
                16,17,18,19,20,21,
                20,21,22,23,24,25,
                24,25,26,27,28,29,
                28,29,30,31,32,1};
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
    int p[32] = {16,7,20,21,
                29,12,28,17,
                1,15,23,26,
                5,18,31,10,
                2,8,24,14,
                32,27,3,9,
                19,13,30,6,
                22,11,4,25};
    string output="";
    input1 = permutate(input1, E, sizeof(E)/sizeof(E[0]));
    input1 = xorr(input1, input2, 48);
    for(int i=0;i<8;i++)
    {
        output.append(sbox(input1.substr(i*6,6),s[i]));
    }
    output = permutate(output, p, sizeof(p)/sizeof(p[0]));
    return output;
}

string des(string input, string key, int mode)
{
    string  m = "",
            k[17] = "",
            c[17] = "",
            d[17] = "",
            l[17] = "",
            r[17] = "",
            output_binary = "",
            output = "",
            temp = "";
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
    int IP1[64] =  {40,8,48,16,56,24,64,32,
                    39,7,47,15,55,23,63,31,
                    38,6,46,14,54,22,62,30,
                    37,5,45,13,53,21,61,29,
                    36,4,44,12,52,20,60,28,
                    35,3,43,11,51,19,59,27,
                    34,2,42,10,50,18,58,26,
                    33,1,41,9,49,17,57,25};
    k[0] = permutate(key, PC1, sizeof(PC1)/sizeof(PC1[0]));
    c[0] = k[0].substr(0,k[0].size()/2);
    d[0] = k[0].substr(k[0].size()/2,k[0].size()/2);
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
        k[i].append(c[i]);
        k[i].append(d[i]);
        k[i] = permutate(k[i], PC2, sizeof(PC2)/sizeof(PC2[0]));
    }
    m = permutate(input, IP, sizeof(IP)/sizeof(IP[0]));
    l[0] = m.substr(0,m.size()/2);
    r[0] = m.substr(m.size()/2,m.size()/2);
    for(int i=1; i<17; i++)
    {
        l[i] = r[i-1];
        if(mode == 1)
            r[i] = xorr(l[i-1],f(r[i-1],k[i]),32);
        else
            r[i] = xorr(l[i-1],f(r[i-1],k[17-i]),32);
    }
    output_binary.append(r[16]);
    output_binary.append(l[16]);
    output_binary = permutate(output_binary, IP1, sizeof(IP1)/sizeof(IP1[0]));
 //NGUBAH KE HEX
    output = binaryToHex(output_binary);
    return output;
}

string ctr(string input, int mode)
{
    string output="", output_ascii="", ctr_binary, temp, c, p;
    int ctr=0;
    if(mode == 1)
    {
        while(input.size()%8!=0)
        {
            input.append(" ");
        }
        input = asciiToBinary(input);
    }
    else
    {
        input = hexToBinary(input);
    }

    string key;
    key = asciiToBinary(KEY);
    for(int i=0; i<input.size(); i+=64, ctr++)
    {
        ctr_binary = bitset<64>(ctr).to_string(); //to binary
        temp = des(ctr_binary,key,1);
        temp = hexToBinary(temp);
        p = input.substr(i,64);
        c = xorr(p,temp,64);
        c = binaryToHex(c);
        output.append(c);
    }
    if(mode == 1)
    {
        return output;
    }else
    {
        output_ascii = hexToAscii(output);
        return output_ascii;
    }

}

int process_client(client_type &new_client)
{
    string klayen, decrypted, dummy;
    while (1)
    {
        memset(new_client.received_message, 0, DEFAULT_BUFLEN);

        if (new_client.socket != 0)
        {
            int iResult = recv(new_client.socket, new_client.received_message, DEFAULT_BUFLEN, 0);

            dummy = new_client.received_message;
            klayen = dummy.substr(0,dummy.find(":")+1);
            decrypted = ctr(dummy.substr(dummy.find(": ")+1), 2);
            klayen = klayen.append(decrypted);

            if (iResult != SOCKET_ERROR)
//                cout << new_client.received_message << endl;
                cout << klayen<< endl;
            else
            {
                cout << "recv() failed: " << WSAGetLastError() << endl;
                break;
            }
        }
    }

    if (WSAGetLastError() == WSAECONNRESET)
        cout << "The server has disconnected" << endl;

    return 0;
}
int stoi(const char *s)
{
    int i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}
int main()
{
    WSAData wsa_data;
    struct addrinfo *result = NULL, *ptr = NULL, hints;
    string sent_message = "";
    client_type client = { INVALID_SOCKET, -1, "" };
    int iResult = 0;
    string message;

    cout << "Starting Client...\n";

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (iResult != 0) {
        cout << "WSAStartup() failed with error: " << iResult << endl;
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    cout << "Connecting...\n";

    // Resolve the server address and port
    iResult = getaddrinfo(static_cast<LPCTSTR>(IP_ADDRESS), DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        cout << "getaddrinfo() failed with error: " << iResult << endl;
        WSACleanup();
        system("pause");
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {

        // Create a SOCKET for connecting to server
        client.socket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (client.socket == INVALID_SOCKET) {
            cout << "socket() failed with error: " << WSAGetLastError() << endl;
            WSACleanup();
            system("pause");
            return 1;
        }

        // Connect to server.
        iResult = connect(client.socket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(client.socket);
            client.socket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (client.socket == INVALID_SOCKET) {
        cout << "Unable to connect to server!" << endl;
        WSACleanup();
        system("pause");
        return 1;
    }

    cout << "Successfully Connected" << endl;

    //Obtain id from server for this client;
    recv(client.socket, client.received_message, DEFAULT_BUFLEN, 0);
    message = client.received_message;

    string encrypted;
    if (message != "Server is full")
    {

        client.id = atoi(client.received_message);

        int q,a,x,ya=1,yb=1,k=1;
        cout<<"Masukkan q: ";
        cin>>q;
        cout<<"Masukkan a: ";
        cin>>a;
        cout<<"Masukkan x: ";
        cin>>x;
        for(int i=0;i<x;i++)ya=ya*a%q;
        //send ya
        string kon=to_string(ya);
        cout << "ya adalah : " << kon << endl;
        send(client.socket, kon.c_str(), strlen(kon.c_str()), 0);
        //recv yb
        recv(client.socket, client.received_message, DEFAULT_BUFLEN, 0);
        cout << "received msg : " << client.received_message <<endl;

        string dummy = client.received_message;
        yb=stoi(dummy.substr(dummy.find(": ")+1));

        cout << "yb adalah : " << yb <<endl;
        for(int i=0;i<x;i++) k=k*yb%q;
        cout << "Key yang dipakai adalah : " << k << endl;
        getchar();
        //int to string k
        string key = to_string(k);
        cout << "key = " << key << endl;
        //if <8 ++++
        while(key.size()<8) key.append("0");
        //KEY = key;
        KEY = key;

//        thread my_thread(process_client, client);
        thread my_thread(process_client, ref(client));

        while (1)
        {
            getline(cin, sent_message);
            encrypted = ctr(sent_message, 1);
//            iResult = send(client.socket, sent_message.c_str(), strlen(sent_message.c_str()), 0);
            iResult = send(client.socket, encrypted.c_str(), strlen(encrypted.c_str()), 0);

            if (iResult <= 0)
            {
                cout << "send() failed: " << WSAGetLastError() << endl;
                break;
            }
        }

        //Shutdown the connection since no more data will be sent
        my_thread.detach();
    }
    else
        cout << client.received_message << endl;

    cout << "Shutting down socket..." << endl;
    iResult = shutdown(client.socket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        cout << "shutdown() failed with error: " << WSAGetLastError() << endl;
        closesocket(client.socket);
        WSACleanup();
        system("pause");
        return 1;
    }

    closesocket(client.socket);
    WSACleanup();
    system("pause");
    return 0;
}
