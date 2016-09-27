CC := icc
C_FLAGS := -O3
OFFLOAD_FLAGS := -qoffload=mandatory -qoffload-attribute-target=mic
INCLUDE_PATHS := 

LIBXEONPHI_SHARED_O := libxeonphi.so
LIBXEONPHI_OBJECTS := \
    core.o
    #test.o

.PHONY: all

%.o: %.c
	$(CC) $(C_FLAGS) $(OFFLOAD_FLAGS) $(INCLUDE_PATHS) -c -o $@ $<

all: $(LIBXEONPHI_SHARED_O)

$(LIBXEONPHI_SHARED_O): $(LIBXEONPHI_OBJECTS)
