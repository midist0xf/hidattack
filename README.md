# hidattack
Human Interface Device attack happens when a USB device claims itself to be a keyboard and starts to injects a malicious sequence of keyboard strokes.

![UI](https://github.com/midist0xf/hidattack/blob/master/atiny.jpg)

## Prerequisites
- Digispark ATiny85
- Arduino

More info on HIDattacks and the instructions to setup everything can be found [here](https://github.com/midist0xf/slides/blob/master/HIDattack.pdf)
## Payloads
Payloads may have to be modified for a specific target. Changes depend on target's Desktop Environment, default shortcuts, keyboard layout etc. 
### Linux 
- [Reverse Shell - Minimum persistence](https://github.com/midist0xf/hidattack/blob/master/revshell/revshell.ino): creates an hidden reverse shell script which runs at every login.

