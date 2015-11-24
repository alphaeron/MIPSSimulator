#include <processor/memory.hpp>

inline
Memory::Memory (size_t mem_size)
	: m_size (mem_size)
{ }

inline
Memory::~Memory ()
{ }

boost::any&
Memory::operator[] (unsigned address)
{
	/// @todo Bounds checking and raise exception if outsize bounds.
	return data[address];
}
