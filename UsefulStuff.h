#ifndef USEFULSTUFF_H
#define USEFULSTUFF_H

#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>

//The number of bits in the number.
unsigned int BitCount( unsigned int n );

//Number flip 2,3,4,8 bytes. Big/Little Endian. Didn't used in project, but can help in the future.
unsigned short swap_uint2(unsigned short x);

unsigned int swap_uint3(unsigned int x); 

unsigned int swap_uint4(unsigned int x);

unsigned long long swap_uint8(unsigned long long val);
//

char change_case (char c);

void StringToHEX(std::string hex, uint8_t *answer);

void HEXToString(std::string& hex, uint8_t *answer, int size);


#endif /* USEFULSTUFF_H */

