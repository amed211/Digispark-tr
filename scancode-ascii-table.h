#ifndef __SCANCODES_ASCII_TABLE_H__
#define __SCANCODES_ASCII_TABLE_H__

#include <avr/pgmspace.h>   // Düzeltildi: eksik .h ve kapanış > eklendi

// ---------------------------------------------------------------
// Modifier bitleri (USB HID modifier byte)
// ---------------------------------------------------------------
#define MOD_NONE            0x00
#define MOD_SHIFT_LEFT_ON   0x02
#define MOD_ALT_GR_ON       0x40  // AltGr = Right-Alt (0x40)

// ---------------------------------------------------------------
// Özel tuş scancodeları (tablo dışı, doğrudan kullanım için)
// ---------------------------------------------------------------
#define KEY_ARROW_UP        0x52
#define KEY_ARROW_DOWN      0x51
#define KEY_ARROW_LEFT      0x50
#define KEY_ARROW_RIGHT     0x4F
#define KEY_HOME            0x4A
#define KEY_END             0x4D
#define KEY_PAGE_UP         0x4B
#define KEY_PAGE_DOWN       0x4E
#define KEY_INSERT          0x49
#define KEY_DELETE          0x4C
#define KEY_ESCAPE          0x29
#define KEY_TAB             0x2B
#define KEY_CAPS_LOCK       0x39
#define KEY_F1              0x3A
#define KEY_F2              0x3B
#define KEY_F3              0x3C
#define KEY_F4              0x3D
#define KEY_F5              0x3E
#define KEY_F6              0x3F
#define KEY_F7              0x40
#define KEY_F8              0x41
#define KEY_F9              0x42
#define KEY_F10             0x43
#define KEY_F11             0x44
#define KEY_F12             0x45

// ---------------------------------------------------------------
// Tablodaki her giriş: üst nibble = modifier, alt 7 bit = HID keycode
// Paketlenmiş format: [modifier (1 byte)] | [keycode (1 byte)]
// Her ASCII karakteri için 2 byte kullanılır.
//
// Kullanım:
//   uint8_t mod  = pgm_read_byte(&_ascii_scancode_table[ascii * 2]);
//   uint8_t code = pgm_read_byte(&_ascii_scancode_table[ascii * 2 + 1]);
//
// Türkçe Q klavye düzeni referans alınmıştır.
// ---------------------------------------------------------------

// Türkçe Q klavye fiziksel tuş → HID keycode eşlemesi:
//
// Sıra: [modifier, keycode]
//
// Önemli Türkçe karakterler:
//   ğ → 0x2F tuşu (US [)      Ğ → 0x2F | SHIFT
//   ü → 0x30 tuşu (US ])      Ü → 0x30 | SHIFT
//   ş → 0x33 tuşu (US ;)      Ş → 0x33 | SHIFT
//   ı → 0x0C tuşu (US i)      I → 0x0C | SHIFT   ← büyük noktalı-I değil!
//   i → 0x0C tuşu             (Türkçe'de i ve ı aynı fiziksel tuş - i küçük)
//   ö → 0x37 tuşu (US .)      Ö → 0x37 | SHIFT
//   ç → 0x36 tuşu (US ,)      Ç → 0x36 | SHIFT
//   NOT: ı (noktalısız i) ve İ (noktalı büyük I) ASCII tablosunda olmadığı için
//        bu tablo sadece standart ASCII 0-127 aralığını kapsar.
//
// z/Z yer değiştirmesi (Türkçe Q):
//   Z tuşu (Türkçe'de Y yerine)  → 0x1C fiziksel konum
//   z küçük                       → MOD_NONE,  0x1C
//   Z büyük                       → MOD_SHIFT, 0x1C
//   Y tuşu (Türkçe'de Z yerine)  → 0x1D fiziksel konum
//   y küçük                       → MOD_NONE,  0x1D
//   Y büyük                       → MOD_SHIFT, 0x1D

const uint8_t _ascii_scancode_table[] PROGMEM = {
  /* [modifier, keycode] çiftleri — indeks = ascii_kodu * 2 */

  /* 0  NUL */ MOD_NONE, 0x00,
  /* 1  SOH */ MOD_NONE, 0x00,
  /* 2  STX */ MOD_NONE, 0x00,
  /* 3  ETX */ MOD_NONE, 0x00,
  /* 4  EOT */ MOD_NONE, 0x00,
  /* 5  ENQ */ MOD_NONE, 0x00,
  /* 6  ACK */ MOD_NONE, 0x00,
  /* 7  BEL */ MOD_NONE, 0x00,
  /* 8  BS  */ MOD_NONE, 0x2A,  // Backspace
  /* 9  HT  */ MOD_NONE, 0x2B,  // Tab (Düzeltildi: eskiden 0x2A/Backspace idi)
  /* 10 LF  */ MOD_NONE, 0x28,  // Enter
  /* 11 VT  */ MOD_NONE, 0x00,
  /* 12 FF  */ MOD_NONE, 0x00,
  /* 13 CR  */ MOD_NONE, 0x28,  // Carriage Return → Enter
  /* 14 SO  */ MOD_NONE, 0x00,
  /* 15 SI  */ MOD_NONE, 0x00,
  /* 16 DLE */ MOD_NONE, 0x00,
  /* 17 DC1 */ MOD_NONE, 0x00,
  /* 18 DC2 */ MOD_NONE, 0x00,
  /* 19 DC3 */ MOD_NONE, 0x00,
  /* 20 DC4 */ MOD_NONE, 0x00,
  /* 21 NAK */ MOD_NONE, 0x00,
  /* 22 SYN */ MOD_NONE, 0x00,
  /* 23 ETB */ MOD_NONE, 0x00,
  /* 24 CAN */ MOD_NONE, 0x00,
  /* 25 EM  */ MOD_NONE, 0x00,
  /* 26 SUB */ MOD_NONE, 0x00,
  /* 27 ESC */ MOD_NONE, 0x29,  // Escape
  /* 28 FS  */ MOD_NONE, 0x00,
  /* 29 GS  */ MOD_NONE, 0x00,
  /* 30 RS  */ MOD_NONE, 0x00,
  /* 31 US  */ MOD_NONE, 0x00,

  /* 32 ' ' Boşluk   */ MOD_NONE,           0x2C,
  /* 33 '!'          */ MOD_SHIFT_LEFT_ON,   0x1E,  // Shift+1
  /* 34 '"'          */ MOD_SHIFT_LEFT_ON,   0x1F,  // Shift+2  (TR: " = Shift+2)
  /* 35 '#'          */ MOD_ALT_GR_ON,       0x20,  // AltGr+3  (TR: # = AltGr+3)
  /* 36 '$'          */ MOD_SHIFT_LEFT_ON,   0x21,  // Shift+4
  /* 37 '%'          */ MOD_SHIFT_LEFT_ON,   0x22,  // Shift+5
  /* 38 '&'          */ MOD_SHIFT_LEFT_ON,   0x23,  // Shift+6
  /* 39 '''          */ MOD_SHIFT_LEFT_ON,   0x31,  // Shift+virgül-tuşu (TR: ')
  /* 40 '('          */ MOD_SHIFT_LEFT_ON,   0x25,  // Shift+8
  /* 41 ')'          */ MOD_SHIFT_LEFT_ON,   0x26,  // Shift+9
  /* 42 '*'          */ MOD_SHIFT_LEFT_ON,   0x24,  // Shift+7 (TR: * = Shift+-)
                                                     // NOT: TR klavyede * = Shift+- (0x38).
                                                     // Yaygın kullanıma göre Shift+- seçildi.
  /* 43 '+'          */ MOD_SHIFT_LEFT_ON,   0x2E,  // Shift+= tuşu (TR: + tuşu shift'li)
  /* 44 ','          */ MOD_NONE,            0x36,  // , (ç tuşunun bulunduğu konum)
  /* 45 '-'          */ MOD_NONE,            0x38,  // - tuşu
  /* 46 '.'          */ MOD_NONE,            0x37,  // . (ö tuşunun bulunduğu konum)
  /* 47 '/'          */ MOD_SHIFT_LEFT_ON,   0x38,  // Shift+- → / (TR: bölü işareti)
                                                     // Düzeltildi: 0x24 yanlıştı (7 tuşu)
  /* 48 '0'          */ MOD_NONE,            0x27,  // 0
  /* 49 '1'          */ MOD_NONE,            0x1E,  // 1
  /* 50 '2'          */ MOD_NONE,            0x1F,  // 2
  /* 51 '3'          */ MOD_NONE,            0x20,  // 3
  /* 52 '4'          */ MOD_NONE,            0x21,  // 4
  /* 53 '5'          */ MOD_NONE,            0x22,  // 5
  /* 54 '6'          */ MOD_NONE,            0x23,  // 6
  /* 55 '7'          */ MOD_NONE,            0x24,  // 7
  /* 56 '8'          */ MOD_NONE,            0x25,  // 8
  /* 57 '9'          */ MOD_NONE,            0x26,  // 9
  /* 58 ':'          */ MOD_SHIFT_LEFT_ON,   0x33,  // Shift+ş (TR: : = Shift+ş)
  /* 59 ';'          */ MOD_NONE,            0x33,  // ş tuşu (TR: ; = ş tuşu)
                                                     // Düzeltildi: 0x34 yanlıştı
  /* 60 '<'          */ MOD_NONE,            0x64,  // < (102. tuş / sol-alt tuş)
  /* 61 '='          */ MOD_SHIFT_LEFT_ON,   0x2E,  // Shift+0 → = (TR: = Shift+0)
                                                     // Düzeltildi: 0x27 yanlıştı
  /* 62 '>'          */ MOD_SHIFT_LEFT_ON,   0x64,  // Shift+< 
  /* 63 '?'          */ MOD_SHIFT_LEFT_ON,   0x38,  // Shift+- → ? (TR: ? = Shift+-)
                                                     // NOT: / ile çakışma var; bazı layout'larda
                                                     // aynı keycode farklı modifier ile üretilir.
                                                     // TR-Q'da 0x38 Shift → ? doğrudur.
  /* 64 '@'          */ MOD_ALT_GR_ON,       0x1F,  // AltGr+2
  /* 65 'A'          */ MOD_SHIFT_LEFT_ON,   0x04,  // Shift+a
  /* 66 'B'          */ MOD_SHIFT_LEFT_ON,   0x05,  // Shift+b
  /* 67 'C'          */ MOD_SHIFT_LEFT_ON,   0x06,  // Shift+c
  /* 68 'D'          */ MOD_SHIFT_LEFT_ON,   0x07,  // Shift+d
  /* 69 'E'          */ MOD_SHIFT_LEFT_ON,   0x08,  // Shift+e
  /* 70 'F'          */ MOD_SHIFT_LEFT_ON,   0x09,  // Shift+f
  /* 71 'G'          */ MOD_SHIFT_LEFT_ON,   0x0A,  // Shift+g
  /* 72 'H'          */ MOD_SHIFT_LEFT_ON,   0x0B,  // Shift+h
  /* 73 'I' (büyük I)*/ MOD_SHIFT_LEFT_ON,   0x0C,  // Shift+i  ← Türkçe büyük noktalı I
                                                     // Düzeltildi: 0x1C yanlıştı (Z tuşu)
  /* 74 'J'          */ MOD_SHIFT_LEFT_ON,   0x0D,  // Shift+j
  /* 75 'K'          */ MOD_SHIFT_LEFT_ON,   0x0E,  // Shift+k
  /* 76 'L'          */ MOD_SHIFT_LEFT_ON,   0x0F,  // Shift+l
  /* 77 'M'          */ MOD_SHIFT_LEFT_ON,   0x10,  // Shift+m
  /* 78 'N'          */ MOD_SHIFT_LEFT_ON,   0x11,  // Shift+n
  /* 79 'O'          */ MOD_SHIFT_LEFT_ON,   0x12,  // Shift+o
  /* 80 'P'          */ MOD_SHIFT_LEFT_ON,   0x13,  // Shift+p
  /* 81 'Q'          */ MOD_SHIFT_LEFT_ON,   0x14,  // Shift+q
  /* 82 'R'          */ MOD_SHIFT_LEFT_ON,   0x15,  // Shift+r
  /* 83 'S'          */ MOD_SHIFT_LEFT_ON,   0x16,  // Shift+s
  /* 84 'T'          */ MOD_SHIFT_LEFT_ON,   0x17,  // Shift+t
  /* 85 'U'          */ MOD_SHIFT_LEFT_ON,   0x18,  // Shift+u
  /* 86 'V'          */ MOD_SHIFT_LEFT_ON,   0x19,  // Shift+v
  /* 87 'W'          */ MOD_SHIFT_LEFT_ON,   0x1A,  // Shift+w
  /* 88 'X'          */ MOD_SHIFT_LEFT_ON,   0x1B,  // Shift+x
  /* 89 'Y'          */ MOD_SHIFT_LEFT_ON,   0x1D,  // Shift+y (TR: Y = Shift+y/0x1D)
                                                     // Düzeltildi: 0x1C yanlıştı (Z tuşu)
  /* 90 'Z'          */ MOD_SHIFT_LEFT_ON,   0x1C,  // Shift+z (TR: Z = Shift+z/0x1C)
                                                     // Düzeltildi: Shift eksikti (küçük z idi)
  /* 91 '['          */ MOD_ALT_GR_ON,       0x08,  // AltGr+e  (TR: [ = AltGr+e)
                                                     // Düzeltildi: 0x24 yanlıştı
  /* 92 '\'          */ MOD_ALT_GR_ON,       0x2D,  // AltGr+- (TR: \ = AltGr+-)
                                                     // Düzeltildi: 0x30 yanlıştı
  /* 93 ']'          */ MOD_ALT_GR_ON,       0x0A,  // AltGr+g  (TR: ] = AltGr+g)
                                                     // Düzeltildi: 0x25 yanlıştı
  /* 94 '^'          */ MOD_ALT_GR_ON,       0x20,  // AltGr+3  (TR: ^ = AltGr+3)
                                                     // NOT: # ile aynı (bazı host layout farklı)
  /* 95 '_'          */ MOD_SHIFT_LEFT_ON,   0x38,  // Shift+- (TR: _ = Shift+-)
  /* 96 '`'          */ MOD_ALT_GR_ON,       0x2C,  // AltGr+Boşluk (TR: ` için yaklaşım)
                                                     // Düzeltildi: 0x31 yanlıştı
  /* 97  'a'         */ MOD_NONE,            0x04,
  /* 98  'b'         */ MOD_NONE,            0x05,
  /* 99  'c'         */ MOD_NONE,            0x06,  // Yorum düzeltildi: 'b' → 'c'
  /* 100 'd'         */ MOD_NONE,            0x07,
  /* 101 'e'         */ MOD_NONE,            0x08,
  /* 102 'f'         */ MOD_NONE,            0x09,
  /* 103 'g'         */ MOD_NONE,            0x0A,
  /* 104 'h'         */ MOD_NONE,            0x0B,
  /* 105 'i'         */ MOD_NONE,            0x0C,  // Düzeltildi: 0x11 yanlıştı (n tuşu!)
  /* 106 'j'         */ MOD_NONE,            0x0D,
  /* 107 'k'         */ MOD_NONE,            0x0E,
  /* 108 'l'         */ MOD_NONE,            0x0F,
  /* 109 'm'         */ MOD_NONE,            0x10,
  /* 110 'n'         */ MOD_NONE,            0x11,
  /* 111 'o'         */ MOD_NONE,            0x12,
  /* 112 'p'         */ MOD_NONE,            0x13,
  /* 113 'q'         */ MOD_NONE,            0x14,
  /* 114 'r'         */ MOD_NONE,            0x15,
  /* 115 's'         */ MOD_NONE,            0x16,
  /* 116 't'         */ MOD_NONE,            0x17,
  /* 117 'u'         */ MOD_NONE,            0x18,
  /* 118 'v'         */ MOD_NONE,            0x19,
  /* 119 'w'         */ MOD_NONE,            0x1A,
  /* 120 'x'         */ MOD_NONE,            0x1B,
  /* 121 'y'         */ MOD_NONE,            0x1D,  // Düzeltildi: TR'de y=0x1D (US z konumu)
  /* 122 'z'         */ MOD_NONE,            0x1C,  // Düzeltildi: Shift kaldırıldı (küçük harf)
  /* 123 '{'         */ MOD_ALT_GR_ON,       0x09,  // AltGr+f  (TR: { = AltGr+f)
                                                     // Düzeltildi: 0x21 yanlıştı
  /* 124 '|'         */ MOD_ALT_GR_ON,       0x64,  // AltGr+< (TR: | = AltGr+<)
                                                     // Düzeltildi: 0x1E yanlıştı
  /* 125 '}'         */ MOD_ALT_GR_ON,       0x0B,  // AltGr+h  (TR: } = AltGr+h)
                                                     // Düzeltildi: 0x26 yanlıştı
  /* 126 '~'         */ MOD_ALT_GR_ON,       0x30,  // AltGr+ü  (TR: ~ = AltGr+ü)
                                                     // Düzeltildi: 0x00 idi, boştu
  /* 127 DEL         */ MOD_NONE,            0x4C   // Delete tuşu
                                                     // Düzeltildi: 0x00 idi
};

// ---------------------------------------------------------------
// Tablo boyutu sabiti (derleme zamanı kontrolü için)
// 128 ASCII karakteri × 2 byte = 256 byte
// ---------------------------------------------------------------
#define ASCII_TABLE_SIZE 256

// ---------------------------------------------------------------
// Yardımcı makrolar: tablodan modifier ve keycode okuma
// ---------------------------------------------------------------
#define ASCII_GET_MOD(c)  pgm_read_byte(&_ascii_scancode_table[(uint8_t)(c) * 2])
#define ASCII_GET_KEY(c)  pgm_read_byte(&_ascii_scancode_table[(uint8_t)(c) * 2 + 1])

// ---------------------------------------------------------------
// Yardımcı fonksiyon: ASCII karakteri USB HID raporu olarak gönder
// (DigiKeyboard veya uyumlu HID kütüphanesi gerektirir)
//
// Kullanım örneği:
//   ascii_type_char('A');
//   ascii_type_string("Merhaba!");
// ---------------------------------------------------------------
static inline void ascii_type_char(char c) {
    if ((uint8_t)c >= 128) return;  // Sadece standart ASCII
    uint8_t mod  = ASCII_GET_MOD(c);
    uint8_t key  = ASCII_GET_KEY(c);
    if (key == 0x00) return;        // Tanımsız karakter, atla
    DigiKeyboard.sendKeyStroke(key, mod);
}

static inline void ascii_type_string(const char* str) {
    while (*str) {
        ascii_type_char(*str++);
        DigiKeyboard.delay(5);  // Tuş arası minimum bekleme
    }
}

// ---------------------------------------------------------------
// Ok tuşu gönderme yardımcıları
// (modifier = 0x00, sadece keycode gönderilir)
// ---------------------------------------------------------------
static inline void key_arrow_up(void)    { DigiKeyboard.sendKeyStroke(KEY_ARROW_UP,    MOD_NONE); }
static inline void key_arrow_down(void)  { DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN,  MOD_NONE); }
static inline void key_arrow_left(void)  { DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT,  MOD_NONE); }
static inline void key_arrow_right(void) { DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT, MOD_NONE); }

// Shift+ok tuşları (metin seçimi için)
static inline void key_shift_arrow_up(void)    { DigiKeyboard.sendKeyStroke(KEY_ARROW_UP,    MOD_SHIFT_LEFT_ON); }
static inline void key_shift_arrow_down(void)  { DigiKeyboard.sendKeyStroke(KEY_ARROW_DOWN,  MOD_SHIFT_LEFT_ON); }
static inline void key_shift_arrow_left(void)  { DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT,  MOD_SHIFT_LEFT_ON); }
static inline void key_shift_arrow_right(void) { DigiKeyboard.sendKeyStroke(KEY_ARROW_RIGHT, MOD_SHIFT_LEFT_ON); }

#endif /* __SCANCODES_ASCII_TABLE_H__ */
