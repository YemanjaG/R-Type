//
// Created by Gabriel de Taxis on 24/09/2022.
//

#ifndef R_TYPE_TCP_CONNECTION_H
#define R_TYPE_TCP_CONNECTION_H

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>


using boost::asio::ip::tcp;
using boost::asio::ip::udp;


class tcp_connection: public boost::enable_shared_from_this<tcp_connection>
{
public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    static pointer create(boost::asio::io_context& io_context)
    {
        return pointer(new tcp_connection(io_context));
    }
    tcp::socket& socket();
    void start();

private:
    tcp_connection(boost::asio::io_context& io_context)
            : socket_(io_context)
    {
    }

    void handle_write();

    tcp::socket socket_;
    std::string message_;
};


#endif //R_TYPE_TCP_CONNECTION_H
