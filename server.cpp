#include <array>
#include <random>
#include <boost/asio.hpp>

#include "chess.hpp"

int main()
{
	using boost::asio::ip::tcp;

	boost::asio::io_service io_service{};
	boost::asio::ip::tcp::socket socket{io_service};

	tcp::acceptor acceptor{io_service, tcp::endpoint{tcp::v4(), 3000}};

	boost::asio::ip::tcp::socket socket_1{io_service};
	boost::asio::ip::tcp::socket socket_2{io_service};

	acceptor.accept(socket_1);
	acceptor.accept(socket_2);

	std::array<chess::player, 2> player
		{
			chess::player{chess::player::color::black, std::move(socket_1)},
			chess::player{chess::player::color::white, std::move(socket_2)}
		};
}
