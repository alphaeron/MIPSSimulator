#include <os/os.hpp>

inline
OS::OS (Clock& clock, MIPSProcessor& processor, Memory& memory)
	: m_clock (clock), m_processor (processor), m_memory (memory)
{ }

inline
OS::~OS ()
{ }
