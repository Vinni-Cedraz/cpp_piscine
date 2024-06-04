BUILD = @make --no-print-directory -C .. && cp ../not_sed .

all:
	$(BUILD)
test: all
	./test
fclean:
	rm -f main not_sed like_a_rolling_stone.replace test
