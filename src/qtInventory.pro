QT += sql
HEADERS += DataBase.h \
    Producto.h \
    Usuario.h \
    Bodega.h \
    DBQueries.h \
    Administrar.h \
    Interfaz.h \
    autenticarse.h \
    Informacion_usuario_pendi.h
SOURCES += DataBase.cpp \
    main.cpp \
    DBQueries.cpp \
    Administrar.cpp \
    Interfaz.cpp \
    autenticarse.cpp \
    Informacion_usuario_pendi.cpp
FORMS += autenticarse.ui \
    administrar.ui \
    Bodega.ui \
    Informacion_usuario_pendi.ui \
    interfaz.ui \
    Producto.ui \
    usuario.ui
