#include "Point.h"

const int Point::firstUpperCaseLetter = 65;

Point::Point(int x, int y) : x_{x}, y_{y} {

}

Point::Point(int x,char y) : x_{x}, y_{to_index(y)} {

}

Point::Point() : x_{-1}, y_{-1} {

}

int Point::get_x() const {
    return x_;
}

int Point::get_y() const {
    return y_;
}

double Point::squared_distance(const Point &point) const {
    return std::pow(point.get_x() - get_x(), 2) + std::pow(point.get_y() - get_y(), 2);
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

/**
 *
 * @param index è l'intero da trasformare in lettera per la tabella
 * @return ritorna la lettera associata all'intero corrispondente
 */
char Point::to_char(int index) {
    // Calcoliamo il valore ASCII della lettera corrispondente
    // al numero passato come argomento.
    // La lettera A ha valore ASCII 65, quindi basta sottrarre 65
    // al numero passato come argomento per ottenere il valore ASCII
    // della lettera corrispondente.
    char letter = char(index + firstUpperCaseLetter);

    // Se la lettera ottenuta è J o K, saltiamo alla successiva
    if (letter >= 'J') letter +=2;


    return letter-1;
}
/**
 *
 * @param x il carattere associato alle ordinate del punto
 * @return ritorna il numero associato al carattere partendo da A=1 e saltando J,K
 */
int Point::to_index(char x) {
    if (x > 'I' && x < 'Z') { //toglie due per le lettere dopo jk
        return x - firstUpperCaseLetter - 2 +1;
    }
    return x - firstUpperCaseLetter+1;
}

std::string Point::to_string() const {
    return std::string{to_char(y_)} + std::to_string(x_);
}
