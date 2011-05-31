
QT += sql

INCLUDEPATH += include/
OBJECTS_DIR = tmp/
MOC_DIR = tmp/
UI_DIR = tmp/

HEADERS += include/DataBase.h \
    include/Producto.h \
    include/Usuario.h \
    include/Bodega.h \
    include/DBQueries.h \
    include/Administrar.h \
    include/Interfaz.h \
    include/autenticarse.h \
    include/Informacion_usuario_pendi.h \
    include/AdministracionUsuario.h
SOURCES += src/DataBase.cpp \
    src/main.cpp \
    src/DBQueries.cpp \
    src/Administrar.cpp \
    src/Interfaz.cpp \
    src/autenticarse.cpp \
    src/Informacion_usuario_pendi.cpp \
    src/AdministracionUsuario.cpp
FORMS += uis/autenticarse.ui \
    uis/administrar.ui \
    uis/Bodega.ui \
    uis/Informacion_usuario_pendi.ui \
    uis/interfaz.ui \
    uis/Producto.ui \
    uis/administracion_usuario.ui
