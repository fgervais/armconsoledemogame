/* a simple random, taken from wikipedia
 * note that this is NOT a proper random, it it a pseudo-random
 * and therefore needs initializers that are changing often to work properly

 */




#include <stdint.h>



class Random {
public:
	Random();
	~Random();


	// m_w and m_z are initializers, most programs use the internal clock but our system does not support this
	uint32_t getRandom(uint32_t m_w, uint32_t m_z);




};
