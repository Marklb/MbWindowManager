EXECUTABLE=mbwm
CC=gcc
# CC=g++
RM=rm -f
CFLAGS=-I. -lm -mwindows

OBJS=src/mbwm.c \
	 src/mb_keyboard.c \
	 src/MB_LinkedList.c \
	 src/WorkspaceList.c \
	 src/mb_mode.c \
	 src/mb_mode_gui.c \
	 src/mb_processes_list_gui.c \
	 src/mb_window_organization_mode.c \
	 src/mb_window_organization_mode_gui.c

# $(EXECUTABLE): $(OBJS)
# 	$(CC) -o $(EXECUTABLE) $(OBJS) kbhook.dll $(CFLAGS)

$(EXECUTABLE): $(OBJS)
	$(CC) -o $(EXECUTABLE) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(EXECUTABLE)
