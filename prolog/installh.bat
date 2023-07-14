echo off
if "%1" == "" goto badstart
if "%2" == "" goto badstart
if "%3" == "CHAIN" goto begin
goto badstart
:begin
echo Copying and unpacking files...
unpack %1\ANSWERS.ARC %2\ANSWERS
unpack %1\EXAMPLES.ARC %2\EXAMPLES
unpack %1\PIE.ARC %2\PIE
unpack %1\PROGRAMS.ARC %2\PROGRAMS
unpack %1\REFEXAMP.ARC %2\REFEXAMP
copy %1\readme.* %2
:chkdsk2
if exist %1PROLOG.EXE goto cpyfile2
echo Please insert the Turbo Prolog disk labeled COMPILER into drive %1
pause
goto chkdsk2
:cpyfile2
copy %1\PROLOG.EXE %2
copy %1\BGI.LIB %2\BGI
copy %1\BGIOBJ.EXE %2\BGI
:chkdsk3
if exist %1PROLOG.ERR goto cpyfile3
echo Please insert the Turbo Prolog disk labeled HELP/BGI into drive %1
pause
goto chkdsk3
:cpyfile3
copy %1\PROLOG.* %2
copy %1\*.BGI %2\BGI
copy %1\*.CHR %2\BGI
copy %1\OLD.SYS %2
:chkdsk4
if exist %1PROLOG.LIB goto cpyfile4
echo Please insert the Turbo Prolog disk labeled LIBRARY into drive %1
pause
goto chkdsk4
:cpyfile4
copy %1\*.* %2
echo off
erase %2\UNPACK.COM
erase %2\INSTALLF.BAT
echo 
echo Turbo Prolog 2.0 is now installed on your hard disk. Before
echo running Turbo Prolog you should add 
echo 
echo   %2
echo 
echo to your DOS PATH so you can run the compiler from any directory.
echo For example, in your AUTOEXEC.BAT file you would add the line:
echo 
echo   PATH=%2
echo 
echo You should also add the lines
echo 
echo   FILES=20
echo   BUFFERS=40
echo 
echo to the CONFIG.SYS file located in the root directory of your hard
echo disk.
echo 
goto quit
:badstart
echo Please use INSTALL to begin installation.
:quit
