#ifndef __MIPSSIMULATOR_PROCESSOR_REGISTERFILE_HPP_
#define __MIPSSIMULATOR_PROCESSOR_REGISTERFILE_HPP_

#include <boost/any.hpp>

#include <processor/register/register.hpp>

// Defines for special registers.

/** The high bits of mult/div. */
#define REG_HI 32
/** The low bits of mult/div. */
#define REG_LO 33
/** The program counter. */
#define REG_PC 34

#define N_REGISTERS (REG_PC)

template <typename DataT = boost::any>
class RegisterFile
{
public:
	// CONSTRUCTORS

	/**
	 * @brief Default constructor (does nothing).
	 */
	RegisterFile ();

	// DESTRUCTOR

	/**
	 * @brief Destructor.
	 */
	~RegisterFile ();

	// OPERATORS

	/**
	 * @brief
	 */
	Register<DataT>&
	operator[] (boost::any reg) const;

	/**
	 * @brief
	 */
	Register<DataT>&
	operator[] (boost::any reg);

// private:
	// VARIABLES

	/// @todo This should be private?
	/** The registers in this register file. */
	Register<DataT> m_registers[N_REGISTERS];
};

#endif // __MIPSSIMULATOR_PROCESSOR_REGISTERFILE_HPP_
