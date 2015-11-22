#include <tuple>

#include <processor/processor.hpp>

MIPSProcessor::MIPSProcessor (Memory& memory, RegisterFile& register_file)
	: m_memory (memory), m_register_file (register_file),	m_processor_state (-1)
{
	using std::placeholders::_1;
	using std::placeholders::_2;
	using std::placeholders::_3;

	// Initalize m_operations.

	m_operations["add"] = std::bind (&MIPSProcessor::mips_add, *this, _1, _2,
																	 _3);
	m_operations["addi"] = std::bind (&MIPSProcessor::mips_addi, *this, _1, _2,
																	 _3);
	m_operations["addiu"] = std::bind (&MIPSProcessor::mips_addiu, *this, _1, _2,
																	 _3);
	m_operations["addu"] = std::bind (&MIPSProcessor::mips_addu, *this, _1, _2,
																	 _3);
	m_operations["beq"] = std::bind (&MIPSProcessor::mips_beq, *this, _1, _2,
																	 _3);
	m_operations["j"] = std::bind (&MIPSProcessor::mips_j, *this, _1);
	m_operations["jal"] = std::bind (&MIPSProcessor::mips_jal, *this, _1);
	m_operations["jr"] = std::bind (&MIPSProcessor::mips_jr, *this, _1);
	m_operations["lui"] = std::bind (&MIPSProcessor::mips_lui, *this, _1, _2,
																	 _3);
	m_operations["lw"] = std::bind (&MIPSProcessor::mips_lw, *this, _1, _2, _3);
	m_operations["mfhi"] = std::bind (&MIPSProcessor::mips_mfhi, *this, _1);
	m_operations["mflo"] = std::bind (&MIPSProcessor::mips_mflo, *this, _1);
	m_operations["mult"] = std::bind (&MIPSProcessor::mips_mult, *this, _1, _2);
	m_operations["ori"] = std::bind (&MIPSProcessor::mips_ori, *this, _1, _2,
																	 _3);
	m_operations["sll"] = std::bind (&MIPSProcessor::mips_sll, *this, _1, _2,
																	 _3);
	m_operations["slt"] = std::bind (&MIPSProcessor::mips_slt, *this, _1, _2,
																	 _3);
	m_operations["slti"] = std::bind (&MIPSProcessor::mips_slti, *this, _1, _2,
																	 _3);
	m_operations["sub"] = std::bind (&MIPSProcessor::mips_sub, *this, _1, _2,
																	 _3);
	m_operations["subu"] = std::bind (&MIPSProcessor::mips_subu, *this, _1, _2,
																	 _3);
	m_operations["sw"] = std::bind (&MIPSProcessor::mips_sw, *this, _1, _2, _3);
	m_operations["syscall"] = std::bind (&MIPSProcessor::mips_syscall, *this);

	m_state_functions[0] = std::bind (&MIPSProcessor::mips_if, *this);
	m_state_functions[1] = std::bind (&MIPSProcessor::mips_id, *this);
	m_state_functions[2] = std::bind (&MIPSProcessor::mips_ex, *this);
	m_state_functions[3] = std::bind (&MIPSProcessor::mips_mem, *this);
	m_state_functions[4] = std::bind (&MIPSProcessor::mips_wb, *this);

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
	m_syscalls[10] = std::bind (&MIPSProcessor::mips_syscall_exit, *this);
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
	m_state_functions[m_processor_state]();
}

// Functions at the processor's different states.

void
MIPSProcessor::mips_if ()
{
}

void
MIPSProcessor::mips_id ()
{
}

void
MIPSProcessor::mips_ex ()
{
}

void
MIPSProcessor::mips_mem ()
{
}

void
MIPSProcessor::mips_wb ()
{
}

// Operation implementations.

void
MIPSProcessor::mips_add (Register& rd, const Register& rs, const Register& rt)
{
	rd = rs + rt;
}

void
MIPSProcessor::mips_addi (Register& rd, const Register& rs, int immediate)
{
	rd = rs + immediate;
}

void
MIPSProcessor::mips_addiu (Register& rd, const Register& rs,
													 unsigned immediate)
{
	/// @todo Is this enough for unsigned add immediate?
	rd = rs + immediate;
}

void
MIPSProcessor::mips_addu (Register& rd, const Register& rs, const Register& rt)
{
	/// @todo Is this enough for unsigned add?
	rd = rs + rt;
}

void
MIPSProcessor::mips_beq (const Register& rs, const Register& rt,
												 unsigned branch_address)
{
	if (rs == rt)
		{
			m_register_file.m_registers[REG_PC] = branch_address;
		}
}

void
MIPSProcessor::mips_j (unsigned jump_address)
{
	m_register_file.m_registers[REG_PC] = jump_address;
}

void
MIPSProcessor::mips_jal (unsigned jump_address)
{
	m_register_file[31] = m_register_file.m_registers[REG_PC];
	m_register_file.m_registers[REG_PC] = jump_address;
}

void
MIPSProcessor::mips_jr (const Register& rs)
{
	m_register_file.m_registers[REG_PC] = rs;
}

void
MIPSProcessor::mips_lui (Register& rt, const Register& rs, unsigned immediate)
{
	rt = rs << 16;
}

void
MIPSProcessor::mips_lw (Register& rt, const Register& rs, int offset)
{
	rt = m_memory[rs + offset];
}

void
MIPSProcessor::mips_mfhi (Register& rd)
{
	rd = m_register_file[REG_HI];
}

void
MIPSProcessor::mips_mflo (Register& rd)
{
	rd = m_register_file[REG_LO];
}

void
MIPSProcessor::mips_mult (const Register& rs, const Register& rt)
{
	std::tie (m_register_file[REG_HI], m_register_file[REG_LO]) = rs * rt;
}

void
MIPSProcessor::mips_ori (Register& rd, const Register& rs, unsigned immediate)
{
	rd = rs | immediate
}

void
MIPSProcessor::mips_sll (Register& rd, const Register& rs, unsigned shamt)
{
	rd = rs << shamt;
}

void
MIPSProcessor::mips_slt (Register& rd, const Register& rs, const Register& rt)
{
	rd = (rs < rt) ? 1 : 0;
}

void
MIPSProcessor::mips_slti (Register& rd, const Register& rs, int immediate)
{
	rd = (rs < immediate) ? 1 : 0;
}

void
MIPSProcessor::mips_sub (Register& rd, const Register& rs, const Register& rt)
{
	rd = rs - rt;
}

void
MIPSProcessor::mips_subu (Register& rd, const Register& rs, const Register& rt)
{
	/// @todo Is this enough for unsigned subtract?
	rd = rs - rt;
}

void
MIPSProcessor::mips_sw (const Register& rt, const Register& rs, int offset)
{
	m_memory[rs + offset] = rt;
}

void
MIPSProcessor::mips_syscall ()
{
	m_syscall_table[m_register_file[2]]();
}

void
MIPSProcessor::mips_syscall_exit ()
{
	os->exit_application ();
}
