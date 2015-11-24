#ifndef __MIPSSIMULATOR_PROCESSOR_MIPSPROCESSOR_HPP_
#define __MIPSSIMULATOR_PROCESSOR_MIPSPROCESSOR_HPP_

#include <functional>
#include <map>
#include <string>

#include <processor/memory.hpp>
#include <processor/register/register_file.hpp>
#include <processor/register/register.hpp>

// These are the states the processor can be in.

#define MIPS_IF 0
#define MIPS_ID 1
#define MIPS_EX 2
#define MIPS_MEM 3
#define MIPS_WB 4

class MIPSProcessor
{
public:
	// CONSTRUCTORS

	/**
	 * @brief Construct a MIPS processor with references to the necessary
	 *        components.
	 *
	 * @param[in]
	 */
	MIPSProcessor (Memory& memory, RegisterFile<unsigned>& register_file);

	// DESTRUCTORS

	/**
	 * @brief Destructor.
	 */
	~MIPSProcessor ();

	// FUNCTIONS

	/**
	 * @brief Execute the functionality at the current state this
	 *        <code>MIPSProcessor</code> is in.
	 */
	void
	tick ();

private:
	// FUNCTIONS

	/**
	 * @brief What this processor does in the if state.
	 */
	void
	mips_if ();

	/**
	 * @brief What this processor does in the id state.
	 */
	void
	mips_id ();

	/**
	 * @brief What this processor does in the ex state.
	 */
	void
	mips_ex ();

	/**
	 * @brief What this processor does in the mem state.
	 */
	void
	mips_mem ();

	/**
	 * @brief What this processor does in the wb state.
	 */
	void
	mips_wb ();

	// /**
	//  * @brief R[rd] = R[rs] + SignExtImm
	//  * MIPS add operation.
	//  * @param[out] rd The destination register.
	//  * @param[in]  rs The first source register.
	//  * @param[in]  rt The second source register.
	//  */
	// void
	// mips_add (Register<unsigned>& rd, const Register<unsigned>& rs, const Register<unsigned>& rt);

	// /**
	//  * @brief R[rd] = R[rs] + SignExtImm
	//  * MIPS addi operation.
	//  * @param[out] rd        The destination register.
	//  * @param[in]  rs        The first source register.
	//  * @param[in]  immediate The immediate.
	//  */
	// void
	// mips_addi (Register<unsigned>& rd, const Register<unsigned>& rs, int immediate);

	// /**
	//  * @brief R[rd] = R[rs] + SignExtImm
	//  * MIPS addiu operation.
	//  * @param[out] rd        The destination register.
	//  * @param[in]  rs        The first source register.
	//  * @param[in]  immediate The immediate.
	//  */
	// void
	// mips_addiu (Register<unsigned>& rd, const Register<unsigned>& rs, unsigned immediate);

	// /**
	//  * @brief R[rd] = R[rs] + SignExtImm
	//  * MIPS addu operation.
	//  * @param[out] rd The destination register.
	//  * @param[in]  rs The first source register.
	//  * @param[in]  rt The second source register.
	//  */
	// void
	// mips_addu (Register<unsigned>& rd, const Register<unsigned>& rs, const Register<unsigned>& rt);

	// /**
	//  * @brief if (R[rs] == R[rt]) PC = PC + 4 + BranchAddr
	//  * MIPS beq operation.
	//  * @param[in] rs             The first source register.
	//  * @param[in] rt             The second source register.
	//  * @param[in] branch_address The branch address.
	//  */
	// void
	// mips_beq (const Register<unsigned>& rs, const Register<unsigned>& rt, unsigned branch_address);

	// /**
	//  * @brief PC = JumpAddr
	//  * MIPS j operation.
	//  * @param[in] jump_address The jump address.
	//  */
	// void
	// mips_j (unsigned jump_address, boost::any a1, boost::any a2);

	// /**
	//  * @brief R[31] = PC + 8; PC = JumpAddr
	//  * MIPS jal operation.
	//  * @param[in] jump_address The jump address.
	//  */
	// void
	// mips_jal (unsigned jump_address, boost::any a1, boost::any a2);

	// /**
	//  * @brief PC = R[rs]
	//  * MIPS jal operation.
	//  * @param[in]  rs The source register.
	//  */
	// void
	// mips_jr (const Register<unsigned>& rs, boost::any a1, boost::any a2);

	// /**
	//  * @brief R[rt] = {imm, 16'b0}
	//  * MIPS lui operation.
	//  * @param[out] rt        The destination register.
	//  * @param[in]  rs        The source register.
	//  * @param[in]  immediate The immediate.
	//  */
	// void
	// mips_lui (Register<unsigned>& rt, const Register<unsigned>& rs, unsigned immediate);

	// /**
	//  * @brief R[rt] = M[R[rs] + SignExtImm]
	//  * MIPS lw operation.
	//  * @param[out] rt     The destination register.
	//  * @param[in]  rs     The source register.
	//  * @param[in]  offset The offset (default <code>0</code>)..
	//  */
	// void
	// mips_lw (Register<unsigned>& rt, const Register<unsigned>& rs, int offset = 0);

	// /**
	//  * @brief R[rd] = Hi
	//  * MIPS mfhi operation.
	//  * @param[out] rd The destination register.
	//  */
	// void
	// mips_mfhi (Register<unsigned>& rd, boost::any a1, boost::any a2);

	// /**
	//  * @brief R[rd] = Lo
	//  * MIPS mflo operation.
	//  * @param[out] rd The destination register.
	//  */
	// void
	// mips_mflo (Register<unsigned>& rd, boost::any a1, boost::any a2);

	// /**
	//  * @brief {Hi, Lo} = R[rs] * R[rt]
	//  * MIPS mult operation.
	//  * @param[out] rs The first source register.
	//  * @param[out] rt The second source register.
	//  */
	// void
	// mips_mult (const Register<unsigned>& rs, const Register<unsigned>& rt, boost::any a1);

	// /**
	//  * @brief R[rd] = R[rs] | ZeroExtImm
	//  * MIPS ori operation.
	//  * @param[out] rd        The destination register.
	//  * @param[in]  rs        The first source register.
	//  * @param[in]  immediate The immediate.
	//  */
	// void
	// mips_ori (Register<unsigned>& rd, const Register<unsigned>& rs, unsigned immediate);

	// /**
	//  * @brief R[rd] = R[rs] << shamt
	//  * MIPS sll operation.
	//  * @param[out] rd    The destination register.
	//  * @param[in]  rs    The first source register.
	//  * @param[in]  shamt The shift amount.
	//  */
	// void
	// mips_sll (Register<unsigned>& rd, const Register<unsigned>& rs, unsigned shamt);

	// /**
	//  * @brief R[rd] = (R[rs] < R[rt]) ? 1 : 0
	//  * MIPS slt operation.
	//  * @param[out] rd The destination register.
	//  * @param[in]  rs The first source register.
	//  * @param[in]  rt The second source register.
	//  */
	// void
	// mips_slt (Register<unsigned>& rd, const Register<unsigned>& rs, const Register<unsigned>& rt);

	// /**
	//  * @brief R[rd] = (R[rs] < SignExtImm) ? 1 : 0
	//  * MIPS slti operation.
	//  * @param[out] rd       The destination register.
	//  * @param[in]  rs       The source register.
	//  * @param[in] immediate The immediate.
	//  */
	// void
	// mips_slti (Register<unsigned>& rd, const Register<unsigned>& rs, int immediate);

	// /**
	//  * @brief R[rd] = R[rs] - SignExtImm
	//  * MIPS sub operation.
	//  * @param[out] rd The destination register.
	//  * @param[in]  rs The first source register.
	//  * @param[in]  rt The second source register.
	//  */
	// void
	// mips_sub (Register<unsigned>& rd, const Register<unsigned>& rs, const Register<unsigned>& rt);

	// /**
	//  * @brief R[rd] = R[rs] - SignExtImm
	//  * MIPS subu operation.
	//  * @param[out] rd The destination register.
	//  * @param[in]  rs The first source register.
	//  * @param[in]  rt The second source register.
	//  */
	// void
	// mips_subu (Register<unsigned>& rd, const Register<unsigned>& rs, const Register<unsigned>& rt);

	// /**
	//  * @brief M[R[rs] + SignExtImm] = R[rt]
	//  * MIPS sw operation.
	//  * @param[out] rt     The destination register.
	//  * @param[in]  rs     The source register.
	//  * @param[in]  offset The offset (default <code>0</code>)..
	//  */
	// void
	// mips_sw (const Register<unsigned>& rt, const Register<unsigned>& rs, int offset = 0);

	// /**
	//  * @brief MIPS syscall operation.
	//  */
	// void
	// mips_syscall (boost::any a1, boost::any a2, boost::any a3);

	/**
	 * @brief R[rd] = R[rs] + SignExtImm
	 * MIPS add operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_add (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt);

	/**
	 * @brief R[rd] = R[rs] + SignExtImm
	 * MIPS addi operation.
	 * @param[out] rd        The destination register.
	 * @param[in]  rs        The first source register.
	 * @param[in]  immediate The immediate.
	 */
	void
	mips_addi (Register<unsigned>& rd, Register<unsigned>& rs, int immediate);

	/**
	 * @brief R[rd] = R[rs] + SignExtImm
	 * MIPS addiu operation.
	 * @param[out] rd        The destination register.
	 * @param[in]  rs        The first source register.
	 * @param[in]  immediate The immediate.
	 */
	void
	mips_addiu (Register<unsigned>& rd, Register<unsigned>& rs, unsigned immediate);

	/**
	 * @brief R[rd] = R[rs] + SignExtImm
	 * MIPS addu operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_addu (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt);

	/**
	 * @brief if (R[rs] == R[rt]) PC = PC + 4 + BranchAddr
	 * MIPS beq operation.
	 * @param[in] rs             The first source register.
	 * @param[in] rt             The second source register.
	 * @param[in] branch_address The branch address.
	 */
	void
	mips_beq (Register<unsigned>& rs, Register<unsigned>& rt, unsigned branch_address);

	/**
	 * @brief PC = JumpAddr
	 * MIPS j operation.
	 * @param[in] jump_address The jump address.
	 */
	void
	mips_j (unsigned jump_address);

	/**
	 * @brief R[31] = PC + 8; PC = JumpAddr
	 * MIPS jal operation.
	 * @param[in] jump_address The jump address.
	 */
	void
	mips_jal (unsigned jump_address);

	/**
	 * @brief PC = R[rs]
	 * MIPS jal operation.
	 * @param[in]  rs The source register.
	 */
	void
	mips_jr (Register<unsigned>& rs);

	/**
	 * @brief R[rt] = {imm, 16'b0}
	 * MIPS lui operation.
	 * @param[out] rt        The destination register.
	 * @param[in]  rs        The source register.
	 * @param[in]  immediate The immediate.
	 */
	void
	mips_lui (Register<unsigned>& rt, Register<unsigned>& rs, unsigned immediate);

	/**
	 * @brief R[rt] = M[R[rs] + SignExtImm]
	 * MIPS lw operation.
	 * @param[out] rt     The destination register.
	 * @param[in]  rs     The source register.
	 * @param[in]  offset The offset (default <code>0</code>)..
	 */
	void
	mips_lw (Register<unsigned>& rt, Register<unsigned>& rs, int offset = 0);

	/**
	 * @brief R[rd] = Hi
	 * MIPS mfhi operation.
	 * @param[out] rd The destination register.
	 */
	void
	mips_mfhi (Register<unsigned>& rd);

	/**
	 * @brief R[rd] = Lo
	 * MIPS mflo operation.
	 * @param[out] rd The destination register.
	 */
	void
	mips_mflo (Register<unsigned>& rd);

	/**
	 * @brief {Hi, Lo} = R[rs] * R[rt]
	 * MIPS mult operation.
	 * @param[out] rs The first source register.
	 * @param[out] rt The second source register.
	 */
	void
	mips_mult (Register<unsigned>& rs, Register<unsigned>& rt);

	/**
	 * @brief R[rd] = R[rs] | ZeroExtImm
	 * MIPS ori operation.
	 * @param[out] rd        The destination register.
	 * @param[in]  rs        The first source register.
	 * @param[in]  immediate The immediate.
	 */
	void
	mips_ori (Register<unsigned>& rd, Register<unsigned>& rs, unsigned immediate);

	/**
	 * @brief R[rd] = R[rs] << shamt
	 * MIPS sll operation.
	 * @param[out] rd    The destination register.
	 * @param[in]  rs    The first source register.
	 * @param[in]  shamt The shift amount.
	 */
	void
	mips_sll (Register<unsigned>& rd, Register<unsigned>& rs, unsigned shamt);

	/**
	 * @brief R[rd] = (R[rs] < R[rt]) ? 1 : 0
	 * MIPS slt operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_slt (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt);

	/**
	 * @brief R[rd] = (R[rs] < SignExtImm) ? 1 : 0
	 * MIPS slti operation.
	 * @param[out] rd       The destination register.
	 * @param[in]  rs       The source register.
	 * @param[in] immediate The immediate.
	 */
	void
	mips_slti (Register<unsigned>& rd, Register<unsigned>& rs, int immediate);

	/**
	 * @brief R[rd] = R[rs] - SignExtImm
	 * MIPS sub operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_sub (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt);

	/**
	 * @brief R[rd] = R[rs] - SignExtImm
	 * MIPS subu operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_subu (Register<unsigned>& rd, Register<unsigned>& rs, Register<unsigned>& rt);

	/**
	 * @brief M[R[rs] + SignExtImm] = R[rt]
	 * MIPS sw operation.
	 * @param[out] rt     The destination register.
	 * @param[in]  rs     The source register.
	 * @param[in]  offset The offset (default <code>0</code>)..
	 */
	void
	mips_sw (Register<unsigned>& rt, Register<unsigned>& rs, int offset = 0);

	/**
	 * @brief MIPS syscall operation.
	 */
	void
	mips_syscall ();

	/**
	 * @brief Exit simulation.
	 *
	 * Transfer control to the OS and exit this simulation.
	 */
	void
	mips_syscall_exit ();

	// Type of an instruction.

	bool
	is_three_regs ();

	bool
	is_two_regs_i ();

	bool
	is_two_args ();

	bool
	is_one_reg ();

	bool
	is_one_i ();

	bool
	is_syscall ();

	// VARIABLES

	/** The state in the instruction pipeline we are in. */
	int m_processor_state;
	/** The memory for this <code>MIPSProcessor</code>. */
	Memory& m_memory;
	/** The register file for this <code>MIPSProcessor</code>. */
	RegisterFile<unsigned>& m_register_file;
	/** The functions at each state in this <code>MIPSProcessor</code>. */
	std::map<std::string, std::function <void()> > m_state_functions;
	// /** The operations that this <code>MIPSProcessor</code> supports. */
	// std::map<std::string, std::function<void(boost::any, boost::any, boost::any)> > m_operations;
	/** The syscalls that this <code>MIPSProcessor</code> supports. */
	std::map<int, std::function<void()> > m_syscalls;

	Register<std::string> ifid_reg;
	std::vector <std::string> cpts;

	// Temporary registers.
};

#endif // __MIPSSIMULATOR_PROCESSOR_MIPSPROCESSOR_HPP_
