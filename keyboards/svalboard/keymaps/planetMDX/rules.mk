VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE ?= yes

# STENO_ENABLE = yes
# STENO_PROTOCOL = geminipr

SRC += ../features/achordion.c
VPATH += keyboards/svalboard/keymaps
# SRC += keymap_support.c

TRI_LAYER_ENABLE = yes
LEADER_ENABLE = yes
REPEAT_KEY_ENABLE = yes
# PROGRAMMABLE_BUTTON_ENABLE = yes
CAPS_WORD_ENABLE = yes
