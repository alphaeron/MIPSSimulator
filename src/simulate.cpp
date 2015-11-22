#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <string>

#include <simulate.hpp>

int
main (int argc, char* argv[])
{
	std::string version = "1.0.0"
	int verbose_flag = 0;
	int num_processes = 32;
	int instruction_time_slice = 50;
	std::string vm_algorithm;
	int virtual_address_bits = 24;
	int page_size = 4096; // 4KiB
	int memory_size = 1; // 1GiB
	std::string program;
	std::string data_dir;

  int c;

  while (1)
    {
      static struct option long_options[] =
        {
					{"help",                   no_argument,       0, 'h'},
          {"version",                no_argument,       0, 'v'},
          {"verbose",                no_argument,       0, 'V'},
					{"num-processes",          optional_argument, 0, 'p'},
					{"instruction-time-slice", optional_argument, 0, 't'},
					{"vm-algorithm",           required_argument, 0, 'a'},
					{"virtual-address-bits",   optional_argument, 0, 'b'},
					{"page-size",              optional_argument, 0, 'g'},
					{"memory-size",            optional_argument, 0, 'm'},
					{"program",                required_argument, 0, 'r'},
					{"data-dir",               required_argument, 0, 'd'}
          {0, 0, 0, 0}
        };

      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "hvVp:t:a:b:g:r:d:",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c)
        {
				case 'h':
					print_usage ();
					exit (0);

				case 'v':
					std::cout << "simulate version " << version << std::endl;
					print_usage ();
					exit (0);

				case 'V':
					verbose_flag = 1;
          break;

				case 'p':
					num_processes = std::stoi (optarg);
          break;

				case 't':
					instruction_time_slice = std::stoi (optarg);
          break;

				case 'a':
					vm_algorithm = optarg;
          break;

				case 'b':
					virtual_address_bits = std::stoi (optarg);
          break;

				case 'g':
					page_size = std::stoi (optarg);
          break;

				case 'm':
					memory_size = std::stoi (optarg);
					break;

				case 'r':
					program = optarg;
          break;

				case 'd':
					data_dir = optarg;
          break;

        case '?':
					print_usage ();
					exit (1);

        default:
          abort ();
        }
    }

	if (verbose_flag == 1)
		{
			std::cout << "Number of Processes: " << num_processes << std::endl
								<< "Instruction Time Slice: " << instruction_time_slice
								<< std::endl
								<< "VM Algorithm: " << vm_algorithm
								<< "Virtual Address Bits: " << virtual_address_bits
								<< std::endl
								<< "Page Size: " << page_size << std::endl
								<< "Program: " << program << std::endl
								<< "Data Directory: " << data_dir << std::endl;
		}

	return 0;
}

void
print_usage ()
{
	printf(
"Usage: simulate [-p NUMPROCESSES] [-t NUMINSTS] [-a ALGORITHM] [-b BITS]\n\
 [-a PAGESIZE] -r PROGRAM -d DATADIR\n\
MIPS processor simulator that executes MIPS assembly programs.\n\
\n\
Mandatory arguments to long options are mandatory for short options to.\n\
  -h, --help                               Output a brief help message and\n\
                                           exit.\n\
  -v, --version                            Output version information and \
exit.\n\
  -V, --verbose                            Output information at each stage \
of\n\
                                           execution.\n\
  -p, --num-processes=NUMPROCESSES         Set the number of processes.\n\
                                           Default is 32 processes.\n\
  -t, --instruction-time-slice=NUMINSTS    Set the number of instructions in \
an\n\
                                           instruction time slice.  Default \
is\n\
                                           50 instructions.\n\
  -a, --vm-algorithm=ALGORITHM             Specify the virtual memory \
algorithm\n\
                                           to use when executing this \
program.\n\
  -b, --virtual-address-bits=BITS          Secify the number of bits in a\n\
                                           virtual address.  Default is 24\n\
                                           bits.\n\
  -g, --page-size=PAGESIZE                 Specify the size of a page.  \
Default\n\
                                           is 4KiB.\n\
  -m, --memory-size=MEMSIZE                Specify the size of physical \
memory.  Default is 1GiB.\n\
  -r, --program=PROGRAM                    Specify the program to execute.  \
The\n\
                                           program must be under the data\n\
                                           directory.\n\
  -d, --data-dir=DATADIR                   The data directory to store the\n\
                                           program's assembly files in.\n");
}
