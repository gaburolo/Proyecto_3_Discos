//
// Create by oldboy 24/11/18
//
#include "Singleton.h"
#include "LectorXML.h"
#include <iostream>

Singleton* Singleton::instance = nullptr;
sf::TcpSocket* Singleton::server = nullptr;
std::string Singleton::directory = "/home/oldboy/CLionProjects/untitled1/cmake-build-debug/Disk";
std::string Singleton::data = "";

Singleton::Singleton() {

}

/// Metodo para instanciar el unico objeto de la clase Singleton
/// \return
Singleton *Singleton::getInstance() {
    //Se crean las instancias si estan no existian previamente
    if(instance == nullptr){

        instance = new Singleton(); //Se crea la instancia de la clase
        server = new sf::TcpSocket(); //Se crea el servidor

        ///Lectura del XML para obtener la ip del servidor
        std::string XML = "Data.xml";
        sf::IpAddress IP;
        int PORT;
        std::string PATH;
        parse(XML,&IP,&PORT,&PATH);
        directory = PATH;

        server->connect("192.168.8.104",2001);

        //Se le indica al servidor que se trata de un disco
        sf::Packet data;
        data << "Disk";
        server->send(data);
        std::cout<<IP;
    }

    return instance;
}

sf::TcpSocket *Singleton::getServer() {
    if(instance == nullptr){

        getInstance();
    }

    return server;
}

std::string Singleton::getDirectory() {
    return directory;
}

/// Metodo para crear la carpeta donde se van a almacenar los datos del disco
/// \param diskNum
void Singleton::createDiskDirectory(int diskNum) {
    if(instance == nullptr){

        getInstance();

    }
    Singleton::directory = "/home/oldboy/CLionProjects/untitled1/cmake-build-debug/Disk";1;
    Singleton::directory += std::to_string(diskNum);
    std::cout<<Singleton::directory;
    mkdir(directory.c_str(),0777);
}


void Singleton::createDiskBlocks(std::string route) {
    std::string block = route + "/Block";
    for(int i = 1; i <= 30 ; i++) {
        std::string number = std::to_string(i);
        route = block;
        route = route + number;
        //std::cout << route << std::endl;
        if(mkdir(route.c_str(), 0777) == -1)
        {
            mkdir(route.c_str(),0777);
        }
    }

}


