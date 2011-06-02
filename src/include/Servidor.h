
#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <QObject>

#define PUERTO	3490

class QUdpSocket;

class Servidor: public QObject
{
    Q_OBJECT
public:
    Servidor(QObject* parent = 0);
    ~Servidor(void);
    
    QUdpSocket * socket(void);

protected:
    QUdpSocket * _socket;

protected slots:
    void readPendingDatagrams(void);
};

inline QUdpSocket * Servidor::socket()
{
  return _socket;
}

#endif