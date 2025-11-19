#include <iostream>
#include <map>
#include <tuple>
using namespace std;

// -----------------------------------------------------------
// BDD Node yapısı
// -----------------------------------------------------------

class BDDNode
{
public:
    int var;
    BDDNode *low;
    BDDNode *high;
    // Const:
    BDDNode(int v, BDDNode *l, BDDNode *h)
    {
        var = v;
        low = l;
        high = h;
    }
};

// -----------------------------------------------------------
// Terminal düğümleri (sabit)
// -----------------------------------------------------------
BDDNode *BDD_ZERO = new BDDNode(-1, nullptr, nullptr);
BDDNode *BDD_ONE = new BDDNode(-1, nullptr, nullptr);

// -----------------------------------------------------------
// UNIQUE TABLE
// Aynı (var, low, high) üçlüsünden sadece 1 tane olmasını sağlar.
// map key: tuple (var, low_ptr, high_ptr)
// -----------------------------------------------------------
map<tuple<int, BDDNode *, BDDNode *>, BDDNode *> uniqueTable; // Anahtar olarak (var, lowPtr, highPtr) üçlüsünü tut, değer olarak da bir BDDNode pointer’ı sakla.

// mk(var, low, high) → unique node üretir
BDDNode *mk(int var, BDDNode *low, BDDNode *high)
{
    // REDUCTION RULE #1 : low == high → redundant test → child döndür
    if (low == high)
    {
        return low;
    }
    // c++ da auto yazarsan c kendisi türünü buluyor
    auto key = make_tuple(var, low, high);
    // unique table'da varsa aynı node'u geri döndür
    // aradigimiz key degeri end e esit degilse uniqtable da vardir döndür (end bulamadim iste demek)
    if (uniqueTable.find(key) != uniqueTable.end())
    {
        return uniqueTable[key];
    }
    // yoksa yeni node oluştur
    BDDNode *node = new BDDNode(var, low, high);
    // unique table a ekle
    uniqueTable[key] = node;
    return node;
}

// -----------------------------------------------------------
// COMPUTED TABLE (Memoization)
// (u, v, op) → result
// op = 0: AND, 1: OR (istersen XOR falan ekleyebilirsin)
// -----------------------------------------------------------
map<tuple<BDDNode *, BDDNode *, int>, BDDNode *> computed;

// -----------------------------------------------------------
// APPLY(u, v, op)
// op = 0 → AND
// op = 1 → OR
// -----------------------------------------------------------

BDDNode *Apply(BDDNode *u, BDDNode *v, int op)
{
    // memoization (computed table) bu digerinin aynisi
    auto key = make_tuple(u, v, op);
    if (computed.find(key) != computed.end())
    {
        return computed[key];
    }
    // 1) Terminal durumlar
    if (u->var == -1 && v->var == -1)
    {
        int a = (u == BDD_ONE) ? 1 : 0;
        int b = (v == BDD_ONE) ? 1 : 0;

        // ops:
        int result;
        if (op == 0)
            result = a & b; // and
        else if (op == 1)
            result = a | b; // or
        else
            result = a ^ b; // xor

        computed[key] = (result == 1 ? BDD_ONE : BDD_ZERO);
        return computed[key];
    }

    // 2) Nonterminal durum
    int u_var = u->var;
    int v_var = v->var;

    if (u_var == -1)
        u_var = 99999;
    if (v_var == -1)
        v_var = 99999;

    BDDNode* low;
    BDDNode* high;

    if (u_var == v_var)
    {
        low = Apply(u->low, v->low, op);
        high = Apply(u->high, v->high, op);
        computed[key] = mk(u->var, low, high);
    }
    else if (u_var < v_var)
    {
        low = Apply(u->low, v, op);
        high = Apply(u->high, v, op);
        computed[key] = mk(u->var, low, high);
    }
    else
    {
        low = Apply(u, v->low, op);
        high = Apply(u, v->high, op);
        computed[key] = mk(v->var, low, high);
    }

    return computed[key];
}

// -----------------------------------------------------------
// Simple test: f = x1 AND x2
// -----------------------------------------------------------


int main() {

    // Raw BDD nodes (ordering: x1 < x2)
    BDDNode* x2 = mk(2, BDD_ZERO, BDD_ONE);
    BDDNode* x1 = mk(1, BDD_ZERO, x2);

    // f = x1  (test için)
    BDDNode* f = x1;

    // g = x2
    BDDNode* g = x2;

    // h = f AND g  → Apply ile hesapla
    BDDNode* h = Apply(f, g, 0); // 0 = AND

    cout << "Apply(x1, x2, AND) calisti. Root var = "
         << h->var << endl;

    // BDD'nin kök değişkeni x1 olmalı
    // high child x2 node'u olmalı
    // low child terminal 0 olmalı

    return 0;
}