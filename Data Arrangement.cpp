/********************************************************************
**                 COMPUTER ENGINEERING
**
**             ALEXANDER KİBAROV(İSKENDER)
********************************************************************/
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <cmath>
#include <sstream>
using namespace std;
string notAraligi(int deger);
double enYuksekNot();
double enDusukNot();
double standartSapma();
void araliktakiOgrenciler(double alt, double ust);
void ustAraliktakiOgrenciler(double kullaniciAltSinir);
void altAraliktakiOgrenciler(double kullaniciUstSinir);
int dogrulukKontrol(string alinan);
void ogrenciYazdirma(int alt, int ust);
double sinifOrtalamasi();
int notKontrol(int notOku);
struct tarih
{
    int gun = 0;
    int ay = 0;
    int yil = 2022;
};
struct ogrenci
{
    string adi = "Ad girilmedi";
    string soyadi = "Soyadi girilmedi";
    string numara = "000000000";
    int kisaSinav1 = 0;
    int kisaSinav2 = 0;
    int odev1 = 0;
    int odev2 = 0;
    int proje = 0;
    int vize = 0;
    int final = 0;
    double basariNotu = 0;
    struct tarih tarihDegeri;
};
ogrenci ogrenciGirisi[100] = {};
int dogrulukdegeri = 0;
int main()
{
    srand(time(NULL));
    string kullaniciAdi, kullaniciSoyad, kullaniciNumara, ekranaYazdirma, calistirmaFonksiyonu;
    int calistirmaDegiskeni = 0, temaDegiskeni, degerAtamaDegiskeni, kullaniciKisaSinav1, kullaniciKisaSinav2, kullaniciOdev1, kullaniciOdev2,
        kullaniciProje, kullaniciVize, kullaniciFinal, kullaniciGun, kullaniciAy, kullaniciYil;
    double enbuyuk = -1, enkucuk = 101, toplam = 0, kullaniciMin, kullaniciMax, kullaniciUstSinir, kullaniciAltSinir, aritmatikToplam = 0, kareselToplam = 0,
        sonucDegeri = 0;
    setlocale(LC_ALL, "Turkish");
    string isimDizisi[30] = { "İskender", "Ali", "İsa", "Aslan", "Cavat", "Sadık", "Samet", "Eren", "Enes", "Burak",
        "Mert", "Berat", "Süleyman", "Mahmut", "Cuneyt", "İsmail", "Barış", "Tarık", "Zarife", "Azize",
        "Senem" ,"Humeyra", "Ayşe", "Selin", "Rumeysa", "Özlem", "Duygu", "Ruken", "İlayda", "Esra" };
    string soyadDizisi[30] = { "Altınbaş", "Altınel", "Altınışık", "Baturalp", "Bayazıt", "Baydar", "Baykam", "Can", "Canberk", "Candan",
        "Cankardeş", "Doymaduk", "Doyum", "Döğerli", "Döğüş", "Döğüşgen", "El", "Ela", "Elban", "Elcek",
    "Oğraş", "Okuyan", "Sabancı", "Sarıgül", "Serdengeçti", "Sözüçetin", "Yaban", "Yabay", "Yabır", "Yabıt" };
    string ogrenciDizisi[100] = {};
    cout << "1) Öğrenci başarı notu tanımlama\n2) Sınıfın listesini yazdırma(Başarı atanmamışsa önerilmez)\n";
    cout << "3) Sınıfın en yüksek notunu bul\n4) Sınıfın en düşük notunu bul\n5) Sınıfın ortalamasını hesapla\n";
    cout << "6) Sınıfın standart sapmasını hesapla\n7) Başarı not aralığı ile bulma\n8) Başarı notu belli notun altında olanlar\n";
    cout << "9) Başarı notu belli notun üstünde olanlar\n10) Tema Değiştirme\n11) Ekranı temizleme\n12) Çıkış\n";
    while (true)
        //Uygulamadan 12 sayısını girene kadar çıkış yapmıyor.
    {
        cout << "İşlem seçiniz: ";
        cin >> calistirmaFonksiyonu;
        if (dogrulukKontrol(calistirmaFonksiyonu) == 1)
            //Burada kullanıcın sadece sayı girip girmemesini kontrol ediyoruz.
        {
            cout << "Lütfen sadece sayı giriniz\n";
            continue;
        }
        //Kullanıcadan aldığımız değeri kontrol edebilmek için string olarak aldık bunu inte çevirip atama yapıp kullanıyoruz bu programda
        calistirmaDegiskeni = stoi(calistirmaFonksiyonu);
        if (calistirmaDegiskeni == 1)
            //Kullanıcının hangi işlemi seçtiğini kontrol ediyoruz if else if else blokları ile
        {
            cout << "İki şekilde tanımlama yapılabilir\n1) Random değer atama\n2) Manuel değer girme(Hız açısından önerilmez)\nİşlem seçiniz: ";
            cin >> degerAtamaDegiskeni;
            if (degerAtamaDegiskeni == 1)
            {
                cout << "Random atama çalışıyor\n";
                for (int i = 0; i < 10; i++)
                    //Öğrencilerin yüzde onluk kısmına belli aralıktaki not değerlerini atıyoruz
                {
                    ogrenciGirisi[i].adi = isimDizisi[rand() % 30];
                    ogrenciGirisi[i].soyadi = soyadDizisi[rand() % 30];
                    ogrenciGirisi[i].numara = to_string(rand() * 1245);
                    ogrenciGirisi[i].kisaSinav1 = rand() % 41;
                    ogrenciGirisi[i].kisaSinav2 = rand() % 41;
                    ogrenciGirisi[i].odev1 = rand() % 41;
                    ogrenciGirisi[i].odev2 = rand() % 41;
                    ogrenciGirisi[i].proje = rand() % 41;
                    ogrenciGirisi[i].final = rand() % 41;
                    ogrenciGirisi[i].vize = rand() % 41;
                    ogrenciGirisi[i].tarihDegeri.gun = rand() % 32;
                    ogrenciGirisi[i].tarihDegeri.ay = rand() % 13;
                    ogrenciGirisi[i].tarihDegeri.yil = 2022;
                    ogrenciGirisi[i].basariNotu = 55 * (ogrenciGirisi[i].vize / float(2) + 7 * ogrenciGirisi[i].kisaSinav1 / float(100) + 7 * ogrenciGirisi[i].kisaSinav2 / float(100) + ogrenciGirisi[i].odev1 / float(10) + ogrenciGirisi[i].odev2 / float(10) + 4 * ogrenciGirisi[i].proje / float(25)) / float(100) + 45 * ogrenciGirisi[i].final / float(100);
                }
                for (int i = 10; i < 60; i++)
                    //Öğrencilerin yüzde ellilik kısmına belli aralıktaki not değerlerini atıyoruz
                {
                    ogrenciGirisi[i].adi = isimDizisi[rand() % 30];
                    ogrenciGirisi[i].soyadi = soyadDizisi[rand() % 30];
                    ogrenciGirisi[i].numara = to_string(rand() * 1245);
                    ogrenciGirisi[i].kisaSinav1 = rand() % 31 + 40;
                    ogrenciGirisi[i].kisaSinav2 = rand() % 31 + 40;
                    ogrenciGirisi[i].odev1 = rand() % 31 + 40;
                    ogrenciGirisi[i].odev2 = rand() % 31 + 40;
                    ogrenciGirisi[i].proje = rand() % 31 + 40;
                    ogrenciGirisi[i].final = rand() % 31 + 40;
                    ogrenciGirisi[i].vize = rand() % 31 + 40;
                    ogrenciGirisi[i].tarihDegeri.gun = rand() % 32;
                    ogrenciGirisi[i].tarihDegeri.ay = rand() % 13;
                    ogrenciGirisi[i].tarihDegeri.yil = 2022;
                    ogrenciGirisi[i].basariNotu = 55 * (ogrenciGirisi[i].vize / float(2) + 7 * ogrenciGirisi[i].kisaSinav1 / float(100) + 7 * ogrenciGirisi[i].kisaSinav2 / float(100) + ogrenciGirisi[i].odev1 / float(10) + ogrenciGirisi[i].odev2 / float(10) + 4 * ogrenciGirisi[i].proje / float(25)) / float(100) + 45 * ogrenciGirisi[i].final / float(100);
                }
                for (int i = 60; i < 75; i++)
                    //Öğrencilerin yüzde on beşlik kısmına belli aralıktaki not değerlerini atıyoruz
                {
                    ogrenciGirisi[i].adi = isimDizisi[rand() % 30];
                    ogrenciGirisi[i].soyadi = soyadDizisi[rand() % 30];
                    ogrenciGirisi[i].numara = to_string(rand() * 1245);
                    ogrenciGirisi[i].kisaSinav1 = rand() % 11 + 70;
                    ogrenciGirisi[i].kisaSinav2 = rand() % 11 + 70;
                    ogrenciGirisi[i].odev1 = rand() % 11 + 70;
                    ogrenciGirisi[i].odev2 = rand() % 11 + 70;
                    ogrenciGirisi[i].proje = rand() % 11 + 70;
                    ogrenciGirisi[i].final = rand() % 11 + 70;
                    ogrenciGirisi[i].vize = rand() % 11 + 70;
                    ogrenciGirisi[i].tarihDegeri.gun = rand() % 32;
                    ogrenciGirisi[i].tarihDegeri.ay = rand() % 13;
                    ogrenciGirisi[i].tarihDegeri.yil = 2022;
                    ogrenciGirisi[i].basariNotu = 55 * (ogrenciGirisi[i].vize / float(2) + 7 * ogrenciGirisi[i].kisaSinav1 / float(100) + 7 * ogrenciGirisi[i].kisaSinav2 / float(100) + ogrenciGirisi[i].odev1 / float(10) + ogrenciGirisi[i].odev2 / float(10) + 4 * ogrenciGirisi[i].proje / float(25)) / float(100) + 45 * ogrenciGirisi[i].final / float(100);
                }
                for (int i = 75; i < 100; i++)
                    //Öğrencilerin yüzde yirmi beşlik kısmına belli aralıktaki not değerlerini atıyoruz
                {
                    ogrenciGirisi[i].adi = isimDizisi[rand() % 30];
                    ogrenciGirisi[i].soyadi = soyadDizisi[rand() % 30];
                    ogrenciGirisi[i].numara = to_string(rand() * 1245);
                    ogrenciGirisi[i].kisaSinav1 = rand() % 21 + 80;
                    ogrenciGirisi[i].kisaSinav2 = rand() % 21 + 80;
                    ogrenciGirisi[i].odev1 = rand() % 21 + 80;
                    ogrenciGirisi[i].odev2 = rand() % 21 + 80;
                    ogrenciGirisi[i].proje = rand() % 21 + 80;
                    ogrenciGirisi[i].final = rand() % 21 + 80;
                    ogrenciGirisi[i].vize = rand() % 21 + 80;
                    ogrenciGirisi[i].tarihDegeri.gun = rand() % 32;
                    ogrenciGirisi[i].tarihDegeri.ay = rand() % 13;
                    ogrenciGirisi[i].tarihDegeri.yil = 2022;
                    ogrenciGirisi[i].basariNotu = 55 * (ogrenciGirisi[i].vize / float(2) + 7 * ogrenciGirisi[i].kisaSinav1 / float(100) + 7 * ogrenciGirisi[i].kisaSinav2 / float(100) + ogrenciGirisi[i].odev1 / float(10) + ogrenciGirisi[i].odev2 / float(10) + 4 * ogrenciGirisi[i].proje / float(25)) / float(100) + 45 * ogrenciGirisi[i].final / float(100);
                }
                cout << "Random atama yapıldı\n";
            }
            else if (degerAtamaDegiskeni == 2)
            {
                cout << "---------------------------------------------------------\n\n\n"
                    << "Öğrenci numarası sadece sayılardan oluşmalıdır." << "\n\n\n";
                for (int i = 0; i < 100; i++)
                    //100 öğrenci için kullanıcının tek tek değer girmesini yapıyoruz
                {
                    cout << "---------------------------------------------------------\n";
                    cout << i + 1 << ". Öğrenci:\n";
                    cout << "---------------------------------------------------------\n";
                    cout << "İsim giriniz: ";
                    cin >> kullaniciAdi;
                    cout << "Soyad giriniz: ";
                    cin >> kullaniciSoyad;
                    cout << "Kısa sınav 1'in notunu giriniz(Lütfen 0-100 arası bir değer giriniz yoksa otomatik değer atanacaktır): ";
                    cin >> kullaniciKisaSinav1;
                    cout << "Kısa sınav 2'nin notunu giriniz(Lütfen 0-100 arası bir değer giriniz yoksa otomatik değer atanacaktır): ";
                    cin >> kullaniciKisaSinav2;
                    cout << "Numara giriniz: ";
                    cin >> kullaniciNumara;
                    cout << "Ödev 1'in notunu giriniz(Lütfen 0-100 arası bir değer giriniz yoksa otomatik değer atanacaktır): ";
                    cin >> kullaniciOdev1;
                    cout << "Ödev 2'nin notunu giriniz(Lütfen 0-100 arası bir değer giriniz yoksa otomatik değer atanacaktır): ";
                    cin >> kullaniciOdev2;
                    cout << "Vize notunu giriniz(Lütfen 0-100 arası bir değer giriniz yoksa otomatik değer atanacaktır): ";
                    cin >> kullaniciVize;
                    cout << "Final notunu giriniz(Lütfen 0-100 arası bir değer giriniz yoksa otomatik değer atanacaktır): ";
                    cin >> kullaniciFinal;
                    cout << "Proje notunu giriniz(Lütfen 0-100 arası bir değer giriniz yoksa otomatik değer atanacaktır): ";
                    cin >> kullaniciProje;
                    cout << "Günü giriniz: ";
                    cin >> kullaniciGun;
                    cout << "Ayı giriniz: ";
                    cin >> kullaniciAy;
                    cout << "Yılı giriniz: ";
                    cin >> kullaniciYil;
                    ogrenciGirisi[i].adi = kullaniciAdi;
                    ogrenciGirisi[i].soyadi = kullaniciSoyad;
                    ogrenciGirisi[i].numara = kullaniciNumara;
                    if (notKontrol(kullaniciKisaSinav1) == 1)
                        //Burda fonksiyon ile kullanıcı doğru aralıktaki değer girdiyse onu alıyoruz girmediyse otomatik değer atıyoruz if else if else blokları ile
                    {
                        ogrenciGirisi[i].kisaSinav1 = kullaniciKisaSinav1;
                    }
                    else
                    {
                        cout << "Kısa sınav 1 için otomatik değer atanmıştır\n";
                        ogrenciGirisi[i].kisaSinav1 = 0;
                    }
                    if (notKontrol(kullaniciKisaSinav2) == 1)
                    {
                        ogrenciGirisi[i].kisaSinav2 = kullaniciKisaSinav2;
                    }
                    else
                    {
                        cout << "Kısa sınav 2 için otomatik değer atanmıştır\n";
                        ogrenciGirisi[i].kisaSinav2 = 0;
                    }
                    if (notKontrol(kullaniciOdev1) == 1)
                    {
                        ogrenciGirisi[i].odev1 = kullaniciOdev1;
                    }
                    else
                    {
                        cout << "Ödev 1 için otomatik değer atanmıştır\n";
                        ogrenciGirisi[i].odev1 = 0;
                    }
                    if (notKontrol(kullaniciOdev2) == 1)
                    {
                        ogrenciGirisi[i].odev2 = kullaniciOdev2;
                    }
                    else
                    {
                        cout << "Ödev 2 için otomatik değer atanmıştır\n";
                        ogrenciGirisi[i].odev2 = 0;
                    }
                    if (notKontrol(kullaniciProje) == 1)
                    {
                        ogrenciGirisi[i].proje = kullaniciProje;
                    }
                    else
                    {
                        cout << "Proje için otomatik değer atanmıştır\n";
                        ogrenciGirisi[i].proje = 0;
                    }
                    if (notKontrol(kullaniciFinal) == 1)
                    {
                        ogrenciGirisi[i].final = kullaniciFinal;
                    }
                    else
                    {
                        cout << "Final için otomatik değer atanmıştır\n";
                        ogrenciGirisi[i].final = 0;
                    }
                    if (notKontrol(kullaniciVize) == 1)
                    {
                        ogrenciGirisi[i].vize = kullaniciVize;
                    }
                    else
                    {
                        cout << "Vize için otomatik değer atanmıştır\n";
                        ogrenciGirisi[i].vize = 0;
                    }
                    ogrenciGirisi[i].tarihDegeri.gun = kullaniciGun;
                    ogrenciGirisi[i].tarihDegeri.ay = kullaniciAy;
                    ogrenciGirisi[i].tarihDegeri.yil = kullaniciYil;
                    ogrenciGirisi[i].basariNotu = 55 * (ogrenciGirisi[i].vize / float(2) + 7 * ogrenciGirisi[i].kisaSinav1 / float(100) + 7 * ogrenciGirisi[i].kisaSinav2 / float(100) + ogrenciGirisi[i].odev1 / float(10) + ogrenciGirisi[i].odev2 / float(10) + 4 * ogrenciGirisi[i].proje / float(25)) / float(100) + 45 * ogrenciGirisi[i].final / float(100);
                }
            }
            else
            {
                cout << "Düzgün bir değer giriniz\n";
            }
        }
        else if (calistirmaDegiskeni == 2)
        {
            ogrenciYazdirma(0, 20);
            //for (int i = 0; i < 20; i++)
            //    /*Öğrencilerin bilgilerini ekrana 20 20 kullanıcı bir tuşa basana kadar yazıyoruz tuşa basma
            //    işlemini if else if else blokları ile kontrol ediyoruz*/
            //{
            //    cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
            //        ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
            //        ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;
            //    cout << "\n";
            //    cout << "-----------------------------------------------------------------------------------------------------";
            //    cout << "\n";
            //}
            cout << "Devam etmek için bir tuşa basınız: ";
            cin >> ekranaYazdirma;
            if (ekranaYazdirma.length() > 0)
                //Tuşa basmasını bekliyoruz basınca ekranı temizleyip diğer parçayı yazdırma işlemine geçiyor
            {
                system("cls");
                ogrenciYazdirma(20, 40);
                //for (int i = 20; i < 40; i++)
                //{
                //    cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
                //        ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
                //        ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
                //    cout << "\n";
                //    cout << "-----------------------------------------------------------------------------------------------------";
                //    cout << "\n";
                //}
            }
            cout << "Devam etmek için bir tuşa basınız: ";
            cin >> ekranaYazdirma;
            if (ekranaYazdirma.length() > 0)
                //Tuşa basmasını bekliyoruz basınca ekranı temizleyip diğer parçayı yazdırma işlemine geçiyor
            {
                system("cls");
                ogrenciYazdirma(40, 60);
                /*for (int i = 40; i < 60; i++)
                {
                    cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
                        ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
                        ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
                    cout << "\n";
                    cout << "-----------------------------------------------------------------------------------------------------";
                    cout << "\n";
                }*/
            }
            cout << "Devam etmek için bir tuşa basınız: ";
            cin >> ekranaYazdirma;
            if (ekranaYazdirma.length() > 0)
                //Tuşa basmasını bekliyoruz basınca ekranı temizleyip diğer parçayı yazdırma işlemine geçiyor
            {
                system("cls");
                ogrenciYazdirma(60, 80);
                /*for (int i = 60; i < 80; i++)
                {
                    cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
                        ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
                        ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
                    cout << "\n";
                    cout << "-----------------------------------------------------------------------------------------------------";
                    cout << "\n";
                }*/
            }
            cout << "Devam etmek için bir tuşa basınız: ";
            cin >> ekranaYazdirma;
            if (ekranaYazdirma.length() > 0)
                //Tuşa basmasını bekliyoruz basınca ekranı temizleyip diğer parçayı yazdırma işlemine geçiyor
            {
                system("cls");
                ogrenciYazdirma(80, 100);
                /*for (int i = 80; i < 100; i++)
                {
                    cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
                        ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
                        ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
                    cout << "\n";
                    cout << "-----------------------------------------------------------------------------------------------------";
                    cout << "\n";
                }*/
            }
        }
        else if (calistirmaDegiskeni == 3)
        {
            //for (int i = 0; i < 100; i++)
            //    //Burada en yüksek notu buluyoruz
            //{
            //    if (ogrenciGirisi[i].basariNotu > enbuyuk)
            //    {
            //        enbuyuk = ogrenciGirisi[i].basariNotu;
            //    }
            //}
            cout << "En yüksek not: " << enYuksekNot() << "\n";
        }
        else if (calistirmaDegiskeni == 4)
        {
            //for (int i = 0; i < 100; i++)
            //    //Burada en düşük notu buluyoruz
            //{
            //    if (ogrenciGirisi[i].basariNotu < enkucuk)
            //    {
            //        enkucuk = ogrenciGirisi[i].basariNotu;
            //    }
            //}
            cout << "En düşük not: " << enDusukNot() << "\n";
        }
        else if (calistirmaDegiskeni == 5)
        {
            //for (int i = 0; i < 100; i++)
            //    //Sınıfın ortalamasını hesaplıyoruz
            //{
            //    toplam = toplam + ogrenciGirisi[i].basariNotu;
            //}
            cout << "Sınıf ortalaması: " << sinifOrtalamasi() / float(100) << "\n";
        }
        else if (calistirmaDegiskeni == 6)
        {
            //for (int i = 0; i < 100; i++)
            //    //Burada aritmatik ortalama değer için toplama yapıyoruz
            //{
            //    aritmatikToplam = aritmatikToplam + ogrenciGirisi[i].basariNotu;
            //}
            //for (int i = 0; i < 100; i++)
            //    //Karesel toplam için aritmatik ortalamadan her değeri çıkarıp karesini alıyoruz
            //{
            //    kareselToplam = kareselToplam + pow(aritmatikToplam / float(100) - ogrenciGirisi[i].basariNotu, 2);
            //}
            //sonucDegeri = sqrt(kareselToplam / 99);
            cout << "Standart sapma: " << standartSapma() << "\n";
        }
        else if (calistirmaDegiskeni == 7)
        {
            cout << "En yüksek notu giriniz: ";
            cin >> kullaniciMax;
            cout << "En düşük notu giriniz: ";
            cin >> kullaniciMin;
            cout << "-----------------------------------------------------------------------------------------------------\n";
            cout << "Başarı notu " << kullaniciMin << "-" << kullaniciMax << " arasında olanlar\n";
            cout << "-----------------------------------------------------------------------------------------------------\n";
            araliktakiOgrenciler(kullaniciMin, kullaniciMax);
            //for (int i = 0; i < 100; i++)
            //    //Burada kullanıcıdan alınan belli bir not aralığındaki öğrencileri yazdırıyoruz
            //{
            //    if (ogrenciGirisi[i].basariNotu <= kullaniciMax && ogrenciGirisi[i].basariNotu >= kullaniciMin)
            //    {
            //        cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
            //            ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
            //            ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
            //        cout << "\n";
            //        cout << "-----------------------------------------------------------------------------------------------------";
            //        cout << "\n";
            //    }
            //}
        }
        else if (calistirmaDegiskeni == 8)
        {
            cout << "Başarı notu üst değeri: ";
            cin >> kullaniciUstSinir;
            cout << "-----------------------------------------------------------------------------------------------------\n";
            cout << "Başarı notu " << kullaniciUstSinir << " altında olanlar\n";
            cout << "-----------------------------------------------------------------------------------------------------\n";
            altAraliktakiOgrenciler(kullaniciUstSinir);
            //for (int i = 0; i < 100; i++)
            //    //Burada kullanıcadan alınan bir değerin altındaki notları yazdırıyoruz
            //{
            //    if (ogrenciGirisi[i].basariNotu <= kullaniciUstSinir)
            //    {
            //        cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
            //            ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
            //            ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
            //        cout << "\n";
            //        cout << "-----------------------------------------------------------------------------------------------------";
            //        cout << "\n";
            //    }
            //}
        }
        else if (calistirmaDegiskeni == 9)
        {
            cout << "Başarı notu alt değeri: ";
            cin >> kullaniciAltSinir;
            cout << "-----------------------------------------------------------------------------------------------------\n";
            cout << "Başarı notu " << kullaniciAltSinir << " üstünde olanlar\n";
            cout << "-----------------------------------------------------------------------------------------------------\n";
            ustAraliktakiOgrenciler(kullaniciAltSinir);
            //for (int i = 0; i < 100; i++)
            //{
            //    if (ogrenciGirisi[i].basariNotu >= kullaniciAltSinir)
            //    {
            //        //Burada kullanıcadan alınan bir değerin üstündeki notları yazdırıyoruz
            //        cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
            //            ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
            //            ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
            //        cout << "\n";
            //        cout << "-----------------------------------------------------------------------------------------------------";
            //        cout << "\n";
            //    }
            //}
        }
        else if (calistirmaDegiskeni == 10)
        {
            cout << "1-5 Arası bir sayi giriniz(Hepsi farklı bir temayı belirtir)\n";
            cin >> temaDegiskeni;
            if (temaDegiskeni == 1)
                //Kullanıcın girdiği değerdeki temayı çağırıyoruz
            {
                system("COLOR 0A");
            }
            else if (temaDegiskeni == 2)
            {
                system("COLOR 0D");
            }
            else if (temaDegiskeni == 3)
            {
                system("COLOR 86");
            }
            else if (temaDegiskeni == 4)
            {
                system("COLOR 74");
            }
            else if (temaDegiskeni == 5)
            {
                system("COLOR 7A");
            }
        }
        else if (calistirmaDegiskeni == 11)
        {
            //Ekranı temizliyoruz
            system("cls");
            cout << "1) Öğrenci başarı notu tanımlama\n2) Sınıfın listesini yazdırma(Başarı atanmamışsa önerilmez)\n";
            cout << "3) Sınıfın en yüksek notunu bul\n4) Sınıfın en düşük notunu bul\n5) Sınıfın ortalamasını hesapla\n";
            cout << "6) Sınıfın standart sapmasını hesapla\n7) Başarı not aralığı ile bulma\n8) Başarı notu belli notun altında olanlar\n";
            cout << "9) Başarı notu belli notun üstünde olanlar\n10) Tema Değiştirme\n11) Ekranı temizleme\n12) Çıkış\n";
        }
        else if (calistirmaDegiskeni == 12)
        {
            //Çıkış yapıyoruz
            cout << "Çıkılıyor...\n";
            Sleep(1000);
            cout << "Çıkıldı\n";
            break;
        }
        else
        {
            cout << "Doğru bir değer girilmedi\n";
        }
    }
    return 0;
}
string notAraligi(int deger)
//Notun sayısal değerine göre harf formatına çeviren fonksiyon
{
    if (deger <= 100 && deger >= 90)
    {
        return "AA";
    }
    else if (deger <= 89 && deger >= 85)
    {
        return "BA";
    }
    else if (deger <= 84 && deger >= 80)
    {
        return "BB";
    }
    else if (deger <= 79 && deger >= 75)
    {
        return "CB";
    }
    else if (deger <= 74 && deger >= 65)
    {
        return "CC";
    }
    else if (deger <= 64 && deger >= 60)
    {
        return "DC";
    }
    else if (deger <= 59 && deger >= 55)
    {
        return "DD";
    }
    else if (deger <= 54 && deger >= 50)
    {
        return "FD";
    }
    else if (deger <= 49 && deger >= 0)
    {
        return "FF";
    }
}
int notKontrol(int notOku)
//Notun 0 ile 100 arasında olup olmadığını kontrol ediyoruz.
{
    if (!(notOku >= 0 && notOku <= 100))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
double enYuksekNot()
{
    double enbuyuk = -1;
    for (int i = 0; i < 100; i++)
        //Burada en yüksek notu buluyoruz
    {
        if (ogrenciGirisi[i].basariNotu > enbuyuk)
        {
            enbuyuk = ogrenciGirisi[i].basariNotu;
        }
    }
    return enbuyuk;
}
double enDusukNot()
{
    double enkucuk = 101;
    for (int i = 0; i < 100; i++)
        //Burada en düşük notu buluyoruz
    {
        if (ogrenciGirisi[i].basariNotu < enkucuk)
        {
            enkucuk = ogrenciGirisi[i].basariNotu;
        }
    }
    return enkucuk;
}
double sinifOrtalamasi()
{
    double toplam = 0;
    for (int i = 0; i < 100; i++)
        //Sınıfın ortalamasını hesaplıyoruz
    {
        toplam = toplam + ogrenciGirisi[i].basariNotu;
    }
    return toplam;
}
double standartSapma()
{
    double aritmatikToplam = 0, kareselToplam = 0, sonucDegeri;
    for (int i = 0; i < 100; i++)
        //Burada aritmatik ortalama değer için toplama yapıyoruz
    {
        aritmatikToplam = aritmatikToplam + ogrenciGirisi[i].basariNotu;
    }
    for (int i = 0; i < 100; i++)
        //Karesel toplam için aritmatik ortalamadan her değeri çıkarıp karesini alıyoruz
    {
        kareselToplam = kareselToplam + pow(aritmatikToplam / float(100) - ogrenciGirisi[i].basariNotu, 2);
    }
    sonucDegeri = sqrt(kareselToplam / 99);
    return sonucDegeri;
}
void araliktakiOgrenciler(double alt, double ust)
{
    for (int i = 0; i < 100; i++)
        //Burada kullanıcıdan alınan belli bir not aralığındaki öğrencileri yazdırıyoruz
    {
        if (ogrenciGirisi[i].basariNotu <= ust && ogrenciGirisi[i].basariNotu >= alt)
        {
            cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
                ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
                ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
            cout << "\n";
            cout << "-----------------------------------------------------------------------------------------------------";
            cout << "\n";
        }
    }
}
void ustAraliktakiOgrenciler(double kullaniciAltSinir)
{
    for (int i = 0; i < 100; i++)
    {
        if (ogrenciGirisi[i].basariNotu >= kullaniciAltSinir)
        {
            //Burada kullanıcadan alınan bir değerin üstündeki notları yazdırıyoruz
            cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
                ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
                ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
            cout << "\n";
            cout << "-----------------------------------------------------------------------------------------------------";
            cout << "\n";
        }
    }
}
void altAraliktakiOgrenciler(double kullaniciUstSinir)
{
    for (int i = 0; i < 100; i++)
        //Burada kullanıcadan alınan bir değerin altındaki notları yazdırıyoruz
    {
        if (ogrenciGirisi[i].basariNotu <= kullaniciUstSinir)
        {
            cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
                ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
                ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;;
            cout << "\n";
            cout << "-----------------------------------------------------------------------------------------------------";
            cout << "\n";
        }
    }
}
void ogrenciYazdirma(int alt, int ust)
{
    for (int i = alt; i < ust; i++)
        /*Öğrencilerin bilgilerini ekrana 20 20 kullanıcı bir tuşa basana kadar yazıyoruz tuşa basma
        işlemini if else if else blokları ile kontrol ediyoruz*/
    {
        cout << "Adı: " << ogrenciGirisi[i].adi << "  Soyadı: " << ogrenciGirisi[i].soyadi << "  Numarası: " << ogrenciGirisi[i].numara << "\n" << "Kısa sınav 1 puanı: " << ogrenciGirisi[i].kisaSinav1 << "  Kısa sınav 2 puanı: " <<
            ogrenciGirisi[i].kisaSinav2 << "  Ödev 1 puanı: " << ogrenciGirisi[i].odev1 << "  Ödev 2 puanı: " << ogrenciGirisi[i].odev2 << "  Proje puanı: " << ogrenciGirisi[i].proje << "\n" << "Vize puanı: " <<
            ogrenciGirisi[i].vize << "  Final puanı: " << ogrenciGirisi[i].final << "  Tarih: " << ogrenciGirisi[i].tarihDegeri.gun << "." << ogrenciGirisi[i].tarihDegeri.ay << "." << ogrenciGirisi[i].tarihDegeri.yil << "\nÖğrenci başarı notu: " << ogrenciGirisi[i].basariNotu;
        cout << "\n";
        cout << "-----------------------------------------------------------------------------------------------------";
        cout << "\n";
    }
}
int dogrulukKontrol(string alinan)
//İçiresinde sayıdan başka karakter varsa 1 yoksa 0 değerini döndürür.
{
    for (int i = 0; i < alinan.length(); i++)
    {
        if (isalnum(alinan[i]) == 0)
        {
            dogrulukdegeri = 1;
            break;
        }
        else
        {
            if (isalpha(alinan[i]) == 0)
            {
                dogrulukdegeri = 0;
                continue;
            }
            else
            {
                dogrulukdegeri = 1;
                break;
            }
        }
    }
    if (dogrulukdegeri == 1)
    {
        return 1;
    }
    else if (dogrulukdegeri == 0)
    {
        return 0;
    }
}
