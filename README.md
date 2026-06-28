This small patch was developed with the assistance of Anthropic's AI model, Claude.

To enable Turkish Q keyboard support, navigate to:

`C:\Users\YourUsername\AppData\Local\Arduino15\packages\digistump\hardware\avr\1.6.7\libraries\DigisparkKeyboard`

Replace the contents of the `scancode-ascii-table.h` file with the version provided in this repository.
Then, simply add the following line at the beginning of your project:

```cpp
#define kbd_tr_tr
```
That's it! Your Digispark project will now use the Turkish Q keyboard layout.
