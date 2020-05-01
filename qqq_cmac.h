#ifndef _QQQ_CMAC_H_
#define _QQQ_CMAC_H_

/* https://en.wikipedia.org/wiki/CBC-MAC
"Length prepending

One solution is to include the length of the message in the first block;[3] in fact CBC-MAC has been proven secure as long as no two messages that are prefixes of each other are ever used and prepending the length is a special case of this."
*/

// Compute length prepended CBC-CMAC of msg, result is in cmac[16]. Keeps key and msg intact.
void cmac(uint8_t* key, uint8_t* msg, uint16_t msglen, uint8_t* cmac);

#endif // _QQQ_CMAC_H_
