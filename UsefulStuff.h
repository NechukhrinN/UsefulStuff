#include "UsefulStuff.h"
#include <iostream>


unsigned int BitCount( unsigned int n )  
{   
    return (log( n ) / log( 2 )) + 1;  
}  

unsigned short swap_uint2(unsigned short x)
{
    return ((x >> 8) | (x << 8));

}

unsigned int swap_uint3(unsigned int x)
{
    return (((x >> 16) & 0x0000ff) | ((x) & 0x00ff00) | ((x << 8) & 0xff0000));
}

unsigned int swap_uint4(unsigned int x)
{
    return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff00) | ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));
}

unsigned long long swap_uint8(unsigned long long val)
{
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL) | ((val >> 8) & 0x00FF00FF00FF00FFULL);
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL) | ((val >> 16) & 0x0000FFFF0000FFFFULL);
    return (val << 32) | (val >> 32);
}


char change_case (char c) 
{
    if (std::islower(c) && !isdigit(c)) 
        return std::toupper(c); 
    else
        return c; 
}

void StringToHEX(std::string hex, uint8_t *answer)
{                      
    std::stringstream convertStream;
    hex.erase(std::remove(hex.begin(), hex.end(), ' '), hex.end());
    unsigned int buffer;   
    int offset = 0, i = 0; 
    if (hex.length() % 2 != 0)
        hex.insert(0, "0");                  
    while (offset < hex.length()) 
    {       
        convertStream << std::hex << hex.substr(offset, 2);         
        convertStream >> std::hex >> buffer;
        answer[i] = static_cast<unsigned char>(buffer);
        offset += 2;
        i++;       
        convertStream.str(std::string());
        convertStream.clear();        
    }              
}

void HEXToString(std::string& hex, uint8_t *answer, int size)
{    
    std::stringstream convertStream;
    unsigned int buffer;       
    for (int i = 0; i < size; ++i)
    {
        buffer = answer[i];         
        convertStream << std::hex << buffer;              
    }   
    convertStream >> hex;
    convertStream.clear(); 
    if (hex.length() % 2 != 0)
        hex.insert(0, "0");    
    std::transform(hex.begin(), hex.end(), hex.begin(), change_case);   
}
