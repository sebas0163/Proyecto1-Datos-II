#ifndef PUNTERO_HPP
#define PUNTERO_HPP


class Puntero
{
public:
    int id;
    Puntero();
    void setId(int);
    int getId();
    virtual bool comprobar();
    virtual void destruir();
};

#endif // PUNTERO_HPP
