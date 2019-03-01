@echo off
:loop
gen.exe > 2.txt
1208with.exe < 2.txt > ans1.txt
1208without.exe < 2.txt > ans2.txt
echo "ok"
fc ans1.txt ans2.txt || pause
goto loop