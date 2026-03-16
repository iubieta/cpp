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
# end

# Main pend split
# break PmergeMe.cpp:135
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

# Position array init
break PmergeMe.cpp:157
commands
	set confirm off
	undisplay
	set confirm on
	display mains
	display groupSize
	display positions
end

# Insert first pend
break PmergeMe.cpp:163
commands
	set confirm off
	undisplay
	set confirm on
	display pends
	display groupSize
	display mains
	display positions
end

# Insert first pend
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
