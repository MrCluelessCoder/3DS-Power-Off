# 3DS-Power-Off
3DS Power Off

These "APT:U" and "APT:S" NS services handles signaling for power button. 

Signal Type: 0x8 Power button pressed. Triggered by a call to aptAppletUtility() type12.

I2C Registers>Device 3>(REGISTER:0x20, WIDTH:8)Writing u8 value 8 triggers a shutdown via power-off?

The idea is to create a 3ds software to power off the console without pressing the power button in order to prolong the lifespan of it.

App seems to be broken.

My coding is in a mess. Codes are missing and potentially broken. 
