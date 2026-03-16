# .gdbinit

# Vector Ford Johnson
# break PmergeMe::vectorFordJohnson(std::vector<int, std::allocator<int> >&, long)
# commands
# 	set confirm off
# 	undisplay
# 	set confirm on
# 	display inVector
# 	display groupSize
# 	display sortVector
# end
#
# Jacobsthal insertion
# break jacobsthalInsertion(std::vector<int, std::allocator<int> >&, long)
# commands
# 	set confirm off
# 	undisplay
# 	set confirm on
# 	display inVector
# 	display groupSize
# 	display groupNumber
# 	display mains
# 	display pends
# 	display positions
# end

# Main pend split
# break PmergeMe::splitGroups(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> >&, std::vector<int, std::allocator<int> >&, long const&)
# commands
# 	set confirm off
# 	undisplay
# 	set confirm on
# 	display inVector
# 	display groupSize
# 	display mains
# 	display pends
# 	display mainStart
# 	display pendStart
# 	display last_main
# 	print "------------------------------------"
# end
#
# break PmergeMe.cpp:144
# commands
# 	set confirm off
# 	undisplay
# 	set confirm on
# 	display positions
# 	display groupSize
# 	display insertPos
# 	display i
# 	display positions[i]
# end
#
break PmergeMe.cpp:175
commands
	set confirm off
	undisplay
	set confirm on
	display inVector
	display groupSize
	display groupNumber
	display mains
	display pends
	display positions
end

break PmergeMe.cpp:182
commands
	set confirm off
	undisplay
	set confirm on
	display inVector
	display groupSize
	display groupNumber
	display mains
	display pends
	display positions
	display pos
end

break PmergeMe.cpp:190
commands
	set confirm off
	undisplay
	set confirm on
	display inVector
	display groupSize
	display groupNumber
	display mains
	display pends
	display pos
end

break PmergeMe.cpp:194
commands
	set confirm off
	undisplay
	set confirm on
	display inVector
	display groupSize
	display groupNumber
	display mains
	display pends
	display pos
	display positions
end
# # Position array init
# break PmergeMe.cpp:157
# commands
# 	set confirm off
# 	undisplay
# 	set confirm on
# 	display mains
# 	display groupSize
# end
#
# # Insert first pend
# break PmergeMe.cpp:163
# commands
# 	set confirm off
# 	undisplay
# 	set confirm on
# 	display pends
# 	display groupSize
# 	display mains
# 	display positions
# end
#
# break PmergeMe::adjustPositions(std::vector<unsigned long, std::allocator<unsigned long> >, long const&, unsigned long)
#
# # Insert first pend
# break PmergeMe.cpp:164
# commands
# 	set confirm off
# 	undisplay
# 	set confirm on
# 	display inVector
# 	display groupSize
# 	display mains
# 	display pends
# 	display i
# 	display pends.size() / groupSize
# 	display j
# 	display \n
# end

# Jacobsthal func
# break PmergeMe.cpp:150
# commands
# 	set confirm off
# 	undisplay
# 	set confirm on
# 	display cache
# 	display i
# 	display cache[i]
# 	print
# end
