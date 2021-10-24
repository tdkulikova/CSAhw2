//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_RANDOM_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_RANDOM_H

#ifndef __rnd__
#define __rnd__

#include<cstdlib>

//------------------------------------------------------------------------------
// random.h - contains random number generator, generates numbers from 1 to 100.
//------------------------------------------------------------------------------

inline auto Random() {
    return rand() % 100 + 1;
}

#endif

#endif

