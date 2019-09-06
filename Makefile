default:
	gcc LanguageGame.c dependencies.c -o game
run:
	./game
clean:
	rm game