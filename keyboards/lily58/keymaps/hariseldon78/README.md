[Lily58 hariseldon78 layout image](https://imgur.com/a/F6zBcoV)

This keymap is the result of a long evolution. It started as a BEAKL 15 layout, then customized in the position of some keys and with the addition of many layers.
The main modifiers Ctrl Alt and Shift are on the homerow, it takes a bit of getting used to, mostly to teach your hands to press the modifier with the opposite hand of the modified key.

I never learned to use vim keys and i find too much counterintuitive to have up and down on the same row, so I mapped the arrow keys near right homerow with classical arrows/WASD conformation.

The macros are useful for the coders, the Scaf and UnScaf macros prepare you inside an indented empty line or remove it, they are meant to be used together with the parentheses macros.

The multiple Scroll Lock keys are used as [Compose key](https://en.wikipedia.org/wiki/Compose_key)

My keyboard is built with the Elite PI microchip, so the installations instructions are:

```
qmk clean && qmk compile -kb lily58/rev1_1 -km hariseldon78
```
- then I connect the first half of the board to usb, 
- double click the chip reset button, 
- copy the file lily58_rev1_1_hariseldon78_elite_pi.uf2 into the mounted drive
- repeat with the other half
