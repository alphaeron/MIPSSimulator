#ifndef __MIPSSIMULATOR_PROCESSOR_CLOCK_HPP_
#define __MIPSSIMULATOR_PROCESSOR_CLOCK_HPP_

#include <processor/processor.hpp>

class Clock
{
public:
	// CONSTRUCTORS

	/**
	 * @brief Default constructor (does nothing).
	 *
	 * @param[in]
	 */
	Clock (MIPSProcessor& processor);

	// DESTRUCTORS

	/**
	 * @brief Destructor.
	 */
	~Clock ();

	// FUNCTIONS

	/**
	 * @brief Tick the clock.
	 *
	 * This simulates the clock advancing one cycle further.
	 */
	void
	tick ();

private:
	// VARIABLES

	/** The processor that this <code>Clock</code> is assosiated with. */
	MIPSProcessor& m_processor;
};

#endif //  __MIPSSIMULATOR_PROCESSOR_CLOCK_HPP_
