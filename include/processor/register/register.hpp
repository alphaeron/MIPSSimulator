#ifndef __MIPSSIMULATOR_PROCESSOR_REGISTER_HPP_
#define __MIPSSIMULATOR_PROCESSOR_REGISTER_HPP_

#include <tuple>

#include <boost/any.hpp>

template <typename DataT = unsigned>
class Register
{
public:
	// CONSTRUCTORS

	/**
	 * @brief Default constructor (does nothing).
	 */
	Register ();

	/**
	 * @brief Copy constructor.
	 *
	 * Copy the contents of one register to this register.
	 *
	 * @param data The data to copy the value of into this register.
	 */
	Register (DataT data);

	// DESTRUCTOR

	/**
	 * @brief Destructor.
	 */
	~Register ();

	// CASTS

	/**
	 * @brief Cast this <code>Register</code> to the type of the stored value.
	 */
	operator DataT ();

	// OPERATORS

	/**
	 * @brief Assign a register to this register.
	 *
	 * @param[in] data The data to copy assign the value of to this register.
	 *
	 * @return *this.
	 */
	DataT
	operator= (DataT data);

	/**
	 * @brief Assign a register to this register.
	 *
	 * @param[in] data The data to copy assign the value of to this register.
	 *
	 * @return *this.
	 */
	DataT
	operator= (boost::any data);

	/**
	 * @brief Test for equality.
	 *
	 * @param[in] data The data to test for equality with.
	 *
	 * @return this == data.
	 */
	bool
	operator== (DataT data);

	// /**
	//  * @brief Test for equality.
	//  *
	//  * @param[in] data The data to test for equality with.
	//  *
	//  * @return this == data.
	//  */
	// bool
	// operator== (const Register<DataT>& data);

	// /**
	//  * @brief Test for equality.
	//  *
	//  * @param[in] data The data to test for equality with.
	//  *
	//  * @return this == data.
	//  */
	// bool
	// operator== (boost::any data);

	/**
	 * @brief Add 2 registers.
	 *
	 * @param[in] r1 The first register.
	 *
	 * @return <code>r1 + r2</code>.
	 */
	//DataT
	//operator+ (boost::any r1) const;

	// /**
	//  * @brief Or 2 registers.
	//  *
	//  * @param[in] r1 The first register.
	//  *
	//  * @return <code>r1 | r2</code>.
	//  */
	// DataT
	// operator| (const Register<DataT>& r1) const;

	// /**
	//  * @brief Subtract 2 registers.
	//  *
	//  * @param[in] r1 The first register.
	//  *
	//  * @return <code>r1 - r2</code>.
	//  */
	// DataT
	// operator- (const Register<DataT>& r1) const;

	/**
	 * @brief Multiply 2 registers.
	 *
	 * @param[in] r1 The first register.
	 *
	 * @return <code>r1 * r2</code>.
	 */
	std::tuple<DataT, DataT>
	operator* (const Register<DataT>& r1);

	// /**
	//  * @brief Test if one register is less than another register.
	//  *
	//  * @param[in] r1 The first register.
	//  *
	//  * @return <code>r1 < r2</code>.
	//  */
	// bool
	// operator< (const Register<DataT>& r1) const;

private:
	// VARIABLES

	/** Store the data for this register as an DataT. */
	DataT m_data;
};

#endif // __MIPSSIMULATOR_PROCESSOR_REGISTER_HPP_
