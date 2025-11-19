#include <iostream>
#include <string>
#include <vector> // vektor kullanmak icin
using namespace std;

// ---------------------------------------------------------
// ARRAYS ve VECTORS — DERS NOTLARI
// ---------------------------------------------------------
//
// ARRAY = Sabit uzunluklu liste
// VEC   = Dinamik liste (büyür, küçülür) → C++ PROJECT’LERDE ÇOK KULLANILIR
//
// Özet:
// int arr[5];           → uzunluk sabit
// vector<int> v;        → uzunluk dinamik (push_back ile eklenir)
//
// ---------------------------------------------------------

int main()
{
    // -----------------------------------------------------
    // 1. ARRAY KULLANIMI (C tarzı dizi)
    // -----------------------------------------------------
    int arr[] = {1, 2, 3, 4, 5};

    cout << "Array elemanlarini yazdiralim: ";
    // sizeof(arr)  → dizinin bellekte kapladigi toplam byte (5*4 = 20)
    // sizeof(arr[0]) → bir elemanin byte boyutu (4)
    // toplam_boyut / eleman_boyutu = eleman sayisi
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // -----------------------------------------------------
    // ARRAY üzerinde en büyük sayıyı bulma örneği
    // -----------------------------------------------------
    int maxValue = arr[0];
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }
    cout << "Array icindeki en büyük sayi: " << maxValue << endl;

    // -----------------------------------------------------
    // 2. VECTOR — DİNAMİK DİZİ
    // -----------------------------------------------------
    vector<int> ages;
    /*
        vector, push_back ile büyür:
        ages.push_back(18);
        ages.push_back(25);
        ages.push_back(30);
    */

    ages.push_back(18);
    ages.push_back(8);
    ages.push_back(20);
    ages.push_back(11);

    cout << "Vector elemanlari: ";
    for (int i = 0; i < ages.size(); i++)
    {
        cout << ages[i] << " ";
    }
    cout << endl;
    // -----------------------------------------------------
    // VECTOR BOYUTU
    // -----------------------------------------------------
    cout << "Vector boyutu: " << ages.size() << endl;

    // -----------------------------------------------------
    // VECTOR'DEN SON ELEMANI SILME (pop_back)
    // -----------------------------------------------------
    ages.pop_back();
    cout << "pop_back sonrasi: ";
    for (int x : ages) // java daki range based for varmis bunda da
    {
        cout << x << " ";
    }
    cout << endl;

    // -----------------------------------------------------
    // KULLANICIDAN 5 SAYI ALIP VECTOR’E EKLEME
    // -----------------------------------------------------

    vector<int> userNumbers;
    cout << "Vectore eklenecek 5 tane sayi giriniz: ";
    for (int i = 0; i < 5; i++)
    {
        int nums;
        cin >> nums;
        userNumbers.push_back(nums);
    }
    cout << "Vectore eklediginiz sayilar: ";
    for (int x : userNumbers)
    {
        cout << x << " ";
    }
    cout << endl;
    // ORTALAMA HESAPLAMA
    int sum = 0;
    for (int x : userNumbers)
    {
        sum += x;
    }
    cout << "Girdigin sayilarin ortalamasi: " << sum / (double)userNumbers.size() << endl;

    // -----------------------------------------------------
    // STRING = KARAKTER ARRAY’I gibi davranır
    // -----------------------------------------------------

    string word = "Hello World";
    for (int i = 0; i < word.length(); i++)
    {
        cout << word[i] << " ";
        // karakterlere index ile erişilir
    }
    cout << endl;
    return 0;
}