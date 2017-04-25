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

## Source Code Menghitung Ya & Yb
<pre><code>
  ```C++
  #include <iostream>

  int main(int argc, char *argv[]) {

    /* An annoying "Hello World" example */
    for (auto i = 0; i < 0xFFFF; i++)
      cout << "Hello, World!" << endl;

    char c = '\n';
    unordered_map <string, vector<string> > m;
    m["key"] = "\\\\"; // this is an error

    return -2e3 + 12l;
  }
  ```
</code></pre>
