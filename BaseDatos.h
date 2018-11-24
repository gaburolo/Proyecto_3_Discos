//
// Create by oldboy 24/11/18
//
#ifndef TECFS_DISK_DATABASEHANDLER_H
#define TECFS_DISK_DATABASEHANDLER_H


#include <SFML/Network/Socket.hpp>
#include <SFML/Network/Packet.hpp>
#include <fstream>
#include "BaseDatos.h"

class DataBaseHandler {
public:
    static void createFile(std::string content);

    static std::string getData();
};


#endif //TECFS_DISK_DATABASEHANDLER_H
