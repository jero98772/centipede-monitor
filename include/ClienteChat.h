#ifndef CLIENTECHAT_H
#define CLIENTECHAT_H

#include <string>
#include <vector>
#include "ProcessMonitor.h" 

class ClienteChat {
public:
    ClienteChat(const std::string& direccionIP, int puerto);
    void conectarAlServidor();
    void manejarComando(const std::string& comando);
    void manejarProcesso(const std::vector<ProcessInfo>& procesos);
    void desconectar();

private:
    void recibirMensajes();

    std::string direccionIP;  // Dirección IP del servidor
    int puerto;  // Puerto del servidor
    int descriptorCliente;  // Descriptor del socket del cliente
    bool conectado;  // Estado de la conexión
};

#endif // CLIENTECHAT_H
