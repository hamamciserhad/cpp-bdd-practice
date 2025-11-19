#include <iostream>
using namespace std;

// -----------------------------------------------------------
// POINTER & REFERENCE DERS NOTLARI
// -----------------------------------------------------------
//
// * C++ pointer = bir değişkenin bellekteki adresini tutan yapı
// * reference (&) = değişkenin bir takma adı (alias)
// int x = 10;
// int& r = x;   // r, x’in takma adı (alias) r x e baglanir o yüzden x in bellekte bi adresi olmali
// r = 30;       // x de 30 olur
// Bellek → RAM üzerinde adresler vardır.
// int x = 10;
// int* p = &x
// &x → x'in bellekteki adresi
// p x in adresini tutan pointer
// *p pointer in isaret ettigi yerdeki deger = 10
// Pointer bildirimi:
// int* ptr = &x;
//
// Pointer üzerinden:
// - değer okunabilir  (*ptr)
// - değer değiştirilebilir (*ptr = 20)
//
// -----------------------------------------------------------

// -----------------------------------------------------------
// 1. Pointer temel örnek
// -----------------------------------------------------------

void basicPointerDemo()
{
    int x = 10;

    cout << "x in degeri: " << x << endl;
    cout << "x in bellekteki adresi: " << &x << endl;

    int *p = &x; // p artik x in adresini tutuyor

    cout << "Pointer p nin tuttugu adres: " << p << endl;
    cout << "Pointer ile x in degeri: " << *p << endl;

    // pointer ile x in degerini degiselim

    *p = 20;

    cout << "Pointer ile x i degistikten sonra x: " << x << endl;
    cout << "Pointer ile x i degistikten sonra x in degerini pointer ile cagirma: " << *p << endl;
    cout << "Pointer ile x i degstikten sonra x in adresini & ile cagrima: " << &x << endl;
    cout << "Pointer ile x i degstikten sonra x in adresini pointer ile cagrima: " << p << endl;
}

// -----------------------------------------------------------
// 2. Pointer ile swap (değer değiştirme)
// -----------------------------------------------------------

void swapWithPointer(int *a, int *b)
{
    cout << "A nin isaret ettigi deger: " << *a << " B nin isaret ettigi deger: " << *b << endl;
    int temp = *a; // a nin isaret ettigi deger
    *a = *b;
    *b = temp;
    cout << "Swap dan sonra A nin isaret ettigi deger: " << *a << " B nin isaret ettigi deger: " << *b << endl;
}

// -----------------------------------------------------------
// 3. Reference (&) — pointer’ın güvenli hali int& r = a ;  r a nin takma adidir.
// -----------------------------------------------------------

void swapWithReference(int &a, int &b)
{
    cout << "\n---- Reference ile swap ----" << endl;
    cout << "Once: a=" << a << ", b=" << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "Sonra: a=" << a << ", b=" << b << endl;
}

// -----------------------------------------------------------
// 4. Pointer ve array ilişkisi
// -----------------------------------------------------------
//
// Array ismi → zaten bir pointer gibi davranır
//
// int arr[3] = {10,20,30};
// arr → ilk elemana pointer (arr == &arr[0])
//
// *(arr + 1) = arr[1]
// -----------------------------------------------------------
void arrayPointerDemo()
{
 int arr[] = {10,20,30};   
 int* p = &arr[0];
 cout << "arr:  " << arr << endl; // adres
 cout << "&arr[0]: " << &arr[0] << endl;
 cout << "p:  " << p << endl; // ayni adres

 cout << "arr[0]: " << arr[0] << endl; 
 cout << "*(arr): " << *(arr) << endl; // bu da arr[0]
 cout << "*p: " << *p << endl; 

 cout << "arr[1]: " << arr[1] << endl; 
 cout << "*(arr+1): " << *(arr+1) << endl; 
 cout << "*(p+1): " << *(p+1) << endl;


}
int main()
{
    basicPointerDemo();
    int a = 12;
    int b = 23;
    swapWithPointer(&a, &b); // abi burda direk int türü bi sey yazamazsin adres göndermemiz lazim &a gibi o yüzden basta degerleri tanimlariz
    int a1 = 13;
    int b1 = 25;
    swapWithReference(a1, b1);
    cout << endl;
    arrayPointerDemo();
    return 0; 
}