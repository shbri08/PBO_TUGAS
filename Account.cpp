#include <iostream>
#include <iomanip>
using namespace std;

class Account {
private:
    int nomor;
    double saldo;

public:
    Account(int nomor) {
        this->nomor = nomor;
        this->saldo = 0.0;
    }

    Account(int nomor, double saldo) {
        this->nomor = nomor;
        this->saldo = saldo;
    }

    int getNomor() {
        return nomor;
    }

    double getSaldo() {
        return saldo;
    }

    string toString() {
        return "Rekening[nomor=" + to_string(nomor) + ",saldo=$" + to_string(saldo) + "]";
    }

    void kredit(double jumlah) {
        saldo += jumlah;
    }

    void debit(double jumlah) {
        if (saldo >= jumlah) {
            saldo -= jumlah;
        } else {
            cout << "Jumlah melebihi saldo" << endl;
        }
    }

    void transferKe(double jumlah, Account& lain) {
        if (saldo >= jumlah) {
            saldo -= jumlah;
            lain.saldo += jumlah;
        } else {
            cout << "Jumlah melebihi saldo" << endl;
        }
    }
};

int main() {
    Account a1(5566);
    cout << a1.toString() << endl;
    Account a2(1234, 99.9);
    cout << a2.toString() << endl;

    cout << "Nomor akun adalah : " << a2.getNomor() << endl;
    cout << "Saldo adalah : $" << a2.getSaldo() << endl;

    a1.kredit(11.1);
    cout << a1.toString() << endl;

    a1.debit(5.5);
    cout << a1.toString() << endl;

    a1.debit(500);
    cout << a1.toString() << endl;

    a2.transferKe(1.0, a1);
    cout << a1.toString() << endl;
    cout << a2.toString() << endl;

    return 0;
}
