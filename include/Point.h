//Marco Pavanetto 2032486

#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <ostream>


class Point {
private:
    int x_;
    int y_;
public:

    static const int firstUpperCaseLetter;

    static char to_char(int index);

    static int to_index(char x);

    Point(int x, int y);

    Point(int y, char x);

    Point();

    int get_x() const;

    int get_y() const;

    Point add_x(int x) const;

    Point add_y(int y) const;

    //Viene utilizzata la distanza al quadrato perché è più veloce moltiplicare che fare la radice quadrata
    double squared_distance(const Point &point) const;

    //Ritorna Point & invece che void per permettere di concatenare questo operatore
    Point &operator=(const Point &);

    Point operator+(const Point &point) const;

    Point operator-(const Point &point) const;

    bool operator==(const Point &point) const;

    bool operator!=(const Point &point) const;

    std::string to_string() const;
};

#endif //POINT_H
