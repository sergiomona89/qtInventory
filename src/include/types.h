
#define print(X)	qDebug() << X;
enum Peticion {
    Autenticar,	// autentica un usuario en la base de datos
    DatosUsuario,	// muestra la información de un usuario
    DatosUsuarios	// lista los usuarios en la base de datos
};

enum Respuesta { done, error };
