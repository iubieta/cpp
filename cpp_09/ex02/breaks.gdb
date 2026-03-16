break PmergeMe.cpp:157
  commands
    set confirm off
    undisplay
    set confirm on
    display mains
    display groupSize
    display positions
  end
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
break PmergeMe::splitGroups(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> >&, std::vector<int, std::allocator<int> >&, long const&)
break PmergeMe::adjustPositions(std::vector<unsigned long, std::allocator<unsigned long> >, long const&, unsigned long)
