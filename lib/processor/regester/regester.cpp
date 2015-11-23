#include <processor/regester/regester.hpp>

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

template <typename DataT>
Register<DataT>&
Register<DataT>::operator= (const Register& rhs)
{
	if (this != &rhs)
		{
			m_data = rhs.m_data;
		}
	return *this;
}

template <typename DataT>
Register<DataT>&
Register<DataT>::operator= (DataT data)
{
	m_data = data;
	return *this;
}

template <typename DataT>
inline DataT
Register<DataT>::operator+ (const Register& r1, const Register& r2)
{
	return r1.m_data + r2.m_data;
}

template <typename DataT>
inline DataT
Register<DataT>::operator| (const Register& r1, const Register& r2)
{
	return r1.m_data | r2.m_data;
}

template <typename DataT>
inline DataT
Register<DataT>::operator- (const Register& r1, const Register& r2)
{
	return r1.m_data - r2.m_data;
}

template <typename DataT>
inline std::tuple<DataT, DataT>
Register<DataT>::operator* (const Register& r1, const Register& r2)
{
	DataT d = r1.m_data * r2.m_data;
	std::tuple<DataT, DataT> tup (d >> 16, d << 16);
}

template <typename DataT>
inline bool
Register<DataT>::operator< (const Register& r1, const Register& r2)
{
	return r1.m_data < r2.m_data;
}
