#include <os/os.hpp>

inline
OS::OS (Clock& clock, MIPSProcessor& processor, Memory& memory)
	: m_clock (clock), m_processor (processor), m_memory (memory)
{
}

inline
OS::~OS ()
{ }

void
OS::execute ()
{
}

void
OS::vm_fifo ()
{
}

void
OS::vm_lru ()
{
}

void
OS::vm_random ()
{
}
