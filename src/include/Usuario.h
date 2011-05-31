
#ifndef USUARIO_H
#define USUARIO_H

#include<QtCore>

class Usuario
{
public:
    Usuario(void);
    ~Usuario(void);

    QString getCargo(void);
    QString getContrasena(void);
    QString getEmail(void);
    int getId(void);
    QString getNombre(void);
    int getTelefono(void);

    void setCargo(QString cargo);
    void setContrasena(QString contrasena);
    void setEmail(QString email);
    void setId(QString id);
    void setNombre(QString nombre);
    void setTelefono(int telefono);

protected:
    QString Cargo;
    QString Contrasena;
    QString Email;
    int Id;
    QString Nombre;
    int Telefono;
};

inline QString Usuario::getCargo()
{
return Cargo;
}

inline QString Usuario::getContrasena()
{
    return Contrasena;
}

inline QString Usuario::getEmail()
{
    return Email;
}

inline int Usuario::getId()
{
    return Id;
}

inline QString Usuario::getNombre()
{
    return Nombre;
}

inline int Usuario::getTelefono()
{
    return Telefono;
}

inline void Usuario::setCargo(QString cargo)
{
    Cargo = cargo;
}

inline void Usuario::setContrasena(QString contrasena)
{
    Contrasena = contrasena;
}

inline void Usuario::setEmail(QString email)
{
    Email = email;
}

inline void Usuario::setId(QString id)
{
    Id = id;
}

inline void Usuario::setNombre(QString nombre)
{
    Nombre = nombre;
}

inline void Usuario::setTelefono(int telefono)
{
    Telefono = telefono;
}

#endif // USUARIO_H
