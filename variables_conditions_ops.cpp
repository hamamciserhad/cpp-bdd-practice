#include <iostream> //ben ekrana veri yazmak ve klavyeden veri almak istiyorum bana bunun kütüpünü ekle (in out stream)
#include <string>   // string kullanabilmek icin
using namespace std;

int main()
{
  // ---------------------------
  // 1. Merhaba Dünya
  // ---------------------------
  cout << "Hello World!" << endl;

  /*
      cout  = console output (ekrana yazma)
      <<    = "şunu ekrana gönder"
      endl  = satır sonu (newline gibi)
  */

  // ---------------------------
  // 2. Temel Veri Tipleri
  // ---------------------------
  int age = 20;           // tamsayı
  double height = 1.85;   // ondalıklı sayı
  bool isStudent = true;  // mantıksal (true/false)
  char grade = 'A';       // tek karakter
  string name = "Serhad"; // kelime / metin

  // Temel bilgileri ekrana yazdır
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
  cout << "Is Student: " << isStudent << endl;
  cout << "Grade: " << grade << endl;

  // ---------------------------
  // 3. Kullanıcıdan Veri Almak
  // ---------------------------
  string name2;
  int age2;

  cout << "Ismin ne? ";
  cin >> name2; // kullanıcıdan string alır

  cout << "Yasin kac? ";
  cin >> age2; // kullanıcıdan int alır

  // Kullanıcıya cevap yazdır
  cout << "Merhaba " << name2
       << ", sen " << age2 << " yasindasin." << endl;

  // ---------------------------
  // 4. Kullanıcıdan Sayı Almak (Örnek)
  // ---------------------------
  int sayi;

  cout << "En sevdigin sayi ne? "; // soru sor
  cin >> sayi;                     // kullanıcıdan integer al

  cout << "Demek en sevdigin sayi: "
       << sayi << " haa!" << endl; // sonucu yazdır

  // ---------------------------
  // 5. If - Else Koşul Yapıları (Karar Verme)
  // ---------------------------
  int age3;
  cout << "Yasin kac?";
  cin >> age3;

  if (age3 < 18)
  {
    cout << "Sen daha resit degilsin!" << endl;
  }
  else if (age3 < 30)
  {
    cout << "Sen artik genclik yillarindasin." << endl;
  }
  else
  {
    cout << "Sen artik büyük adam olmussun!" << endl;
  }

  // ---------------------------
  // 6. Tek mi Çift mi? (Mod İşlemiyle Kontrol)
  // ---------------------------
  int sayi2;

  cout << "Bir sayi giriniz: ";
  cin >> sayi2; // kullanıcıdan sayı al

  // sayi % 2 → sayinin 2'ye bölümünden kalanı verir
  // kalan 0 ise → sayı çifttir
  // kalan 1 ise → sayı tektir
  if (sayi2 % 2 == 0)
  {
    cout << "Bu sayi CIFT bir sayidir." << endl;
  }
  else
  {
    cout << "Bu sayi TEK bir sayidir." << endl;
  }

  // Full satir okuma (getline)
  /*
  not: cin >> sadece bi ilk kelimeyi alir tam bir cümle almak isitiyorsan getline kullanilir.
  */
  cin.ignore(); // önce buffer temizlenir
  string fullName;
  cout << "Tam isminizi yaziniz ";
  getline(cin, fullName);
  cout << "Adiniz ve soyadiniz: " << fullName << endl;

  // mantiksal ops.
  int ageTest;
  cout << "Yasin kac? ";
  cin >> ageTest;
  // && ve , || veya , ! degil
  if (ageTest >= 18 && ageTest <= 30)
  {
    cout << "18 ile 30 yas arasindasin. " << endl;
  }
  else if (ageTest < 18 || ageTest > 50)
  {
    cout << "18 den kücük veya 50 den büyüksün " << endl;
  }
  // ic ice if 
  int x; 
  cout << "Bir sayi giriniz: ";
  cin >> x ; 
  if(x%2 == 0){
      if(x>10){
          cout << "Cift ve 10 dan büyük." << endl;
      }
      else{
        cout << "Cift ve 10 dan kücük. " << endl;
      }
  }
  else{
    cout << "bu sayi tek. " << endl;
  }
  // ---------------------------
  // 4. Programı Bitir
  // ---------------------------
  return 0; // 0 = başarıyla bitti
}