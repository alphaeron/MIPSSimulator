#include <processor/register/register.hpp>

template <typename DataT>
inline
Register<DataT>::Register ()
{ }

template <typename DataT>
inline
Register<DataT>::Register (DataT data)
	: m_data (data)
{ }

template <typename DataT>
inline
Register<DataT>::~Register ()
{ }

template <typename DataT>
inline
Register<DataT>::operator DataT ()
{
	return m_data;
}

// template <typename DataT>
// Register<DataT>&
// Register<DataT>::operator= (const Register& rhs)
// {
// 	if (this != &rhs)
// 		{
// 			m_data = rhs.m_data;
// 		}
// 	return *this;
// }

template <typename DataT>
DataT
Register<DataT>::operator= (DataT data)
{
	m_data = data;
	return m_data;
}

// template <typename DataT>
// DataT
// Register<DataT>::operator= (boost::any data)
// {
// 	m_data = boost::any_cast<DataT>(data);
// 	return m_data;
// }

template <typename DataT>
bool
Register<DataT>::operator== (DataT data)
{
	return m_data == data;
}

// template <typename DataT>
// bool
// operator== (const Register<DataT>& data)
// {
// 	return m_data == data.m_data;
// }

// template <typename DataT>
// Register<DataT>&
// Register<DataT>::operator== (boost::any data)
// {
// 	return m_data == boost::any_cast<DataT>(data);
// }

//template <typename DataT>
//inline DataT
//Register<DataT>::operator+ (boost::any r1)
//{
//	return this->m_data + r1.m_data;
//}

// template <typename DataT>
// inline DataT
// Register<DataT>::operator| (const Register<DataT>& r1)
// {
// 	return this->m_data | r1.m_data;
// }

// template <typename DataT>
// inline DataT
// Register<DataT>::operator- (const Register<DataT>& r1)
// {
// 	return this->m_data - r1.m_data;
// }

template <typename DataT>
inline std::tuple<DataT, DataT>
Register<DataT>::operator* (const Register<DataT>& r1)
{
	DataT d = this->m_data * r1.m_data;
	std::tuple<DataT, DataT> tup (d >> 16, d << 16);
}

// template <typename DataT>
// inline bool
// Register<DataT>::operator< (const Register<DataT>& r1)
// {
// 	return this->m_data < r1.m_data;
// }
