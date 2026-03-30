# breaks.gdb

break jacobsthalInsertion(std::vector<int, std::allocator<int> > const&, long const&)
  commands
    set confirm off
    undisplay
    set confirm on
    display jsi
  end

break insertIntoMain(jacobSthalIns_s&, unsigned long)
  commands
    set confirm off
    undisplay
    set confirm on
    display jsi
    display group
    display startIt
    display endIt
    display pos
  end

break groupLowerBound(jacobSthalIns_s&, __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int)
  commands
    set confirm off
    undisplay
    set confirm on
    display jsi
    display limit
    display target
    display low
    display high
	display mid
  end

break insertExcess(jacobSthalIns_s&)
  commands
    set confirm off
    undisplay
    set confirm on
    display jsi
    display startIt
    display endIt
    display pos
  end

