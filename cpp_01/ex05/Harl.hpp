
#include <string>
#include <iostream>

class Harl
{
	public:
		void complain( std::string level );

	private:
		void debug( void );//const...
		void info( void );
		void warning( void );
		void error( void );
};
