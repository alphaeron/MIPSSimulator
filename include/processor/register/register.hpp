#ifndef __MIPSSIMULATOR_PROCESSOR_REGISTER_HPP_
#define __MIPSSIMULATOR_PROCESSOR_REGISTER_HPP_

#include <tuple>

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
	Register (unsigned data);

	// DESTRUCTOR

	/**
	 * @brief Destructor.
	 */
	~Register ();

	// CASTS

	/**
	 * @brief Cast this <code>Register</code> to the type of the stored value.
	 */
	operator unsigned () const;

	// OPERATORS

	/**
	 * @brief Assign a register to this register.
	 *
	 * @param[in] data The data to copy assign the value of to this register.
	 *
	 * @return *this.
	 */
	unsigned
	operator= (unsigned data);

	/**
	 * @brief Add 2 registers.
	 *
	 * @param[in] r1 The first register.
	 * @param[in] r2 The second register.
	 *
	 * @return <code>r1 + r2</code>.
	 */
	unsigned
	operator+ (const Register& r1, const Register& r2) const;

	/**
	 * @brief Or 2 registers.
	 *
	 * @param[in] r1 The first register.
	 * @param[in] r2 The second register.
	 *
	 * @return <code>r1 | r2</code>.
	 */
	unsigned
	operator| (const Register& r1, const Register& r2) const;

	/**
	 * @brief Subtract 2 registers.
	 *
	 * @param[in] r1 The first register.
	 * @param[in] r2 The second register.
	 *
	 * @return <code>r1 - r2</code>.
	 */
	unsigned
	operator- (const Register& r1, const Register& r2) const;

	/**
	 * @brief Multiply 2 registers.
	 *
	 * @param[in] r1 The first register.
	 * @param[in] r2 The second register.
	 *
	 * @return <code>r1 * r2</code>.
	 */
	std::tuple<unsigned, unsigned>
	operator* (const Register& r1, const Register& r2) const;

	/**
	 * @brief Test if one register is less than another register.
	 *
	 * @param[in] r1 The first register.
	 * @param[in] r2 The second register.
	 *
	 * @return <code>r1 < r2</code>.
	 */
	bool
	operator< (const Register& r1, const Register& r2) const;

private:
	// VARIABLES

	/** Store the data for this register as an unsigned. */
	unsigned m_data;
};

#endif // __MIPSSIMULATOR_PROCESSOR_REGISTER_HPP_
