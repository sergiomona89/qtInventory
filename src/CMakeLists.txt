PROJECT(inventory)

FIND_PACKAGE(Qt4 REQUIRED QtCore QtGui QtNetwork QtTest QtSql)

INCLUDE( ${QT_USE_FILE} )

INCLUDE_DIRECTORIES( ${QT_INCLUDES} ${CMAKE_BINARY_DIR} include )

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_DEFINITIONS( -Wall -Iinclude -I/usr/include/xlib -g -DQGLVIEWER_SHARED )


SET( QT_INVENTORY_HDRS
include/Act_bodega.h
include/Act_usuario.h
include/Administracionbodega.h
include/AdministracionUsuario.h
include/Administrar.h
include/autenticarse.h
include/Bodega.h
include/Cliente.h
include/Consulta_inventario.h
include/Crear_bodega.h
include/Crear_producto.h
include/Crear_usuario.h
include/DataBase.h
include/DataStream.h
include/DBQueries.h
include/Informacion_usuario_pendi.h
include/Info_usuario.h
include/Interfaz.h
include/Producto.h
include/Servidor.h
include/types.h
include/Usuario.h
)

SET( QT_INVENTORY_SRCS
src/Act_bodega.cpp
src/Act_usuario.cpp
src/Administracionbodega.cpp
src/AdministracionUsuario.cpp
src/Administrar.cpp
src/autenticarse.cpp
src/Cliente.cpp
src/Consulta_inventario.cpp
src/Crear_bodega.cpp
src/Crear_producto.cpp
src/Crear_usuario.cpp
src/DataBase.cpp
src/DBQueries.cpp
src/Informacion_usuario_pendi.cpp
src/Info_usuario.cpp
src/Interfaz.cpp
src/Servidor.cpp
src/DataStream.cpp
)

SET( QT_INVENTORY_UIS
uis/Act_bodega.ui
uis/actualizacion_bodega.ui
uis/actualizacion_producto.ui
uis/Act_usuario.ui
uis/Administracionbodega.ui
uis/AdministracionUsuario.ui
uis/administrar.ui
uis/autenticacion.ui
uis/autenticarse.ui
uis/Bodega.ui
uis/Consulta_inventario.ui
uis/consultar.ui
uis/Crear_bodega.ui
uis/Crear_producto.ui
uis/Crear_usuario.ui
uis/eliminar_bodega.ui
uis/gestor_inventario.ui
uis/informacion_bodega.ui
uis/Informacion_usuario_pendi.ui
uis/Info_usuario.ui
uis/ingresar_producto.ui
uis/interfaz.ui
uis/Producto.ui
uis/salida.ui
)


QT4_WRAP_UI( QT_INVENTORY_HDRS_UIS
${QT_INVENTORY_UIS}
)

QT4_WRAP_CPP( QT_INVENTORY_MOC_HDRS 
${QT_INVENTORY_HDRS}
)

add_library ( invlib 
${QT_INVENTORY_HDRS_UIS}
${QT_INVENTORY_MOC_HDRS}
${QT_INVENTORY_SRCS}
)


ADD_EXECUTABLE(client test/client.cpp)
ADD_EXECUTABLE(server test/server.cpp)


TARGET_LINK_LIBRARIES( client invlib ${QT_LIBRARIES} )
TARGET_LINK_LIBRARIES( server invlib ${QT_LIBRARIES} )
