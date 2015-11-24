#include <algorithm>
#include <iterator>
#include <sstream>
#include <tuple>

#include <os/os.hpp>
#include <processor/processor.hpp>

MIPSProcessor::MIPSProcessor (Memory& memory, RegisterFile<unsigned>& register_file)
	: m_memory (memory), m_register_file (register_file),	m_processor_state (-1)
{
	using std::placeholders::_1;
	using std::placeholders::_2;
	using std::placeholders::_3;

	// Initalize m_operations.

	// m_operations["add"] = std::bind (&MIPSProcessor::mips_add, this, _1, _2,
	// 																 _3);
	// m_operations["addi"] = std::bind (&MIPSProcessor::mips_addi, this, _1, _2,
	// 																 _3);
	// m_operations["addiu"] = std::bind (&MIPSProcessor::mips_addiu, this, _1, _2,
	// 																 _3);
	// m_operations["addu"] = std::bind (&MIPSProcessor::mips_addu, this, _1, _2,
	// 																 _3);
	// m_operations["beq"] = std::bind (&MIPSProcessor::mips_beq, this, _1, _2,
	// 																 _3);
	// m_operations["j"] = std::bind (&MIPSProcessor::mips_j, this, _1, 0, 0);
	// m_operations["jal"] = std::bind (&MIPSProcessor::mips_jal, this, _1, 0, 0);
	// m_operations["jr"] = std::bind (&MIPSProcessor::mips_jr, this, _1, 0, 0);
	// m_operations["lui"] = std::bind (&MIPSProcessor::mips_lui, this, _1, _2,
	// 																 _3);
	// m_operations["lw"] = std::bind (&MIPSProcessor::mips_lw, this, _1, _2, _3);
	// m_operations["mfhi"] = std::bind (&MIPSProcessor::mips_mfhi, this, _1, 0,
	// 																	0);
	// m_operations["mflo"] = std::bind (&MIPSProcessor::mips_mflo, this, _1, 0,
	// 																	0);
	// m_operations["mult"] = std::bind (&MIPSProcessor::mips_mult, this, _1, _2,
	// 																	0);
	// m_operations["ori"] = std::bind (&MIPSProcessor::mips_ori, this, _1, _2,
	// 																 _3);
	// m_operations["sll"] = std::bind (&MIPSProcessor::mips_sll, this, _1, _2,
	// 																 _3);
	// m_operations["slt"] = std::bind (&MIPSProcessor::mips_slt, this, _1, _2,
	// 																 _3);
	// m_operations["slti"] = std::bind (&MIPSProcessor::mips_slti, this, _1, _2,
	// 																 _3);
	// m_operations["sub"] = std::bind (&MIPSProcessor::mips_sub, this, _1, _2,
	// 																 _3);
	// m_operations["subu"] = std::bind (&MIPSProcessor::mips_subu, this, _1, _2,
	// 																 _3);
	// m_operations["sw"] = std::bind (&MIPSProcessor::mips_sw, this, _1, _2, _3);
	// m_operations["syscall"] = std::bind (&MIPSProcessor::mips_syscall, this, 0,
	// 																		 0, 0);

	// m_state_functions[0] = std::bind (&MIPSProcessor::mips_if, this);
	// m_state_functions[1] = std::bind (&MIPSProcessor::mips_id, this);
	// m_state_functions[2] = std::bind (&MIPSProcessor::mips_ex, this);
	// m_state_functions[3] = std::bind (&MIPSProcessor::mips_mem, this);
	// m_state_functions[4] = std::bind (&MIPSProcessor::mips_wb, this);

	// Initalize m_syscalls.

	// // Print integer.
	// m_syscalls[1] = ;
	// // Print float.
	// m_syscalls[2] = ;
	// // Print double.
	// m_syscalls[3] = ;
	// // Print string.
	// m_syscalls[4] = ;
	// // Read integer.
	// m_syscalls[5] = ;
	// // Read float.
	// m_syscalls[6] = ;
	// // Read double.
	// m_syscalls[7] = ;
	// // Read string.
	// m_syscalls[8] = ;
	// // sbrk (allocate memory buffer).
	// m_syscalls[9] = ;
	// Exit.
	// m_syscalls[10] = std::bind (&MIPSProcessor::mips_syscall_exit, this);
}

MIPSProcessor::~MIPSProcessor ()
{ }

// Public interface (things a processor can do).

void
MIPSProcessor::tick ()
{
	// Update the processor state.
	m_processor_state = (m_processor_state + 1) % 5;
	// Perform whatever function we do at that state.
	if (m_processor_state == 0)
		{
			mips_if ();
		}
	if (m_processor_state == 1)
		{
			mips_id ();
		}
	if (m_processor_state == 2)
		{
			mips_ex ();
		}
	if (m_processor_state == 3)
		{
			mips_mem ();
		}
	if (m_processor_state == 4)
		{
			mips_wb ();
		}
	// m_state_functions[m_processor_state]();
}

// Functions at the processor's different states.

void
MIPSProcessor::mips_if ()
{
	// Get the instruction to execute (at $pc).
	// $pc will be "mux"ed at the end of the ex stage.
	ifid_reg = m_memory[m_register_file.m_registers[REG_PC]];
	if (ifid_reg == "")
		{
			exit (0);
		}
}

void
MIPSProcessor::mips_id ()
{
	// Decode ifid_reg
	std::string command = ifid_reg;
	std::replace (command.begin (), command.end (), ',', ' ');
	std::stringstream ss (command);
	std::istream_iterator <std::string> begin (ss);
	std::istream_iterator <std::string> end;
	std::vector <std::string> command_parts (begin, end);
	std::copy (command_parts.begin (), command_parts.end (),
						 std::back_inserter (cpts));
}

void
MIPSProcessor::mips_ex ()
{
	// std::vector <Register<unsigned> > regs;
	// std::function <void()> cmd = m_operations[cpts[0]];

	// Based on instruction class, do the operation.

	if (is_three_regs ())
		{
			if (cpts[0] == "add")
				{
					mips_add (m_register_file[std::stoi (cpts[1])],
										m_register_file[std::stoi (cpts[2])],
										m_register_file[std::stoi (cpts[3])]);;
				}
			if (cpts[0] == "addu")
					mips_addu (m_register_file[std::stoi (cpts[1])],
										 m_register_file[std::stoi (cpts[2])],
										 m_register_file[std::stoi (cpts[3])]);;
				{
				}
			if (cpts[0] == "sub")
				{
					mips_sub (m_register_file[std::stoi (cpts[1])],
										m_register_file[std::stoi (cpts[2])],
										m_register_file[std::stoi (cpts[3])]);;
				}
			if (cpts[0] == "subu")
				{
					mips_subu (m_register_file[std::stoi (cpts[1])],
										 m_register_file[std::stoi (cpts[2])],
										 m_register_file[std::stoi (cpts[3])]);;
				}
			if (cpts[0] == "slt")
				{
					mips_slt (m_register_file[std::stoi (cpts[1])],
										m_register_file[std::stoi (cpts[2])],
										m_register_file[std::stoi (cpts[3])]);;
				}
			// m_operations[cpts[0]](m_register_file[std::stoi (cpts[1])],
			// 											m_register_file[std::stoi (cpts[2])],
			// 											m_register_file[std::stoi (cpts[3])]);
		}
	if (is_two_regs_i ())
		{
			// If we have a lw or sw.
			if (cpts[0] == "lui")
				{
					unsigned offset;
					unsigned reg_number;
					int offset_end_index = cpts[2].find ("(");
					int end_index = cpts[2].find (")");
					offset = std::stoi (cpts[2].substr (0, offset_end_index));
					reg_number = std::stoi (cpts[2].substr (offset_end_index + 2, end_index - offset_end_index + 1));
					int first = std::stoi (cpts[1].substr(1, cpts[1].length () - 1));
					mips_lui(m_register_file[first],
									 m_register_file[reg_number], offset);
					// m_operations[cpts[0]](m_register_file[std::stoi (cpts[1])],
					// 											rt, offset);
				}
			if (cpts[0] == "lw")
				{
					unsigned offset;
					unsigned reg_number;
					int offset_end_index = cpts[2].find ("(");
					int end_index = cpts[2].find (")");
					offset = std::stoi (cpts[2].substr (0, offset_end_index));
					reg_number = std::stoi (cpts[2].substr (offset_end_index + 2, end_index - offset_end_index + 1));
					int first = std::stoi (cpts[1].substr(1, cpts[1].length () - 1));
					mips_lw(m_register_file[first],
									m_register_file[reg_number], offset);
					// m_operations[cpts[0]](m_register_file[std::stoi (cpts[1])],
					// 											rt, offset);
				}
			else if (cpts[0] == "sw")
				{
					unsigned offset;
					unsigned reg_number;
					int offset_end_index = cpts[2].find ("(");
					int end_index = cpts[2].find (")");
					offset = std::stoi (cpts[2].substr (0, offset_end_index));
					reg_number = std::stoi (cpts[2].substr (offset_end_index + 2, end_index - offset_end_index + 1));
					int first = std::stoi (cpts[1].substr(1, cpts[1].length () - 1));
					mips_sw(m_register_file[first],
									m_register_file[reg_number], offset);
					// m_operations[cpts[0]](m_register_file[std::stoi (cpts[1])],
					// 											rt, offset);
				}
			else
				{
					if (cpts[0] == "addiu")
						{
							mips_addiu(m_register_file[std::stoi (cpts[1])],
												 m_register_file[std::stoi (cpts[2])],
												 std::stoi (cpts[3]));
						}
					if (cpts[0] == "beq")
						{
							mips_beq(m_register_file[std::stoi (cpts[1])],
											 m_register_file[std::stoi (cpts[2])],
											 std::stoi (cpts[3]));
						}
					if (cpts[0] == "ori")
						{
							mips_ori(m_register_file[std::stoi (cpts[1])],
											 m_register_file[std::stoi (cpts[2])],
											 std::stoi (cpts[3]));
						}
					if (cpts[0] == "sll")
						{
							mips_sll(m_register_file[std::stoi (cpts[1])],
											 m_register_file[std::stoi (cpts[2])],
											 std::stoi (cpts[3]));
						}
					if (cpts[0] == "slti")
						{
							mips_slti(m_register_file[std::stoi (cpts[1])],
												m_register_file[std::stoi (cpts[2])],
												std::stoi (cpts[3]));
						}
					// m_operations[cpts[0]](m_register_file[std::stoi (cpts[1])],
					// 											m_register_file[std::stoi (cpts[2])],
					// 											std::stoi (cpts[3]));
				}
		}
	if (is_two_args ())
		{
			mips_mult(m_register_file[std::stoi (cpts[1])],
								m_register_file[std::stoi (cpts[2])]);
			// m_operations[cpts[0]](m_register_file[std::stoi (cpts[1])],
			// 											m_register_file[std::stoi (cpts[2])]);
		}
	if (is_one_reg ())
		{
			if (cpts[0] == "jr")
				{
					mips_jr (m_register_file[std::stoi (cpts[1])]);
				}
			if (cpts[0] == "mfhi")
				{
					mips_jr (m_register_file[std::stoi (cpts[1])]);
				}
			if (cpts[0] == "mflo")
				{
					mips_jr (m_register_file[std::stoi (cpts[1])]);
				}
			// m_operations[cpts[0]](m_register_file[std::stoi (cpts[1])]);
		}
	if (is_one_i ())
		{
			if (cpts[0] == "j")
				{
					mips_j (m_register_file[std::stoi (cpts[1])]);
				}
			if (cpts[0] == "jal")
				{
					mips_jal (m_register_file[std::stoi (cpts[1])]);
				}
			// m_operations[cpts[0]](std::stoi (cpts[1]));
		}
	if (is_syscall ())
		{
			mips_syscall ();
			// m_operations["syscall"]();
		}
}

void
MIPSProcessor::mips_mem ()
{
	// Only update program counter if we didn't branch.
	if (cpts[0] == "beq")
		{
			unsigned i;
			std::stringstream ss;
			std::string line = m_memory[m_register_file.m_registers[REG_PC]];
			ss << std::hex << line.substr (2, line.length () - 2);
			ss >> i;
			/// @todo Implement operator+=
			m_memory[m_register_file.m_registers[REG_PC]] = i + 4;
		}
	else
		{
			m_register_file.m_registers[REG_PC] = m_register_file.m_registers[REG_PC] + 4;
		}
}

void
MIPSProcessor::mips_wb ()
{
	// Nothing to do because of the way we are simulating int.
}

// Operation implementations.

void
MIPSProcessor::mips_add (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt)
{
	rd = rs + rt;
}

void
MIPSProcessor::mips_addi (Register<unsigned>& rd, Register<unsigned>& rs, int immediate)
{
	rd = rs + immediate;
}

void
MIPSProcessor::mips_addiu (Register<unsigned>& rd, Register<unsigned>& rs,
													 unsigned immediate)
{
	/// @todo Is this enough for unsigned add immediate?
	rd = rs + immediate;
}

void
MIPSProcessor::mips_addu (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt)
{
	/// @todo Is this enough for unsigned add?
	rd = rs + rt;
}

void
MIPSProcessor::mips_beq (Register<unsigned>& rs, Register<unsigned>& rt,
												 unsigned branch_address)
{
	if (rs == rt)
		{
			m_register_file.m_registers[REG_PC] = branch_address;
		}
}

void
MIPSProcessor::mips_j (unsigned jump_address)//, boost::any a1, boost::any a2)
{
	m_register_file.m_registers[REG_PC] = jump_address;
}

void
MIPSProcessor::mips_jal (unsigned jump_address)//, boost::any a1, boost::any a2)
{
	m_register_file[31] = m_register_file.m_registers[REG_PC];
	m_register_file.m_registers[REG_PC] = jump_address;
}

void
MIPSProcessor::mips_jr (Register<unsigned>& rs)//, boost::any a1, boost::any a2)
{
	m_register_file.m_registers[REG_PC] = rs;
}

void
MIPSProcessor::mips_lui (Register<unsigned>& rt, Register<unsigned>& rs, unsigned immediate)
{
	rt = rs << 16;
}

void
MIPSProcessor::mips_lw (Register<unsigned>& rt, Register<unsigned>& rs, int offset)
{
	unsigned i;
	std::stringstream ss;
	std::string line = m_memory[rs + offset];
	ss << std::hex << line.substr (2, line.length () - 2);
	ss >> i;
	rt = i;
	//rt = boost::any_cast<unsigned>(m_memory[boost::any_cast<unsigned>(rs) + offset]);
}

void
MIPSProcessor::mips_mfhi (Register<unsigned>& rd)//, boost::any a1, boost::any a2)
{
	rd = m_register_file[REG_HI];
}

void
MIPSProcessor::mips_mflo (Register<unsigned>& rd)//, boost::any a1, boost::any a2)
{
	rd = m_register_file[REG_LO];
}

void
MIPSProcessor::mips_mult (Register<unsigned>& rs, Register<unsigned>& rt)//, boost::any a1)
{
	std::tie (m_register_file[REG_HI], m_register_file[REG_LO]) = rs * rt;
}

void
MIPSProcessor::mips_ori (Register<unsigned>& rd, Register<unsigned>& rs, unsigned immediate)
{
	rd = rs | immediate;
}

void
MIPSProcessor::mips_sll (Register<unsigned>& rd, Register<unsigned>& rs, unsigned shamt)
{
	rd = rs << shamt;
}

void
MIPSProcessor::mips_slt (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt)
{
	rd = (rs < rt) ? 1 : 0;
}

void
MIPSProcessor::mips_slti (Register<unsigned>& rd, Register<unsigned>& rs, int immediate)
{
	rd = (rs < immediate) ? 1 : 0;
}

void
MIPSProcessor::mips_sub (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt)
{
	rd = rs - rt;
}

void
MIPSProcessor::mips_subu (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt)
{
	/// @todo Is this enough for unsigned subtract?
	rd = rs - rt;
}

void
MIPSProcessor::mips_sw (Register<unsigned>& rt, Register<unsigned>& rs, int offset)
{
	std::stringstream ss;
	ss << std::hex << rt;
	std::string hex_string ("0x" + ss.str ());
	m_memory[rs + offset] = hex_string;
}

void
MIPSProcessor::mips_syscall ()//boost::any a1, boost::any a2, boost::any a3)
{
	mips_syscall_exit ();
	// m_syscall_table[m_register_file[2]]();
}

void
MIPSProcessor::mips_syscall_exit ()
{
	os->exit_application ();
}

bool
MIPSProcessor::is_three_regs ()
{
	if (cpts[0] == "add"
			|| cpts[0] == "addu"
			|| cpts[0] == "sub"
			|| cpts[0] == "subu"
			|| cpts[0] == "slt")
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool
MIPSProcessor::is_two_regs_i ()
{
	if (cpts[0] == "addi"
			|| cpts[0] == "addiu"
			|| cpts[0] == "beq"
			|| cpts[0] == "lui"
			|| cpts[0] == "lw"
			|| cpts[0] == "ori"
			|| cpts[0] == "sll"
			|| cpts[0] == "slti"
			|| cpts[0] == "sw")
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool
MIPSProcessor::is_two_args ()
{
	if (cpts[0] == "mult")
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool
MIPSProcessor::is_one_reg ()
{
	if (cpts[0] == "jr"
			|| cpts[0] == "mfhi"
			|| cpts[0] == "mflo")
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool
MIPSProcessor::is_one_i ()
{
	if (cpts[0] == "j"
			|| cpts[0] == "jal")
		{
			return true;
		}
	else
		{
			return false;
		}
}

bool
MIPSProcessor::is_syscall ()
{
	if (cpts[0] == "syscall")
		{
			return true;
		}
	else
		{
			return false;
		}
}
