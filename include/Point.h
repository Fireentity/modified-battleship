#ifndef POINT_H
#define POINT_H

//Viene utilizzato uno struct per i punti nella board perchè non c'è nessun motivo di rendere private i field x e y
//In quanto field pubblici di uno struct non seguono la naming convention di tutte le altre classe (infatti non c'è "_")
struct Point {
    int x, y;
};

#endif //POINT_H
