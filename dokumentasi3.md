# Diffie-Hellman Key Exchange

KIJ-F Kelompok 14 :
<li> Vinsensia Sipriana Zega (5114100066) 
<li> Ivaldy Putra Lifiari (5114100105) 
<li> Dwika Setya Muhammad (5114100142) </li>

## Penjelasan
<p>
  Diffie-Hellman key exchange adalah metode dimana subyek menukar kunci rahasia melalui media yang tidak aman tanpa mengekspos kunci. Metode ini diperlihatkan oleh Dr. W. Diffie dan Dr. M. E. Hellman pada tahun 1976 pada papernya “New Directions in Cryptography”. Metode ini memungkinkan dua pengguna untuk bertukar kunci rahasia melalui media yang tidak aman tanpa kunci tambahan.
</p>

## Cara Perhitungan
<p>
  <ol>
  <li> Tentukan variabel q yang berupa bilangan prima </li>
  <li> Tentukan variabel a yang merupakan primitive root mod dari q</li> 
  <li> Setiap user menentukan secret key: 
    <ul>
    <li>Xa < q. </li>
    <li>Xb < q. </li>
    </ul>
  </li>
  <li> Menghitung public key: 
    <ul>
    <li>Ya = a^Xa mod q</li>
    <li>Yb = a^Xb mod q</li>
    </ul>
  </li>
  <li> Setiap user saling mengirimkan hasil Ya untuk perhitungan key</li>
  <li> Menghitung key: 
    <ul>
    <li>K = Yb^Xa mod q</li>
    <li>K = Ya^Xb mod q</li>
    </ul>
  </li>
  </ol>

## Source Code
### Menghitung Ya & Yb
  ```C++
int q,a,x,ya=1,yb=1,k=1;
cout<<"Masukkan q: ";
cin>>q;
cout<<"Masukkan a: ";
cin>>a;
cout<<"Masukkan x: ";
cin>>x;
for(int i=0;i<x;i++)
  ya=ya*a%q;
  ```

### Melakukan Send dan Receive

  Program kami melakukan send terlebih dahulu, baru receive. Jadi jika user 1 telah menentukan nilai Xa, user tersebut harus menunggu user 2 menentukan nilai Xb nya. Jika kedua user telah menentukan nilai Xa dan Xb nya masing-masing, baru program ini dapat dilanjutkan 

  ```C++
//send ya
string kon=to_string(ya);
cout << "ya adalah : " << kon << endl;
send(client.socket, kon.c_str(), strlen(kon.c_str()), 0);

//receive yb
recv(client.socket, client.received_message, DEFAULT_BUFLEN, 0);
cout << "received msg : " << client.received_message <<endl;

//ubah string yb menjadi integer 
string dummy = client.received_message;
yb=stoi(dummy.substr(dummy.find(": ")+1));
cout << "yb adalah : " << yb <<endl;
  ```

### Menghitung Key
```C++
//menghitung nilai key
for(int i=0;i<x;i++) 
  k=k*yb%q;
cout << "Key yang dipakai adalah : " << k << endl;
getchar();

//mengubah int to string key
string key = to_string(k);
cout << "key = " << key << endl;

//jika key < 8 karakter, akan ditambahkan karakter "0"
while(key.size()<8) 
  key.append("0");

KEY = key;
```
