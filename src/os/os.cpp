#include <os/os.hpp>

inline
OS::OS (MIPSProcessor& processor, Memory& memory)
	: m_processor (processor), m_memory (memory)
{
}

inline
OS::~OS ()
{ }

void
OS::execute ()
{
	while (true)
		{
			// This handles everything that should occur...
			m_processor.tick ();
		}
}

void
OS::exit_application ()
{
	exit (0);
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
