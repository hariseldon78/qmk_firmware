SWAP_HANDS_ENABLE = no       # Enable one-hand typing
MOUSEKEY_ENABLE = yes        # Mouse keys
LTO_ENABLE = yes             # Enable link-time optimization
LEADER_ENABLE = yes
UNICODE_ENABLE = yes          # Unicode
CONVERT_TO = elite_pi
FIRMWARE_FORMAT = uf2

# If you want to change the display of OLED, you need to change here
SRC +=  caps_word.c
        #./lib/rgb_state_reader.c \
        #./lib/layer_state_reader.c \
        #./lib/logo_reader.c \
        #./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
