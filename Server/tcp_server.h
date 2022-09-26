//
// Created by Gabriel de Taxis on 24/09/2022.
//

#ifndef R_TYPE_TCP_SERVER_H
#define R_TYPE_TCP_SERVER_H

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

#include "tcp_connection.h"

using boost::asio::ip::tcp;

class tcp_server
{
public:
    tcp_server(boost::asio::io_context& io_context)
            : io_context_(io_context),
              acceptor_(io_context, tcp::endpoint(tcp::v4(), 13))
    {
        start_accept();
    }

private:
    void start_accept();
    void handle_accept(tcp_connection::pointer new_connection, const boost::system::error_code& error);

    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
};


#endif //R_TYPE_TCP_SERVER_H
