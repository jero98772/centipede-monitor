#include <iostream>
#include "ClienteChat.h"
#include "ServidorChat.h"
#include "ProcessMonitor.h" 
//#include <pybind11/pybind11.h>
//#include <pybind11/stl.h>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <set>
#include <algorithm>
#include <pwd.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <chrono>



/*
namespace py = pybind11;
PYBIND11_MODULE(process_monitor, m) {
    py::class_<ProcessInfo>(m, "ProcessInfo")
        .def(py::init<int, std::string, std::string, std::string, long, double>())
        .def("to_dict", &ProcessInfo::to_dict);

    py::class_<ProcessMonitor>(m, "ProcessMonitor")
        .def(py::init<>())
        .def("get_processes", &ProcessMonitor::getProcesses)
        .def("monitor_processes", &ProcessMonitor::monitorProcesses);
}*/
int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <modo> <direccionIP> <puerto>\n";
        std::cerr << "Modos disponibles: servidor, cliente\n";
        return 1;
    }

    std::string modo = argv[1];

    if (modo == "servidor") {
        if (argc < 3) {
            std::cerr << "Uso: " << argv[0] << " servidor <puerto>\n";
            return 1;
        }
        int puerto = std::stoi(argv[2]);
        ServidorChat servidor(puerto);  // Inicializa el servidor con el puerto proporcionado
        servidor.iniciar();  // Inicia el servidor
    } else if (modo == "cliente") {
        if (argc < 4) {
            std::cerr << "Uso: " << argv[0] << " cliente <direccionIP> <puerto>\n";
            return 1;
        }
        std::string direccionIP = argv[2];
        int puerto = std::stoi(argv[3]);
        ClienteChat cliente(direccionIP, puerto);  // Inicializa el cliente con la dirección IP y puerto proporcionados
        cliente.conectarAlServidor();  // Conecta al servidor

        std::string mensaje;
        ProcessMonitor monitor;
        //auto start = std::chrono::high_resolution_clock::now(); // Reset the start time

        while (true) {
            /*
            auto now = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();

            if (elapsed >= 5) {
                //runAfterFiveSeconds();
                functionCalled = true;
                start = std::chrono::high_resolution_clock::now(); // Reset the start time

            } 
            */
            //std::this_thread::sleep_for(std::chrono::seconds(5));
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            auto processes = monitor.getProcesses();
            cliente.manejarProcesso(processes);  // Envía el mensaje al servidor
        }

        cliente.desconectar();  // Desconecta del servidor
    } else {
        std::cerr << "Modo desconocido: " << modo << "\n";
        return 1;
    }

    return 0;
}
