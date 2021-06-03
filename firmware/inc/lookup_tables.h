/* FILE AUTOMATICALLY GENERATED BY: /utils/lookup_table_gen.py */

#ifndef LOOKUP_TABLES_H_INCLUDED
#define LOOKUP_TABLES_H_INCLUDED

#include <stdint.h>

// the attack curve lookup table
extern const uint32_t ADSR_ATTACK_TABLE[1024];

// the decay curve lookup table, used for decay and release curves
extern const uint32_t ADSR_DECAY_TABLE[1024];

#endif