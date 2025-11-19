#include <iostream>
using namespace std;

// -----------------------------------------------------------
// BDD NODE DERS NOTLARI
// -----------------------------------------------------------
//
// Temel BDD Node üç şeyden oluşur:
//
//  - var     → temsil ettiği boolean değişken (x1, x2, x3 …)
//  - low     → var = 0 olduğunda gidilecek node
//  - high    → var = 1 olduğunda gidilecek node
//
// TERMINAL NODE = 0 ve 1 düğümleri
//  (BDD'nin yapraklarıdır)
//
// BDD DAG yapısıdır. Ağaç değil → shared nodes olabilir.
// -----------------------------------------------------------

class BDDNode
{
public:
    int var;       // x1 = 1, x2 = 2, terminal = -1
    BDDNode *low;  // var = 0 olursa
    BDDNode *high; // var = 1 olursa
    // Const:
    BDDNode(int v, BDDNode *l, BDDNode *h)
    {
        var = v;
        low = l;
        high = h;
    }
};

// -----------------------------------------------------------
// Küçük bir test BDD'si kuralım:
// F = x1 AND x2  (çok basit bir BDD)
//
// x1
// ├─0 → 0
// └─1 → x2
//       ├─0 → 0
//       └─1 → 1
// -----------------------------------------------------------
int main()
{
    // Terminal dügümleri olustur(sabit olarak). Ikisi de -1 dönecek ve low veya high child lari da yok leaf yani.
    BDDNode *BDD_ONE = new BDDNode(-1, nullptr, nullptr);  // terminal 1
    BDDNode *BDD_ZERO = new BDDNode(-1, nullptr, nullptr); // terminal 0

    // x2 dügümü
    BDDNode *x2 = new BDDNode(
        2,        // var = x2
        BDD_ZERO, // x2 = 0 ise sonuc 0 olacak (low branch)
        BDD_ONE   // x2= 1 ise sonud 1 olacak (high branch)
    );

    // x1 dügümü
    BDDNode *x1 = new BDDNode(
        1,
        BDD_ZERO,
        x2);

    // simdi test edecez kullanicidan x1 ve x2 degerini 0-1 olacak sekilde alalim
    int x1_val, x2_val;
    cout << "x1 degerini gir (0/1): ";
    cin >> x1_val;
    cout << "x2 degerini gir (0/1): ";
    cin >> x2_val;

    // BDD üzerinden yürüyelim
    BDDNode *current = x1;

    // x1 e göre dal, verilen x1 in degeri 0 ise low 1 ise high a gec.
    if (x1_val == 0)
    {
        current = current->low;
    }
    else
    {
        current = current->high;
    }
    // ve eger terminal e ulastiysan dur ve sonucu yazdir.
    if (current->var == -1)
    {
        if (current == BDD_ONE)
        {
            cout << "Sonuc: " << 1 << endl;
        }
        else
        {
            cout << "Sonuc: " << 0 << endl;
        }
        return 0;
    }
    // x2 e göre dal:
    if (x2_val == 0)
    {
        current = current->low;
    }
    else
    {
        current = current->high;
    }

    // Terminal kontrolü
    if (current->var == -1)
    {
        cout << "Sonuc: " << (current == BDD_ONE ? 1 : 0) << endl;
        return 0;
    }
    return 0;
}