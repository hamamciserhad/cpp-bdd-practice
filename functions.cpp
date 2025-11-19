#include <iostream>
#include <string>
using namespace std;
// ---------------------------------------------------------
// C++ FONKSİYONLARI — DERS NOTLARI
// ---------------------------------------------------------
//
// Fonksiyon = Belirli bir işi yapan küçük kod bloklarıdır.
//
// NEDEN KULLANIRIZ?
// - Kod tekrarını azaltmak için
// - Programı modüler yapmak için
// - Okunabilirliği artırmak için
//
// Temel yapı:
// return_type functionName(parameter_list) {
//      // kodlar
//      return değer; void se return etmez
// }
//
// Örnek:
// int topla(int a, int b) {
//     return a + b;
// }
//
// ---------------------------------------------------------

// ---------------------------------------------------------
// 1. PARAMETRELİ VE RETURN'lü FONKSİYON
// ---------------------------------------------------------

// Bir sayının çift olup olmadığını söyleyen fonksiyon
bool isEven(int x)
{
    return x % 2 == 0;
}

// ---------------------------------------------------------
// 2. VOID (GERİ DÖNÜŞSÜZ) FONKSİYON
// Bir şey döndürmez → sadece iş yapar
// ---------------------------------------------------------
void greet(string name)
{
    cout << "Merhaba " << name << "! Dersimize hos geldin. " << endl;
}

// ---------------------------------------------------------
// 3. BİRDEN FAZLA PARAMETRELİ FONKSİYON
// ---------------------------------------------------------
int maxOfTwo(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

// ---------------------------------------------------------
// 4. OVERLOADING (AYNI İSİMLE BİRDEN FAZLA FONKSİYON)
// ---------------------------------------------------------
//
// *Gelişmiş bir konudur ama bilmek + görüşmede söylemek avantaj sağlar
//
// Aynı isim ama farklı parametrelerle fonksiyon yazabilirsin!
// C++ bunu destekler → buna OVERLOADING denir.
//

int square(int x)
{
    return x * x;
}

double square(double x)
{
    return x * x;
}

// ---------------------------------------------------------
// 5. FONKSİYON PROTOTYPE — İleri Seviye Küçük Bilgi
// ---------------------------------------------------------
//
// C++ fonksiyonları main'den sonra da yazabilirsin.
// Ama önce “prototip” bildirmen gerekir.
// (Bu konu BDD’de class yazarken işine yarar)
// ---------------------------------------------------------

// ---------------------------------------------------------
// MAIN FONKSİYONU
// ---------------------------------------------------------

int main()
{
    // -----------------------------------------------------
    // isEven fonksiyonu testi
    // -----------------------------------------------------
    int number;
    cout << "Bir sayi giriniz: ";
    cin >> number;
    if (isEven(number))
    {
        cout << "Bu sayi bir cift sayidir." << endl;
    }
    else
    {
        cout << "Bu sayi bir tek sayidir." << endl;
    }

    // -----------------------------------------------------
    // greet fonksiyonu testi
    // -----------------------------------------------------
    string name;
    cout << "Ismini gir: ";
    cin >> name;
    greet(name);

    // -----------------------------------------------------
    // maxOfTwo fonksiyonu testi
    // -----------------------------------------------------
    int a, b;
    cout << "Iki sayi gir: ";
    cin >> a >> b;

    cout << "Büyük olan sayi: " << maxOfTwo(a, b) << endl;

    // -----------------------------------------------------
    // Overloading testi
    // -----------------------------------------------------
    cout << "square(5) = " << square(5) << endl;       // int
    cout << "square(3.5) = " << square(3.5) << endl;   // double


    return 0;
}