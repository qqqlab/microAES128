# microAES128
AES encryption tested on AVR microcontollers. Uses minimal RAM as round keys are calculated on the fly.

To keep code size to a minimum, only the encryption algorithm is implemented, for use on nodes with minimal memory. For two way communication, the host should _encrypt_ messages to the node with _aes_decrypt()_. The node uses _aes_encrypt()_ to _decrypt_ the incoming message. The node uses aes_encrypt() to send an answer back to the host. The host uses aes_decrypt() to decrypt the message.

## Benchmarks aes_encrypt()
|AVR-GCC Option|Code Size (bytes)|kCycles / block|
|:--:|--:|--:|
|-O1|813|11.7|
|-O2| |10.0|
|-O3|2119|7.2|
|-Os|703|10.0|

## CMAC
Implements a length prepedend CBC-MAC.

>https://en.wikipedia.org/wiki/CBC-MAC  
>__Length prepending:__ One solution is to include the length of the message in the first block; in fact CBC-MAC has been proven secure as long as no two messages that are prefixes of each other are ever used and prepending the length is a special case of this."
