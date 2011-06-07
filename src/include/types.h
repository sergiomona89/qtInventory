
#ifndef TYPES_H
#define TYPES_H

#define HOST			"localhost"
#define PUERTO			3490

#define print(X)		qDebug() << X;

#define SERIALIZAR(X)		reinterpret_cast<char *>(&X)
#define DESERIALIZAR(X)		reinterpret_cast<char *>(&X)

#define debug()			qDebug() << __LINE__ << " - " << __FILE__

enum Peticion {
    Autenticar,		// autentica un usuario en la base de datos
    DatosUsuario,	// muestra la información de un usuario
    DatosUsuarios,	// lista los usuarios en la base de datos
    DatosBodega,	// muestra la información de una bodega
    DatosBodegas,	// lista las bodegas en la base de datos
    ActualizarUsuario,
    NuevoUsuario,
    EliminarUsuario,
};

enum Respuesta { done, error };

#endif
