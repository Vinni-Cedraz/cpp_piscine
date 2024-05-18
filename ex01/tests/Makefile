TESTS =	\
  		add_contacts \

## VARIABLES
CXX = c++
FLAGS = -lcriterion -w
LIBS = phonebook.a
SHELL = /bin/zsh

## FUNCTIONS
define compile_fn
	if [[ ! -f $(1) ]] || [[ $(1).cpp -nt $(1) ]]; then \
		$(CC) $(FLAGS) $(1).cpp $(LIBS) -o $(1) && printf "$(CC) $(FLAGS) $(1).cpp $(LIBS) -o $(1)\n"; \
	fi
endef

define run_fn
	$(1) --verbose && sleep 0.1
endef

## RULES
all: $(LIBS)
	@$(foreach name, $(TESTS), $(call compile_fn, $(name));)

$(LIBS):
	make --no-print-directory as_lib -C ../
run:
	@$(foreach name, $(TESTS), $(call run_fn, ./$(name));)
clean:
	$(foreach name, $(TESTS), $(RM) $(name);)
	@rm -f $(LIBS)
