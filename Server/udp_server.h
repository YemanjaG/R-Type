//
// Created by Gabriel de Taxis on 24/09/2022.
//

#ifndef R_TYPE_UDP_SERVER_H
#define R_TYPE_UDP_SERVER_H

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class udp_server
{
public:
    udp_server(boost::asio::io_context& io_context)
            : socket_(io_context, udp::endpoint(udp::v4(), 13))
    {
        start_receive();
    }

private:
    void start_receive();
    void handle_receive(const boost::system::error_code& error);
    void handle_send(boost::shared_ptr<std::string> /*message*/);

    udp::socket socket_;
    udp::endpoint remote_endpoint_;
    boost::array<char, 1> recv_buffer_;
};


#endif //R_TYPE_UDP_SERVER_H
