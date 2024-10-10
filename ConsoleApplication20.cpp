#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class Frac {
private:
    int num;
    int denom;


    void reduce() {
        int gcd = gcd(num, denom);
        num /= gcd;
        denom /= gcd;
    }

public:
    Frac() : num(0), denom(1) {}


    Frac(int n, int d) : num(n), denom(d) {
        if (denom == 0) {
            throw inwers("Знаменник не може бути нульовим.");
        }
        reduce();
    }

    void intdata() {
        cout << "Введіть чисельник: ";
        cin >> num;
        cout << "Введіть знаменник: ";
        cin >> denom;
        if (denom == 0) {
            throw inwers("Знаменник не може бути нульовим.");
        }
        reduce();
    }


    void dspdat() const {
        if (denom == 1) {
            cout << num << endl;
        }
        else {
            cout << num << "/" << denom << endl;
        }
    }

    Frac add(const Frac& other) const {
        int new_num = num * other.denom + other.num * denom;
        int new_denom = denom * other.denom;
        return Frac(new_num, new_denom);
    }

    Frac sub(const Frac& other) const {
        int new_num = num * other.denom - other.num * denom;
        int new_denom = denom * other.denom;
        return Frac(new_num, new_denom);
    }

    Frac mul(const Frac& other) const {
        return Frac(num * other.num, denom * other.denom);
    }

    void savfar(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Не вдалося відкрити файл для запису.");
        }
        file << num << " " << denom << endl;
        file.close();
        cout << "Дані збережено у файл " << filename << endl;
    }

    void kgkfoeg(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Не вдалося відкрити файл для читання.");
        }
        file >> num >> denom;
        if (!file || denom == 0) {
            throw runtime_error("Помилка читання даних з файлу.");
        }
        reduce();
        file.close();
        cout << "Дані завантажено з файлу " << filename << endl;
    }
};

int main() {
    try {
        Frac f1;
        f1.intdata();
        f1.dspdat();

        string filename = "frac_data.txt";
        f1.savfar(filename);

        Frac f2;
        f2.kgkfoeg(filename);
        f2.dspdat();
    }
    catch (const exception& e) {
        cerr << "Помилка " << e.what() << endl;
    }

    return 0;
}
