#ifndef __MIPSSIMULATOR_PROCESSOR_MIPSPROCESSOR_HPP_
#define __MIPSSIMULATOR_PROCESSOR_MIPSPROCESSOR_HPP_

#include <function>
#include <map>
#include <string>

#include <os/os.hpp>
#include <processor/memory.hpp>
#include <processor/register/register_file.hpp>
#include <processor/register/register.hpp>

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
	MIPSProcessor (OS& os, Memory& memory, RegisterFile& register_file);

	// DESTRUCTORS

	/**
	 * @brief Destructor.
	 */
	~MIPSProcessor ();

private:
	// Friend required classes.

	friend class OS;
	friend class RegisterFile;

	// FUNCTIONS

	/**
	 * @brief R[rd] = R[rs] + SignExtImm
	 * MIPS add operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_add (Register& rd, const Register& rs, const Register& rt);

	/**
	 * @brief R[rd] = R[rs] + SignExtImm
	 * MIPS addi operation.
	 * @param[out] rd        The destination register.
	 * @param[in]  rs        The first source register.
	 * @param[in]  immediate The immediate.
	 */
	void
	mips_addi (Register& rd, const Register& rs, int immediate);

	/**
	 * @brief R[rd] = R[rs] + SignExtImm
	 * MIPS addiu operation.
	 * @param[out] rd        The destination register.
	 * @param[in]  rs        The first source register.
	 * @param[in]  immediate The immediate.
	 */
	void
	mips_addiu (Register& rd, const Register& rs, unsigned immediate);

	/**
	 * @brief R[rd] = R[rs] + SignExtImm
	 * MIPS addu operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_addu (Register& rd, const Register& rs, const Register& rt);

	/**
	 * @brief if (R[rs] == R[rt]) PC = PC + 4 + BranchAddr
	 * MIPS beq operation.
	 * @param[in] rs             The first source register.
	 * @param[in] rt             The second source register.
	 * @param[in] branch_address The branch address.
	 */
	void
	mips_beq (const Register& rs, const Register& rt, unsigned branch_address);

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
	mips_jr (const Register& rs);

	/**
	 * @brief R[rt] = {imm, 16'b0}
	 * MIPS lui operation.
	 * @param[out] rt        The destination register.
	 * @param[in]  rs        The source register.
	 * @param[in]  immediate The immediate.
	 */
	void
	mips_lui (Register& rt, const Register& rs, unsigned immediate);

	/**
	 * @brief R[rt] = M[R[rs] + SignExtImm]
	 * MIPS lw operation.
	 * @param[out] rt     The destination register.
	 * @param[in]  rs     The source register.
	 * @param[in]  offset The offset (default <code>0</code>)..
	 */
	void
	mips_lw (Register& rt, const Register& rs, int offset = 0);

	/**
	 * @brief R[rd] = Hi
	 * MIPS mfhi operation.
	 * @param[out] rd The destination register.
	 */
	void
	mips_mfhi (Register& rd);

	/**
	 * @brief R[rd] = Lo
	 * MIPS mflo operation.
	 * @param[out] rd The destination register.
	 */
	void
	mips_mflo (Register& rd);

	/**
	 * @brief {Hi, Lo} = R[rs] * R[rt]
	 * MIPS mult operation.
	 * @param[out] rs The first source register.
	 * @param[out] rt The second source register.
	 */
	void
	mips_mult (const Register& rs, const Register& rt);

	/**
	 * @brief R[rd] = R[rs] | ZeroExtImm
	 * MIPS ori operation.
	 * @param[out] rd        The destination register.
	 * @param[in]  rs        The first source register.
	 * @param[in]  immediate The immediate.
	 */
	void
	mips_ori (Register& rd, const Register& rs, unsigned immediate);

	/**
	 * @brief R[rd] = R[rs] << shamt
	 * MIPS sll operation.
	 * @param[out] rd    The destination register.
	 * @param[in]  rs    The first source register.
	 * @param[in]  shamt The shift amount.
	 */
	void
	mips_sll (Register& rd, const Register& rs, unsigned shamt);

	/**
	 * @brief R[rd] = (R[rs] < R[rt]) ? 1 : 0
	 * MIPS slt operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_slt (Register& rd, const Register& rs, const Register& rt);

	/**
	 * @brief R[rd] = (R[rs] < SignExtImm) ? 1 : 0
	 * MIPS slti operation.
	 * @param[out] rd       The destination register.
	 * @param[in]  rs       The source register.
	 * @param[in] immediate The immediate.
	 */
	void
	mips_slti (Register& rd, const Register& rs, int immediate);

	/**
	 * @brief R[rd] = R[rs] - SignExtImm
	 * MIPS sub operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_sub (Register& rd, const Register& rs, const Register& rt);

	/**
	 * @brief R[rd] = R[rs] - SignExtImm
	 * MIPS subu operation.
	 * @param[out] rd The destination register.
	 * @param[in]  rs The first source register.
	 * @param[in]  rt The second source register.
	 */
	void
	mips_subu (Register& rd, const Register& rs, const Register& rt);

	/**
	 * @brief M[R[rs] + SignExtImm] = R[rt]
	 * MIPS sw operation.
	 * @param[out] rt     The destination register.
	 * @param[in]  rs     The source register.
	 * @param[in]  offset The offset (default <code>0</code>)..
	 */
	void
	mips_sw (const Register& rt, const Register& rs, int offset = 0);

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

	// VARIABLES

	/** The OS running on this <code>MIPSProcessor</code>. */
	OS& m_os;
	/** The memory for this <code>MIPSProcessor</code>. */
	Memory& m_memory;
	/** The register file for this <code>MIPSProcessor</code>. */
	RegisterFile& m_register_filo;
	/** The operations that this <code>MIPSProcessor</code> supports. */
	std::map<std::string, std::function<void()> > m_operations;
	/** The syscalls that this <code>MIPSProcessor</code> supports. */
	std::map<int, std::function<void()> > m_syscalls;
};

#endif // __MIPSSIMULATOR_PROCESSOR_MIPSPROCESSOR_HPP_
