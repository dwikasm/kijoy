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
    <li>Xa < q </li>
    <li>Xb < q </li>
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

## Source Code Menghitung Ya & Yb
<pre><code>
  int q,a,x,ya=1,yb=1,k=1;
  cout<<"Masukkan q: ";
  cin>>q;
  cout<<"Masukkan a: ";
  cin>>a;
  cout<<"Masukkan x: ";
  cin>>x;
  for(int i=0;i<x;i++)
    ya=ya*a%q;
</code></pre>

## Source Code Melakukan Send dan Receive
<p>
  Pada source code kami, terlihat user melakukan send terlebih dahulu baru melakukan receive agar ketika ada 1 user yang sudah mengetikkan kode Xa, user tersebut harus menunggu user lainnya mengetikkan nilai Xb nya baru kedua user dapat melanjutkan program tersebut
</p>
<pre><code>
//send ya
string kon=to_string(ya);
cout << "ya adalah : " << kon << endl;
send(client.socket, kon.c_str(), strlen(kon.c_str()), 0);

//receive yb
recv(client.socket, client.received_message, DEFAULT_BUFLEN, 0);
cout << "received msg : " << client.received_message <<endl;

//mengubah nilai yb dari string menjadi integer
string dummy = client.received_message;
yb=stoi(dummy.substr(dummy.find(": ")+1));
cout << "yb adalah : " << yb <<endl;
</code></pre>
