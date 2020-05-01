#include "qqq_cmac.h"
#include "qqq_aes.h"

// Compute length prepended CBC-CMAC of msg[msglen] with AES128 key[16], result is in cmac[16]. Keeps key and msg intact.
void cmac(uint8_t* key, uint8_t* msg, uint16_t msglen, uint8_t* cmac) {
	//prepend 4 byte length little endian
	memset(cmac, 0x00, 16);
	cmac[0] = msglen;
	cmac[1] = msglen >> 8;
	
	//load up to 12 bytes from msg and encrypt first block
	uint16_t pos = 0;
	while(pos<12 && pos<msglen) {
		cmac[pos+4] = msg[pos];
		pos++;
	}
	aes_encrypt(key, cmac);
	
	while(pos < msglen) {
		//xor next block, then encrypt
		for(uint8_t i=0;i<16;i++) {
			if(pos >= msglen) break;
			cmac[pos+4] ^= msg[pos];
			pos++;
		}
		aes_encrypt(key, cmac);
	}
}

