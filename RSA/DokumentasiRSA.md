# RSA

KIJ-F Kelompok 14 :
<li> Vinsensia Sipriana Zega (5114100066) 
<li> Ivaldy Putra Lifiari (5114100105) 
<li> Dwika Setya Muhammad (5114100142) </li>

## Dasar Teori
### Kriptografi
<p>
  Kriptografi merupakan suatu ilmu seni dengan filosofinya the art of war, dimana waktu itu 
  pernah digunakan untuk mengirim pesan rahasia pada jaman romawi pada era raja Caesar.
  Tujuannya agar pembajak surat rahasia tidak dapat membaca pesannya secara langsung oleh 
  orang lain jika belum dideskripsikan dengan metode tertentu. Kritografi adalah studi 
  mengenai ilmu dan seni dalam rangka menjaga keamanan data atau informasi yang dikirim 
  dan juga merupakan ilmu untuk bagaimana memecahkan pesan yang terenkripsi (tersamar).
</p>
<p>
  Di dalam kriptografi sering ditemukan berbagai istilah atau terminologi, beberapa istilah yang penting untuk diketahui yakni :
    <li> Enkripsi : mekanisme yang dilakukan untuk merubah plaintext menjadi ciphertext. </li>
    <li> Dekripsi : mekanisme yang dilakukan untuk merubah ciphertext menjadi plaintext. </li>
    <li> Pesan (message) : data atau informasi yang dapat dibaca atau dimengerti maknanya. Nama lainnya untuk pesan adalah plainteks (plaintext) atau teks jelas (clear text).</li>
    <li> Pengirim (sender) : entitas yang melakukan pengiriman pesan kepada entitas lainnya. </li>
    <li> Kunci (cipher) : aturan atau fungsi matematika yang digunakan untuk melakukan proses enkripsi dan dekripsi pada plaintext dan ciphertext. </li>
    <li> Penerima (recipient) adalah entitas yang menerima pesan dari pengirim/entitas yang berhak atas pesan yang dikirim. </li>
</p>

## RSA (Ron Rivest, Shamir, dan Adleman)
### Sejarah
<p>
  RSA merupakan sebuah algoritma pada enkripsi public key dan termasuk ke dalam algoritma pertama 
  yang cocok untuk digital signature seperti halnya ekripsi, dan salah satu yang paling maju dalam bidang kriptografi public key. 
  RSA masih digunakan secara luas dalam protokol electronic commerce, dan dipercaya dalam mengamankan 
  dengan menggunakan kunci yang cukup panjang.
  
  RSA merupakan sebuah algoritma berdasarkan skema public-key cryptography.
 Asal mula nama algoritma RSA ini sebagai inisial para penemunya: Ron Rivest, Adi Shamir, dan
  Leonard Adleman. RSA dibuat di MIT pada tahun 1977 dan dipatenkan oleh MIT
  pada tahun 1983. Setelah bulan September tahun 2000, paten tersebut
  berakhir, sehingga saat ini semua orang dapat menggunakannya dengan bebas.

  Lebih jauh, RSA adalah algoritma yang mudah untuk diimplementasikan dan
  dimengerti. Algoritma RSA ini tergolong ke dalam aplikasi dari sekian banyak teori
  seperti extended euclid algorithm, euler's function sampai fermat theorem. 
</p>

### Skenario
<p>
  Di dalam skenario ini akan ada 2 partisipan, yaitu Alice dan Bob yang akan melakukan pertukaran informasi. 
  Berikut adalah skenario bagaimana public-key crypto sistem bekerja  :
  <li> Pertama-tama, kedua partisipan (Alice dan Bob) setuju untuk menggunakan public-key cryptosystem. 
  <li> Lalu, si Bob akan mengirimkan public key-nya kepada Alice. 
  <li> Lalu, si Alice akan meng-encrypt pesan yang dibuatkan dengan menggunakan public
     key milik Bob dan mengirimkan pesan yang sudah di-encrypt kepada 
     Bob. 
  <li> Pada akhirnya, si Bob men-decrypt pesan dari Alice menggunakan private key
     miliknya.</li>
</p>

### Notasi Matematika
<p>
  Di dalam algoritma RSA terdapat beberapa notasi matematika, yaitu sebagai berikut :
</p>

#### <li> Modulo </li>
<p>
  Seperti yang kita ketahui , Modulo dinotasikan menjadi 'x mod m' atau 'x % m' dalam beberapa
  bahasa komputer. Sebagai contoh :
   <li>10 mod 5 = 0 karena 5 habis membagi 10 </li>
   <li>9 mod 7 = 2 karena 9 / (7 * 1) menyisakan 2</li>
</p>

#### <li> Z/mZ </li>
<p>
  Operasi yang termasuk kedalam Z/mZ yakni penjumlahan, pengurangan,pembagian dan perkalian. Tidak hanya itu, terdapat Inverse dan Units
  juga. Dimana Inversi merupakan sebuah elemen dalam Z/mZ seperti A, memiliki sebuah inverse B
  jika dan hanya jika [A]x[B] = [1]. Dan Units merupakan setiap elemen dalam Z/mZ yang memiliki inverse adalah sebuah
  unit.
</p>

#### <li> GCD (A,B) - Greatest Common Divisor </li>
<p>
  Operasi GCD (A,B) ini dapat ditemukan dengan menggunakan algoritma extended euclid. Apabila
  GCD(A,B) = 1 maka A and B dalah coprime satu sama lainnya (dengan kata lain, A dan B adalah relatively prime).
</p>

#### <li> Pow (A,B) </li>
<p>
   Operasi ini merupakan operasi pangkat yang dimana menggunakan notasi '^'.
   Sebagai contoh : a pangkat b =  a^b 
</p>

#### <li> Euler's phi function </li>
<p>
  Ini merupakan fungsi untuk sebuah total bilangan unit dalam Z/mZ. Dimana terdapat teorema sbb :
  <li> Jika p = bilangan prima , maka phi (p) = p - 1 ; p dan phi(p) adalah (contoh: gcd(p,phi(p)) = 1), contoh : phi(11) = 10 </li>
  <li> phi(m*n) = phi(m) * phi (n), contoh : phi(840) = phi(8) * phi(105) </li>
  <li> phi(p^a) = (p^a) - p^(a-1) </li>
 </p>

### Pembuatan Key
<p>
  Dikarenakan si Alice ingin Bob mengirimnya sebuah pesan melalui jalur yang aman, maka si Alice akan memberikan public keynya kepada     Bob dan menyimpan private key untuk dirinya sendiri. Oleh karena itu, berikut ini adalah langkah-langkah dalam pembuatan key :
  <li> Pertama-tama, pilih 2 bilangan prima besar seperti p,q dimana p tidak sama
     dengan q.
  <li> Kedua, hitunglah M, dimana M = p x q
  <li> Ketiga, hitunglah phi(M), dimana phi(M) = phi(p) * phi(q)
  <li> Keempat, pilihlah sebuah nilai integer 'e' dimana e lebih lecil dari phi(M) dan lebih besar dari 1, dan 'e' serta
     phi(M) adalah coprime
  <li> Kelima, hitunglah 'd' integer sehingga (d * e) mod M = 1
  <li> Pada akhirnya, (M,e) adalah public key dimana M adalah modulo dan e adalah
     eksponen encryption; serta (M,d) adalah private key dimana M adalah modulo dan d adalah
     eksponen decryption. </li>   
</p>

### Cara Enkripsi Pesan
<p>
  Sebagai contoh, si Alice akan mengirim pesan "z" kepada Bob, maka cara mengenkripsi pesannya yaitu:
   <li> Pertama-tama, 
     Bob harus membuat key dirinya sehingga Bob memiliki private dan 
     public keys. Dimana private key = (M,d) dan public key  = (M,e)
  <li> Kedua, 
     Mengubah pesan yang berupa plaintext menjadi bilangan. Sebuah contoh mudah adalah 
     mapping A = 1, B = 2 ... Z = 26. 
     Sehingga z = 26
  <li> Ketiga, 
     Mencari nilai C, dimana c merupakan bilangan yang ter-enkripsi. 
     Nilai C didapat dari 8^e (mod M)
  <li> Pada akhirnya, Alice mengirimkan bilangan tersebut kepada Alice sehingga Alice 
     dapat melakukan decode ulang menggunakan private keynya.</li> 
</p>

### Cara Dekripsi Pesan
<p>
  Sebagai contoh,  Bob menerima sebuah pesan sudah ter-enkripsi, maka Bob akan mendekripsikan menggunakan tahapan-tahapan berikut:
  <li> Pertama-tama, 
     Bob sudah mempunyai private key dari langkah-langkah memperoleh Key (M,d)
  <li> Kedua,  
     Mencari nilai N (merupakan bilangan) dengan menggunakan konversi table alphabet untuk mengubah N menjadi karakter yang direpresentasikannya.
     Nilai N didapat dari C^d (mod M) </li>
</p>

### Referensi
<li> https://id.wikipedia.org/wiki/RSA#Pembuatan_Kunci </li>
<li> Rivest R.L., Shamir A., Adleman L. "A Method for Obtaining Digital
     Signatures and Public-Key Cryptosystems. MIT: Massachusetts. 1977.</li>
