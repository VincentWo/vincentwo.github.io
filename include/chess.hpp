namespace chess
{
	class player
	{
		public:
			enum class color : std::uint8_t;

			player(color);

			enum class color : std::uint8_t
			{
				black = 'B',
				white = 'W'
			};

		private:
	};
}
