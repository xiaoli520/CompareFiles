mkdir build
cd build
qmake.exe ../CompareFilesApp.pro -r -spec win32-msvc2010
call "%VS100COMNTOOLS%\vsvars32.bat"
nmake
