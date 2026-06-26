bootkit.bin: bootkit.asm
	nasm -f bin bootkit.asm -o bootkit.bin

installer.exe: installer.c
	x86_64-w64-mingw32-gcc -o installer.exe installer.c -luser32 -ladvapi32

payload.exe: payload.c
	x86_64-w64-mingw32-gcc -o payload.exe payload.c -luser32 -lgdi32 -mwindows

all: bootkit.bin installer.exe payload.exe

clean:
	rm -f bootkit.bin installer.exe payload.exe
