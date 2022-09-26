//
// Created by Gabriel de Taxis on 24/09/2022.
//

#include "udp_server.h"
#include "Utils.h"

void udp_server::start_receive()
{
    socket_.async_receive_from(
            boost::asio::buffer(recv_buffer_), remote_endpoint_,
            boost::bind(&udp_server::handle_receive, this,
                        boost::asio::placeholders::error));
}

void udp_server::handle_receive(const boost::system::error_code& error)
{
    if (!error)
    {
        boost::shared_ptr<std::string> message(
                new std::string(make_daytime_string()));

        socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
                              boost::bind(&udp_server::handle_send, this, message));

        start_receive();
    }
}

void udp_server::handle_send(boost::shared_ptr<std::string> /*message*/)
{
}