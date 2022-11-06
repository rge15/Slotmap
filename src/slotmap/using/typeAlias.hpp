#include "config.hpp"

//################################ TYPE  ALIASES ##############################

using Size_t = std::size_t; 

//############################## TEMPLATE ALIASES #############################

template <typename T1>
using Vector = std::vector<T1>;
	
template <typename T2, typename D2>
using Pair = std::pair<T2, D2>;

template <typename T3>
using UniqPtr = std::unique_ptr<T3>;
