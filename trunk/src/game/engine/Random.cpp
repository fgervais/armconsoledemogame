

#include "Random.h"

Random::Random(){
}




uint32_t Random::getRandom(uint32_t m_w, uint32_t m_z)
{

    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;  /* 32-bit result */
}
