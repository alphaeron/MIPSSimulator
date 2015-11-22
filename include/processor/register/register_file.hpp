#ifndef __MIPSSIMULATOR_PROCESSOR_REGISTERFILE_HPP_
#define __MIPSSIMULATOR_PROCESSOR_REGISTERFILE_HPP_

#include <processor/register/register.hpp>>

// Defines for special registers.

/** The high bits of mult/div. */
#define REG_HI 32
/** The low bits of mult/div. */
#define REG_LO 33
/** The program counter. */
#define REG_PC 34

#define N_REGISTERS (REG_PC)

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
	Register&
	operator[] (unsigned reg) const;

	/**
	 * @brief
	 */
	Register&
	operator[] (unsigned reg);

private:
	// VARIABLES

	/** The registers in this register file. */
	Register m_registers[N_REGISTERS];
};

#endif // __MIPSSIMULATOR_PROCESSOR_REGISTERFILE_HPP_
