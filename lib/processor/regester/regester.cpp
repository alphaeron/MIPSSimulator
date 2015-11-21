#include <processor/regester/regester.hpp>

inline
Register::Register ()
{ }

inline
Register::Register (unsigned data)
	: m_data (data)
{ }

inline
Register::~Register ()
{ }

inline
Register::operator unsigned ()
{
	return m_data;
}

Register&
Register::operator= (const Register& rhs)
{
	if (this != &rhs)
		{
			m_data = rhs.m_data;
		}
	return *this;
}

Register&
Register::operator= (unsigned data)
{
	m_data = data;
	return *this;
}

inline unsigned
Register::operator+ (const Register& r1, const Register& r2)
{
	return r1.m_data + r2.m_data;
}

inline unsigned
Register::operator| (const Register& r1, const Register& r2)
{
	return r1.m_data | r2.m_data;
}

inline unsigned
Register::operator- (const Register& r1, const Register& r2)
{
	return r1.m_data - r2.m_data;
}

inline std::tuple<unsigned, unsigned>
Register::operator* (const Register& r1, const Register& r2)
{
	unsigned d = r1.m_data * r2.m_data;
	std::tuple<unsigned, unsigned> tup (d >> 16, d << 16);
}

inline bool
Register::operator< (const Register& r1, const Register& r2)
{
	return r1.m_data < r2.m_data;
}
