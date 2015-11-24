#include <fstream>
#include <sstream>
#include <iostream>
#include <os/os.hpp>

inline
OS::OS (MIPSProcessor& processor, Memory& memory, std::string program,
				std::string data_dir)
	: m_processor (processor), m_memory (memory)
{
	// Read in the program's asm and addr files, and put them in memory.
	std::ifstream asm_file (data_dir + "/" + program + ".asm");
	std::ifstream addrs_file (data_dir + "/" + program + ".addrs");
	std::string asm_line;
	std::string addrs_line;

	// Need first pc...
	int cnt = 0;
	unsigned first_pc = -1;
	while (std::getline (asm_file, asm_line) && std::getline (addrs_file, addrs_line))
		{
			unsigned i;
			std::stringstream ss;
			ss << std::hex << addrs_line.substr (2, addrs_line.length () - 2);
			ss >> i;
			if (cnt == 0)
				{
					first_pc = i;
				}
			cnt++;
			// if (i < first_pc || first_pc < 0)
			// 	{
			// 		first_pc = i;
			// 	}
			m_memory[i] = asm_line;
			// try
			// 	{
			// 		boost::any_cast<std::string>(&m_memory[i]);
			// 		std::cout << *boost::any_cast<std::string>(&m_memory[i]) << std::endl;
			// 	}
			// catch (const boost::bad_any_cast &)
			// 	{
			// 		std::cout << "NO!!!!!" << std::endl;
			// 	}
		}
	m_processor.m_register_file.m_registers[REG_PC] = first_pc;
}

inline
OS::~OS ()
{ }

void
OS::execute ()
{
	while (true)
		{
			// This handles everything that should occur...
			m_processor.tick ();
		}
}

std::string
OS::get_memory (unsigned address)
{
	return m_memory[address];
}

void
OS::set_memory (unsigned address, std::string value)
{
	m_memory[address] = value;
}

void
OS::exit_application ()
{
	exit (0);
}

void
OS::vm_fifo ()
{
}

void
OS::vm_lru ()
{
}

void
OS::vm_random ()
{
}
