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
break jacobsthalInsertion(std::vector<int, std::allocator<int> > const&, long const&)
  commands
    set confirm off
    undisplay
    set confirm on
    display jsi
  end
break adjustPositions(jacobSthalIns_s&, __gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > > const&)
  commands
    set confirm off
    undisplay
    set confirm on
    display jsi
    display offset
  end
