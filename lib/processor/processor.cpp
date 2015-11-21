#include <tuple>

#include <processor/processor.hpp>

MIPSProcessor::MIPSProcessor (Memory& memory, RegisterFile& register_file)
	: m_memory (memory), m_register_file (register_file)
{
}

MIPSProcessor::~MIPSProcessor ()
{
}

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
}

void
MIPSProcessor::mips_j (unsigned jump_address)
{
}

void
MIPSProcessor::mips_jal (unsigned jump_address)
{
}

void
MIPSProcessor::mips_jr (const Register& rs)
{
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
}
