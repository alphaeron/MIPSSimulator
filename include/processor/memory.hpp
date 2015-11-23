#ifndef __MIPSSIMULATOR_PROCESSOR_MEMORY_HPP_
#define __MIPSSIMULATOR_PROCESSOR_MEMORY_HPP_

#include <experimental/any>
#include <map>

class Memory
{
public:
	// CONSTRUCTORS

	/**
	 * @brief Construct main memory given a size for it.
	 *
	 * @param[in] mem_size The size of main memory.
	 */
	Memory (size_t mem_size);

	// DESTRUCTORS

	/**
	 * @brief Destructor.
	 */
	~Memory ();

	// OPERATORS

	/**
	 * @brief Index memory as you normally would.
	 *
	 * @param[in] address The "address" to use as an index into this
	 *            <code>Memory</code>.
	 *
	 * @return The value of this <code>Memory</code> at <code>address</code>.
	 */
	unsigned
	operator[] (unsigned address) const;

	/**
	 * @brief Index memory as you normally would.
	 *
	 * @param[in] address The "address" to use as an index into this
	 *            <code>Memory</code>.
	 *
	 * @return The value of this <code>Memory</code> at <code>address</code>.
	 */
	unsigned&
	operator[] (unsigned address);

private:
	// VARIABLES

	/** The size of data. */
	size_t m_size;
	/** The data that is stored in this <code>Memory</code>. */
	std::map<unsigned, std::experimental::any> data;
};

#endif // __MIPSSIMULATOR_PROCESSOR_MEMORY_HPP_
