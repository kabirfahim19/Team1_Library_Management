library: Item.o Book.o Magazine.o User.o Admin.o Member.o BorrowRecord.o FileManager.o Library.o main.o
	g++ Item.o Book.o Magazine.o User.o Admin.o Member.o BorrowRecord.o FileManager.o Library.o main.o -o library

Item.o: src/Item.cpp
	g++ -c src/Item.cpp -Iinclude

Book.o: src/Book.cpp
	g++ -c src/Book.cpp -Iinclude

Magazine.o: src/Magazine.cpp
	g++ -c src/Magazine.cpp -Iinclude

User.o: src/User.cpp
	g++ -c src/User.cpp -Iinclude

Admin.o: src/Admin.cpp
	g++ -c src/Admin.cpp -Iinclude

Member.o: src/Member.cpp
	g++ -c src/Member.cpp -Iinclude

BorrowRecord.o: src/BorrowRecord.cpp
	g++ -c src/BorrowRecord.cpp -Iinclude

FileManager.o: src/FileManager.cpp
	g++ -c src/FileManager.cpp -Iinclude

Library.o: src/Library.cpp
	g++ -c src/Library.cpp -Iinclude

main.o: src/main.cpp
	g++ -c src/main.cpp -Iinclude

clean:
	del *.o library.exe