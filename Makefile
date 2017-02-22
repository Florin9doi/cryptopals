
SRCDIR  = src
OBJDIR  = obj
BINDIR  = bin

SRC     = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGETS = $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%)

CFLAGS  = -Wall -Werror

all: mkdirs $(TARGETS)

$(BINDIR)/%: $(OBJDIR)/%.o
	$(CC) -o $(LDFLAGS) $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

mkdirs:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(BINDIR)

clean:
	rm $(OBJECTS)
	rm $(TARGETS)
	@rmdir $(OBJDIR)
	@rmdir $(BINDIR)


#keep object files
.PRECIOUS: $(OBJDIR)/%.o