#include <boost/asio.hpp>

#include "chess.hpp"

int main()
{
	boost::asio::io_service io_service{};
	boost::asio::ip::tcp::socket socket{io_service};


	io_service.run();
}
