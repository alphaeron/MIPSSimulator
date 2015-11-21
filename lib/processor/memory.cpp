#include <processor/memory.hpp>

Memory::Memory (size_t mem_size)
	: m_size (mem_size)
{
	data = new unsigned[mem_size];
}

Memory::~Memory ()
{
	delete [] data;
}

unsigned
Memory::operator[] (unsigned address)
{
	/// @todo Bounds checking and raise exception if outsize bounds.
	return data[address];
}

unsigned&
Memory::operator[] (unsigned address)
{
	/// @todo Bounds checking and raise exception if outsize bounds.
	return data[address];
}
