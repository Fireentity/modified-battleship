#ifndef POINT_H
#define POINT_H

#include <cmath>


class Point {
private:
    int x_;
    int y_;
public:
    Point(int x, int y);

    Point();

    int get_x() const;

    int get_y() const;

    Point add_x(int x) const;

    Point add_y(int y) const;

    //Viene utilizzata la distanza al quadrato perché è più veloce moltiplicare che fare la radice quadrata
    double squared_distance(const Point &point) const;

    Point middle_point(const Point &point) const;

    //TODO controllare i tipi di ritorno degli operatori
    //Ritorna Point & invece che void per permettere di concatenare questo operatore
    Point& operator=(const Point &);

    Point operator+(const Point &point) const;

    Point operator-(const Point &point) const;

    bool operator==(const Point &point) const;

    bool operator!=(const Point &point) const;
};

#endif //POINT_H
