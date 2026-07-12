# CFileManager

A lightweight command-line file manager written in C for Windows, built from scratch using the Windows API. Navigate your file system, manage files and folders — all from the terminal.

## Features

- Navigate directories (enter and go back)
- List folder contents with file sizes in KB
- Copy files to another location
- Move files to another location
- Delete files with confirmation prompt
- Rename files and folders
- Create new folders
- Automatic start at the user's Desktop

## Requirements

- Windows OS
- GCC compiler (MinGW/MSYS2 recommended)

## How to compile

```bash
gcc proj_Gerenciardor_arquivo_cli.c -o CFileManager.exe
```

## How to use

Run the executable:

```bash
./CFileManager.exe
```

The program starts at your Desktop automatically. Use the menu to navigate:

```
1 - List contents
2 - Enter folder
3 - Go back
4 - Copy file (keeps original)
5 - Move file (removes original)
6 - Delete file
7 - Rename file or folder
8 - Create folder
0 - Exit
```

## Notes

- File sizes are displayed in KB
- Delete and move operations require confirmation before executing
- Windows only — uses windows.h and native cmd commands (copy, move, del, rename, mkdir)
- Linux port planned for a future version

## Built with

- C (C99)
- windows.h
- GCC / MinGW

## Author

Joaquim — ADS student at IFCE Campus Boa Viagem
