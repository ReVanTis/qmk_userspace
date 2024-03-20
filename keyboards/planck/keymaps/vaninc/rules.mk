ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

NKRO_ENABLE = yes
UNICODE_ENABLE = yes
MOUSEKEY_ENABLE = yes
COMMAND_ENABLE = yes
LTO_ENABLE = yes

# pick one you like:
CONSOLE_ENABLE = no
VIA_ENABLE = yes