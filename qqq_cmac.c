#include "qqq_cmac.h"
#include "qqq_aes.h"

// Compute length prepended CBC-CMAC of msg[msglen] with AES128 key[16], result is in cmac[16]. Keeps key and msg intact.
void cmac(uint8_t* key, uint8_t* msg, uint32_t msglen, uint8_t* cmac) {
	uint8_t cpos = 0;
	uint32_t mpos = 0;
  
	//clear cmac
	memset(cmac, 0x00, 16);	
	
	//prepend 1 or 5 bytes with lenght
	if(msglen<255) {
	  cmac[cpos++] = msglen;
	}else{
	  cmac[cpos++] = 0xff;
    cmac[cpos++] = msglen;
	  cmac[cpos++] = msglen >> 8;
    cmac[cpos++] = msglen >> 16;
	  cmac[cpos++] = msglen >> 24;
  }
  
	//load up to 15 bytes from msg and encrypt first block
	while(cpos<16 && mpos<msglen) {
		cmac[cpos++] = msg[mpos++];
	}
	aes_encrypt(key, cmac);
	
	while(mpos < msglen) {
		//xor next (partial) block, then encrypt
    cpos = 0;
    while(cpos<16 && mpos<msglen) {
		  cmac[cpos++] ^= msg[mpos++];
	  }
		aes_encrypt(key, cmac);
	}
}

