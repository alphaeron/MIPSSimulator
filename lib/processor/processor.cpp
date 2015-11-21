A#include <processor/processor.hpp>

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
}

void
MIPSProcessor::mips_addi (Register& rd, const Register& rs, int immediate)
{
}

void
MIPSProcessor::mips_addiu (Register& rd, const Register& rs,
													 unsigned immediate)
{
}

void
MIPSProcessor::mips_addu (Register& rd, const Register& rs, const Register& rt)
{
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
}

void
MIPSProcessor::mips_lw (Register& rt, const Register& rs, int offset)
{
}

void
MIPSProcessor::mips_mfhi (Register& rd)
{
}

void
MIPSProcessor::mips_mflo (Register& rd)
{
}

void
MIPSProcessor::mips_mult (const Register& rs, const Register& rt)
{
}

void
MIPSProcessor::mips_ori (Register& rd, const Register& rs, unsigned immediate)
{
}

void
MIPSProcessor::mips_sll (Register& rd, const Register& rs, unsigned shamt)
{
}

void
MIPSProcessor::mips_slt (Register& rd, const Register& rs, const Register& rt)
{
}

void
MIPSProcessor::mips_slti (Register& rd, const Register& rs, int immediate)
{
}

void
MIPSProcessor::mips_sub (Register& rd, const Register& rs, const Register& rt)
{
}

void
MIPSProcessor::mips_subu (Register& rd, const Register& rs, const Register& rt)
{
}

void
MIPSProcessor::mips_sw (const Register& rt, const Register& rs, int offset)
{
}

void
MIPSProcessor::mips_syscall ()
{
}
