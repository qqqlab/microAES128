# microAES128
AES encryption tested on AVR microcontollers. Uses minimal RAM as round keys are calculated on the fly.

To keep code size to a minimum, only the encryption algorithm is implemented, for use on nodes with minimal memory. 

But even with only aes_encrypt(), two way encrypted communication is still possible:

#### Node to Host  
Node: c = aes_encrypt(plaintext); send(c);  
Host: c = receive(); plaintext = aes_decrypt(c);  

#### Host to Node  
Host: c = __aes_decrypt__(plaintext); send(c);  
Node: c = receive(); plaintext = __aes_encrypt__(c);

## Benchmarks aes_encrypt()
|AVR-GCC Option|Code Size (bytes)|kCycles / block|
|:--:|--:|--:|
|-O1|813|11.7|
|-O2| |10.0|
|-O3|2119|7.2|
|-Os|703|10.0|

This is a factor 2-3 slower than pure AVR assembly implementations, but C-code can be ported more easily to other microcontrollers.

## CMAC
Implements a length prepedend CBC-MAC.

>https://en.wikipedia.org/wiki/CBC-MAC  
>__Length prepending:__ One solution is to include the length of the message in the first block; in fact CBC-MAC has been proven secure as long as no two messages that are prefixes of each other are ever used and prepending the length is a special case of this."
