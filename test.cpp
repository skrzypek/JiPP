// nnoremap <F5> :<C-U>make %:r && ./%:r<CR>
#include <iostream>

using namespace std;


class Pojazd{

    public:
        virtual int liczba_kol() = 0;
};


class Rower:public Pojazd{

    public:
        int a;
        int b;
        int liczba_kol(){
            cout << a << "--" << b << endl;
            return 2;
        }

    Rower(int, int);
};


class Auto: public Pojazd{

    public:
        int liczba_kol(){
            return 4;
        }
};


int ile_kol(Pojazd &pojazd){
    return pojazd.liczba_kol();
}

Rower::Rower(int _b, int _a): a(_a), b(_b){}


int main(){
    Rower rower = Rower(3, 1);
    Auto samochod;

    cout << ile_kol(rower) << endl;
    cout << ile_kol(samochod) << endl;
    return 0;
}
