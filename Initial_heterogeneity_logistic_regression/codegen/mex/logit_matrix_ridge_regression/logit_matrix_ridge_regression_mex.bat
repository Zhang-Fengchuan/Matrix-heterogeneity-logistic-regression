@echo off
call setEnv.bat
"D:\MATLAB2023A\toolbox\shared\coder\ninja\win64\ninja.exe" -t compdb cc cxx cudac > compile_commands.json
"D:\MATLAB2023A\toolbox\shared\coder\ninja\win64\ninja.exe" -v %*
