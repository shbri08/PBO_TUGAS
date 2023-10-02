#include <iostream>
#include <cmath>

class Point {
private:
    int x, y;

public:
    Point() : x(0), y(0) {}

    Point(int x, int y) : x(x), y(y) {}

    int getX() {
        return x;
    }

    void setX(int x) {
        this->x = x;
    }

    int getY() {
        return y;
    }

    void setY(int y) {
        this->y = y;
    }

    std::string toString() {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }

    int* getXY() {
        int* hasil = new int[2];
        hasil[0] = x;
        hasil[1] = y;
        return hasil;
    }

    void setXY(int x, int y) {
        this->x = x;
        this->y = y;
    }

    double jarak(int x, int y) {
        int selisihX = this->x - x;
        int selisihY = this->y - y;
        return sqrt(selisihX * selisihX + selisihY * selisihY);
    }

    double jarak(Point lainnya) {
        int selisihX = this->x - lainnya.getX();
        int selisihY = this->y - lainnya.getY();
        return sqrt(selisihX * selisihX + selisihY * selisihY);
    }

    double jarak() {
        return sqrt(x * x + y * y);
    }
};

int main() {
    // Uji konstruktor dan toString()
    Point p1(1, 2);
    std::cout << p1.toString() << std::endl;
    Point p2;
    std::cout << p2.toString() << std::endl;

    // Uji setter dan getter
    std::cout << p1.toString() << std::endl;
    std::cout << "Nilai X adalah : " << p1.getX() << std::endl;
    std::cout << "Nilai Y adalah : " << p1.getY() << std::endl;

    // Uji setXY() dan getXY()
    std::cout << p1.toString() << std::endl;
    int* xy = p1.getXY();
    std::cout << "Nilai X adalah: " << xy[0] << std::endl;
    std::cout << "Nilai Y adalah: " << xy[1] << std::endl;
    delete[] xy;

    // Uji 3 versi overloaded dari jarak()
    Point p3(10, 11);
    std::cout << "Jarak adalah: " << p1.jarak(10, 11) << std::endl;
    std::cout << "Jarak adalah: " << p1.jarak(p3) << std::endl;
    std::cout << "Jarak adalah: " << p3.jarak(p1) << std::endl;
    std::cout << "Jarak adalah: " << p1.jarak() << std::endl;

    return 0;
}
