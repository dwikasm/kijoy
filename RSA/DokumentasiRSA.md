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
  Berikut adalah skenario bagaimana public-key cryptosystem bekerja  :
  <li> 1. Kedua partisipan (Alice dan Bob) setuju untuk menggunakan public-key cryptosystem. </li>
  <li> 2. Bob akan mengirimkan public key-nya kepada Alice. </li>
  <li> 3. Alice akan meng-encrypt pesan yang dibuatkan dengan menggunakan public
     key milik Bob dan mengirimkan pesan yang sudah di-encrypt kepada 
     Bob. </li>
  <li> 4. Bob men-decrypt pesan dari Alice menggunakan private key
     miliknya.</li>
</p


  
  
  
  
