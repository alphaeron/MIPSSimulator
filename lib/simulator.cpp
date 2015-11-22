#include <os/os.hpp>
#include <processor/clock.hpp>
#include <processor/memory.hpp>
#include <processor/processor.hpp>
#include <processor/register/register.hpp>
#include <processor/register/register_file.hpp>
#include <simulator.hpp>

// Global OS.
#include <globals.hpp>

OS* os;

inline
Simulator::Simulator (int num_processes, int instruction_time_slice,
											std::string vm_algorithm, int virtual_address_bits,
											int page_size, int memory_size, std::string program,
											std::string data_dir)
	: m_num_processes (num_processes),
		m_instruction_time_slice (instruction_time_slice),
		m_vm_algorithm (vm_algorithm),
		m_virtual_address_bits (virtual_address_bits), m_page_size (page_size),
		m_memory_size (memory_size), m_program (program), m_data_dir (data_dir)
{ }

inline
Simulator::~Simulator ()
{
	delete os;
}

void
simulate ()
{
	// First, build the registers and the register file.
	RegisterFile register_file;

	// Construct main memory.
	Memory memory (m_memory_size);

	// Next build the processor.
	MIPSProcessor processor (memory, register_file);

	// Construct the clock for this system.
	Clock clock (processor);

	// Construct the last required object, the OS.
	os = new OS (clock, processor, memory);

	// Finally, execute.
	os->execute ();
}
