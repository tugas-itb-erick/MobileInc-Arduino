# Mobile Inc (Arduino)
IF3111 Pengembangan Aplikasi pada Platform Khusus

## Anggota kelompok Chlordane
- [Reinhard Benjamin Linardi (13515011)](https://github.com/reinhardlinardi)
- [Erick Wijaya (13515057)](https://github.com/wijayaerick)
- [Roland Hartanto (13515107)](https://github.com/rolandhartanto)

## Deskripsi subsistem Arduino
Subsistem Arduino merupakan subsistem yang berperan sebagai sensor suhu dan kelembapan. Subsistem ini dapat mengirimkan data ke Unity dan dapat mempengaruhi permainan pada Unity.

## Fitur-fitur subsistem Arduino
- Subsistem mampu mengukur suhu lingkungan dengan sensor suhu.
- Subsistem mampu mengukur kelembapan lingkungan dengan sensor kelembapan.
- Subsistem mampu menampilkan kategori cuaca berdasarkan hasil pembacaan sensor melalui 7 segment LED.
- Subsistem mampu menampilkan hasil pembacaan sensor pada layar LCD. Hasil pembacaan sensor suhu ditampilkan dalam derajat Celcius, dan hasil pembacaan sensor kelembapan ditampilkan dalam %RH.
- Subsistem memiliki switch berupa *push button* untuk mematikan/menyalakan lampu LED.
- Subsistem mampu mengeluarkan output PWM dari lampu LED. Cahaya lampu LED akan menghilang perlahan dan menyala perlahan ketika cuaca tidak cerah dan menyala konstan apabila cuaca cerah.
- Subsistem mampu mengirimkan data ke permainan utama pada subsistem Unity. 

## Cara instalasi aplikasi
1. Buka link berikut :
https://drive.google.com/open?id=1R2LVf0eJqQqwxEMbJ_Q9IvqCWonDNfAY
2. Download ZIP pada link tersebut
3. Extract ZIP
4. Buka IDE Arduino, buka file *main.ino*
5. Pilih Sketch > Include Library > Add ZIP Library. Masukkan semua library yang ada.
6. Pilih semua library dari list.
7. Sambungkan Arduino ke komputer.
8. Tekan tombol Upload. Program akan otomatis dikompilasi dan dijalankan oleh Arduino.

## Panduan pemakaian
Pada subsistem Arduino, program langsung berjalan ketika user menghubungkan Arduino dengan komputer. User dapat melihat hasil pembacaan sensor suhu dan kelembapan pada LCD. Selain itu, user juga dapat melihat kategori cuaca pada 7 segment. Kategori cuaca juga dapat dilihat melalui LED. Untuk menyalakan/mematikan fitur LED, user dapat menekan *push button*.
    
<br />
<br />Homepage : http://mobileinc.herokuapp.com
<br />API server : https://github.com/reinhardlinardi/mobile-inc
