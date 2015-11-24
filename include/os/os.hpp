#ifndef __MIPSSIMULATOR_OS_OS_HPP_
#define  __MIPSSIMULATOR_OS_OS_HPP_

#include <processor/memory.hpp>
#include <processor/processor.hpp>

class OS
{
public:
	// CONSTRUCTORS

	/**
	 * @brief Construct the OS.
	 *
	 * @param[in] processor The processor this <code>OS</code> is
	 *                                   running on.
	 * @param[in] memory    The memory assosiated with this system.
	 */
	OS (MIPSProcessor& processor, Memory& memory);

	// DESTRUCTORS

	/**
	 * Destructor.
	 */
	~OS ();

	// FUNCTIONS

	/**
	 * @brief Begin execution.
	 */
	void
	execute ();

	/**
	 * @brief Exit application (syscall).
	 */
	void
	exit_application ();

private:
	// FUNCTIONS

	// VM management algorithms

	/**
	 * @brief FIFO management.
	 */
	void
	vm_fifo ();

	/**
	 * @brief LRU management.
	 */
	void
	vm_lru ();

	/**
	 * @brief Random management.
	 */
	void
	vm_random ();

	// VARIABLES

	/** The processor this <code>OS</code> is running on. */
	MIPSProcessor& m_processor;
	/** THe memory for this system. */
	Memory& m_memory;
};

extern OS* os;

#endif //  __MIPSSIMULATOR_OS_OS_HPP_
