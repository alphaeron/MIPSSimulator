#ifndef __MIPSSIMULATOR_STATS_HPP_
#define __MIPSSIMULATOR_STATS_HPP_

/**
 * @brief POD containing important statistics about the execution of a
 *        simulation.
 */
struct RunStatistics
{
	/** The wall clock time the simulation took. */
	unsigned long wall_clock_time;
	/** THe number of cycles the simulation took. */
	unsigned long n_cycles;
	/** The number of context switches in a simulation. */
	unsigned long n_context_switches;
	/** The number of tlb hits. */
	unsigned long n_tlb_hits;
	/** The number of tlb misses. */
	unsigned long n_tlb_misses;
	/** The number of page table hits. */
	unsigned long n_page_table_hits;
	/** The number of page table misses. */
	unsigned long n_page_table_misses;
};

#endif //  __MIPSSIMULATOR_STATS_HPP_
