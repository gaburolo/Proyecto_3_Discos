//
// Create by oldboy 24/11/18
//
#ifndef TECFS_DISK_SINGLETON_H
#define TECFS_DISK_SINGLETON_H


#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>

#include "BaseDatos.h"
#include <sys/stat.h>

class Singleton {
public:
    static std::string data;

    static Singleton* getInstance();

    static sf::TcpSocket* getServer();

    static std::string getDirectory();

    static void createDiskDirectory(int diskNum);

    static void createDiskBlocks(std::string path);

private:
    Singleton();

    static Singleton* instance;

    static sf::TcpSocket* server;

    static std::string directory;
};


#endif //TECFS_DISK_SINGLETON_H
