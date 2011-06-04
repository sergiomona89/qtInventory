
QT += sql
QT += network

INCLUDEPATH += include/
OBJECTS_DIR = tmp/
MOC_DIR = tmp/
UI_DIR = tmp/

HEADERS += include/Servidor.h \
    include/DataBase.h \
    include/Act_usuario.h \
    include/Producto.h \
    include/Usuario.h \
    include/Bodega.h \
    include/DBQueries.h \
    include/Administrar.h \
    include/Info_usuario.h \
    include/Interfaz.h \
    include/autenticarse.h \
    include/Informacion_usuario_pendi.h \
    include/AdministracionUsuario.h \
    include/Crear_usuario.h \
    include/types.h \
    include/Crear_bodega.h \
    include/Act_bodega.h \
    include/Administracionbodega.h

SOURCES += src/Servidor.cpp \
    src/DataBase.cpp \
    src/Act_usuario.cpp \
    src/DBQueries.cpp \
    src/Administrar.cpp \
    src/Info_usuario.cpp \
    src/Interfaz.cpp \
    src/autenticarse.cpp \
    src/Informacion_usuario_pendi.cpp \
    src/AdministracionUsuario.cpp \
    src/Crear_usuario.cpp \
    src/Crear_bodega.cpp \
    src/Act_bodega.cpp \
    src/Administracionbodega.cpp
FORMS += uis/autenticarse.ui \
    uis/administrar.ui \
    uis/Act_usuario.ui \
    uis/Bodega.ui \
    uis/Info_usuario.ui \
    uis/Informacion_usuario_pendi.ui \
    uis/interfaz.ui \
    uis/Producto.ui \
    uis/AdministracionUsuario.ui \
    uis/Crear_usuario.ui \
    uis/Crear_bodega.ui \
    uis/Act_bodega.ui \
    uis/Administracionbodega.ui

server {
    TARGET = server
    SOURCES += test/server.cpp
}

client {
    TARGET = client
    SOURCES += test/client.cpp
}
