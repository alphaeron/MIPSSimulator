#include <processor/register/register_file.hpp>

template <typename DataT>
inline
RegisterFile<DataT>::RegisterFile ()
{ }

template <typename DataT>
inline
RegisterFile<DataT>::~RegisterFile ()
{ }

template <typename DataT>
Register<DataT>&
RegisterFile<DataT>::operator[] (unsigned reg)
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

// template <typename DataT>
// Register<DataT>&
// RegisterFile<DataT>::operator[] (unsigned reg)
// {
// 	if (reg < 0 || reg > 31)
// 		{
// 			/// @todo If reg is not in [0, 31], throw an exception.
// 		}
// 	else
// 		{
// 			return m_registers[reg];
// 		}
// }
