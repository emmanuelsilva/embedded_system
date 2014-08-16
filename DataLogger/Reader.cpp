//
//  Reader.cpp
//  DataLogger
//
//  Created by Emmanuel Silva on 6/15/14.
//  Copyright (c) 2014 Emmanuel Silva. All rights reserved.
//

#include <unistd.h>
#include "Reader.h"
#include "Structure.h"
#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>
#include <boost/tokenizer.hpp>
#include <boost/range/algorithm/count.hpp>

using namespace boost;

asio::io_service io;
asio::serial_port serialport(io);

Reader::Reader(string port) {
    this->port = port;
}

Reader::~Reader() {
    this->closeSerialConnection();
}

void Reader::openSerialConnection() {
    if (!serialport.is_open()) {
        serialport.open(port);
        serialport.set_option(asio::serial_port_base::baud_rate(9600));
        serialport.set_option(asio::serial_port_base::character_size(8));
        serialport.set_option(asio::serial_port_base::parity(asio::serial_port_base::parity::none));
        serialport.set_option(asio::serial_port_base::stop_bits(asio::serial_port_base::stop_bits::one));
        serialport.set_option(asio::serial_port_base::flow_control( asio::serial_port_base::flow_control::none));
    }
}

void Reader::closeSerialConnection() {
    if (serialport.is_open()) {
        serialport.close();
    }
}

string Reader::getPort() {
    return this->port;
}

string Reader::getDataFromArduino() {
    cout << "Lendo dados do arduino" << endl;
    
    char readChar;
    std::string response;
    
    
    while (readChar != '\n') {
        asio::read(serialport, asio::buffer(&readChar,1));
        
        if (readChar != '\r' && readChar != '\n') {
            response += readChar;
        }
    }
    
    cout << "Fim da leitura " << response.size() << endl;
    return response;
}

ReadData Reader::getValue() {
    this->openSerialConnection();
    sleep(1);
    
    bool ok = false;
    string arduinoData = "";
    int retryCount = 0;
    
    //char flagWrite = 'W';
    //char flagPause = 'P';
    
    //asio::write(serialport, asio::buffer(&flagWrite, 1));

    while (!ok) {
        arduinoData = this->getDataFromArduino();
        long commaQuantity = boost::count(arduinoData, ';');
        ok = (commaQuantity == 8L);
        
        retryCount++;
        
        if (retryCount > 10) {
            this->closeSerialConnection();
            this->openSerialConnection();
            sleep(1);
        }
    }
    
    //asio::write(serialport, asio::buffer(&flagPause, 1));
    
    ReadData data;
    data.data = arduinoData;
    
    this->closeSerialConnection();
    
    return data;
}




