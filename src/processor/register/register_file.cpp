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
RegisterFile<DataT>::operator[] (boost::any reg)
{
	DataT reg_ = boost::any_cast<DataT> (reg);
	if (reg_ < 0 || reg_ > 31)
		{
			/// @todo If reg_ is not in [0, 31], throw an exception.
		}
	else
		{
			return m_registers[reg_];
		}
}

// template <typename DataT>
// Register<DataT>&
// RegisterFile<DataT>::operator[] (boost::any reg)
// {
// 	DataT reg_ = boost::any_cast<DataT> (reg);
// 	if (reg_ < 0 || reg_ > 31)
// 		{
// 			/// @todo If reg_ is not in [0, 31], throw an exception.
// 		}
// 	else
// 		{
// 			return m_registers[reg_];
// 		}
// }
