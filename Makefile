GURU=c
all: $(patsubst %.$(GURU),%,$(wildcard *.$(GURU)))
%:%.c
        gcc $^ -o $@

