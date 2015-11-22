#include <utility/stats.hpp>

ostream&
operator<< (ostream& os, const RunStatistics& stats)
{
	os << "Wall Clock Time: " << stats.wall_clock_time << std::endl
		 << "Number of Cycles: " << stats.n_cycles << std::endl
		 << "Number of Context Switches: " << stats.n_context_switches << std::endl
		 << "Number of TLB Hits: " << stats.n_tlb_hits << std::endl
		 << "Number of TLB Misses: " << stats.n_tlb_misses << std::endl
		 << "Number of Page Table Hits: " << stats.n_page_table_hits << std::endl
		 << "Number of Page Table Misses: " << stats.n_page_table_misses
		 << std::endl;
}
