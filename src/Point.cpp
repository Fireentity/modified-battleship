#include "Point.h"

Point::Point(int x, int y) : x_{x}, y_{y} {

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

Point::Point() : x_{0}, y_{0} {

}

Point Point::operator+(const Point &point) const {
    return Point{get_x()+point.get_x(),get_y()+point.get_y()};
}

Point Point::operator-(const Point &point) const {
    return Point{get_x()-point.get_x(),get_y()-point.get_y()};
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
    return Point{x_+x,y_};
}

Point Point::add_y(int y) const {
    return Point{x_, y_ + y};
}