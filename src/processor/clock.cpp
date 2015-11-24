#include <processor/clock.hpp>

inline
Clock::Clock (MIPSProcessor& processor)
	: m_processor (processor)
{ }

inline
Clock::~Clock ()
{ }

void
Clock::tick ()
{
	m_processor.tick ();
}
