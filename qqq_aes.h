#ifndef _QQQ_AES_H_
#define _QQQ_AES_H_

// Encrypt plain text state[16] to encrypted state[16], key[16] gets destroyed
void aes_encrypt(uint8_t* key, uint8_t* state);

#endif // _QQQ_AES_H_
