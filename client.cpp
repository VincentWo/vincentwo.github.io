#include <iostream>

#include <boost/asio.hpp>

#include "chess.hpp"

namespace asio = boost::asio;
using asio::ip::tcp;

int main()
{
	asio::io_service io_service{};
	tcp::socket socket{io_service};

	asio::connect(socket, tcp::resolver{io_service}.resolve({"localhost", "3000"}));

	chess::player buffer;
	asio::read(socket, asio::buffer(&buffer, sizeof(buffer)));

	std::cout
		<< "You are the "
		<< (buffer == chess::player::black ? "black" : "white")
		<< " player\n";
}
