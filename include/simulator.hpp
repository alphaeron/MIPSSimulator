#ifndef __MIPSSIMULATOR_SIMULATOR_HPP_
#define __MIPSSIMULATOR_SIMULATOR_HPP_

#include <string>

class Simulator
{
public:
	// CONSTRUCTORS

	/**
	 * @param[in] num_processes          The number of processes that are
	 *                                   supported.
	 * @param[in] instruction_time_slice The number of instructions one process
	 *                                   can execute at once.
	 * @param[in] vm_algorithm           The virtual memory algorithm to use in
	 *                                   this <code>OS</code>.
	 * @param[in] virtual_address_bits   The number of bits in a virtual memory
	 *                                   address (in bits).
	 * @param[in] page_size              The size of a page (in bytes).
	 * @param[in] memory_size            The size of the "physical" memory (in
	 *                                   GiB).
	 * @param[in] program                The name of the program to execute.
	 * @param[in] data_dir               The directory the program is stored in.
	 */
	Simulator (int num_processes, int instruction_time_slice,
						 std::string vm_algorithm, int virtual_address_bits, int page_size,
						 int memory_size, std::string program, std::string data_dir);

	// DESTRUCTORS

	/**
	 * @brief Destructor.
	 */
	~Simulator ();

	// FUNCTIONS

	/**
	 * @brief Execute the simulation.
	 */
	void
	simulate ();

private:
	// VARIABLES

	/** The number of processes to use in this simulation. */
	int m_num_processes;
	/** The number of instructions one process can execute at once. */
	int m_instruction_time_slice;
	/** The virtual memory algorithm. */
	std::string m_vm_algorithm;
	/** The number of bits in a virtual memory address. */
	int m_virtual_address_bits;
	/** The size of a page. */
	int m_page_size;
	/** The size of "physical" memory. */
	int m_memory_size;
	/** The name of the program to execute. */
	std::string m_program;
	/** The directory the program is stored in. */
	std::string m_data_dir;
};

#endif // __MIPSSIMULATOR_SIMULATOR_HPP_
