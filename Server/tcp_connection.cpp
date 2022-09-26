//
// Created by Gabriel de Taxis on 24/09/2022.
//

#include "tcp_connection.h"
#include "Utils.h"

//Private
void tcp_connection::handle_write()
{

}

//Public
tcp::socket& tcp_connection::socket()
{
    return socket_;
}

void tcp_connection::start()
{
    message_ = make_daytime_string();

    boost::asio::async_write(socket_, boost::asio::buffer(message_),
                             boost::bind(&tcp_connection::handle_write, shared_from_this()));
}