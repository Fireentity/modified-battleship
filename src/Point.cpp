#include "Point.h"

const int Point::firstUpperCaseLetter = 65;

Point::Point(int x, int y) : x_{x}, y_{y} {

}

Point::Point(int y,char x) : x_{to_index(x)}, y_{y} {

}

double Point::squared_distance(const Point &point) const {
    return std::pow(point.get_x() - get_x(), 2) + std::pow(point.get_y() - get_y(), 2);
}

int Point::get_x() const {
    return x_;
}

int Point::get_y() const {
    return y_;
}

Point Point::middle_point(const Point &point) const {
    return Point{(point.get_x() + get_x()) / 2, (point.get_y() + get_y()) / 2};
}

Point::Point() : x_{-1}, y_{-1} {

}

Point Point::operator+(const Point &point) const {
    return Point{get_x() + point.get_x(), get_y() + point.get_y()};
}

Point Point::operator-(const Point &point) const {
    return Point{get_x() - point.get_x(), get_y() - point.get_y()};
}

bool Point::operator==(const Point &point) const {
    return x_ == point.x_ &&
           y_ == point.y_;
}

bool Point::operator!=(const Point &point) const {
    return !(point == *this);
}

Point &Point::operator=(const Point &point) {
    this->x_ = point.get_x();
    this->y_ = point.get_y();
    return *this;
}

Point Point::add_x(int x) const {
    return Point{x_ + x, y_};
}

Point Point::add_y(int y) const {
    return Point{x_, y_ + y};
}

char Point::to_char(int index) {
    // Calcoliamo il valore ASCII della lettera corrispondente
    // al numero passato come argomento.
    // La lettera A ha valore ASCII 65, quindi basta sottrarre 65
    // al numero passato come argomento per ottenere il valore ASCII
    // della lettera corrispondente.
    char letter = char(index + firstUpperCaseLetter);

    // Se la lettera ottenuta è J o K, saltiamo alla successiva
    if (letter >= 'J') letter +=2;


    return letter;
}

int Point::to_index(char x) {
    if (x > 'I' && x < 'Z') { //toglie due per le lettere dopo jk
        return x - firstUpperCaseLetter - 2;
    }
    return x - firstUpperCaseLetter;
}

std::ostream &Point::operator<<(std::ostream &os) const {
    return os << to_char(x_) << y_;
}
