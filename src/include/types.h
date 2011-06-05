
#ifndef TYPES_H
#define TYPES_H

#define PUERTO			3490

#define SERIALIZAR(X)		reinterpret_cast<char *>(&X)
#define DESERIALIZAR(X)		reinterpret_cast<char *>(&X)

#define debug()			qDebug() << __LINE__ << " - " << __FILE__

enum Peticion {
    Autenticar,		// autentica un usuario en la base de datos
    DatosUsuario,	// muestra la información de un usuario
    DatosUsuarios	// lista los usuarios en la base de datos
};

enum Respuesta { done, error };

#endif