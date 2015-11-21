#include <processor/regester/regester_file.hpp>

inline
RegisterFile::RegisterFile ()
{ }

Register&
RegisterFile::operator[] (unsigned reg)
{
	if (reg < 0 || reg > 31)
		{
			/// @todo If reg is not in [0, 31], throw an exception.
		}
	else
		{
			return m_registers[reg];
		}
}

Register&
RegisterFile::operator[] (unsigned reg)
{
	if (reg < 0 || reg > 31)
		{
			/// @todo If reg is not in [0, 31], throw an exception.
		}
	else
		{
			return m_registers[reg];
		}
}
