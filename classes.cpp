#include <iostream>
#include <string>
using namespace std;

// -----------------------------------------------------------
// STRUCT ve CLASS — DERS NOTLARI
// -----------------------------------------------------------
//
// STRUCT:
// - C ve C++’ta veri gruplamak için kullanılır
// - Varsayılan erişim: public
//
// CLASS:
// - C++’ın asıl OOP yapısıdır
// - Varsayılan erişim: private
//
// Temel fark: Sadece varsayılan erişim belirleyicisi.
// Modern C++’ta struct = public class gibi kullanılır.
//
// -----------------------------------------------------------

// -----------------------------------------------------------
// 1. STRUCT ÖRNEĞİ — Basit Öğrenci yapısı
// -----------------------------------------------------------

struct Student
{
    string name;
    int age;
    double grade;
    void printInfo()
    {
        cout << "Isim: " << name << " Yas: " << age << " Not: " << grade << endl;
    }
};

// -----------------------------------------------------------
// 2. CLASS ÖRNEĞİ — private / public farkı
// -----------------------------------------------------------
class Rectangle
{
private: // private bi etikettik altindaki bütün üyeleri private yapar.
    double height;
    double width;

public: // const u public olmazsa nesnesini olusturamayiz
    // C++’ta "this" bir pointerdir (Rectangle* this). Bu yüzden "->" kullanılır.
    // Java’daki gibi this.height değil, this->height yazılır.
    // this->height = height;  →  pointer’ın gösterdiği nesnenin height alanına erişir
    // height (sağdaki) ise constructor parametresidir (shadowing durumu).
    Rectangle(double height, double width)
    {
        (*this).height = height; // abi aslinda this-> i su sekilde yazabiliriz (*this).
        this->width = width;
    }
    double area()
    {
        return width * height;
    }
    double perimeter()
    {
        return 2 * (width + height);
    }

    void print()
    {
        cout << "Rectangle: " << width << " x " << height
             << ", Alan = " << area()
             << ", Cevre = " << perimeter()
             << endl;
    }
};

// -----------------------------------------------------------
// 3. CLASS + POINTER KULLANIMI (ÇOK ÖNEMLİ!)
// -----------------------------------------------------------

// -----------------------------------------------------------
// ÖNEMLİ FARKLAR — Pointer vs Nesne, Stack vs Heap
// -----------------------------------------------------------
// 1) C++’ta iki şekilde nesne oluşturulur:
//    - Stack:  Student s;        → Nesnenin kendisi oluşturulur.
//    - Heap:   Student* s = new Student();
//              → Heap’te nesne oluşur, s sadece adresi tutar.
//                (delete s; yazmazsan bellek kaçağı olur!)
//
// 2) Java’da her şey heap’tedir ve new kullanılır.
//    C++’ta ise new ZORUNLU değildir. Çoğu zaman stack daha güvenli.
//
// 3) Pointer sadece bir adres tutar. Bir özelliği yoktur.
//    Eğer node->next yazabiliyorsak, bu pointer’ın gösterdiği
//    sınıfın içinde 'next' adlı bir üye olduğu içindir.
//
// 4) (*ptr).value ile ptr->value tamamen aynıdır.
//    Ama ptr->value daha kısadır ve standarttır.
//
// 5) BDD veri yapılarında (linked list, tree, graph)
//    birbirine bağlanan yapılar pointer ile yapılır.
//    Bu yüzden Node* next kullanımı çok önemlidir.
// -----------------------------------------------------------

class Node
{
public:
    int value;
    Node *next; // sonraki node a pointer yani o nodun adresini gösterir.
    Node(int value)
    {
        this->value = value;
        next = nullptr; // baslangicta herhangi bi yere bagli degil.
    }
};

int main()
{
    // iki tane nesen olusturma mantigi var:
    // Student s1; (stack: bellekte direk bi student nesnesi olusturur)
    // Student* s2 = new Student(); (bellekte heap üzerinde bi student nesnesi olusturur s2 o nesnenin adresini tutan pointer dir. ama c de garbage collector yok silmen lazim manual "delete s2;")
    Student s1;
    s1.name = "Serhad";
    s1.age = 22;
    s1.grade = 2.0;
    s1.printInfo();

    Rectangle r(3, 5);
    r.print();

    // ---------------- NODE + POINTER ÖRNEĞİ ----------------
    /*
        Node1 → Node2 → Node3 şeklinde bir zincir yapacağız.
        Bu, yarın BDD Node yapısı kurarken çok işimiz görecek.
    */
    Node *n1 = new Node(10); // n1 olusturulan degeri 10 olan node nesnesnin adresini tutar
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);

    // node lari birbirine baglayalim
    n1->next = n2;
    (*n2).next = n3;

    // Zinciri gezelim:
    cout << "\nNode zinciri:" << endl;
    Node *current = n1;
    while (current != nullptr)
    {
        cout << "Node degeri: " << (*current).value << endl; 
        current = current->next;
    }

    return 0;
}