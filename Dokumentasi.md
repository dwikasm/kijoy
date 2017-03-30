# Algoritma Data Encryption Standard (DES) dengan operasi Counter (CTR)

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

## Data Encryption Standard (DES)
<p>
  DES merupakan salah satu algoritma enkripsi yang dikembangkan oleh 
  NIST (National Institute of Standards and Technology) sebagai standar pengolahan informasi Federal AS.
  Secara umum, Data Encryption Standard (DES) terbagi menjadi tiga kelompok di mana 
  kelompok yang satu dengan yang lain saling berinteraksi dan terkait antara satu dengan yang 
  lain. Kelompok-kelompok tersebut ialah 
  <ol>
    <li>Pemrosesan kunci</li>
    <li>Enkripsi data 64 bit </li>
    <li>Dekripsi data 64 bit. </li>
  </ol>
</p>

<p>
  Data yang dienkripsi dalam blok-blok 64 bit menggunakan kunci 56 bit, DES mentransformasikan input 64 bit dalam 
  beberapa tahap enkripsi ke dalam output 64 bit. Dengan demikian, DES termasuk lama block cipher dengan tahapan 
  pemakaian kunci yang sama untuk deskripsinya.
</p>
<p>
  Skema global dari algoritma DES adalah sebagai berikut:
</p>
<img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="http://4.bp.blogspot.com/-iBKtCrSKUI4/T_1T9EBLA9I/AAAAAAAAAl4/jRHKo_Ce_ME/s1600/Laporan+DES.jpg" border="0">
<p>
  Penjelasan dari skema di atas ialah :
  <ol>
    <li> Blok plainteks dipermutasi dengan matriks permutasi awal (initial permutation atau IP). </li>
    <li> Hasil permutasi awal kemudian di-enciphering- sebanyak 16 kali (16 putaran). Setiap putaran menggunakan kunci internal yang berbeda. </li>
    <li> Hasil enciphering kemudian dipermutasi dengan matriks permutasi balikan (invers initial permutation atau IP-1 ) menjadi blok cipherteks. </li>
  </ol>
</p>

## Counter (CTR)
<p>
  Metode ini akan mengubah cipher blok menjadi cipher stream. Mode ini membangkitkan blok 
  keystream selanjutnya dengan mengenkripsi nilai berkelanjutan dari suatu ‘counter’, 
  yang dimana counter dapat berupa fungsi apapun yang mengeluarkan suatu sekuens yang 
  dijamin tidak akan berulang dalam jangka waktu yang lama. Mode ini sangat cocok untuk 
  beroperasi pada komputer multi-processor dimana blok dapat dienkripsikan secara pararel. 
  Pada mode ini, terdapat nonce yang menjadi Initial Vector (IV) yang dimana IV dan counter 
  dapat digabungkan dengan menggunakan XOR, sehingga menjadi blok counter unik yang 
  sebenarnya untuk proses enkripsi.
  <p>
    Berikut skema CTR dalam proses enkripsi :
    <img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="https://upload.wikimedia.org/wikipedia/commons/thumb/4/4d/CTR_encryption_2.svg/601px-CTR_encryption_2.svg.png" border="0">
  </p>
  <p>
    Berikut skema CTR dalam proses dekripsi :
    <img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/3c/CTR_decryption_2.svg/601px-CTR_decryption_2.svg.png" border="0">
  </p>
</p>

## Proses konversi ascii, bilangan biner dan heksadesimal.
  ###  Mengubah ASCII ke Binary 
<pre><code>
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
</code></pre>

 ###  Mengubah Hex ke Binary
<pre><code>
  string hexToBinary(string input) </br>
  {
      string output="";
      for(int i=0; i<input.size(); i++)</br>
      {
          switch(input[i])
          {
              case '0' : output.append("0000"); break;
              case '1' : output.append("0001"); break;</br>
              case '2' : output.append("0010"); break;
              case '3' : output.append("0011"); break;
              case '4' : output.append("0100"); break;
              case '5' : output.append("0101"); break;<br>
              case '6' : output.append("0110"); break;
              case '7' : output.append("0111"); break;
              case '8' : output.append("1000"); break;
              case '9' : output.append("1001"); break;
              case 'A' : output.append("1010"); break;<br>
              case 'B' : output.append("1011"); break;
              case 'C' : output.append("1100"); break;
              case 'D' : output.append("1101"); break;
              case 'E' : output.append("1110"); break;</br>
              case 'F' : output.append("1111"); break;
          }
      }
      return output;
  }</br>
</pre></code>

 ###  Mengubah Binary ke Hex
<pre><code>
    string binaryToHex(string input)</br>
    {</br>
        string output="", temp;</br>
        for(int i=0;i<input.size();i+=4)</br>
        {</br>
            temp = input.substr(i,4);</br>
            if (!temp.compare("0000")){output.append("0");}</br>
            else if (!temp.compare("0001")){output.append("1");}</br>
            else if (!temp.compare("0010")){output.append("2");}</br>
            else if (!temp.compare("0011")){output.append("3");}</br>
            else if (!temp.compare("0100")){output.append("4");}</br>
            else if (!temp.compare("0101")){output.append("5");}</br>
            else if (!temp.compare("0110")){output.append("6");}</br>
            else if (!temp.compare("0111")){output.append("7");}</br>
            else if (!temp.compare("1000")){output.append("8");}</br>
            else if (!temp.compare("1001")){output.append("9");}</br>
            else if (!temp.compare("1010")){output.append("A");}</br>
            else if (!temp.compare("1011")){output.append("B");}</br>
            else if (!temp.compare("1100")){output.append("C");}</br>
            else if (!temp.compare("1101")){output.append("D");}</br>
            else if (!temp.compare("1110")){output.append("E");}</br>
            else if (!temp.compare("1111")){output.append("F");}</br>
        }</br>
        return output;
    }
</pre></code>

 ###  Mengubah Hex ke ASCII
<pre><code>
  string hexToAscii(string input)</br>
  {
      string output, temp;
      char chr;</br>
      for(int i=0; i<input.size(); i+=2)
      {
          temp = input.substr(i,2);</br>
          chr = (char) (int)strtol(temp.c_str(), NULL, 16);
          output.push_back(chr);
      }
      return output;</br>
  }</br>
</pre></code>

## Proses Enkripsi DES untuk Key Schedule
  ### 1 : PC-1 Permutation
  <p>
    Tujuan dari initialization permutation ialah untuk mengacak plainteks sehingga urutan bit-bit di dalamnya berubah. 
    Pengacakan dilakukan dengan menggunakan matriks permutasi awal yaitu sebagai berikut :
    <p>
    <img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="https://1.bp.blogspot.com/-frSweGgXTo8/WNqzFSuNFjI/AAAAAAAAFBc/AW5LqD5xSVoJsAq4RCw1fL5-xC1JxJTUQCLcB/s1600/1.PNG" border="0">
    </p>
  </p>
  <p>
    Bisa dilihat bahwa nilai pertama dari tabel diatas adalah "57" , ini berarti bahwa bit ke-57 dari 
    kunci K akan diberikan menjadi bit pertama dari permutasi kunci K+, begitu pula dengan 
    yang selanjutnya. Aturan ini diterapkan untuk setiap permutasi lanjut. Sangat penting untuk 
    menyadari bahwa hanya 56 bit dari kunci asli tetap di kunci permutasi yang baru dibuat. 
    Seperti ditulis sebelumnya, setiap bit 8 dari setiap byte diabaikan.
  </p>
  <p>Berikut ini adalah inisial PC1 :</p>
  <pre><code>
  int PC1[56] =  {57,49,41,33,25,17,9,
                    1,58,50,42,34,26,18,
                    10,2,59,51,43,35,27,
                    19,11,3,60,52,44,36,
                    63,55,47,39,31,23,15,
                    7,62,54,46,38,30,22,
                    14,6,61,53,45,37,29,
                    21,13,5,28,20,12,4}; 
   </pre></code>
   <p>Berikut ini adalah fungsi untuk permutasi</p>
   <pre><code>
     string permutate(string input, int table[], int tablesize) </br>
          {
              string output="", temp="";
              for(int i=0; i<tablesize; i++)</br>
              {
                  temp = input[table[i]-1];
                  output.append(temp);</br>
              }
              return output;
     }</br>
   </pre></code>

### 2 : k+ Splitting
  <p>
    Cara selanjutnya ialah 56 bit yang terdapat pada K+ dibagi menjadi 2 bagian yakni menjadi C0 dan D0 , yang dimana setiap bagian menjadi 28 bit.
    <p>Sebagai contoh : </p>
    <p>
      <img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="https://4.bp.blogspot.com/-73Na3yn9nOg/WNq4cporK9I/AAAAAAAAFBs/iCT-5cxkjXU0Dt12kS_VnuK5AnwSBNbmACLcB/s1600/2.PNG" border="0">
    </p>
  </p>
  <p>Berikut ini adalah fungsi untuk splitting :</p>
  <pre><code>
      k[0] = permutate(key, PC1, sizeof(PC1)/sizeof(PC1[0]));
      c[0] = k[0].substr(0,k[0].size()/2);
      d[0] = k[0].substr(k[0].size()/2,k[0].size()/2);  
  </pre></code>
  
### 3 : Creating 16 subkeys using shifting
  <p>
   Selanjutnya kita akan membuat 16 pasang Cn dan Dn untuk 1<=n<=16. Dimana setiap 
   pasangan Cn dan Dn dibuat dari pasangan sebelumnya Cn-1 dan Dn-1 untuk 1<=n<=16 melalui 
   sejumlah “pergeseran ke kiri” dari blok sebelumnya. Pergeseran ke kiri haruslah sesuai dengan tabel pergeseran berikut ini :</p>
    <p>
      <img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="https://3.bp.blogspot.com/-fmt7N4ixuIs/WNq6bMvYlRI/AAAAAAAAFB4/3M7yVYakSqsS8SGCsS3ocLLt0A3_nmLFwCLcB/s1600/3.PNG" border="0">
    </p>
  </p>
  <p>Berikut ini adalah fungsi untuk left shifting :</p>
  <pre><code>
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
  </pre></code>
  
  ### 4 : PC-2 Permutation
  <p>
    Setelah pergeseran bit, maka masing-masing Cn dan Dn yang memiliki 56 bit akan dipermutasi kembali dengan menggunakan matriks PC-2 
    yang hanya menggunakan 48 bit. Berikut adalah matriks PC-2:
    <p>
      <img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="https://1.bp.blogspot.com/-AsOwIBMrE_w/WNq8d8K-4jI/AAAAAAAAFCE/wGWy8TYN844t4WeiNe9qqgo0EPkcDW9VwCLcB/s1600/4.PNG" border="0">
    </p>
  </p>
  <p>Berikut ini adalah inisial PC1 :</p>
  <pre><code>
    int PC2[48] =  {14,17,11,24,1,5,
                    3,28,15,6,21,10,
                    23,19,12,4,26,8,
                    16,7,27,20,13,2,
                    41,52,31,37,47,55,
                    30,40,51,45,33,48,
                    44,49,39,56,34,53,
                    46,42,50,36,29,32};
   </pre></code>
   
## Proses Enkripsi DES untuk Message Encoding 
 ### 1 : IP Permutation
  <p>
   Proses permutasi awal IP dari plaintext M ini adalah langkah pertama dari tahap pesan enkripsi.
   Permutasi dari M harus sesuai dengan tabel IP yang bertujuan untuk menciptakan blok ulang bit IP.
   Matriks permutasi awal IP yaitu sebagai berikut :
    <p>
    <img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="https://1.bp.blogspot.com/-frSweGgXTo8/WNqzFSuNFjI/AAAAAAAAFBc/AW5LqD5xSVoJsAq4RCw1fL5-xC1JxJTUQCLcB/s1600/1.PNG" border="0">
    </p>
  </p>
  <p>
    Bisa dilihat bahwa nilai pertama dari tabel diatas adalah "58" , ini berarti bahwa bit ke-58 dari 
    M akan diberikan menjadi bit pertama dari permutasi IP yang baru, begitu pula dengan 
    yang selanjutnya. Aturan ini diterapkan untuk setiap permutasi lanjut.
  </p>
  <p>Berikut ini adalah inisial IP :</p>
  <pre><code>
   int IP[64] =   {58,50,42,34,26,18,10,2,
                    60,52,44,36,28,20,12,4,
                    62,54,46,38,30,22,14,6,
                    64,56,48,40,32,24,16,8,
                    57,49,41,33,25,17,9,1,
                    59,51,43,35,27,19,11,3,
                    61,53,45,37,29,21,13,5,
                    63,55,47,39,31,23,15,7}; 
   </pre></code>
   <p>Berikut ini adalah fungsi untuk permutasi</p>
   <pre><code>
     string permutate(string input, int table[], int tablesize) </br>
          {
              string output="", temp="";
              for(int i=0; i<tablesize; i++)</br>
              {
                  temp = input[table[i]-1];
                  output.append(temp);</br>
              }
              return output;
     }</br>
   </pre></code>

### 2 : IP Splitting
  <p>
    Membagi block IP Permutasi menjadi 2 bagian yaitu bagian kiri sebanyak 32 bit dan bagian kanan sebanyak 32 bit.
    <p>Sebagai contoh : </p>
    <p>
      <img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="https://4.bp.blogspot.com/-RnBzcymmRW0/WNrCksW3nCI/AAAAAAAAFCU/cAlCVb9I84kB95HMFGXSHsWZzb8eYx2egCLcB/s1600/5.PNG" border="0">
    </p>
  </p>
  <p>Berikut ini adalah fungsi untuk splitting :</p>
     <pre><code>
         m = permutate(input, IP, sizeof(IP)/sizeof(IP[0]));
          l[0] = m.substr(0,m.size()/2);</br>
          r[0] = m.substr(m.size()/2,m.size()/2); </br>
    </pre></code>

  
 ### 3 : Iterations
  <p>
    Dilakukannya 16 iterasi untuk 1<=n<=16 dengan cara : 
    Berikut rumusya :
    <lo>
      <li> Ln = Rn-1 </li>
      <li> Rn = Ln-1 + f(Rn-1,Kn) </li>
    </lo>
    menggunakan fungsi f yang beroperasi di dua blok data (Rn-1) 32 bit dan key (Kn) 
    48 bit untuk menghasilkan 32 bit blok panjang data. Untuk proses menghitung 
    fungsi f terdiri dari 4 langkah :
      <li> 1. E Permutation</li>
      Pada awalnya kita harus memperluas blok Rn-1 dari 32 bit menjadi 48 bit, 
      ini dibuat oleh permutasinya dari inputan blok sesuai dengan tabel E. Di operasi 
      ini terdapat beberapa bit yang berulang, dimana output block ditandai dengan E 
      (R0). Berikut ini adalah tabel E yang dimaksud :
      <p>
        <p>
          <img style="margin: 0pt 10px 10px 0pt; float: left; cursor: pointer" src="https://1.bp.blogspot.com/-AyaABA0-y-A/WNrGBfOjOLI/AAAAAAAAFCg/Ux-YsDWB-7QnZpUWbrMemymZl76EsFsbACLcB/s1600/6.PNG" border="0">
        </p>
      </p>
      <p>Berikut ini adalah inisial E :</p>
      <pre><code>
          int E[48] ={32,1,2,3,4,5,</br>
                      4,5,6,7,8,9,
                      8,9,10,11,12,13,</br>
                      12,13,14,15,16,17,
                      16,17,18,19,20,21,
                      20,21,22,23,24,25,
                      24,25,26,27,28,29,
                      28,29,30,31,32,1};</br>
      </pre></code>
  </p>
  
  <li> 2. XOR with KEY</li>
      Langkah ini kita harus melakukan XOR E (Rn-1) dengan key (Kn). Untuk iterasi pertama ialah K1 XOR E (R0).
      <p>Berikut ini adalah fungsi untuk XOR:</p>
      <pre><code>
          string xorr(string input1, string input2, int insize)
          {
              string output="";
              for(int i=0; i<insize; i++)</br>
              {
                  if(input1[i] == input2[i]) output.append("0");</br>
                  else output.append("1");
              }
              return output;</br>
          }
        </pre></code>
       
  
   <li> 3. S box Transformation</li>
            Saat ini kita memiliki blok 48 bit panjang data. Kita harus membaginya kedalam 8 
            kelompok 6 bit, dimana 6 kelompok yang digunakan sekarang sebagai alamat 
            dalam tabel yang disebut “S boxes”. Pada lokasi tertentu dikasih sejumlah 4 bit 
            yang dimana berguna untuk menggantikan kelompok asli 6 bit tadi. Untuk 
            outputnya kita mendapatkan 8 kelompok 4 bit.
            Untuk transformasinya :
            Baris nya dibuat dengan kisaran desimal 0 sampe 3, lalu kolomnya dibuat 
            dengan kisaran desimal dari 0 sampai 15. Kedua koordinat menunjukkan angka 
            desimal, dimana panjang bilangan biner 4 bit menjadi output. Lalu diulangi 
            operasi untuk setiap 8 kelompok 6 bit dan sebagai hasilnya kita mendapat 8 
            kelompok 4 bit. 
      <p>Berikut ini adalah fungsi untuk S Boxes :</p><pre><code>
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
          </pre></code>
       
  
   <li> 4. P Permutation</li>
      Langkah ini ialah tahap akhir dalam menghitung fungsi f. Dimana dilakukan permutasi dari setiap nilai S Boxes sesuai matriks P.
      <p>Berikut ini adalah inisial matriks P:</p>
      <pre><code>
          int p[32] = {16,7,20,21,</br>
                      29,12,28,17,
                      1,15,23,26,
                      5,18,31,10,
                      2,8,24,14,
                      32,27,3,9,
                      19,13,30,6,
                      22,11,4,25};</br>
      </pre></code>
       <p>Berikut ini adalah fungsi untuk mendapatkan output dari setiap iterasi:</p>
       <pre><code>
                string output="";
                input1 = permutate(input1, E, sizeof(E)/sizeof(E[0]));
                input1 = xorr(input1, input2, 48);
                for(int i=0;i<8;i++)
                {
                    output.append(sbox(input1.substr(i*6,6),s[i]));
                }
                output = permutate(output, p, sizeof(p)/sizeof(p[0]));
                return output;</br>
       </pre></code>
       
 ### 4 : Reverse connecting 
   <p>
      Berikutnya kita membalikkan urutan dua blok dan menggabungkan mereka (Rn Ln)
   <p>

 ### 5 : Final Permutation
   <p>
      Ini adalah langkah terakhir dalam enkripsi pesan, 
      dimana outputnnya berasal dari IP Permutasi dari Rn Ln yang sudah didapat dari langkah reverse connecting.
    </p>
     <p>Berikut ini adalah inisial IP-1:</p>
       <pre><code>
                   int IP1[64] =  {40,8,48,16,56,24,64,32,
                    39,7,47,15,55,23,63,31,
                    38,6,46,14,54,22,62,30,
                    37,5,45,13,53,21,61,29,
                    36,4,44,12,52,20,60,28,
                    35,3,43,11,51,19,59,27,
                    34,2,42,10,50,18,58,26,
                    33,1,41,9,49,17,57,25};
       </pre></code>
   <p>Berikut ini adalah proses untuk mencari hasil akhir (output) dan mengubah output dari bilangan biner ke dalam hex:</p>
       <pre><code>
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
          output = binaryToHex(output_binary);
          return output;
       </pre></code>
 
 
