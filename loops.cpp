#include <iostream>
#include <string>
using namespace std;
int main()
{
    // ---------------------------
    // 7. Döngüler (Loops)
    // ---------------------------

    // FOR DÖNGÜSÜ
    // 1'den 10'a kadar sayıları yazdıran basit bir döngü
    cout << "1'den 10'a kadar sayılar: " << endl;

    for (int i = 1; i <= 10; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    // ---------------------------
    // Çift sayıları yazdırma
    // ---------------------------
    cout << "0-20 arasi cift sayilari yazdirma: " << endl;
    for (int i = 0; i <= 20; i++)
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    // ---------------------------
    // WHILE DÖNGÜSÜ
    // ---------------------------
    cout << "While ile geri sayim:" << endl;
    int sayi = 10;   // initializer
    while (sayi > 0) // condition
    {
        cout << sayi << " ";
        sayi--; // inc-decrement
    }
    cout << endl;

    // ---------------------------
    // break ve continue
    // ---------------------------
    cout << "Break ve Continue Örneği:" << endl;
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            continue;
        }
        if (i == 8)
        {
            break;
        }
        cout << i << " ";
    }
    cout << endl;

    // ---------------------------
    // Kullanıcı şifre doğru girene kadar döngü
    // ---------------------------
    string password;
    cout << "sifrenizi giriniz (1234): ";

    while (true)
    {
        cin >> password;
        if (password == "1234")
        {
            cout << "sifreniz dogru!" << endl;
            break;
        }
        else
        {
            cout << "Sifre yanlis tekrar deneyiniz!";
        }
    }

    return 0;
}