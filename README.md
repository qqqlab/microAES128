# microAES128
AES encryption tested on AVR microcontollers. Uses minimal RAM as round keys are calculated on the fly.

## Benchmarks
|AVR-GCC Option|Code Size (bytes)|kCycles / block|
|:--:|--:|--:|
|-O1|813|11.7|
|-O2| |10.0|
|-O3|2119|7.2|
|-Os|703|10.0|
